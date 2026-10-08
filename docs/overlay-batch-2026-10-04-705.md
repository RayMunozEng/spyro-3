# Verified overlay batch 2026-10-04-705

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 102 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch705.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Reuses the verified initializer and class-flag structures for original level 47 modes 13, 14 and 23. Retains actor-class flags for 371 and 659, the original shared reset path, and the saved global settling pointer. Empty register and memory constraints preserve original address preparation and emit no instructions. No new camera semantics are inferred.

Categories: {'three-mode camera initialization': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_47_8008DC60` | three-mode camera initialization | 102 | `3ac5d408fb492e463cc3d3a045bde061d4914dc9604da733190c2c22e1168a1c` | `asm/nonmatchings/overlays/level_47/camera/func_level_47_8008DC60.s` |
