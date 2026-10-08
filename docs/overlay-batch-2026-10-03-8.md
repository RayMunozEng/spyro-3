# Verified overlay batch 2026-10-03-8

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 52 functions, 2848 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch8.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'HUD divided value and selector callback': 15, 'HUD sprite dimensions and accumulated height': 15, 'component bounds and vector helper': 7, 'HUD target ratio and halfword step': 14, 'particle zero offset and fragment wrapper': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_80084ED0` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_10/level/func_level_10_80084ED0.s` |
| `func_level_12_800858C0` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_12/level/func_level_12_800858C0.s` |
| `func_level_18_800855CC` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_18/level/func_level_18_800855CC.s` |
| `func_level_20_80086058` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_20/level/func_level_20_80086058.s` |
| `func_level_24_8008EFE4` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_24/level/func_level_24_8008EFE4.s` |
| `func_level_28_8008373C` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_28/level/func_level_28_8008373C.s` |
| `func_level_30_80084AC0` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_30/level/func_level_30_80084AC0.s` |
| `func_level_32_80092258` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_32/level/func_level_32_80092258.s` |
| `func_level_33_80095884` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_33/level/func_level_33_80095884.s` |
| `func_level_34_80091148` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_34/level/func_level_34_80091148.s` |
| `func_level_37_8008686C` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_37/level/func_level_37_8008686C.s` |
| `func_level_38_80085090` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_38/level/func_level_38_80085090.s` |
| `func_level_41_8008B5E0` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_41/level/func_level_41_8008B5E0.s` |
| `func_level_48_800849A4` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_48/level/func_level_48_800849A4.s` |
| `func_level_50_80094A44` | HUD divided value and selector callback | 49 | `730d5c42465853e57424dfd4d77526dbfb512e25d58aeaa6eaff6a80a9e3f000` | `asm/nonmatchings/overlays/level_50/level/func_level_50_80094A44.s` |
| `func_level_10_80084B08` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_10/level/func_level_10_80084B08.s` |
| `func_level_12_800854F8` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_12/level/func_level_12_800854F8.s` |
| `func_level_18_80085204` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_18/level/func_level_18_80085204.s` |
| `func_level_20_80085C90` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_20/level/func_level_20_80085C90.s` |
| `func_level_24_8008EC1C` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_24/level/func_level_24_8008EC1C.s` |
| `func_level_28_80083374` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_28/level/func_level_28_80083374.s` |
| `func_level_30_800846F8` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_30/level/func_level_30_800846F8.s` |
| `func_level_32_80091E90` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_32/level/func_level_32_80091E90.s` |
| `func_level_33_800954BC` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_33/level/func_level_33_800954BC.s` |
| `func_level_34_80090D80` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_34/level/func_level_34_80090D80.s` |
| `func_level_37_800864A4` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_37/level/func_level_37_800864A4.s` |
| `func_level_38_80084CC8` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_38/level/func_level_38_80084CC8.s` |
| `func_level_41_8008B218` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_41/level/func_level_41_8008B218.s` |
| `func_level_48_800845DC` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_48/level/func_level_48_800845DC.s` |
| `func_level_50_8009467C` | HUD sprite dimensions and accumulated height | 62 | `6a0d63e1ae6347342883eb98ef58bcccc3105f474e674bb5f4b58eedec62cb7d` | `asm/nonmatchings/overlays/level_50/level/func_level_50_8009467C.s` |
| `func_level_15_800837F8` | component bounds and vector helper | 42 | `7308d36bf9d5ab7dad2b3c733f07751a7698aa2ac8c3fdbc36c7cfcd9a126470` | `asm/nonmatchings/overlays/level_15/level/func_level_15_800837F8.s` |
| `func_level_25_800841B0` | component bounds and vector helper | 42 | `7308d36bf9d5ab7dad2b3c733f07751a7698aa2ac8c3fdbc36c7cfcd9a126470` | `asm/nonmatchings/overlays/level_25/level/func_level_25_800841B0.s` |
| `func_level_32_80091DE8` | component bounds and vector helper | 42 | `7308d36bf9d5ab7dad2b3c733f07751a7698aa2ac8c3fdbc36c7cfcd9a126470` | `asm/nonmatchings/overlays/level_32/level/func_level_32_80091DE8.s` |
| `func_level_35_80085534` | component bounds and vector helper | 42 | `7308d36bf9d5ab7dad2b3c733f07751a7698aa2ac8c3fdbc36c7cfcd9a126470` | `asm/nonmatchings/overlays/level_35/level/func_level_35_80085534.s` |
| `func_level_41_8008B078` | component bounds and vector helper | 42 | `7308d36bf9d5ab7dad2b3c733f07751a7698aa2ac8c3fdbc36c7cfcd9a126470` | `asm/nonmatchings/overlays/level_41/level/func_level_41_8008B078.s` |
| `func_level_45_80083AF0` | component bounds and vector helper | 42 | `7308d36bf9d5ab7dad2b3c733f07751a7698aa2ac8c3fdbc36c7cfcd9a126470` | `asm/nonmatchings/overlays/level_45/level/func_level_45_80083AF0.s` |
| `func_level_50_800945D4` | component bounds and vector helper | 42 | `7308d36bf9d5ab7dad2b3c733f07751a7698aa2ac8c3fdbc36c7cfcd9a126470` | `asm/nonmatchings/overlays/level_50/level/func_level_50_800945D4.s` |
| `func_level_11_80086A90` | HUD target ratio and halfword step | 62 | `fd62d5ad19d8b4ea562be38497fd14765de3a7458af150f9c26047aa5581e9d6` | `asm/nonmatchings/overlays/level_11/level/func_level_11_80086A90.s` |
| `func_level_14_8008EF48` | HUD target ratio and halfword step | 62 | `fd62d5ad19d8b4ea562be38497fd14765de3a7458af150f9c26047aa5581e9d6` | `asm/nonmatchings/overlays/level_14/level/func_level_14_8008EF48.s` |
| `func_level_17_800804E4` | HUD target ratio and halfword step | 62 | `fd62d5ad19d8b4ea562be38497fd14765de3a7458af150f9c26047aa5581e9d6` | `asm/nonmatchings/overlays/level_17/level/func_level_17_800804E4.s` |
| `func_level_18_8008510C` | HUD target ratio and halfword step | 62 | `fd62d5ad19d8b4ea562be38497fd14765de3a7458af150f9c26047aa5581e9d6` | `asm/nonmatchings/overlays/level_18/level/func_level_18_8008510C.s` |
| `func_level_22_80090F60` | HUD target ratio and halfword step | 62 | `fd62d5ad19d8b4ea562be38497fd14765de3a7458af150f9c26047aa5581e9d6` | `asm/nonmatchings/overlays/level_22/level/func_level_22_80090F60.s` |
| `func_level_23_8008DA84` | HUD target ratio and halfword step | 62 | `fd62d5ad19d8b4ea562be38497fd14765de3a7458af150f9c26047aa5581e9d6` | `asm/nonmatchings/overlays/level_23/level/func_level_23_8008DA84.s` |
| `func_level_27_80085CF8` | HUD target ratio and halfword step | 62 | `fd62d5ad19d8b4ea562be38497fd14765de3a7458af150f9c26047aa5581e9d6` | `asm/nonmatchings/overlays/level_27/level/func_level_27_80085CF8.s` |
| `func_level_28_8008327C` | HUD target ratio and halfword step | 62 | `fd62d5ad19d8b4ea562be38497fd14765de3a7458af150f9c26047aa5581e9d6` | `asm/nonmatchings/overlays/level_28/level/func_level_28_8008327C.s` |
| `func_level_31_800896A8` | HUD target ratio and halfword step | 62 | `fd62d5ad19d8b4ea562be38497fd14765de3a7458af150f9c26047aa5581e9d6` | `asm/nonmatchings/overlays/level_31/level/func_level_31_800896A8.s` |
| `func_level_33_800951EC` | HUD target ratio and halfword step | 62 | `fd62d5ad19d8b4ea562be38497fd14765de3a7458af150f9c26047aa5581e9d6` | `asm/nonmatchings/overlays/level_33/level/func_level_33_800951EC.s` |
| `func_level_37_800863AC` | HUD target ratio and halfword step | 62 | `fd62d5ad19d8b4ea562be38497fd14765de3a7458af150f9c26047aa5581e9d6` | `asm/nonmatchings/overlays/level_37/level/func_level_37_800863AC.s` |
| `func_level_38_80084BD0` | HUD target ratio and halfword step | 62 | `fd62d5ad19d8b4ea562be38497fd14765de3a7458af150f9c26047aa5581e9d6` | `asm/nonmatchings/overlays/level_38/level/func_level_38_80084BD0.s` |
| `func_level_47_80088FB4` | HUD target ratio and halfword step | 62 | `fd62d5ad19d8b4ea562be38497fd14765de3a7458af150f9c26047aa5581e9d6` | `asm/nonmatchings/overlays/level_47/level/func_level_47_80088FB4.s` |
| `func_level_48_800844E4` | HUD target ratio and halfword step | 62 | `fd62d5ad19d8b4ea562be38497fd14765de3a7458af150f9c26047aa5581e9d6` | `asm/nonmatchings/overlays/level_48/level/func_level_48_800844E4.s` |
| `func_level_33_8007E0DC` | particle zero offset and fragment wrapper | 21 | `23ebfc31b82bbfe505586888d023aced422071cde38a11aa8c109ebb6bafc1e2` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_8007E0DC.s` |
