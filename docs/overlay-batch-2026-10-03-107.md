# Verified overlay batch 2026-10-03-107

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 8 functions, 518 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch107.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream `Vector3D`, `Angle`, `SHORTMATRIX` and particle/helper declarations, plus original instructions for the listed routines. The loop draws random pitch/yaw, passes the matrix and scalar through the original helpers, copies and adjusts the resulting position, and emits selector-controlled particles. The callback routine compares a masked ten-bit random sample against tag word +0x18, passes two signed offsets in [-127,128] to the original callback, and clears returned particle byte +0x11. Coordinate and matrix fixed-point units remain unresolved; no conversion is added. Empty constraints preserve original loop-index/argument scheduling without emitting instructions. Next evidence target: callback semantics and selector-to-particle payload chain.

Categories: {'word threshold random callback and particle result byte clear': 2, 'original random angle matrix vector and particle loop': 6}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_32_80089F90` | word threshold random callback and particle result byte clear | 43 | `9a24b0c1a78b003e1f8ecd2ede2ed2c8540fad693a77ebde6a202670834f85ee` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_80089F90.s` |
| `func_level_34_8007D058` | word threshold random callback and particle result byte clear | 43 | `9a24b0c1a78b003e1f8ecd2ede2ed2c8540fad693a77ebde6a202670834f85ee` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_8007D058.s` |
| `func_level_15_800841DC` | original random angle matrix vector and particle loop | 72 | `5241270ee4226cf2759d7169187b3e4159f369c273002734a52f18b7cdc324eb` | `asm/nonmatchings/overlays/level_15/level/func_level_15_800841DC.s` |
| `func_level_16_80080C58` | original random angle matrix vector and particle loop | 72 | `5241270ee4226cf2759d7169187b3e4159f369c273002734a52f18b7cdc324eb` | `asm/nonmatchings/overlays/level_16/level/func_level_16_80080C58.s` |
| `func_level_23_8008DB7C` | original random angle matrix vector and particle loop | 72 | `5241270ee4226cf2759d7169187b3e4159f369c273002734a52f18b7cdc324eb` | `asm/nonmatchings/overlays/level_23/level/func_level_23_8008DB7C.s` |
| `func_level_32_80092D60` | original random angle matrix vector and particle loop | 72 | `5241270ee4226cf2759d7169187b3e4159f369c273002734a52f18b7cdc324eb` | `asm/nonmatchings/overlays/level_32/level/func_level_32_80092D60.s` |
| `func_level_37_80086930` | original random angle matrix vector and particle loop | 72 | `5241270ee4226cf2759d7169187b3e4159f369c273002734a52f18b7cdc324eb` | `asm/nonmatchings/overlays/level_37/level/func_level_37_80086930.s` |
| `func_level_50_8009559C` | original random angle matrix vector and particle loop | 72 | `5241270ee4226cf2759d7169187b3e4159f369c273002734a52f18b7cdc324eb` | `asm/nonmatchings/overlays/level_50/level/func_level_50_8009559C.s` |
