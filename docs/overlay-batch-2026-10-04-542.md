# Verified overlay batch 2026-10-04-542

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 240 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch542.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes: ordinary C retains both projectile bounds and timers, one-time sound, velocity addition, world collision rollback, actor heading byte clamp, draw update and the original five-argument impact callback. The collision radii are 0x177 for level 15 and 0xC8 for level 37. All other instructions match without scheduling constraints.

Categories: {'bounded projectile movement collision rollback actor heading and burst': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_15_8007902C` | bounded projectile movement collision rollback actor heading and burst | 120 | `eb07dd74098a01f080da2872091660bc2e3dfe40dd1fb0c3103b4d55261f10e7` | `asm/nonmatchings/overlays/level_15/moby/func_level_15_8007902C.s` |
| `func_level_37_80079664` | bounded projectile movement collision rollback actor heading and burst | 120 | `b2afb7d13b587c93bd7b8f78ca74b7bd35a6113f3a1453b6ffd4a5b588b17257` | `asm/nonmatchings/overlays/level_37/moby/func_level_37_80079664.s` |
