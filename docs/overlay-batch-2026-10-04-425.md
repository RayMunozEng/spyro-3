# Verified overlay batch 2026-10-04-425

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 328 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch425.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: uses upstream Moby, Spyro, model-frame, Vector3D, particle, and helper conventions. Preserves distinct activation/deactivation distances and original animation-byte reset order; an empty memory constraint retains byte-store scheduling. Other handlers preserve numeric selector gates, four original rand-derived particle positions, and the timer/world/point/actor-query chain with exact rollback and deletion branches. Unknown field meanings remain uninterpreted.

Categories: {'distance and player-state animation toggle': 1, 'bounds trigger and selector-state interaction': 1, 'damage gate and four randomized particle positions': 1, 'moving actor timer and collision-query state': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_12_8007F6FC` | distance and player-state animation toggle | 82 | `60fa608ea3534b2ed3254b0bd058ce9a52d76a54a2cb6a1756ab07bd8478d07d` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_8007F6FC.s` |
| `func_level_33_8008FBF8` | bounds trigger and selector-state interaction | 82 | `82ec4c828d9294b9b332d151c668cf96855a9095191f4dbf2d88948812fd6908` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_8008FBF8.s` |
| `func_level_36_80079BC0` | damage gate and four randomized particle positions | 82 | `c1b7045bf792afc9d471de142837a5b69650fa12cc4e3271f6cee74050db5ff8` | `asm/nonmatchings/overlays/level_36/moby/func_level_36_80079BC0.s` |
| `func_level_42_8007F5F8` | moving actor timer and collision-query state | 82 | `bb5aa68e46f4b3a4ecbea156296a1c2e7c733fd61bd75dd95956c005e8d0ac2f` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_8007F5F8.s` |
