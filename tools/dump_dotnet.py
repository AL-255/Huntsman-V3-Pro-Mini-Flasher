#!/usr/bin/env python3
"""Inspect a .NET assembly: types, methods, fields, signatures, P/Invoke maps,
and a lightweight IL listing for reconstructing the update flow.

Usage:
  dump_dotnet.py <assembly> types [--filter SUBSTR]
  dump_dotnet.py <assembly> pinvoke
  dump_dotnet.py <assembly> methods <TypeName> [--il]
  dump_dotnet.py <assembly> il <TypeName>
"""
from __future__ import annotations

import sys

import dnfile

# --- ECMA-335 element type constants -------------------------------------
ET = {
    0x01: "void", 0x02: "bool", 0x03: "char", 0x04: "i1", 0x05: "u1",
    0x06: "i2", 0x07: "u2", 0x08: "i4", 0x09: "u4", 0x0a: "i8", 0x0b: "u8",
    0x0c: "r4", 0x0d: "r8", 0x0e: "string", 0x0f: "ptr", 0x10: "byref",
    0x11: "valuetype", 0x12: "class", 0x13: "var", 0x14: "genericinst",
    0x15: "array", 0x16: "typedbyref", 0x18: "i", 0x19: "u", 0x1a: "fnptr",
    0x1b: "object", 0x1c: "object", 0x1d: "szarray", 0x1e: "mvar",
    0x45: "pinned", 0x50: "modifier", 0x55: "sentinel", 0x63: "i4", 0x64: "u4",
}


class Pe:
    def __init__(self, path: str):
        self.pe = dnfile.dnPE(path)
        self.md = self.pe.net.mdtables

    @staticmethod
    def _idx(i):
        if hasattr(i, "row_index"):
            return i.row_index
        return int(i)

    # --- tables ---
    def type_def(self, i):
        return self.md.TypeDef.rows[self._idx(i) - 1]

    def type_ref(self, i):
        return self.md.TypeRef.rows[self._idx(i) - 1]

    def type_spec(self, i):
        return self.md.TypeSpec.rows[self._idx(i) - 1]

    def method_def(self, i):
        return self.md.MethodDef.rows[self._idx(i) - 1]

    def member_ref(self, i):
        return self.md.MemberRef.rows[self._idx(i) - 1]

    def field(self, i):
        return self.md.Field.rows[self._idx(i) - 1]

    def module_ref(self, i):
        return self.md.ModuleRef.rows[self._idx(i) - 1]

    def str(self, o):
        return str(o)

    # --- compressed int / coded index ---
    @staticmethod
    def read_cint(buf, pos):
        b = buf[pos]
        if b & 0x80 == 0:
            return b, pos + 1
        if b & 0xc0 == 0x80:
            v = ((b & 0x3f) << 8) | buf[pos + 1]
            return v, pos + 2
        v = ((b & 0x1f) << 24) | (buf[pos + 1] << 16) | (buf[pos + 2] << 8) | buf[pos + 3]
        return v, pos + 4

    def decode_tdor(self, coded):
        # TypeDefOrRef: tag 2 bits
        tag = coded & 3
        idx = coded >> 2
        if tag == 0:
            try:
                t = self.type_def(idx)
                return str(t.TypeNamespace) + "." + str(t.TypeName)
            except Exception:  # noqa: BLE001
                return "typedef#" + str(idx)
        if tag == 1:
            t = self.type_ref(idx)
            return str(t.TypeNamespace) + "." + str(t.TypeName)
        return "typespec#" + str(idx)

    def type_name(self, coded):
        # coded is raw coded index value (already includes tag)
        return self.decode_tdor(coded)

    def parse_type(self, buf, pos):
        et = buf[pos]
        pos += 1
        if et == 0x1d:  # szarray
            inner, pos = self.parse_type(buf, pos)
            return inner + "[]", pos
        if et == 0x0f or et == 0x10 or et == 0x45:  # ptr/byref/pinned
            inner, pos = self.parse_type(buf, pos)
            sym = {"0x0f": "*", "0x10": "&", "0x45": ""}[hex(et)]
            return inner + sym, pos
        if et == 0x11 or et == 0x12:  # valuetype/class
            coded, pos = self.read_cint(buf, pos)
            name = self.decode_tdor(coded)
            return ("struct " + name) if et == 0x11 else name, pos
        if et == 0x14:  # genericinst
            coded, pos = self.read_cint(buf, pos)
            base = self.decode_tdor(coded)
            argc, pos = self.read_cint(buf, pos)
            args = []
            for _ in range(argc):
                a, pos = self.parse_type(buf, pos)
                args.append(a)
            return base + "<" + ",".join(args) + ">", pos
        if et == 0x15:  # array
            inner, pos = self.parse_type(buf, pos)
            # rank, sizes, lobounds
            rank, pos = self.read_cint(buf, pos)
            nsz, pos = self.read_cint(buf, pos)
            for _ in range(nsz):
                _, pos = self.read_cint(buf, pos)
            nlb, pos = self.read_cint(buf, pos)
            for _ in range(nlb):
                _, pos = self.read_cint(buf, pos)
            return inner + "[*]", pos
        if et in ET:
            return ET[et], pos
        if et == 0x50:  # modifier
            coded, pos = self.read_cint(buf, pos)
            inner, pos = self.parse_type(buf, pos)
            return inner, pos
        return "unknown(0x%02x)" % et, pos

    def parse_method_sig(self, sig: bytes):
        pos = 0
        cc = sig[pos]
        pos += 1
        has_this = bool(cc & 0x20)
        explicit = bool(cc & 0x40)
        generic = bool(cc & 0x10)
        if generic:
            _, pos = self.read_cint(sig, pos)
        param_count, pos = self.read_cint(sig, pos)
        ret, pos = self.parse_type(sig, pos)
        params = []
        for _ in range(param_count):
            t, pos = self.parse_type(sig, pos)
            params.append(t)
        return ret, params, has_this

    def method_sig(self, mdef):
        sig = mdef.Signature.value
        return self.parse_method_sig(sig)

    def field_type(self, fdef):
        sig = fdef.Signature.value
        # field sig: 0x06 (FIELD) then type
        pos = 1
        t, _ = self.parse_type(sig, pos)
        return t


