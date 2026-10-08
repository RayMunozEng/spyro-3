# Verified overlay batch 2026-10-03-33

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 20 functions, 2400 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch33.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream `common.h`, `stdutil.h`, `str.h`, and `loaders.h` structures and helper declarations, with partial record layouts proved by the original assembly accesses.

Categories: {'archive relocation preserving count reloads and stack reservation': 20}.

## Relocation evidence and remaining unknowns

The archive table uses eight-byte entries containing 32-bit offset and length words. `DecodedRelocationHeader.records` begins at byte offset `0x3C`; each slot is a 32-bit address. The routine adds the buffer base to the selected slot and record offsets `0x0C` and `0x20`, adds the header base to offsets `0x10` and `0x14`, and clears the two words at `0x18` and `0x1C`. These are byte addresses and lengths, with no world-coordinate conversion or fixed-point interpretation.

The original routine reserves a 48-byte stack frame including eight unused bytes. The C reservation reproduces that frame; its original purpose is unknown. Register constraints contain empty strings and emit no instructions. They preserve the original index calculation and count reload ordering. Helper names `func_80064A2C`, `func_80064A8C`, and `func_80064AEC` remain address names: this batch proves their calls and wait condition, without claiming a complete archive or playback interpretation.

The next semantic evidence target is the producer of these archive records and the complete consumer chain for the helper calls. Binary matching establishes the routine's instruction behavior, not a human-reviewed interpretation of the format.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_cutscene_61_80077464` | archive relocation preserving count reloads and stack reservation | 120 | `fa13d17034a8a871583938260a1547a5d35669acf4034911a95e971301043c3b` | `asm/nonmatchings/overlays/cutscene_61/camera/func_cutscene_61_80077464.s` |
| `func_cutscene_62_80077A90` | archive relocation preserving count reloads and stack reservation | 120 | `d05432b3c71e1f75992db2d3b9d66f14218a6679518ed8856a5cfd772b8946d5` | `asm/nonmatchings/overlays/cutscene_62/camera/func_cutscene_62_80077A90.s` |
| `func_cutscene_63_80077338` | archive relocation preserving count reloads and stack reservation | 120 | `6fdd82b8ead89c781264c7bc87c2764f80e88c2f47a42eaa8352a589c49c7d7c` | `asm/nonmatchings/overlays/cutscene_63/camera/func_cutscene_63_80077338.s` |
| `func_cutscene_64_80077898` | archive relocation preserving count reloads and stack reservation | 120 | `722dc7aa27fd3d866949cd935bc2c7ff0d042170a6bf8623a96baa65a04f688e` | `asm/nonmatchings/overlays/cutscene_64/camera/func_cutscene_64_80077898.s` |
| `func_cutscene_65_80076FE0` | archive relocation preserving count reloads and stack reservation | 120 | `d026685651688b2d3ca68541b3b78b72b01936714a2590b0a68fcf8df67b7281` | `asm/nonmatchings/overlays/cutscene_65/camera/func_cutscene_65_80076FE0.s` |
| `func_cutscene_66_80076FE0` | archive relocation preserving count reloads and stack reservation | 120 | `d026685651688b2d3ca68541b3b78b72b01936714a2590b0a68fcf8df67b7281` | `asm/nonmatchings/overlays/cutscene_66/camera/func_cutscene_66_80076FE0.s` |
| `func_cutscene_67_80077338` | archive relocation preserving count reloads and stack reservation | 120 | `6fdd82b8ead89c781264c7bc87c2764f80e88c2f47a42eaa8352a589c49c7d7c` | `asm/nonmatchings/overlays/cutscene_67/camera/func_cutscene_67_80077338.s` |
| `func_cutscene_68_80076FE0` | archive relocation preserving count reloads and stack reservation | 120 | `d026685651688b2d3ca68541b3b78b72b01936714a2590b0a68fcf8df67b7281` | `asm/nonmatchings/overlays/cutscene_68/camera/func_cutscene_68_80076FE0.s` |
| `func_cutscene_69_80077234` | archive relocation preserving count reloads and stack reservation | 120 | `9661262cdfb8eece66be47f08d014f72e754800342b77b99f290bbf5d8466060` | `asm/nonmatchings/overlays/cutscene_69/camera/func_cutscene_69_80077234.s` |
| `func_cutscene_70_80077628` | archive relocation preserving count reloads and stack reservation | 120 | `0f9a3a1286750ed8c21b0c82bd05876f1018971fab9c7553683e58405b6a96f0` | `asm/nonmatchings/overlays/cutscene_70/camera/func_cutscene_70_80077628.s` |
| `func_cutscene_71_80077278` | archive relocation preserving count reloads and stack reservation | 120 | `df2ece7926d2ccdee21c80fc25c2b4d45424f4dd8afdddff01189a5af6c33809` | `asm/nonmatchings/overlays/cutscene_71/camera/func_cutscene_71_80077278.s` |
| `func_cutscene_73_80077DB0` | archive relocation preserving count reloads and stack reservation | 120 | `c10c061375330e997461f2936beebc7d2356b669ac9b92c4bd9be393407fe6e9` | `asm/nonmatchings/overlays/cutscene_73/camera/func_cutscene_73_80077DB0.s` |
| `func_cutscene_74_80076FE0` | archive relocation preserving count reloads and stack reservation | 120 | `d026685651688b2d3ca68541b3b78b72b01936714a2590b0a68fcf8df67b7281` | `asm/nonmatchings/overlays/cutscene_74/camera/func_cutscene_74_80076FE0.s` |
| `func_cutscene_75_800770C8` | archive relocation preserving count reloads and stack reservation | 120 | `0964d2d1ce4e40829bea995f626fe6fa02507d5f44807e69e99762ee62bdc307` | `asm/nonmatchings/overlays/cutscene_75/camera/func_cutscene_75_800770C8.s` |
| `func_cutscene_76_800770C8` | archive relocation preserving count reloads and stack reservation | 120 | `0964d2d1ce4e40829bea995f626fe6fa02507d5f44807e69e99762ee62bdc307` | `asm/nonmatchings/overlays/cutscene_76/camera/func_cutscene_76_800770C8.s` |
| `func_cutscene_77_800770C8` | archive relocation preserving count reloads and stack reservation | 120 | `0964d2d1ce4e40829bea995f626fe6fa02507d5f44807e69e99762ee62bdc307` | `asm/nonmatchings/overlays/cutscene_77/camera/func_cutscene_77_800770C8.s` |
| `func_cutscene_78_80077730` | archive relocation preserving count reloads and stack reservation | 120 | `4eaa1a873be76bc51fff2e807a9e2064d4c7e7938d25cf07e79bf1407da8d9a6` | `asm/nonmatchings/overlays/cutscene_78/camera/func_cutscene_78_80077730.s` |
| `func_cutscene_79_80076FE0` | archive relocation preserving count reloads and stack reservation | 120 | `d026685651688b2d3ca68541b3b78b72b01936714a2590b0a68fcf8df67b7281` | `asm/nonmatchings/overlays/cutscene_79/camera/func_cutscene_79_80076FE0.s` |
| `func_cutscene_80_800776B0` | archive relocation preserving count reloads and stack reservation | 120 | `997600e349613d0bc4cb022773da83c04328f21007216e2097d9a048d2baef8a` | `asm/nonmatchings/overlays/cutscene_80/camera/func_cutscene_80_800776B0.s` |
| `func_title_80079FE0` | archive relocation preserving count reloads and stack reservation | 120 | `de6b94e96a071b6d8690b99c548a6e3085e1caf0bb2dfc9aabe3248f97ad92c8` | `asm/nonmatchings/overlays/title/title3/func_title_80079FE0.s` |
