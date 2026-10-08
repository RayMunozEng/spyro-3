# Verified overlay batch 2026-10-03-14

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 10 functions, 333 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch14.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'parent state and signed table byte yaw update': 5, 'marker gated retail EXE word patch': 1, 'marker gated byte flag clear': 1, 'surface word and bounds gated player flags': 2, 'player mode and position word flag setup': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_8007A840` | parent state and signed table byte yaw update | 44 | `0c86d1a53a15211b3902f740da9abc7157ae27f806dc5d37088cb5f81a00cfe7` | `asm/nonmatchings/overlays/level_10/moby/func_level_10_8007A840.s` |
| `func_level_20_8007C158` | parent state and signed table byte yaw update | 44 | `73179a1e7a8a0c9409186942338e67cce6de7afb2688ec4efd8faac18cf70c8c` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_8007C158.s` |
| `func_level_30_8007AAC4` | parent state and signed table byte yaw update | 44 | `8d30a41b40aec72ca34f1b1eceabf8b9a284becf66e48e9f93bff51762d4b5d3` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_8007AAC4.s` |
| `func_level_40_8007B64C` | parent state and signed table byte yaw update | 44 | `3f5fa6ef64c3852b29f55e79515b68ca887654f0e46fdd824a989d652e66f9df` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_8007B64C.s` |
| `func_level_50_80085EF0` | parent state and signed table byte yaw update | 44 | `d2ddfde67280a355720fccba08ab20b432a63dc6585ff5e84a6b6b5216797ca0` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_80085EF0.s` |
| `func_level_41_8008067C` | marker gated retail EXE word patch | 19 | `291e0d7518897b6a5a539c6906e221e962a9d3a5e88fbc036478ab4878536346` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_8008067C.s` |
| `func_level_16_8007D4AC` | marker gated byte flag clear | 22 | `ba6a14450fc5ec25a42c7e4532738feb389d69b991b313fbddc8e032db170873` | `asm/nonmatchings/overlays/level_16/moby/func_level_16_8007D4AC.s` |
| `func_level_13_80082CF8` | surface word and bounds gated player flags | 23 | `1673e9ceb13e1049d2b784348bb7f5db3e17cce93ab655af0ec658660ff0bc55` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_80082CF8.s` |
| `func_level_14_8007B4EC` | surface word and bounds gated player flags | 23 | `1673e9ceb13e1049d2b784348bb7f5db3e17cce93ab655af0ec658660ff0bc55` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_8007B4EC.s` |
| `func_level_42_80083940` | player mode and position word flag setup | 26 | `bfe70c023828b082534b707ff9e6d0dc501fdb4b830cf1f073ce60fe29de887a` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_80083940.s` |
