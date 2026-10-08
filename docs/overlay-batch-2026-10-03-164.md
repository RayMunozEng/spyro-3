# Verified overlay batch 2026-10-03-164

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 9 functions, 635 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch164.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: upstream `HudEntry`, `Moby`, `Colour`, `Vector3D`, particle/vector helpers and the exact instructions. HUD routines clamp signed source values against an unsigned 16-bit maximum, compute the original signed value*144/maximum ratio and clamp negative results, then move an unsigned 16-bit display value by one and preserve the positive-source minimum of one. Division-by-zero behavior is retained rather than hidden by an invented guard. Cutscene routines allocate with original arguments 4/0x40/0x489090, write tag byte +0x10=4, call original helpers and temporarily replace/restore actor position around a callback when (ticks&15)<2. Literal callback arguments actor-address/3 are retained without interpreting them as vector pointers. The five fade copies add the original delta word to tag counter +0, delete at signed counter>=30, otherwise compute ((30-counter)<<8)/30, multiply unsigned colour components and shift right eight, and set yaw from unsigned substate<<8 divided by six. Byte truncation, stack colour accesses and original draw/alpha writes match exactly. Counter cadence and colour/position fixed-point domains remain unresolved. Next evidence target: delta/tick producers, colour-table schema and cutscene callback argument/payload chain.

Categories: {'HUD signed clamp ratio and unsigned one-step approach': 2, 'cutscene tag allocation and timed position particle sequence': 2, 'tag counter colour fade and actor byte updates': 5}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_32_800916E8` | HUD signed clamp ratio and unsigned one-step approach | 62 | `c3682ff22b81cfec5c93581bfa789ef5e2d9b174a1e2bfb54c69931ebe93d4e9` | `asm/nonmatchings/overlays/level_32/level/func_level_32_800916E8.s` |
| `func_level_50_80093ED4` | HUD signed clamp ratio and unsigned one-step approach | 62 | `c3682ff22b81cfec5c93581bfa789ef5e2d9b174a1e2bfb54c69931ebe93d4e9` | `asm/nonmatchings/overlays/level_50/level/func_level_50_80093ED4.s` |
| `func_cutscene_75_80074788` | cutscene tag allocation and timed position particle sequence | 58 | `e70a042c0e979e46147f9eeaec43d21c811db1c3b2f75b9dee06d0fd4c50608c` | `asm/nonmatchings/overlays/cutscene_75/moby/func_cutscene_75_80074788.s` |
| `func_cutscene_76_80074788` | cutscene tag allocation and timed position particle sequence | 58 | `e70a042c0e979e46147f9eeaec43d21c811db1c3b2f75b9dee06d0fd4c50608c` | `asm/nonmatchings/overlays/cutscene_76/moby/func_cutscene_76_80074788.s` |
| `func_level_10_8007D4F0` | tag counter colour fade and actor byte updates | 79 | `8f4082f699c91d39c328c290ecd1ab4dc24b3d7b1032792b90031cd884166ba9` | `asm/nonmatchings/overlays/level_10/moby/func_level_10_8007D4F0.s` |
| `func_level_20_8007CF58` | tag counter colour fade and actor byte updates | 79 | `b720a2aa3d169a68cc71476594ae1324725ba06af86da2444dbb18db6c6a6e22` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_8007CF58.s` |
| `func_level_30_8007C598` | tag counter colour fade and actor byte updates | 79 | `02ee4ce35f1b8f3dc11930198cb44d4ef138038e6c01c8b67393b1211652a2e1` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_8007C598.s` |
| `func_level_40_8007BCF4` | tag counter colour fade and actor byte updates | 79 | `5fe9aeeaf7c4f1e23c2148fdee92797f56c2a1a66f98b4afa043464b8f30b36f` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_8007BCF4.s` |
| `func_level_50_80086CCC` | tag counter colour fade and actor byte updates | 79 | `544bcd23779af1be9044ce9c4906369f338748400a54b5f9a120ecaadaf28af3` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_80086CCC.s` |
