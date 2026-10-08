# Verified overlay batch 2026-10-03-201

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 3 functions, 155 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch201.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The level 12 damage routine reuses the verified saved-state baseline, then updates the indexed actor substate and current actor state/animation. The atlas transfer uses the existing RECT and GPU API baseline, masks page to one bit, selects a buffer with stride 0xB800 and header offset 0x1C, uploads the original palette/image rectangles and preserves all three synchronization calls. The level 31 transition preserves deletion of its stored actor, the seven original selector/constant arguments, and conditional updates of bytes 0x41, 0x47 and 0x48 before its helper call. Empty constraints preserve register selection and field-load order; they emit no instructions. Original numeric values and source addresses are the authority; unknown tag and byte meanings are not invented.

Categories: {'damage-gated saved word and linked actor transition': 1, 'atlas two-rectangle image transfer': 1, 'actor deletion and conditional stored-state transition': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_12_80079960` | damage-gated saved word and linked actor transition | 52 | `5ebd25e4ddfe078163c5ca3ff97bb5715d7a5ab7203da9e882b1ca3cd493c837` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_80079960.s` |
| `func_atlas_80075CA8` | atlas two-rectangle image transfer | 52 | `f1f110ea4b47231561171dd0637e7e2dde4a695e2c9c78e4335af055f97a97d3` | `asm/nonmatchings/overlays/atlas/atlas1/func_atlas_80075CA8.s` |
| `func_level_31_8008866C` | actor deletion and conditional stored-state transition | 51 | `2f7597f9eb8f42984afe76c47f7204971eb04b5f92ebd82b7a5129c2b3041fbf` | `asm/nonmatchings/overlays/level_31/level/func_level_31_8008866C.s` |
