# Verified overlay batch 2026-10-04-900

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 5 functions, 920 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch900.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Source baseline: original state-dispatch instructions listed below; existing upstream Moby/vector declarations and callback symbols are reused. The private record contains word timer and mode followed by signed halfword lower/upper bounds. State 0 preserves global mode 2/3 handling and deletion conditions. State 1 preserves strict range comparisons, byte visibility fields, yaw conversion from signed Q4 halfword via arithmetic shift 4 minus 128, pitch low-byte conversion, and the query callback argument 1024. State 2 makes exactly eight ordered particle calls with vector helper shift 5 and per-axis `(rand() & 254) - 127`, then writes signed halfword 75 and heading-selected +1/-1 at player offsets 0x148/0x14A, hides the actor, and records timer 60/state 3. State 3 preserves timer-helper argument 4, camera-derived angle refresh, draw/update distance 63/16, and state 1. World-vector units, particle selector meaning, query/timer helper semantics, and caller cadence remain separate evidence targets. Empty constraints retain original load-delay filling, arithmetic order, and loop-counter initialization without emitting instructions. No instruction-bearing inline assembly is introduced.

Categories: {'mode and range gated timed pickup with particle burst': 5}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_15_8007A9A0` | mode and range gated timed pickup with particle burst | 184 | `1829c52c267b460738bccf1353d25ae4a0a1ceecb5ef5975e473d36458e727a6` | `asm/nonmatchings/overlays/level_15/moby/func_level_15_8007A9A0.s` |
| `func_level_25_8007A374` | mode and range gated timed pickup with particle burst | 184 | `a683050a1c29dfbcc18c367e425d5ab926c7b0b2ac23305f72528f6afc8c1a37` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_8007A374.s` |
| `func_level_35_80079128` | mode and range gated timed pickup with particle burst | 184 | `bb6323dc837a5a0996e692a8c1fa995a523fdfaed9e173bbfa96fa90fe8e7c7a` | `asm/nonmatchings/overlays/level_35/moby/func_level_35_80079128.s` |
| `func_level_41_8007CF80` | mode and range gated timed pickup with particle burst | 184 | `eb1a5402987b8acee942839c0e4304f777e2acdc9599bb163ec444ec18f9fb11` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_8007CF80.s` |
| `func_level_45_80079298` | mode and range gated timed pickup with particle burst | 184 | `283d1195102045bade50f8b6d91e43358268ceb891516a245231237da4edbd71` | `asm/nonmatchings/overlays/level_45/moby/func_level_45_80079298.s` |
