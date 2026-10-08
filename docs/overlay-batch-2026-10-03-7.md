# Verified overlay batch 2026-10-03-7

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 25 functions, 874 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch7.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'HUD value clamp and ratio': 14, 'HUD sprite frame and byte difference': 6, 'fragment result particle wrapper': 1, 'fragment result helper and particle chain': 1, 'bounds helper and conditional callback': 1, 'title callback shutdown sequence': 1, 'tag and substate gated particle wrapper': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_11_800869E8` | HUD value clamp and ratio | 42 | `4243f9142d7c358e18fd16059c937c92cb3d29eb9ab1b131bd92686c09049e3d` | `asm/nonmatchings/overlays/level_11/level/func_level_11_800869E8.s` |
| `func_level_14_8008EEA0` | HUD value clamp and ratio | 42 | `4243f9142d7c358e18fd16059c937c92cb3d29eb9ab1b131bd92686c09049e3d` | `asm/nonmatchings/overlays/level_14/level/func_level_14_8008EEA0.s` |
| `func_level_17_8008043C` | HUD value clamp and ratio | 42 | `4243f9142d7c358e18fd16059c937c92cb3d29eb9ab1b131bd92686c09049e3d` | `asm/nonmatchings/overlays/level_17/level/func_level_17_8008043C.s` |
| `func_level_18_80085064` | HUD value clamp and ratio | 42 | `4243f9142d7c358e18fd16059c937c92cb3d29eb9ab1b131bd92686c09049e3d` | `asm/nonmatchings/overlays/level_18/level/func_level_18_80085064.s` |
| `func_level_22_80090EB8` | HUD value clamp and ratio | 42 | `4243f9142d7c358e18fd16059c937c92cb3d29eb9ab1b131bd92686c09049e3d` | `asm/nonmatchings/overlays/level_22/level/func_level_22_80090EB8.s` |
| `func_level_23_8008D9DC` | HUD value clamp and ratio | 42 | `4243f9142d7c358e18fd16059c937c92cb3d29eb9ab1b131bd92686c09049e3d` | `asm/nonmatchings/overlays/level_23/level/func_level_23_8008D9DC.s` |
| `func_level_27_80085C50` | HUD value clamp and ratio | 42 | `4243f9142d7c358e18fd16059c937c92cb3d29eb9ab1b131bd92686c09049e3d` | `asm/nonmatchings/overlays/level_27/level/func_level_27_80085C50.s` |
| `func_level_28_800831D4` | HUD value clamp and ratio | 42 | `4243f9142d7c358e18fd16059c937c92cb3d29eb9ab1b131bd92686c09049e3d` | `asm/nonmatchings/overlays/level_28/level/func_level_28_800831D4.s` |
| `func_level_31_80089600` | HUD value clamp and ratio | 42 | `4243f9142d7c358e18fd16059c937c92cb3d29eb9ab1b131bd92686c09049e3d` | `asm/nonmatchings/overlays/level_31/level/func_level_31_80089600.s` |
| `func_level_33_80095144` | HUD value clamp and ratio | 42 | `4243f9142d7c358e18fd16059c937c92cb3d29eb9ab1b131bd92686c09049e3d` | `asm/nonmatchings/overlays/level_33/level/func_level_33_80095144.s` |
| `func_level_37_80086304` | HUD value clamp and ratio | 42 | `4243f9142d7c358e18fd16059c937c92cb3d29eb9ab1b131bd92686c09049e3d` | `asm/nonmatchings/overlays/level_37/level/func_level_37_80086304.s` |
| `func_level_38_80084B28` | HUD value clamp and ratio | 42 | `4243f9142d7c358e18fd16059c937c92cb3d29eb9ab1b131bd92686c09049e3d` | `asm/nonmatchings/overlays/level_38/level/func_level_38_80084B28.s` |
| `func_level_47_80088F0C` | HUD value clamp and ratio | 42 | `4243f9142d7c358e18fd16059c937c92cb3d29eb9ab1b131bd92686c09049e3d` | `asm/nonmatchings/overlays/level_47/level/func_level_47_80088F0C.s` |
| `func_level_48_8008443C` | HUD value clamp and ratio | 42 | `4243f9142d7c358e18fd16059c937c92cb3d29eb9ab1b131bd92686c09049e3d` | `asm/nonmatchings/overlays/level_48/level/func_level_48_8008443C.s` |
| `func_level_15_80083234` | HUD sprite frame and byte difference | 30 | `6ffeeac524a5a78f2f0346b04f5371fbb598c4788c9746c3ff9bfd937b3ff3d4` | `asm/nonmatchings/overlays/level_15/level/func_level_15_80083234.s` |
| `func_level_25_80083BEC` | HUD sprite frame and byte difference | 30 | `6ffeeac524a5a78f2f0346b04f5371fbb598c4788c9746c3ff9bfd937b3ff3d4` | `asm/nonmatchings/overlays/level_25/level/func_level_25_80083BEC.s` |
| `func_level_32_80091D70` | HUD sprite frame and byte difference | 30 | `6ffeeac524a5a78f2f0346b04f5371fbb598c4788c9746c3ff9bfd937b3ff3d4` | `asm/nonmatchings/overlays/level_32/level/func_level_32_80091D70.s` |
| `func_level_35_80084F70` | HUD sprite frame and byte difference | 30 | `6ffeeac524a5a78f2f0346b04f5371fbb598c4788c9746c3ff9bfd937b3ff3d4` | `asm/nonmatchings/overlays/level_35/level/func_level_35_80084F70.s` |
| `func_level_45_8008352C` | HUD sprite frame and byte difference | 30 | `6ffeeac524a5a78f2f0346b04f5371fbb598c4788c9746c3ff9bfd937b3ff3d4` | `asm/nonmatchings/overlays/level_45/level/func_level_45_8008352C.s` |
| `func_level_50_8009455C` | HUD sprite frame and byte difference | 30 | `6ffeeac524a5a78f2f0346b04f5371fbb598c4788c9746c3ff9bfd937b3ff3d4` | `asm/nonmatchings/overlays/level_50/level/func_level_50_8009455C.s` |
| `func_level_36_8007D8FC` | fragment result particle wrapper | 18 | `aa9381123ab900cf91db6ccc185eb1bfcc9831ca4c49627741598f8cd44f3cc0` | `asm/nonmatchings/overlays/level_36/moby/func_level_36_8007D8FC.s` |
| `func_level_44_80084424` | fragment result helper and particle chain | 26 | `14722f2bb8be2c872d679f0ff6fe3e9aaa5dc0c6ceedb94c911912cca196e112` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_80084424.s` |
| `func_level_40_8007EBA8` | bounds helper and conditional callback | 16 | `c8c61b63d10aefc6a38e5f98d356860cd433cb8ffdc4226271677ed451cd222f` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_8007EBA8.s` |
| `func_title_80078B38` | title callback shutdown sequence | 20 | `85f7032ff9549c892e14605f3293723845bc023a010aecc73fb917e080d0610f` | `asm/nonmatchings/overlays/title/crash/func_title_80078B38.s` |
| `func_level_23_8007A73C` | tag and substate gated particle wrapper | 26 | `85dbd9b32d160e031273a6da98edd008772b5a16ce9699660e946deec740a2a8` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_8007A73C.s` |
