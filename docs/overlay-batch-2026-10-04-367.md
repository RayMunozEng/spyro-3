# Verified overlay batch 2026-10-04-367

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 41 functions, 7851 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch367.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: 37 copies of a radius/heading helper and four linked draw-distance/paired-spawn routines. Uses the existing Moby, Vector3D and numeric helper interfaces; no new instruction assembly. The movement helper preserves all 13 arguments, absolute-value/distance gates, both optional angle checks, +/-3 table index adjustment, signed halfword table products shifted by 12, the delta==3/4 speed branches, flags bit 8 and every movement-helper argument/return branch. Empty constraints preserve the original allocation and load scheduling; the repository ABS macro preserves the final retail return sequence. The four actor routines retain referenced draw-distance copying, both distinct class 0x17F spawn paths and point/vector helper chains, substate gates and exact globals/constants. Runtime helper meanings and coordinate units beyond the original arithmetic remain unverified.

Categories: {'radius heading and movement helper dispatch': 37, 'linked draw-distance gate and paired actor spawn': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_80084034` | radius heading and movement helper dispatch | 199 | `0fbf4130932932df87dd156d1bf2487d9e16e3e3ab2097a8861ecc121e3b9f74` | `asm/nonmatchings/overlays/level_10/level/func_level_10_80084034.s` |
| `func_level_11_80085498` | radius heading and movement helper dispatch | 199 | `cf9c1bf131fd10ae52c324a3fa3acf4c00a6b729e2966b5f26f3c6460e37627d` | `asm/nonmatchings/overlays/level_11/level/func_level_11_80085498.s` |
| `func_level_12_80084AEC` | radius heading and movement helper dispatch | 199 | `2b08ad8d77bdf880c504084d3a514db78e867484bb0e26394b2bffc7c9954fdb` | `asm/nonmatchings/overlays/level_12/level/func_level_12_80084AEC.s` |
| `func_level_13_80084E28` | radius heading and movement helper dispatch | 199 | `1561622a215355b2ee9801c9d96faea822056590d1d7f2d63462ab86af363680` | `asm/nonmatchings/overlays/level_13/level/func_level_13_80084E28.s` |
| `func_level_14_8008D9A4` | radius heading and movement helper dispatch | 199 | `54ed19fa4236a827381da2768139e5bb56a3b29ee44e815c265f4aaee68d6955` | `asm/nonmatchings/overlays/level_14/level/func_level_14_8008D9A4.s` |
| `func_level_15_8007F53C` | radius heading and movement helper dispatch | 199 | `37f0e3ae138f2d1d8748afd8bdfc6583a946039ff97365e45f338dcae3074936` | `asm/nonmatchings/overlays/level_15/level/func_level_15_8007F53C.s` |
| `func_level_16_8007F8AC` | radius heading and movement helper dispatch | 199 | `6a7287fd93c9c6813dfa98a689cb05909321f128c9efc83ead2dcca01b763864` | `asm/nonmatchings/overlays/level_16/level/func_level_16_8007F8AC.s` |
| `func_level_17_8007F3E8` | radius heading and movement helper dispatch | 199 | `ae972cff75fcb118ccb7acd704d8ea7a7c68fb1b884f1e66ae1aa80d8430ae16` | `asm/nonmatchings/overlays/level_17/level/func_level_17_8007F3E8.s` |
| `func_level_18_80083ACC` | radius heading and movement helper dispatch | 199 | `a01e48dc59717832346edfc1d5413ed232e97242d05bb01bc221a8168b6b931a` | `asm/nonmatchings/overlays/level_18/level/func_level_18_80083ACC.s` |
| `func_level_20_800851BC` | radius heading and movement helper dispatch | 199 | `bfcee5a85136001710cbc751dbdd2c7fdc7ddb82905eeca3b4d06d136364dc68` | `asm/nonmatchings/overlays/level_20/level/func_level_20_800851BC.s` |
| `func_level_21_8008630C` | radius heading and movement helper dispatch | 199 | `c6d9840061064c4253f1bd8205d9507e064560d8f075b9362e02d602e0ebefdf` | `asm/nonmatchings/overlays/level_21/level/func_level_21_8008630C.s` |
| `func_level_22_8008F920` | radius heading and movement helper dispatch | 199 | `68ffb9c3c50732a1bdb73b9f57a5f4a5155e88c26c4c7431e1e2fb9bf523a000` | `asm/nonmatchings/overlays/level_22/level/func_level_22_8008F920.s` |
| `func_level_23_8008C4E0` | radius heading and movement helper dispatch | 199 | `1c51cdd5a30d32f96695d69fbc8e3af94c67133f5dd98e99c49b1d059530ed2b` | `asm/nonmatchings/overlays/level_23/level/func_level_23_8008C4E0.s` |
| `func_level_24_8008D644` | radius heading and movement helper dispatch | 199 | `a8194bdaa9eec856a1254b15b4d4ef2931552331bdecdc47173dd47fe5cf7557` | `asm/nonmatchings/overlays/level_24/level/func_level_24_8008D644.s` |
| `func_level_25_8008023C` | radius heading and movement helper dispatch | 199 | `95aa73fc0d7593685cc1a63fc49254f0c8e3f8c1f5c36bf1136c78cbb6c3936e` | `asm/nonmatchings/overlays/level_25/level/func_level_25_8008023C.s` |
| `func_level_26_800854BC` | radius heading and movement helper dispatch | 199 | `737e606cbbe9adc910fdbb9a1e83c2a269d3b2adec3441b746695dd5030f4939` | `asm/nonmatchings/overlays/level_26/level/func_level_26_800854BC.s` |
| `func_level_27_80084BFC` | radius heading and movement helper dispatch | 199 | `fcf9e5b10875fbfe9b1dbed8aea95cabf55e0f682f3aca4c261828b3be2bfe9d` | `asm/nonmatchings/overlays/level_27/level/func_level_27_80084BFC.s` |
| `func_level_28_80081C3C` | radius heading and movement helper dispatch | 199 | `097dd5bf444bc7ee5d320a85ab1525998e3a57403dc8936449f6783dead0a6f4` | `asm/nonmatchings/overlays/level_28/level/func_level_28_80081C3C.s` |
| `func_level_30_800837BC` | radius heading and movement helper dispatch | 199 | `96bf8111be9793f3ea6e811dcc7ba46070a2f92856306aceef50fd7ee47a921c` | `asm/nonmatchings/overlays/level_30/level/func_level_30_800837BC.s` |
| `func_level_32_8008FED8` | radius heading and movement helper dispatch | 199 | `cfb996601f142dea860cbf52d344183d020e6a3bf1053e705f3b59114ee0d5b4` | `asm/nonmatchings/overlays/level_32/level/func_level_32_8008FED8.s` |
| `func_level_33_800934C8` | radius heading and movement helper dispatch | 199 | `dd9e6b82fd4f30338b28ff445eb91321ee41c395001f89d264080a96c13eb63c` | `asm/nonmatchings/overlays/level_33/level/func_level_33_800934C8.s` |
| `func_level_34_8008FACC` | radius heading and movement helper dispatch | 199 | `0974c2998cd32fb9d8c6dac9ac67496f0959c3ec481ab0fa1cc419c758590b11` | `asm/nonmatchings/overlays/level_34/level/func_level_34_8008FACC.s` |
| `func_level_35_800810C4` | radius heading and movement helper dispatch | 199 | `4904bb2c8d9d766687f1aac1610c56ed1278cfb9327a87c1a43438eecb4683c0` | `asm/nonmatchings/overlays/level_35/level/func_level_35_800810C4.s` |
| `func_level_36_8007FF64` | radius heading and movement helper dispatch | 199 | `9da9ff6ae03e308768ef3ae7525f2c6134b0604ddea4cedbf107ed9f18fca1d8` | `asm/nonmatchings/overlays/level_36/level/func_level_36_8007FF64.s` |
| `func_level_37_800852B0` | radius heading and movement helper dispatch | 199 | `2e3806cc7e7f0cac5aba037151b72b064c9d42c2e6f8ac7221ae412a22ca9484` | `asm/nonmatchings/overlays/level_37/level/func_level_37_800852B0.s` |
| `func_level_38_800836A0` | radius heading and movement helper dispatch | 199 | `4aff71db2036cb90679901bee275370bde97eafeb6351fc41c6bc58049687786` | `asm/nonmatchings/overlays/level_38/level/func_level_38_800836A0.s` |
| `func_level_40_80082D2C` | radius heading and movement helper dispatch | 199 | `f96e94b239a72aaf0eabad2a1de1c95915b2f213548c0cc81aa08345444fbe19` | `asm/nonmatchings/overlays/level_40/level/func_level_40_80082D2C.s` |
| `func_level_41_80089564` | radius heading and movement helper dispatch | 199 | `8ab7d25719e9e9b812d2df29607cd805d75e1511ab4dba25e16dc42ac8d7ffdf` | `asm/nonmatchings/overlays/level_41/level/func_level_41_80089564.s` |
| `func_level_42_80084AB8` | radius heading and movement helper dispatch | 199 | `74cc663e48aa61aba31d16a7b513d450a911dc0626c617097758259e7c81a1e8` | `asm/nonmatchings/overlays/level_42/level/func_level_42_80084AB8.s` |
| `func_level_43_8008B598` | radius heading and movement helper dispatch | 199 | `e5b31f762cf8b46bab40b44e12211da95e56e8084d678249f21f7d2fb3d61ae6` | `asm/nonmatchings/overlays/level_43/level/func_level_43_8008B598.s` |
| `func_level_44_80088EC4` | radius heading and movement helper dispatch | 199 | `911824e728d89d321ced588fa011aee2d89241fcc5f10c9c849d5124805ff417` | `asm/nonmatchings/overlays/level_44/level/func_level_44_80088EC4.s` |
| `func_level_45_8007F680` | radius heading and movement helper dispatch | 199 | `40063f6e577be6cc1bf9d878dce4d54eb376d6d95d21ac185d153c4cabf19c36` | `asm/nonmatchings/overlays/level_45/level/func_level_45_8007F680.s` |
| `func_level_46_80089764` | radius heading and movement helper dispatch | 199 | `bcdec31980856beedfe3eaef7a700147a51252b10e1d793682bc576f45d3eb7b` | `asm/nonmatchings/overlays/level_46/level/func_level_46_80089764.s` |
| `func_level_47_80087AFC` | radius heading and movement helper dispatch | 199 | `a03a39e026284a647d130487e521b35c82e28da7e38ba0e617f0da420de94e84` | `asm/nonmatchings/overlays/level_47/level/func_level_47_80087AFC.s` |
| `func_level_48_80082EA4` | radius heading and movement helper dispatch | 199 | `05e40c2080eb6707c37674e7df287b1c55aa456788dc15da91999ea8f7bc9869` | `asm/nonmatchings/overlays/level_48/level/func_level_48_80082EA4.s` |
| `func_level_50_80092640` | radius heading and movement helper dispatch | 199 | `1924d07b7cd85e6545d75667bb32ec5c743359d166722a6889b0665b3ceef7fe` | `asm/nonmatchings/overlays/level_50/level/func_level_50_80092640.s` |
| `func_level_15_8007B2E8` | linked draw-distance gate and paired actor spawn | 122 | `4402166a2a7aba560de1cb89e2ead2039a6ff6d93d9b8b7a6e77083c58920358` | `asm/nonmatchings/overlays/level_15/moby/func_level_15_8007B2E8.s` |
| `func_level_25_8007B78C` | linked draw-distance gate and paired actor spawn | 122 | `2b550b43f23e34b3df01522e0611b81ab43542a578a20a946c4f1b26a1fd0c28` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_8007B78C.s` |
| `func_level_35_8007ACA4` | linked draw-distance gate and paired actor spawn | 122 | `d6051b7941a68fc13229aa529cefb6cf1ff8a784096db59975ef6b89c6ca1dae` | `asm/nonmatchings/overlays/level_35/moby/func_level_35_8007ACA4.s` |
| `func_level_45_8007A6B0` | linked draw-distance gate and paired actor spawn | 122 | `fee291767f2047a64098cb318ecaf962aabeff1f1b15c763d4f4d4a6760319bf` | `asm/nonmatchings/overlays/level_45/moby/func_level_45_8007A6B0.s` |
| `func_level_31_800874E0` | radius heading and movement helper dispatch | 199 | `13e1b133e66c68ffeb2c6f6b243439e3d6670db1063d4bd0bb9d220e0a4f3319` | `asm/nonmatchings/overlays/level_31/level/func_level_31_800874E0.s` |
