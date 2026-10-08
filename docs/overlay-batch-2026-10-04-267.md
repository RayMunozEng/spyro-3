# Verified overlay batch 2026-10-04-267

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 23 functions, 4048 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch267.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- Twenty-three identical actor routines retain the tag-word gate, distance and signed height comparisons, focus-actor callbacks, target and timer writes, damage branch and spawn capacity test.
- The original spawn loop has no null check after `SpawnMoby`; this branch is retained exactly. First five spawned actors receive substate 3; later actors receive animation byte 1.
- Four iterations preserve all random calls, position offsets and both numeric particle calls before the final cleanup helpers. Empty constraints preserve the original arithmetic and load order without emitting instructions.
- Partial focus-tag fields remain numeric. Existing helper names do not establish sound or event semantics; those interpretations remain unreviewed.

Categories: {'focus actor callbacks and damage gated repeated spawns': 23}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_80077488` | focus actor callbacks and damage gated repeated spawns | 176 | `d575f4b1a26d0c63b6277e7a6848b55cc58f20d4ac13c8a8a4a147277899a6be` | `asm/nonmatchings/overlays/level_10/moby/func_level_10_80077488.s` |
| `func_level_11_800779F8` | focus actor callbacks and damage gated repeated spawns | 176 | `2f21bace7e41aad36bae508c9f483e7de6e8107f965da55db004ac3aaced502a` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_800779F8.s` |
| `func_level_12_800777A4` | focus actor callbacks and damage gated repeated spawns | 176 | `b55cfd43f8e4acfa558b515006be278c648064963fbc96c18bc16c4f17459829` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_800777A4.s` |
| `func_level_13_800779F0` | focus actor callbacks and damage gated repeated spawns | 176 | `10996e472e096abd2bc96deef0dcf8a79d5a2c1aa82fd76dcae4c6b9d4bfdde3` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_800779F0.s` |
| `func_level_14_80077C8C` | focus actor callbacks and damage gated repeated spawns | 176 | `599f118d0db639ef6932fce328e5411b36b16137ca112fcf3136f456d48bce0d` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_80077C8C.s` |
| `func_level_16_800772EC` | focus actor callbacks and damage gated repeated spawns | 176 | `9df08388bf73e3e8bfb1e3c1b639a942d5f19587e9a45f5eb6b051537f0d6058` | `asm/nonmatchings/overlays/level_16/moby/func_level_16_800772EC.s` |
| `func_level_20_80077AA4` | focus actor callbacks and damage gated repeated spawns | 176 | `221d6a700ec059ee62beb44e068e9b3ec8eafaf8e16b192f2ca9c580d89ddb63` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_80077AA4.s` |
| `func_level_21_80077BD0` | focus actor callbacks and damage gated repeated spawns | 176 | `b32cc9614c417c5b5091205a4e416d362d6a4de7ef0e9fed8bde65e07db88f77` | `asm/nonmatchings/overlays/level_21/moby/func_level_21_80077BD0.s` |
| `func_level_22_800780C0` | focus actor callbacks and damage gated repeated spawns | 176 | `5effb1434168c3b0f91b2691c3e7eb6f29d538a431fd987e3c4508d0df036709` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_800780C0.s` |
| `func_level_23_80077DB0` | focus actor callbacks and damage gated repeated spawns | 176 | `036710950a6604fe39a985ff090e2fb1b8e3670159becc3957bef71d2e979833` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_80077DB0.s` |
| `func_level_24_80078210` | focus actor callbacks and damage gated repeated spawns | 176 | `ae823dffc5036dba383bc3de6fb89d2441b50910142dca0ac7dcef52cf526c8d` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_80078210.s` |
| `func_level_26_8007773C` | focus actor callbacks and damage gated repeated spawns | 176 | `cd4b09f3d500e0fa48b26e9e1a331dae15f1fa5a6d5b85cad2f92270d1bcc5da` | `asm/nonmatchings/overlays/level_26/moby/func_level_26_8007773C.s` |
| `func_level_31_80078188` | focus actor callbacks and damage gated repeated spawns | 176 | `484d521b59abbf8f8e0c4633a4ddea638071e3978dbd31881e709201ebd57efc` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_80078188.s` |
| `func_level_32_800785F8` | focus actor callbacks and damage gated repeated spawns | 176 | `cce396cbe6bdbd5f5554c3f84e574db3ce7b3d89147abb216544003ca3d09944` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_800785F8.s` |
| `func_level_33_80078800` | focus actor callbacks and damage gated repeated spawns | 176 | `13de924f59be12ba3d603bd608f92fc1623abc8d01197d1472ccf50a60231dcf` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_80078800.s` |
| `func_level_34_800780FC` | focus actor callbacks and damage gated repeated spawns | 176 | `589a7a7590f5f060d0f280d6240e5e46217a56fd89fe3d17220825f2ab777e37` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_800780FC.s` |
| `func_level_36_80077308` | focus actor callbacks and damage gated repeated spawns | 176 | `0279a291286f4235a51f2d9608b14ac8afda3543801e9db05683e0e0411cdc36` | `asm/nonmatchings/overlays/level_36/moby/func_level_36_80077308.s` |
| `func_level_40_800771E8` | focus actor callbacks and damage gated repeated spawns | 176 | `249e231c3e9526e9570be7fe39990135528ed056131bec0b4c76119eb66b3998` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_800771E8.s` |
| `func_level_41_80077D7C` | focus actor callbacks and damage gated repeated spawns | 176 | `2adeec750675eb9fc305d125834be6a3e9371eda0e92e1d01de011316fd98a05` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_80077D7C.s` |
| `func_level_42_80077A5C` | focus actor callbacks and damage gated repeated spawns | 176 | `9e4a59e38b254a6e255eebeaa651693f174f571ed4347b05925c842183644af3` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_80077A5C.s` |
| `func_level_43_800781C0` | focus actor callbacks and damage gated repeated spawns | 176 | `4f13903d359b69375cb247f8ce0bc02d58a19b11d419e1dfa24b795333ac2829` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_800781C0.s` |
| `func_level_44_80077DE4` | focus actor callbacks and damage gated repeated spawns | 176 | `f2572af13f7ab0ca33eb5e3f994fe202248c3fe702f0126157932c0231b3309e` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_80077DE4.s` |
| `func_level_46_80077678` | focus actor callbacks and damage gated repeated spawns | 176 | `2b6f26a5d8e70aca89fc18b5a3c2beb1e550105d76ffe9062139f5e1f153e98c` | `asm/nonmatchings/overlays/level_46/moby/func_level_46_80077678.s` |
