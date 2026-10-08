# Verified overlay batch 2026-10-03-206

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 244 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch206.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Camera selectors reuse the verified mode/override/input/animation-table baselines. Modes 4/0x11 retain distinct fallback paths in two overlay copies, while modes 5/0x22 preserve their initial current-state value and selector-6 fallback in level 31. The animation selector preserves all 15 cases 0x41..0x4F and the original extra zero table-padding word. Cases 0x47/0x48 test player word 0xB8 before choosing the null or player-0xCC vector. SDK symbol aliases and empty constraints preserve original load order and separate constant-address setup without emitting instructions. Numeric selectors and unknown field meanings remain explicit.

Categories: {'two-mode camera selector with input and override paths': 2, 'two-mode camera selector with override and fallback': 1, 'animation selector with conditional vector branch': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_20_8008C438` | two-mode camera selector with input and override paths | 70 | `c1f6ff2fc6e4aed3c854b92d90900c2f4ed61283eaea9dcad75a4d3028ad0a3e` | `asm/nonmatchings/overlays/level_20/camera/func_level_20_8008C438.s` |
| `func_level_30_8008D1C0` | two-mode camera selector with input and override paths | 70 | `b555001798c2b2177930abc7c40b271f3ca050ad3d7c34586562ceaeb3d55112` | `asm/nonmatchings/overlays/level_30/camera/func_level_30_8008D1C0.s` |
| `func_level_31_8008FA28` | two-mode camera selector with override and fallback | 52 | `654e36470b4b203d34ad86df5df8e2654f7aff0b38604cc5395759d16f207478` | `asm/nonmatchings/overlays/level_31/camera/func_level_31_8008FA28.s` |
| `func_level_16_80084B0C` | animation selector with conditional vector branch | 52 | `c70e7e89741dca6f309fd36cfca8e85d216570352133f29680e02357679f1209` | `asm/nonmatchings/overlays/level_16/animation/func_level_16_80084B0C.s` |
