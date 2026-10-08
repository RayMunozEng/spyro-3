# Verified overlay batch 2026-10-03-16

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 16 functions, 1222 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch16.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'signed node count and vector distance maximum': 3, 'camera halfwords and parent record follow': 13}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_32_8009231C` | signed node count and vector distance maximum | 39 | `5e882fa50dc9fb6e2f1b5d3d6d14191eaed8840db3d87a9a136349bf90b3fd8c` | `asm/nonmatchings/overlays/level_32/level/func_level_32_8009231C.s` |
| `func_level_41_8008B6A4` | signed node count and vector distance maximum | 39 | `5e882fa50dc9fb6e2f1b5d3d6d14191eaed8840db3d87a9a136349bf90b3fd8c` | `asm/nonmatchings/overlays/level_41/level/func_level_41_8008B6A4.s` |
| `func_level_50_80094B08` | signed node count and vector distance maximum | 39 | `5e882fa50dc9fb6e2f1b5d3d6d14191eaed8840db3d87a9a136349bf90b3fd8c` | `asm/nonmatchings/overlays/level_50/level/func_level_50_80094B08.s` |
| `func_level_10_800799AC` | camera halfwords and parent record follow | 85 | `873547467380bd5def4136ba7b9353bfc146585f79450decfc5ef9d7c0ca0df3` | `asm/nonmatchings/overlays/level_10/moby/func_level_10_800799AC.s` |
| `func_level_11_80079A10` | camera halfwords and parent record follow | 85 | `24e341a84de3001fb54157d852879943eb930309795ba8b5288a931e3b32d36f` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_80079A10.s` |
| `func_level_14_80079F88` | camera halfwords and parent record follow | 85 | `fd5d7e47ea3560387bd76bd23838b13e8789c4b9d9e627af3042721bc82bec4e` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_80079F88.s` |
| `func_level_20_8007A9E0` | camera halfwords and parent record follow | 85 | `3b7f57a1703d2f4a18f31eb6a377976dc76707c2121089d9f11bfc99a80cab96` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_8007A9E0.s` |
| `func_level_21_8007A720` | camera halfwords and parent record follow | 85 | `3903df35779bb67a7330e26f7213d500394744208e19c0aaf476e8b79dcbe004` | `asm/nonmatchings/overlays/level_21/moby/func_level_21_8007A720.s` |
| `func_level_22_8007B0F4` | camera halfwords and parent record follow | 85 | `c39373661cfef0ab2eab267d9cfad7b08bc9ce1bc22c7f192ca03c64f60e53f8` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_8007B0F4.s` |
| `func_level_24_8007B7F4` | camera halfwords and parent record follow | 85 | `924c814ab80a4922a9e8c71299fc662ba60706c431996961d963c7d967273b86` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8007B7F4.s` |
| `func_level_30_80079C2C` | camera halfwords and parent record follow | 85 | `a4783e9711a0657fe7278077dfecb741aa34c5ed427da5b87f59e3131eece4cf` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_80079C2C.s` |
| `func_level_32_80084C0C` | camera halfwords and parent record follow | 85 | `f6174a4d6db87bdf58342e18c105d02b10f1226dab52d52d3480995c0db7bbca` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_80084C0C.s` |
| `func_level_41_8007B5D4` | camera halfwords and parent record follow | 85 | `8063bcbf8b0010d2a5559016e3027916fb300e78e312671fbd19938a1679ae62` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_8007B5D4.s` |
| `func_level_42_8007B884` | camera halfwords and parent record follow | 85 | `aba1382cac233d8d7ba6e60eaabeb843d0628c2d2851163a76c2d53c4acf023a` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_8007B884.s` |
| `func_level_44_8007A170` | camera halfwords and parent record follow | 85 | `53f6e0781c81f98543c16df062102b9ea7e825163b832260fca9920dcc9dfd32` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_8007A170.s` |
| `func_level_50_8008102C` | camera halfwords and parent record follow | 85 | `bdb7b686a251e321b641bbdb8e782d33dd163e410e42921fdd8a70cdaf88e13a` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_8008102C.s` |