def cmd_types(pe: Pe, filt=None):
    md = pe.md
    for i, r in enumerate(md.TypeDef.rows):
        name = str(r.TypeNamespace) + "." + str(r.TypeName)
        if filt and filt.lower() not in name.lower():
            continue
        print(f"[{i}] {name}")


def cmd_pinvoke(pe: Pe):
    md = pe.md
    for imp in md.ImplMap.rows:
        mod = str(pe.module_ref(imp.ImportScope).Name)
        entry = str(imp.ImportName)
        mdef = pe.method_def(imp.MemberForwarded)
        name = str(mdef.Name)
        try:
            ret, params, _ = pe.method_sig(mdef)
        except Exception as e:  # noqa: BLE001
            ret, params = "?", []
        flags = getattr(imp.MappingFlags, "value", imp.MappingFlags)
        print(f"{name}({', '.join(params)}) -> {ret}  [DllImport {mod} entry={entry} flags={flags!r}]")


def cmd_methods(pe: Pe, type_name: str, show_il=False, only=None):
    md = pe.md
    for i, r in enumerate(md.TypeDef.rows):
        name = str(r.TypeNamespace) + "." + str(r.TypeName)
        if name != type_name:
            continue
        for m_idx in r.MethodList:
            m = md.MethodDef.rows[m_idx.row_index - 1]
            mname = str(m.Name)
            if only and mname != only:
                continue
            try:
                ret, params, has_this = pe.method_sig(m)
            except Exception:  # noqa: BLE001
                ret, params, has_this = "?", [], False
            mflags = m.Flags
            mimpl = m.ImplFlags
            flags = "static" if getattr(mflags, "mdStatic", False) else "instance"
            attrs = ""
            if getattr(mimpl, "miNative", False):
                attrs += " [native]"
            if getattr(mimpl, "miRuntime", False):
                attrs += " [runtime]"
            rva = m.Rva
            print(f"  {flags} {ret} {mname}({', '.join(params)}) rva=0x{rva:x}{attrs}")
            if show_il and rva != 0 and not getattr(m.ImplFlags, "miRuntime", False):
                dump_il(pe, m)
        return


