# Verified overlay batch 2026-10-03-2

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 77 functions, 1435 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch2.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'fragment wrapper': 39, 'critter pointer and draw flags': 21, 'position and pointer setup': 17}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_14_80083F7C` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_80083F7C.s` |
| `func_level_15_8007AC80` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_15/moby/func_level_15_8007AC80.s` |
| `func_level_20_80083EAC` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_80083EAC.s` |
| `func_level_21_8008527C` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_21/moby/func_level_21_8008527C.s` |
| `func_level_23_8007D7B8` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_8007D7B8.s` |
| `func_level_24_8007B7D4` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8007B7D4.s` |
| `func_level_24_80086980` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_80086980.s` |
| `func_level_25_8007A654` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_8007A654.s` |
| `func_level_25_8007F584` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_8007F584.s` |
| `func_level_26_80082EFC` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_26/moby/func_level_26_80082EFC.s` |
| `func_level_26_80083CA8` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_26/moby/func_level_26_80083CA8.s` |
| `func_level_27_8008035C` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_27/moby/func_level_27_8008035C.s` |
| `func_level_28_800794BC` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_28/moby/func_level_28_800794BC.s` |
| `func_level_30_80082218` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_80082218.s` |
| `func_level_31_80083C24` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_80083C24.s` |
| `func_level_32_80084024` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_80084024.s` |
| `func_level_32_8008E73C` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_8008E73C.s` |
| `func_level_33_8007F2D4` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_8007F2D4.s` |
| `func_level_34_80080164` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_80080164.s` |
| `func_level_35_80079408` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_35/moby/func_level_35_80079408.s` |
| `func_level_35_8007E4A0` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_35/moby/func_level_35_8007E4A0.s` |
| `func_level_36_8007F30C` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_36/moby/func_level_36_8007F30C.s` |
| `func_level_37_8007889C` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_37/moby/func_level_37_8007889C.s` |
| `func_level_37_80083FA8` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_37/moby/func_level_37_80083FA8.s` |
| `func_level_38_800794C0` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_38/moby/func_level_38_800794C0.s` |
| `func_level_40_80082260` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_80082260.s` |
| `func_level_41_8007EC44` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_8007EC44.s` |
| `func_level_42_8007B864` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_8007B864.s` |
| `func_level_42_80083100` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_80083100.s` |
| `func_level_43_8007C4C0` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_8007C4C0.s` |
| `func_level_44_8007CC34` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_8007CC34.s` |
| `func_level_45_80079578` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_45/moby/func_level_45_80079578.s` |
| `func_level_45_8007DD9C` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_45/moby/func_level_45_8007DD9C.s` |
| `func_level_46_8007C074` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_46/moby/func_level_46_8007C074.s` |
| `func_level_46_80082FC0` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_46/moby/func_level_46_80082FC0.s` |
| `func_level_47_800798A4` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_47/moby/func_level_47_800798A4.s` |
| `func_level_48_800794E4` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_48/moby/func_level_48_800794E4.s` |
| `func_level_50_800804A4` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_800804A4.s` |
| `func_level_50_800896C4` | fragment wrapper | 8 | `bb4988fee6b21805cf647789b645186c4da3b9b6f4cfd76b08d0c6bca3d627d8` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_800896C4.s` |
| `func_level_15_8007F858` | critter pointer and draw flags | 30 | `73fc06deab5d90a4919adc5ab4b4330b49cd3ff0769257086e04bb528882dcc5` | `asm/nonmatchings/overlays/level_15/level/func_level_15_8007F858.s` |
| `func_level_16_8007FBC8` | critter pointer and draw flags | 30 | `28bb7fc0a9073c3e2e7c3df90592ec40856fea7c21da85e064a7b4cb3e6ce582` | `asm/nonmatchings/overlays/level_16/level/func_level_16_8007FBC8.s` |
| `func_level_18_80083DE8` | critter pointer and draw flags | 30 | `dfcf9da3dc779e928422687675722ebaa3f0cc598a4852eaffe21ac550c4e7c7` | `asm/nonmatchings/overlays/level_18/level/func_level_18_80083DE8.s` |
| `func_level_22_8008FC3C` | critter pointer and draw flags | 30 | `6f65e8f18970b6902838b14ac5e322a30233a75da1c936d521b3bbb50c60389b` | `asm/nonmatchings/overlays/level_22/level/func_level_22_8008FC3C.s` |
| `func_level_23_8008C7FC` | critter pointer and draw flags | 30 | `581eded288bc3ebe7847c6d596bf31267b54794f3a44d4aea50d4b3d8717cb90` | `asm/nonmatchings/overlays/level_23/level/func_level_23_8008C7FC.s` |
| `func_level_24_8008D960` | critter pointer and draw flags | 30 | `1edd53478fa2e4f5157626e2f116960b889f779bb428419c4d873b1e244a4950` | `asm/nonmatchings/overlays/level_24/level/func_level_24_8008D960.s` |
| `func_level_26_800857D8` | critter pointer and draw flags | 30 | `d99cf9dc6e6e5d43fa90c4b092d96ffa3c3520aa427259ee2809808129bcbf7a` | `asm/nonmatchings/overlays/level_26/level/func_level_26_800857D8.s` |
| `func_level_28_80081F58` | critter pointer and draw flags | 30 | `85ced07c98cd02054a829f1e9dd11628c83a7adf533a8f0aec97ceb8a81f6c86` | `asm/nonmatchings/overlays/level_28/level/func_level_28_80081F58.s` |
| `func_level_31_800877FC` | critter pointer and draw flags | 30 | `c0db545af5d28271d33376028b68932742647b066173266f7ceb651113575cd0` | `asm/nonmatchings/overlays/level_31/level/func_level_31_800877FC.s` |
| `func_level_32_800901F4` | critter pointer and draw flags | 30 | `5ec984ce1a05e67abcb0c019bd12a8887668955d76d5be3f02d679a0bcc85199` | `asm/nonmatchings/overlays/level_32/level/func_level_32_800901F4.s` |
| `func_level_33_800937E4` | critter pointer and draw flags | 30 | `df7ac1069d4f29153eb6decdfcc90099694bfec2da458c25066ecc0cc81bdfa1` | `asm/nonmatchings/overlays/level_33/level/func_level_33_800937E4.s` |
| `func_level_34_8008FDE8` | critter pointer and draw flags | 30 | `4a37250adc5049f2daccd04bbfb645153a1961b65bb9a5e7065e16c743008ad9` | `asm/nonmatchings/overlays/level_34/level/func_level_34_8008FDE8.s` |
| `func_level_35_800813E0` | critter pointer and draw flags | 30 | `b71db8aeb26973f3a0b93dcffc73ca01cb8c50f1a8e05594c36671cd5ce78903` | `asm/nonmatchings/overlays/level_35/level/func_level_35_800813E0.s` |
| `func_level_36_80080280` | critter pointer and draw flags | 30 | `03f88ca539a0976fb7c44693f9b9006137f4886f283f17c9a83af2132aa0bf9f` | `asm/nonmatchings/overlays/level_36/level/func_level_36_80080280.s` |
| `func_level_38_800839BC` | critter pointer and draw flags | 30 | `d644cefce27c7334bf5b19f3e4831d61c8492bffbf629487dd43c5dc55f6272c` | `asm/nonmatchings/overlays/level_38/level/func_level_38_800839BC.s` |
| `func_level_41_80089880` | critter pointer and draw flags | 30 | `d8fb2ff4937153b7a0013282a4c179f22d7eaa7c9d23baca0f43a658bd957b87` | `asm/nonmatchings/overlays/level_41/level/func_level_41_80089880.s` |
| `func_level_44_800891E0` | critter pointer and draw flags | 30 | `7c2c9d4291cdf04fcbb5b583a1c3797ab8d7a5697ff6cf6d09e6a25b89b3a6af` | `asm/nonmatchings/overlays/level_44/level/func_level_44_800891E0.s` |
| `func_level_45_8007F99C` | critter pointer and draw flags | 30 | `4ef96bbae467055dcd486e2f6ef3480ed60862859ac46642ecdf1e3d774705b6` | `asm/nonmatchings/overlays/level_45/level/func_level_45_8007F99C.s` |
| `func_level_46_80089A80` | critter pointer and draw flags | 30 | `03a08c8e4d6cad64140859b3bc6308508b3cf3111ff14204681ab0253642728b` | `asm/nonmatchings/overlays/level_46/level/func_level_46_80089A80.s` |
| `func_level_48_800831C0` | critter pointer and draw flags | 30 | `55c1d75d38bb564858499e81537058d6349124da73ecbfb8eb4b45b5d7c53c0e` | `asm/nonmatchings/overlays/level_48/level/func_level_48_800831C0.s` |
| `func_level_50_8009295C` | critter pointer and draw flags | 30 | `8a818fbd6f8c20b61c0a85e2ef9d60f35667ac286ed569f34cf5c955960886ff` | `asm/nonmatchings/overlays/level_50/level/func_level_50_8009295C.s` |
| `func_level_10_80084350` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_10/level/func_level_10_80084350.s` |
| `func_level_11_80085CB0` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_11/level/func_level_11_80085CB0.s` |
| `func_level_13_80085750` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_13/level/func_level_13_80085750.s` |
| `func_level_14_8008E1BC` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_14/level/func_level_14_8008E1BC.s` |
| `func_level_17_8007F704` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_17/level/func_level_17_8007F704.s` |
| `func_level_20_800854D8` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_20/level/func_level_20_800854D8.s` |
| `func_level_23_8008CCF8` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_23/level/func_level_23_8008CCF8.s` |
| `func_level_24_8008DF6C` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_24/level/func_level_24_8008DF6C.s` |
| `func_level_27_80084F18` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_27/level/func_level_27_80084F18.s` |
| `func_level_30_80083BE8` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_30/level/func_level_30_80083BE8.s` |
| `func_level_31_80087CF8` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_31/level/func_level_31_80087CF8.s` |
| `func_level_34_800903F4` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_34/level/func_level_34_800903F4.s` |
| `func_level_37_800855CC` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_37/level/func_level_37_800855CC.s` |
| `func_level_40_80083048` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_40/level/func_level_40_80083048.s` |
| `func_level_41_80089E8C` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_41/level/func_level_41_80089E8C.s` |
| `func_level_44_80089E88` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_44/level/func_level_44_80089E88.s` |
| `func_level_50_80093148` | position and pointer setup | 29 | `8d589851e4a7d5789e60003705a61b8941ac0c3a48a2e6e9cb32be6bf4e435f4` | `asm/nonmatchings/overlays/level_50/level/func_level_50_80093148.s` |
