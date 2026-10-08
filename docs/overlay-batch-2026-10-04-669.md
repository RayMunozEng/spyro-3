# Verified overlay batch 2026-10-04-669

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 171 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch669.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream Moby fields, camera helpers and path records, with the original level 31 routine defining modes, eight-argument path calls, signed waypoint modulo and completion flags. The false path-update result retains the draw-helper path. An empty count-minus-one constraint preserves the original arithmetic order and emits no instructions.

Categories: {'camera path state and waypoint completion': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_31_8007D610` | camera path state and waypoint completion | 171 | `b0c0692c6f67873baf300649411bc26cc8ef41da0a6b6fc841b3bb6d422d3020` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_8007D610.s` |