def dump_il(pe: Pe, mdef):
    """Lightweight IL listing with resolved operands."""
    rva = mdef.Rva
    try:
        header = pe.pe.get_data(rva, 1)[0]
    except Exception:  # noqa: BLE001
        return
    if header & 3 == 3:  # fat
        hdr = pe.pe.get_data(rva, 12)
        hdr_size = (hdr[1] >> 4) * 4
        code_size = int.from_bytes(hdr[4:8], "little")
        code = pe.pe.get_data(rva + hdr_size, code_size)
    else:  # tiny
        code_size = header >> 2
        code = pe.pe.get_data(rva + 1, code_size)
    print(f"      // IL ({code_size} bytes):")
    dump_il_bytes(pe, code)


# minimal IL opcodes we care about
IL_OP = {
    0x00: "nop", 0x01: "break", 0x02: "ldarg.0", 0x03: "ldarg.1",
    0x04: "ldarg.2", 0x05: "ldarg.3", 0x06: "ldloc.0", 0x07: "ldloc.1",
    0x08: "ldloc.2", 0x09: "ldloc.3", 0x0a: "stloc.0", 0x0b: "stloc.1",
    0x0c: "stloc.2", 0x0d: "stloc.3", 0x0e: "ldarg.s", 0x0f: "ldarga.s",
    0x10: "starg.s", 0x11: "ldloc.s", 0x12: "ldloca.s", 0x13: "stloc.s",
    0x14: "ldnull", 0x15: "ldc.i4.m1", 0x16: "ldc.i4.0", 0x17: "ldc.i4.1",
    0x18: "ldc.i4.2", 0x19: "ldc.i4.3", 0x1a: "ldc.i4.4", 0x1b: "ldc.i4.5",
    0x1c: "ldc.i4.6", 0x1d: "ldc.i4.7", 0x1e: "ldc.i4.8", 0x1f: "ldc.i4.s",
    0x20: "ldc.i4", 0x21: "ldc.i8", 0x22: "ldc.r4", 0x23: "ldc.r8",
    0x25: "dup", 0x26: "pop", 0x27: "jmp", 0x28: "call", 0x29: "callvirt",
    0x2a: "calli", 0x2b: "ret", 0x2c: "br.s", 0x2d: "brfalse.s",
    0x2e: "brtrue.s", 0x2f: "beq.s", 0x30: "bge.s", 0x31: "bgt.s",
    0x32: "ble.s", 0x33: "blt.s", 0x34: "bne.un.s", 0x35: "bge.un.s",
    0x36: "bgt.un.s", 0x37: "ble.un.s", 0x38: "blt.un.s", 0x39: "br",
    0x3a: "brfalse", 0x3b: "brtrue", 0x3c: "beq", 0x3d: "bge", 0x3e: "bgt",
    0x3f: "ble", 0x40: "blt", 0x41: "bne.un", 0x42: "bge.un", 0x43: "bgt.un",
    0x44: "ble.un", 0x45: "blt.un", 0x46: "switch", 0x58: "add",
    0x59: "sub", 0x5a: "mul", 0x5b: "div", 0x5d: "rem", 0x5e: "and",
    0x5f: "or", 0x60: "xor", 0x61: "shl", 0x62: "shr", 0x63: "shr.un",
    0x64: "neg", 0x65: "not", 0x66: "conv.i1", 0x67: "conv.i2",
    0x68: "conv.i4", 0x69: "conv.i8", 0x6a: "conv.r4", 0x6b: "conv.r8",
    0x6c: "conv.u4", 0x6d: "conv.u8", 0x72: "ldstr", 0x73: "newobj",
    0x74: "castclass", 0x75: "isinst", 0x79: "unbox", 0x7b: "ldfld",
    0x7c: "ldflda", 0x7d: "stfld", 0x7e: "ldsfld", 0x7f: "ldsflda",
    0x80: "stsfld", 0x81: "stobj", 0x82: "conv.r.un", 0x83: "box",
    0x84: "newarr", 0x8c: "box", 0x8d: "ldlen", 0x8e: "ldelema",
    0x8f: "ldelem.i1", 0x90: "ldelem.u1", 0x91: "ldelem.i2", 0x92: "ldelem.u2",
    0x93: "ldelem.i4", 0x94: "ldelem.u4", 0x95: "ldelem.i8", 0x96: "ldelem.i",
    0x97: "ldelem.r4", 0x98: "ldelem.r8", 0x99: "ldelem.ref",
    0x9a: "stelem.i", 0x9b: "stelem.i1", 0x9c: "stelem.i2", 0x9d: "stelem.i4",
    0x9e: "stelem.i8", 0x9f: "stelem.r4", 0xa0: "stelem.r8",
    0xa1: "stelem.ref", 0xa3: "ldelem", 0xa4: "stelem", 0xa5: "unbox.any",
    0xab: "throw", 0xb3: "conv.ovf.i1.un", 0xb4: "conv.ovf.i2",
    0xb6: "conv.ovf.i4", 0xbd: "conv.ovf.i8", 0xbe: "conv.ovf.u1",
    0xc0: "conv.ovf.u2", 0xc2: "conv.ovf.u4", 0xc6: "conv.ovf.u8",
    0xd0: "ldtoken", 0xd3: "conv.u2", 0xfe: "extended",
}


