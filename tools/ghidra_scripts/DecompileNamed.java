// Decompiles a set of root functions and everything they call up to a
// bounded depth. Outputs one .c file per function into <outdir>.
//
// usage: DecompileNamed.java <outdir> <depth> <root1,root2,...>

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;

public class DecompileNamed extends GhidraScript {

	private static String sanitize(String s) {
		return s.replaceAll("[^A-Za-z0-9_.-]", "_");
	}

	private static void writeFunc(BufferedWriter w, Function f) throws IOException {
		w.write("/* " + f.getEntryPoint() + " " + f.getName() + " " + f.getBody() + " */\n");
	}

	@Override
	public void run() throws Exception {
		if (getScriptArgs().length != 3) {
			throw new IllegalArgumentException(
				"usage: DecompileNamed.java <outdir> <depth> <root1,root2,...>");
		}
		String outdir = getScriptArgs()[0];
		int depth = Integer.parseInt(getScriptArgs()[1]);
		String[] rootNames = getScriptArgs()[2].split(",");

		Map<String, Function> byName = new HashMap<>();
		for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
			byName.put(f.getName(), f);
		}

		List<Function> roots = new ArrayList<>();
		for (String r : rootNames) {
			String name = r.trim();
			Function f = byName.get(name);
			if (f == null) {
				for (Map.Entry<String, Function> e : byName.entrySet()) {
					if (e.getKey().endsWith(name)) {
						f = e.getValue();
						break;
					}
				}
			}
			if (f == null) {
				println("MISSING ROOT: " + name);
				continue;
			}
			roots.add(f);
		}

		LinkedHashSet<Function> seen = new LinkedHashSet<>();
		Deque<Function> queue = new ArrayDeque<>();
		Deque<Integer> depths = new ArrayDeque<>();
		for (Function r : roots) {
			queue.add(r);
			depths.add(0);
		}
		while (!queue.isEmpty()) {
			Function f = queue.poll();
			int d = depths.poll();
			if (!seen.add(f)) {
				continue;
			}
			if (d >= depth) {
				continue;
			}
			for (Function callee : f.getCalledFunctions(monitor)) {
				if (!seen.contains(callee)) {
					queue.add(callee);
					depths.add(d + 1);
				}
			}
		}

		File dir = new File(outdir);
		if (!dir.isDirectory() && !dir.mkdirs()) {
			throw new IOException("could not create " + dir);
		}

		DecompInterface dec = new DecompInterface();
		dec.setSimplificationStyle("decompile");
		if (!dec.openProgram(currentProgram)) {
			throw new IOException("could not open decompiler");
		}

		int n = 0;
		for (Function f : seen) {
			File out = new File(dir, sanitize(f.getName()) + ".c");
			try (BufferedWriter w = new BufferedWriter(new FileWriter(out))) {
				writeFunc(w, f);
				DecompileResults res = dec.decompileFunction(f, 60, monitor);
				if (res.decompileCompleted() && res.getDecompiledFunction() != null) {
					w.write(res.getDecompiledFunction().getC()
						.replaceAll("(?m)[ \\t]+$", "")
						.replaceAll("\\s+\\z", ""));
				} else {
					w.write("/* decompilation failed: " + res.getErrorMessage() + " */");
				}
				w.write("\n");
			}
			n++;
		}
		dec.dispose();
		println("Wrote " + n + " functions for " + currentProgram.getName() + " to " + outdir);
	}
}
