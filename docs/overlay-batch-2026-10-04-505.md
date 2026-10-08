# Verified overlay batch 2026-10-04-505

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 221 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch505.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes: the level 45 sound/damage/motion prefix reuses the verified `func_level_25_8007A0E8` layout, with constants and the added floor-height flag update taken from this routine's original instructions. Empty compiler constraints preserve the original argument/result scheduling without emitting instructions. The level 32 routine expresses the original signed Q12 sine/cosine products, halfword gravity decrement, byte timer/yaw updates, and three separate collision checks as ordinary C.

Categories: {'sound handle damage fragments motion and floor-height flag': 1, 'tagged movement gravity timer and original collision checks': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_45_8007A898` | sound handle damage fragments motion and floor-height flag | 111 | `9d3d32a36feee23c7ece7e8ef0a2c3fd5dc41ddf23b355e262a968f405439bdc` | `asm/nonmatchings/overlays/level_45/moby/func_level_45_8007A898.s` |
| `func_level_32_80085EC0` | tagged movement gravity timer and original collision checks | 110 | `205ff2951d7bd21ab2a2b4a7c5e2632a355019438501ae08eb7a18fe7c73fcd8` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_80085EC0.s` |
