# Verified overlay batch 2026-10-04-364

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 460 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch364.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: four actor damage/delay state routines using the original instruction chain, the existing Moby and EnemyTag layouts, and a partial tag with the original timer and count offsets. Preserves the class 0x2E branch, halfword updates, numeric actor spawn callback, collision field clearing, states 0/1/2/3 and every original helper call/argument. The original countdown and retry branches are retained; labels do not establish independent helper or runtime semantics. No empty constraints or embedded instructions are needed.

Categories: {'enemy damage and delay state dispatch': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_12_80079794` | enemy damage and delay state dispatch | 115 | `eedeaa3bcb046781a74ba520813ad9736fb4b4e20d3ef296b39736dd87622b15` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_80079794.s` |
| `func_level_16_800793F8` | enemy damage and delay state dispatch | 115 | `870e75ca66578291c145b3138a3e3df9478e0771a7bc536b7dc31319251e491f` | `asm/nonmatchings/overlays/level_16/moby/func_level_16_800793F8.s` |
| `func_level_21_8007A554` | enemy damage and delay state dispatch | 115 | `ddcfc161652b3bd856e2270bd1f66c409d2b62563fb94e985ba64ca5f3b342f8` | `asm/nonmatchings/overlays/level_21/moby/func_level_21_8007A554.s` |
| `func_level_32_8007D57C` | enemy damage and delay state dispatch | 115 | `35eb62ab61e8b06989d507c8cd18ae082e6746d8afdc706a2823594b55156a6e` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_8007D57C.s` |
