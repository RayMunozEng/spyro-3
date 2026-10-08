# Verified overlay batch 2026-10-03-137

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 7 functions, 471 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch137.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: upstream `Spyro`, `Moby`, `Vector3D16`, `SHORTMATRIX`, `Angle12` and camera/helper declarations plus the exact instructions. Camera modes 13 and 17 preserve their distinct control paths, override handling and animation-state lookups. A second C declaration aliases the same retail state table so the compiler retains both original lookup blocks instead of sharing their tail; the linked address is unchanged. The actor-list routine processes signed 16-bit entries including the negative terminator, indexes actors with low 15 bits and writes one unsigned substate byte. The matrix routine widens actor angle bytes by a four-bit left shift into signed 16-bit locals, negates the first pitch, calls the original matrix helpers in order with their original in-place arguments, and narrows signed outputs shifted right four bits back to angle bytes. Stack layout matches the original 144-byte frame with existing SDK types. Exact helper representation, valid angle domain, tag/table producers and invocation cadence remain unresolved; no scale conversion beyond the original shifts is inferred. Next evidence target: matrix helper producer/consumer units and synchronized retail captures of camera transitions.

Categories: {'original actor angle and three-matrix helper chain': 3, 'camera modes thirteen and seventeen state selection': 3, 'signed halfword actor list substate assignment': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_22_8009284C` | original actor angle and three-matrix helper chain | 76 | `2dbd9f69b659d0c75b841393240986be0b81c745d16a0f8d7838eeb963d5b101` | `asm/nonmatchings/overlays/level_22/level/func_level_22_8009284C.s` |
| `func_level_32_80092E80` | original actor angle and three-matrix helper chain | 76 | `2dbd9f69b659d0c75b841393240986be0b81c745d16a0f8d7838eeb963d5b101` | `asm/nonmatchings/overlays/level_32/level/func_level_32_80092E80.s` |
| `func_level_50_80095A84` | original actor angle and three-matrix helper chain | 76 | `2dbd9f69b659d0c75b841393240986be0b81c745d16a0f8d7838eeb963d5b101` | `asm/nonmatchings/overlays/level_50/level/func_level_50_80095A84.s` |
| `func_level_17_80083DD0` | camera modes thirteen and seventeen state selection | 71 | `6e7ba70723a27bb09ac7bc16827fd0010d1791b826c1416513233087d8ed7798` | `asm/nonmatchings/overlays/level_17/camera/func_level_17_80083DD0.s` |
| `func_level_27_80089AC4` | camera modes thirteen and seventeen state selection | 71 | `fdc1634e0ab1d671923c3d1c9f0362ac88ca8995dfd8c19c2f93adc6553537dd` | `asm/nonmatchings/overlays/level_27/camera/func_level_27_80089AC4.s` |
| `func_level_37_8008B91C` | camera modes thirteen and seventeen state selection | 71 | `15b0f4cde97d605d2d69e4633c6f2fd13daa8d2a687abb9ee69165f2ab29179a` | `asm/nonmatchings/overlays/level_37/camera/func_level_37_8008B91C.s` |
| `func_level_16_80080BE0` | signed halfword actor list substate assignment | 30 | `1856656c3e0e0076192dfc30ef50f314d83ed793da0324210729c69f2758ccb3` | `asm/nonmatchings/overlays/level_16/level/func_level_16_80080BE0.s` |