def dump_il_bytes(pe: Pe, code: bytes):
    md = pe.md
    labels = {}
    # first pass: collect branch targets
    i = 0
    while i < len(code):
        op = code[i]
        i += 1
        if op == 0xfe:
            op = 0xfe00 | code[i]
            i += 1
        if op in (0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34,
                  0x35, 0x36, 0x37, 0x38):
            tgt = i + 1 + int.from_bytes(code[i:i + 1], "little", signed=True)
            i += 1
            labels[tgt] = True
        elif op in (0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41,
                    0x42, 0x43, 0x44, 0x45):
            tgt = i + 4 + int.from_bytes(code[i:i + 4], "little", signed=True)
            i += 4
            labels[tgt] = True
        elif op == 0x46:  # switch
            n = int.from_bytes(code[i:i + 4], "little")
            i += 4
            base = i + 4 * n
            for k in range(n):
                labels[base + int.from_bytes(code[i + 4 * k:i + 4 * k + 4], "little", signed=True)] = True
            i += 4 * n
        else:
            i = skip_operand(op, code, i)
    # second pass: print
    i = 0
    while i < len(code):
        if i in labels:
            print(f"      IL_{i:04x}:")
        instr_off = i
        op = code[i]
        raw = code[i]
        i += 1
        name = IL_OP.get(op, "0x%02x" % op)
        extra = ""
        if op == 0xfe:
            sub = code[i]
            i += 1
            name = "ext.%02x" % sub
            # handle common fe sub-opcodes
            if sub == 0x01: name = "ceq"
            elif sub == 0x02: name = "cgt"
            elif sub == 0x03: name = "cgt.un"
            elif sub == 0x04: name = "clt"
            elif sub == 0x05: name = "clt.un"
            elif sub == 0x09: name = "ldftn"
            elif sub == 0x0a: name = "ldvirtftn"
            elif sub == 0x06: name = "ldarg"
            elif sub == 0x0a: name = "ldvirtftn"
        elif op == 0x72:  # ldstr
            toks = int.from_bytes(code[i:i + 4], "little")
            i += 4
            s = pe.pe.net.user_strings.get(toks & 0x00ffffff)
            try:
                extra = f'"{s.value}"'
            except Exception:  # noqa: BLE001
                extra = f"str@{toks:x}"
        elif op in (0x28, 0x29):  # call/callvirt
            tok = int.from_bytes(code[i:i + 4], "little")
            i += 4
            extra = resolve_member(pe, tok)
        elif op in (0x6f,):  # callvirt (0x6f also callvirt)
            tok = int.from_bytes(code[i:i + 4], "little")
            i += 4
            extra = resolve_member(pe, tok)
        elif op in (0x73,):  # newobj
            tok = int.from_bytes(code[i:i + 4], "little")
            i += 4
            extra = resolve_member(pe, tok)
        elif op in (0x7b, 0x7c, 0x7d, 0x7e, 0x7f, 0x80):  # field ops
            tok = int.from_bytes(code[i:i + 4], "little")
            i += 4
            extra = resolve_field(pe, tok)
        elif op == 0x20:  # ldc.i4
            v = int.from_bytes(code[i:i + 4], "little", signed=True)
            i += 4
            extra = f"{v} (0x{v & 0xffffffff:x})"
        elif op == 0x21:  # ldc.i8
            v = int.from_bytes(code[i:i + 8], "little", signed=True)
            i += 8
            extra = f"{v}"
        elif op == 0x1f:  # ldc.i4.s
            v = int.from_bytes(code[i:i + 1], "little", signed=True)
            i += 1
            extra = f"{v}"
        elif op == 0x22:
            import struct
            v = struct.unpack("<f", code[i:i + 4])[0]
            i += 4
            extra = f"{v}"
        elif op == 0x23:
            import struct
            v = struct.unpack("<d", code[i:i + 8])[0]
            i += 8
            extra = f"{v}"
        elif op in (0x0e, 0x11, 0x13, 0x0f, 0x12, 0x10):  # short arg/local
            v = code[i]
            i += 1
            extra = f"{v}"
        elif op == 0xfe:
            pass
        elif op in (0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34,
                    0x35, 0x36, 0x37, 0x38):
            tgt = i + 1 + int.from_bytes(code[i:i + 1], "little", signed=True)
            i += 1
            extra = f"IL_{tgt:04x}"
        elif op in (0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41,
                    0x42, 0x43, 0x44, 0x45):
            tgt = i + 4 + int.from_bytes(code[i:i + 4], "little", signed=True)
            i += 4
            extra = f"IL_{tgt:04x}"
        elif op == 0x46:
            n = int.from_bytes(code[i:i + 4], "little")
            i += 4
            base = i + 4 * n
            t = [f"IL_{base + int.from_bytes(code[i + 4 * k:i + 4 * k + 4], 'little', signed=True):04x}" for k in range(n)]
            i += 4 * n
            extra = ",".join(t)
        else:
            i = skip_operand(op, code, i)
        print(f"      {instr_off:08x}: {name:12s} {extra}")


