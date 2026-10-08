# Shared upstream sound-selector implementation

AI-generated integration and this note are not yet human-reviewed. The retained selector implementation comes from the original upstream repository.

Baseline: upstream fc206c745091a11a9ff7e96072e7afcf8b435be0, include/overlay/animation.inc.h. The per-overlay wrappers reuse that implementation through the existing PlaySpyroSounds macro. The nine earlier standalone selectors were replaced with this baseline in cleanup batch 28, without increasing the match count. Full EXE/all-overlay verification passed in build/overlay_cleanup28.full.log and subsequent accepted full builds.

Every selector preserves original state/table constants and compiled bytes. This establishes native binary equality, without establishing human review or complete audio asset/event semantics. Next evidence target: complete animation-to-sound descriptor/archive/playback chain and synchronized retail captures.

| Source | Function |
| --- | --- |
| `src/overlays/level_10/animation.c` | `func_level_10_80089B9C` |
| `src/overlays/level_11/animation.c` | `func_level_11_8008E730` |
| `src/overlays/level_12/animation.c` | `func_level_12_80089FE4` |
| `src/overlays/level_13/animation.c` | `func_level_13_8008A5E4` |
| `src/overlays/level_14/animation.c` | `func_level_14_80096874` |
| `src/overlays/level_15/animation.c` | `func_level_15_800886FC` |
| `src/overlays/level_16/animation.c` | `func_level_16_80084B04` |
| `src/overlays/level_17/animation.c` | `func_level_17_80082DC4` |
| `src/overlays/level_18/animation.c` | `func_level_18_80087D6C` |
| `src/overlays/level_20/animation.c` | `func_level_20_8008AC84` |
| `src/overlays/level_21/animation.c` | `func_level_21_8008CF80` |
| `src/overlays/level_22/animation.c` | `func_level_22_800983C0` |
| `src/overlays/level_23/animation.c` | `func_level_23_800937D4` |
| `src/overlays/level_24/animation.c` | `func_level_24_80094558` |
| `src/overlays/level_25/animation.c` | `func_level_25_800882C4` |
| `src/overlays/level_26/animation.c` | `func_level_26_80089BC4` |
| `src/overlays/level_27/animation.c` | `func_level_27_80088940` |
| `src/overlays/level_28/animation.c` | `func_level_28_80085EBC` |
| `src/overlays/level_30/animation.c` | `func_level_30_8008A778` |
| `src/overlays/level_31/animation.c` | `func_level_31_8008DCF8` |
| `src/overlays/level_32/animation.c` | `func_level_32_80099CE0` |
| `src/overlays/level_33/animation.c` | `func_level_33_8009B598` |
| `src/overlays/level_34/animation.c` | `func_level_34_80096828` |
| `src/overlays/level_35/animation.c` | `func_level_35_8008A808` |
| `src/overlays/level_36/animation.c` | `func_level_36_8008537C` |
| `src/overlays/level_37/animation.c` | `func_level_37_8008A0DC` |
| `src/overlays/level_38/animation.c` | `func_level_38_800880EC` |
| `src/overlays/level_40/animation.c` | `func_level_40_80086564` |
| `src/overlays/level_41/animation.c` | `func_level_41_80092FC4` |
| `src/overlays/level_42/animation.c` | `func_level_42_8008C968` |
| `src/overlays/level_43/animation.c` | `func_level_43_800930D4` |
| `src/overlays/level_44/animation.c` | `func_level_44_8009090C` |
| `src/overlays/level_45/animation.c` | `func_level_45_800882C8` |
| `src/overlays/level_46/animation.c` | `func_level_46_8008F5D0` |
| `src/overlays/level_47/animation.c` | `func_level_47_8008CC44` |
| `src/overlays/level_48/animation.c` | `func_level_48_80087124` |
| `src/overlays/level_50/animation.c` | `func_level_50_8009D568` |
