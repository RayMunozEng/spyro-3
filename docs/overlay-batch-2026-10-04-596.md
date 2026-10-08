# Verified overlay batch 2026-10-04-596

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 145 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch596.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream Moby, vector, and sound interfaces, plus original level-26 instructions. The routine preserves gravity subtraction, movement before bounds checks, ordered world/player/actor queries, heading writes, and both original fragment calls. Separate actor and fragment result variables allow the original register lifetimes without compiler constraints. No gameplay constants or behavior were inferred.

Categories: {'falling impact velocity collision and two fragment calls': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_26_8007E920` | falling impact velocity collision and two fragment calls | 145 | `1e78d34c0948330cf3a257f6f9d1e54bc4ff2cf1cf67fa380164814ba4a5df06` | `asm/nonmatchings/overlays/level_26/moby/func_level_26_8007E920.s` |
