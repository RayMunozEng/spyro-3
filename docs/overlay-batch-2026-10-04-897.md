# Verified overlay batch 2026-10-04-897

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 9 functions, 1449 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch897.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Source baseline: the original polygon-helper instructions listed below, with existing upstream vector declarations and helpers func_8004F1C8 and func_8004EDE8. The record uses an unsigned byte entry count at +1, a signed halfword initial bound at +2, a vector at +4, and 28-byte entries starting at +12. Each entry supplies the vector at +8 and signed word coefficients at +16/+20. The helper finds the nearest entry using initial minimum 0xFFFFFF and nearest sentinel -1, then evaluates two wrapped neighbor indices with signed remainder and all original divide traps. Signed products and side tests preserve retail return priority exactly. Count rereads, vector helper argument 0, and all access widths remain intact. Coordinate units, coefficient representation, record producers, and caller cadence remain open evidence targets; exact byte matching does not establish browser collision parity. Empty scheduling/register constraints emit no instructions and preserve compiler load order, address operands, and return branches.

Categories: {'nearest polygon neighbor signed products': 9}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_11_80087780` | nearest polygon neighbor signed products | 161 | `4e466dfda8c3dfd0659567d958ce8a57f7f561c272ea270fe79c3454cbaba28a` | `asm/nonmatchings/overlays/level_11/level/func_level_11_80087780.s` |
| `func_level_13_80086728` | nearest polygon neighbor signed products | 161 | `0eefce61b59542aec3b55f4dac300f690e18d0c8c700d6ebbbea9fd3ff63db22` | `asm/nonmatchings/overlays/level_13/level/func_level_13_80086728.s` |
| `func_level_14_8008FCBC` | nearest polygon neighbor signed products | 161 | `4c5c1abab78342f0ffb529ab2489d5110cdf9f446a41a8f8a61e7d8008632ac3` | `asm/nonmatchings/overlays/level_14/level/func_level_14_8008FCBC.s` |
| `func_level_22_800925C8` | nearest polygon neighbor signed products | 161 | `4b549fe46897b3bf4404144514f2a527b233ce9bb27d6c918f6eb9759c96321a` | `asm/nonmatchings/overlays/level_22/level/func_level_22_800925C8.s` |
| `func_level_23_8008DC9C` | nearest polygon neighbor signed products | 161 | `7faeb5e3ba6dd6315e95ac1b1633506dca137412bd78b9cbb2d6b9ef56edbc90` | `asm/nonmatchings/overlays/level_23/level/func_level_23_8008DC9C.s` |
| `func_level_34_800916EC` | nearest polygon neighbor signed products | 161 | `43ec447a309820a8069ff244ff714074f8d2b049e8347939a4aa92c512649c7b` | `asm/nonmatchings/overlays/level_34/level/func_level_34_800916EC.s` |
| `func_level_41_8008BB7C` | nearest polygon neighbor signed products | 161 | `958f77c717cb5544b3098000a5ccf61ff03eb5e3d98e462ff625d3c0bb04d899` | `asm/nonmatchings/overlays/level_41/level/func_level_41_8008BB7C.s` |
| `func_level_43_8008CFE0` | nearest polygon neighbor signed products | 161 | `d900a28e643261bfb49344aa02d839405fb6034cd6119dbe76d29db44424eea0` | `asm/nonmatchings/overlays/level_43/level/func_level_43_8008CFE0.s` |
| `func_level_46_8008B8F8` | nearest polygon neighbor signed products | 161 | `f11f38675ac49d495a25aa67f14cc8f78e19e0505fa17dc9b9ad61d3ea68a563` | `asm/nonmatchings/overlays/level_46/level/func_level_46_8008B8F8.s` |
