# Verified overlay batch 2026-10-04-598

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 147 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch598.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream Moby and animation layout, plus original level-14 instructions and the 23-entry jump table. All original no-op cases remain explicit. Empty compiler constraints keep the two separately compiled completion gates distinct without emitting instructions. Original animation transitions, linked actor check, halfword adjustments, and three accepted fragment-result values are preserved.

Categories: {'animation state transitions and fragment completion switch': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_14_8008BE8C` | animation state transitions and fragment completion switch | 147 | `6a277876a9f61a4579ab58cdc8c50f7a73ba90871131e7252450bdba6a871ca5` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_8008BE8C.s` |