def skip_operand(op, code, i):
    if op == 0xfe:
        return i + 1
    if op in (0x72, 0x28, 0x29, 0x6f, 0x73, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
              0x80, 0x74, 0x75, 0x79, 0x83, 0x8c, 0xa5, 0xd0, 0x27, 0x2a):
        return i + 4
    if op == 0x20:
        return i + 4
    if op == 0x21:
        return i + 8
    if op in (0x1f, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13):
        return i + 1
    if op == 0x22:
        return i + 4
    if op == 0x23:
        return i + 8
    if op == 0x84:  # newarr
        return i + 4
    if op in (0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35,
              0x36, 0x37, 0x38):
        return i + 1
    if op in (0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42,
              0x43, 0x44, 0x45):
        return i + 4
    return i


def resolve_member(pe: Pe, tok: int):
    table = (tok >> 24) & 0xff
    idx = tok & 0x00ffffff
    try:
        if table == 0x0a:  # MemberRef
            m = pe.member_ref(idx)
            cls = pe.decode_tdor(m.Class)
            return f"{cls}::{m.Name}"
        if table == 0x06:  # MethodDef
            m = pe.method_def(idx)
            return f"MethodDef::{m.Name}"
        if table == 0x2b:  # MethodSpec
            return f"MethodSpec#{idx}"
    except Exception:  # noqa: BLE001
        pass
    return f"member(0x{tok:x})"


def resolve_field(pe: Pe, tok: int):
    table = (tok >> 24) & 0xff
    idx = tok & 0x00ffffff
    try:
        if table == 0x04:  # Field
            f = pe.field(idx)
            return f"Field::{f.Name}"
        if table == 0x0a:  # MemberRef (field)
            m = pe.member_ref(idx)
            cls = pe.decode_tdor(m.Class)
            return f"{cls}::{m.Name}"
    except Exception:  # noqa: BLE001
        pass
    return f"field(0x{tok:x})"


def main():
    path = sys.argv[1]
    cmd = sys.argv[2]
    pe = Pe(path)
    if cmd == "types":
        filt = None
        if "--filter" in sys.argv:
            filt = sys.argv[sys.argv.index("--filter") + 1]
        cmd_types(pe, filt)
    elif cmd == "pinvoke":
        cmd_pinvoke(pe)
    elif cmd == "methods":
        tname = sys.argv[3]
        show_il = "--il" in sys.argv
        only = sys.argv[sys.argv.index("--only") + 1] if "--only" in sys.argv else None
        cmd_methods(pe, tname, show_il, only)
    elif cmd == "il":
        tname = sys.argv[3]
        only = sys.argv[sys.argv.index("--only") + 1] if "--only" in sys.argv else None
        cmd_methods(pe, tname, show_il=True, only=only)
    else:
        print("unknown command", cmd)


if __name__ == "__main__":
    main()
