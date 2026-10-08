# Verified overlay batch 2026-10-04-415

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 3 functions, 235 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch415.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: reuses upstream CameraPosition, Moby, Spyro and animation layouts. Camera update preserves state 13, target-vector heading, index clamp and four original destination/table addresses. Animation cases are decoded directly from original jump-table entries, including no-op entries, shared dispatch and the state-6 exclusion. Full linked validation includes every original table word and its original padding.

Categories: {'camera-state target and position-table update': 1, 'animation selector table and original helper dispatch': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_36_8008653C` | camera-state target and position-table update | 77 | `40dbb89a87d43c9922413cac3f906237ba145a0c05770ff934c12b81d65a1050` | `asm/nonmatchings/overlays/level_36/camera/func_level_36_8008653C.s` |
| `func_level_20_8008AED4` | animation selector table and original helper dispatch | 80 | `b97ffca3dbba465ca6de573e9015e2e02e7954ac9bf3885557d98b8b9be3a41f` | `asm/nonmatchings/overlays/level_20/animation/func_level_20_8008AED4.s` |
| `func_level_47_8008CD4C` | animation selector table and original helper dispatch | 78 | `249ff9165704c72f93b807c525bb4792f84bd1e243bc51ba001825d67b6b38f3` | `asm/nonmatchings/overlays/level_47/animation/func_level_47_8008CD4C.s` |
