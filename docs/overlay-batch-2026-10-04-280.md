# Verified overlay batch 2026-10-04-280

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 17 functions, 3706 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch280.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- Seventeen identical routines preserve linked-actor spawning and fields, the drawn/timer gates, particle allocation, signed trigonometric table conversion, damage cleanup and all original spawn counts.
- Random-position updates reuse the previously verified repeated-spawn body. Table reads retain unsigned halfword loads followed by signed conversion and shift; empty constraints preserve their exact load and store order.
- Collection indexing retains the original actor-pointer difference, signed packed index and level/bit selection. The particle allocation alias records the pointer-returning call-site ABI without assigning a semantic particle type.
- Every linked instruction and all complete overlay hashes match. Existing numeric particle selectors and helper names remain semantically unreviewed.

Categories: {'attached actor, particle timer and damage gated spawns': 17}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_800794B8` | attached actor, particle timer and damage gated spawns | 218 | `5eeb6f5469d98b379337d1ef8fb57663d63e1b8816423bc2019e9f896cd9771d` | `asm/nonmatchings/overlays/level_10/moby/func_level_10_800794B8.s` |
| `func_level_11_8007951C` | attached actor, particle timer and damage gated spawns | 218 | `010310490f6ce10e19be043befe8f5d09ce9ab0a51bb3a713592b47075cc4856` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_8007951C.s` |
| `func_level_12_8007922C` | attached actor, particle timer and damage gated spawns | 218 | `53d6b15338fa46f37f4fe86129ea97af32e36a607395c3076ec98499fc05296a` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_8007922C.s` |
| `func_level_14_80079A94` | attached actor, particle timer and damage gated spawns | 218 | `cfca554ea19109b4b4869d21c55cf7b99be8469e11a45c4ac4273d4eea269e12` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_80079A94.s` |
| `func_level_16_80078D74` | attached actor, particle timer and damage gated spawns | 218 | `66d538b5c821dd6256df7f9054db2600c5a7482037ce05a22148d04b80ac5c37` | `asm/nonmatchings/overlays/level_16/moby/func_level_16_80078D74.s` |
| `func_level_21_80079CA8` | attached actor, particle timer and damage gated spawns | 218 | `3cc015d38c8c9e38bfd02c038065e75633040f2cd5c1a5d2ca5339bf4c18068e` | `asm/nonmatchings/overlays/level_21/moby/func_level_21_80079CA8.s` |
| `func_level_22_8007A81C` | attached actor, particle timer and damage gated spawns | 218 | `49f9bf8588868207e7bea2d0861ba79ce6ea9e1c5195ce2e97d3f57e9a9608b8` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_8007A81C.s` |
| `func_level_24_8007B2E0` | attached actor, particle timer and damage gated spawns | 218 | `07c0171437fdefc954ea576df9071077376711d28f0a5e8371456a273cacd4e0` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8007B2E0.s` |
| `func_level_26_80079848` | attached actor, particle timer and damage gated spawns | 218 | `0c20c9930476d953e8a2e5eea3e63e2b7871165bf075787d8129cf4ea23e7a00` | `asm/nonmatchings/overlays/level_26/moby/func_level_26_80079848.s` |
| `func_level_30_80079738` | attached actor, particle timer and damage gated spawns | 218 | `222d9d2bc8b8232fd86aebb6bf8b37fb27456c73f8971e148688b5fe2d204eb0` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_80079738.s` |
| `func_level_32_8007A400` | attached actor, particle timer and damage gated spawns | 218 | `75550e13437afe2e2fb04e44666637b4898c6affb1205e001dd29f0f6c5d4da6` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_8007A400.s` |
| `func_level_33_8007AF98` | attached actor, particle timer and damage gated spawns | 218 | `cd047b5a61e7afdb8c79753749af2b4453610c6f4c753814eb6cfa2b6abcc8e5` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_8007AF98.s` |
| `func_level_34_8007BFC4` | attached actor, particle timer and damage gated spawns | 218 | `90cd202f833c435121268a8ea8b1ad53db5dbbe677c75c56509e311d4ec073fa` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_8007BFC4.s` |
| `func_level_40_80078F50` | attached actor, particle timer and damage gated spawns | 218 | `608e0336d6fd452cf088373da7844748846de09fdb705a1b2aa41e1d4a3d78e9` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_80078F50.s` |
| `func_level_42_8007A5DC` | attached actor, particle timer and damage gated spawns | 218 | `1b0f89728e53d9ba509d4f114b995ac25155466d7687e5b17dd4ff751a28636f` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_8007A5DC.s` |
| `func_level_43_80079C48` | attached actor, particle timer and damage gated spawns | 218 | `764747c0f9d56edcd32808f9d45fe678003605a7b631fa7e529711e81dbfbb33` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_80079C48.s` |
| `func_level_44_80079BEC` | attached actor, particle timer and damage gated spawns | 218 | `1673f70e26cfbf79dacfc3e109e6f54b843cc3b77415578a5ff16d4a15321dd7` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_80079BEC.s` |
