# Verified overlay batch 2026-10-03-13

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 41 functions, 2997 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch13.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'tag selector colour and byte size update': 23, 'cutscene allocation and record initialization': 13, 'substate and tag gated four-record helper loop': 5}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_13_800778B4` | tag selector colour and byte size update | 79 | `d1163aa90bf468831c54e3afd55622a8a72f8cce50bed218cbbc90b615c5b480` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_800778B4.s` |
| `func_level_15_80076B58` | tag selector colour and byte size update | 79 | `da14c06fb704011bce9513b58fee602e48175466d98f11e21d884cd2df578558` | `asm/nonmatchings/overlays/level_15/moby/func_level_15_80076B58.s` |
| `func_level_18_8007728C` | tag selector colour and byte size update | 79 | `42b351f04548be5542860250e256513f059948927f0fd63583206665dd2c1ed2` | `asm/nonmatchings/overlays/level_18/moby/func_level_18_8007728C.s` |
| `func_level_20_800777F8` | tag selector colour and byte size update | 79 | `0fa35802600f67d5c8758b502ec72e1485d47fa73eebaf47ba8eb87dfe12778e` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_800777F8.s` |
| `func_level_21_80077A94` | tag selector colour and byte size update | 79 | `f7166b6b84d15dbbf46cd2ee2ad5608bd69911d13b2d735d6c15574f9cb2f6fa` | `asm/nonmatchings/overlays/level_21/moby/func_level_21_80077A94.s` |
| `func_level_22_80077F84` | tag selector colour and byte size update | 79 | `083730bbcd2ebac809c9adfc6ec3450604a3a34406833f4133d3a6462e92b0f6` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_80077F84.s` |
| `func_level_24_80077F64` | tag selector colour and byte size update | 79 | `1bb53ee1be657984337075365e012f35e075a159a3fbe8fb254e588b70b4f1c0` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_80077F64.s` |
| `func_level_25_80076E8C` | tag selector colour and byte size update | 79 | `cbbc2f8858b8a7b304d4aa450451664ef254c51586c85f769bd6016092b727df` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_80076E8C.s` |
| `func_level_26_80077600` | tag selector colour and byte size update | 79 | `23c939f2b5bfcf645ae7ee198220bc33bc22e88c1b2121c74603c15c0b889c9d` | `asm/nonmatchings/overlays/level_26/moby/func_level_26_80077600.s` |
| `func_level_27_800769C8` | tag selector colour and byte size update | 79 | `319c1b2d982050c2afd9b9a0e4c88e7ab3f9443afc93080c5ccb65cbb4f0d92a` | `asm/nonmatchings/overlays/level_27/moby/func_level_27_800769C8.s` |
| `func_level_28_80077244` | tag selector colour and byte size update | 79 | `4df3d54860c8ca99e1f61ba8da20af82dbc3e5e4bcaaf0a2a716a0918ef64a7b` | `asm/nonmatchings/overlays/level_28/moby/func_level_28_80077244.s` |
| `func_level_32_800784BC` | tag selector colour and byte size update | 79 | `e7ac1d33552d9e46d53fd49e05214607e5fb9e3a8d2c0625b9ebb6960314f1ba` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_800784BC.s` |
| `func_level_33_80078554` | tag selector colour and byte size update | 79 | `85a4519b265cce96e32b3eb32450203a8aa26057c9f67311cd7a622413af66cd` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_80078554.s` |
| `func_level_34_80077E50` | tag selector colour and byte size update | 79 | `738b4e5ac164b078c8786e312ba9bbbd0704c56c923eb92e55747051beec9cf3` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_80077E50.s` |
| `func_level_35_8007708C` | tag selector colour and byte size update | 79 | `3637bdd834f269bed873347c944570d0d684fe34cb8c00dd4f74eeae99e78894` | `asm/nonmatchings/overlays/level_35/moby/func_level_35_8007708C.s` |
| `func_level_37_8007696C` | tag selector colour and byte size update | 79 | `56a28a30c393cb4480fc31ccdc014b1429cbec5e61d5890f2c884cac4aab6cf7` | `asm/nonmatchings/overlays/level_37/moby/func_level_37_8007696C.s` |
| `func_level_38_80077248` | tag selector colour and byte size update | 79 | `ca52474ad20e7538d9dba3dadd60f271c0a913f4d5a1b6f9034acffdac978b99` | `asm/nonmatchings/overlays/level_38/moby/func_level_38_80077248.s` |
| `func_level_42_800777B0` | tag selector colour and byte size update | 79 | `e5099504473e8058fc74abf64e3d3cef409d1b2c6b36b6b22169239af3d73cd9` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_800777B0.s` |
| `func_level_43_80078084` | tag selector colour and byte size update | 79 | `03672e83053b8cf567a6ac5e3fc4118f08fed093ff3abf2ab8e2c3915233739b` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_80078084.s` |
| `func_level_45_80076DD4` | tag selector colour and byte size update | 79 | `ca8f7ad3251198c3848fb411140fe68c831362631f1caa3423ea5f195da973d4` | `asm/nonmatchings/overlays/level_45/moby/func_level_45_80076DD4.s` |
| `func_level_47_80076958` | tag selector colour and byte size update | 79 | `9bc971a5d5302db1940945d8b69c687d120a16e426a51ee365c644d228f6f38c` | `asm/nonmatchings/overlays/level_47/moby/func_level_47_80076958.s` |
| `func_level_48_8007726C` | tag selector colour and byte size update | 79 | `ef05b05ebef955cc33a328b341ee5aec2d6cdd08ed26e5c6d4b25106c0b6f61a` | `asm/nonmatchings/overlays/level_48/moby/func_level_48_8007726C.s` |
| `func_level_50_80077C68` | tag selector colour and byte size update | 79 | `579ce8a06a2966ad72fcab84770c52c135e5347680bff92dd310123e1eb84b99` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_80077C68.s` |
| `func_cutscene_61_80074C0C` | cutscene allocation and record initialization | 70 | `8027958b4fb716757dbf509c7a2728da6fc5244672c7d8f6198d8fb8e6942150` | `asm/nonmatchings/overlays/cutscene_61/moby/func_cutscene_61_80074C0C.s` |
| `func_cutscene_65_80074788` | cutscene allocation and record initialization | 70 | `82af7b49b016855ec6af2e90a1fe148c539f737aaf20f69d02eaead7ee15e3f4` | `asm/nonmatchings/overlays/cutscene_65/moby/func_cutscene_65_80074788.s` |
| `func_cutscene_66_80074788` | cutscene allocation and record initialization | 70 | `82af7b49b016855ec6af2e90a1fe148c539f737aaf20f69d02eaead7ee15e3f4` | `asm/nonmatchings/overlays/cutscene_66/moby/func_cutscene_66_80074788.s` |
| `func_cutscene_68_80074788` | cutscene allocation and record initialization | 70 | `82af7b49b016855ec6af2e90a1fe148c539f737aaf20f69d02eaead7ee15e3f4` | `asm/nonmatchings/overlays/cutscene_68/moby/func_cutscene_68_80074788.s` |
| `func_cutscene_69_800749DC` | cutscene allocation and record initialization | 70 | `264ce3a11af6ceb1dfbf314af1fdbc84e2b884b0136094e671483f863ca05e94` | `asm/nonmatchings/overlays/cutscene_69/moby/func_cutscene_69_800749DC.s` |
| `func_cutscene_70_80074788` | cutscene allocation and record initialization | 70 | `82af7b49b016855ec6af2e90a1fe148c539f737aaf20f69d02eaead7ee15e3f4` | `asm/nonmatchings/overlays/cutscene_70/moby/func_cutscene_70_80074788.s` |
| `func_cutscene_71_800747B4` | cutscene allocation and record initialization | 70 | `8a206afcd500d830ae4e4a71f053a4fa2d2e27ae1c2fbfaf58893f0d9c1caa6a` | `asm/nonmatchings/overlays/cutscene_71/moby/func_cutscene_71_800747B4.s` |
| `func_cutscene_74_80074788` | cutscene allocation and record initialization | 70 | `82af7b49b016855ec6af2e90a1fe148c539f737aaf20f69d02eaead7ee15e3f4` | `asm/nonmatchings/overlays/cutscene_74/moby/func_cutscene_74_80074788.s` |
| `func_cutscene_75_80074870` | cutscene allocation and record initialization | 70 | `be92e55dc05453ff36b75e9523f53d2cee1d3cfe5c92bf7acd4af457596d1941` | `asm/nonmatchings/overlays/cutscene_75/moby/func_cutscene_75_80074870.s` |
| `func_cutscene_76_80074870` | cutscene allocation and record initialization | 70 | `be92e55dc05453ff36b75e9523f53d2cee1d3cfe5c92bf7acd4af457596d1941` | `asm/nonmatchings/overlays/cutscene_76/moby/func_cutscene_76_80074870.s` |
| `func_cutscene_77_80074870` | cutscene allocation and record initialization | 70 | `be92e55dc05453ff36b75e9523f53d2cee1d3cfe5c92bf7acd4af457596d1941` | `asm/nonmatchings/overlays/cutscene_77/moby/func_cutscene_77_80074870.s` |
| `func_cutscene_79_80074788` | cutscene allocation and record initialization | 70 | `82af7b49b016855ec6af2e90a1fe148c539f737aaf20f69d02eaead7ee15e3f4` | `asm/nonmatchings/overlays/cutscene_79/moby/func_cutscene_79_80074788.s` |
| `func_cutscene_80_800747B4` | cutscene allocation and record initialization | 70 | `8a206afcd500d830ae4e4a71f053a4fa2d2e27ae1c2fbfaf58893f0d9c1caa6a` | `asm/nonmatchings/overlays/cutscene_80/moby/func_cutscene_80_800747B4.s` |
| `func_level_13_80081DBC` | substate and tag gated four-record helper loop | 54 | `957fa161f9f331d4653b25ddce2e8c006168859c78a248e057d24eee3e029e5b` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_80081DBC.s` |
| `func_level_30_8007A9EC` | substate and tag gated four-record helper loop | 54 | `957fa161f9f331d4653b25ddce2e8c006168859c78a248e057d24eee3e029e5b` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_8007A9EC.s` |
| `func_level_40_8007B2A0` | substate and tag gated four-record helper loop | 54 | `957fa161f9f331d4653b25ddce2e8c006168859c78a248e057d24eee3e029e5b` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_8007B2A0.s` |
| `func_level_42_8007E3D8` | substate and tag gated four-record helper loop | 54 | `957fa161f9f331d4653b25ddce2e8c006168859c78a248e057d24eee3e029e5b` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_8007E3D8.s` |
| `func_level_45_800791AC` | substate and tag gated four-record helper loop | 54 | `957fa161f9f331d4653b25ddce2e8c006168859c78a248e057d24eee3e029e5b` | `asm/nonmatchings/overlays/level_45/moby/func_level_45_800791AC.s` |
