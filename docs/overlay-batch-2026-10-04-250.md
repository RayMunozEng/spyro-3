# Verified overlay batch 2026-10-04-250

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 322 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch250.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- Two identical random particle routines preserve the three signed halfword initializers, three temporary vector components, optional returned-particle byte write, and damage-helper gated second particle call.
- Two identical vector-transform routines preserve the animation selector, distance and Z comparisons, yaw access as an unsigned halfword followed by signed conversion, rotation helper, timer and player-state writes. Empty constraints preserve the original player-Z and yaw load order without emitting instructions.
- Particle selectors, constants and player fields retain their original numeric values and widths. No broader semantic mapping is established.

Categories: {'random halfword setup and gated particle updates': 2, 'gated vector transformation and player-state writes': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_14_8007DE24` | random halfword setup and gated particle updates | 79 | `b7cdd31ab0c25839c24121ed1ff7fa2a35fbcd5e628f3d724ce03133f7cc2448` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_8007DE24.s` |
| `func_level_46_80081D8C` | random halfword setup and gated particle updates | 79 | `2f6b8a2d1b4a83d3e99f229587c0246949278f7e0fe6d9ee7b1af2ee3d1c58d5` | `asm/nonmatchings/overlays/level_46/moby/func_level_46_80081D8C.s` |
| `func_level_23_8008AD4C` | gated vector transformation and player-state writes | 82 | `a0fc4fbf6221985ca6a08042736d083aea616cbfc28fbb310df0b90da3aef6a3` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_8008AD4C.s` |
| `func_level_34_8008EB98` | gated vector transformation and player-state writes | 82 | `a0fc4fbf6221985ca6a08042736d083aea616cbfc28fbb310df0b90da3aef6a3` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_8008EB98.s` |
