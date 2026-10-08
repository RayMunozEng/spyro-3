# Verified overlay batch 2026-10-04-242

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 7 functions, 685 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch242.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- Six identical vector-query routines retain subtraction, the conditional Z offset of 0x80, length-derived segment count, three signed divisions, and the original per-segment query arguments. The original frame size is 0x68; no speculative stack reservation is needed. Each copy is independently checked against its original instructions and complete overlay hash.
- `func_level_35_8008C244` reuses the verified camera initializer template with mode-specific byte flags. The full linked audit identified that the first two branches must enter the shared flag-clearing tail before the vector helpers; the corrected branches match the original jump targets exactly.

Categories: {'segmented vector query with original division and actor parameter': 6, 'three-mode camera initializer with original flag combinations': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_33_80095B78` | segmented vector query with original division and actor parameter | 102 | `4531d985b13eb3400e334a1eeb93a1e5c783552fa44da16c9d55d0ca01c41ace` | `asm/nonmatchings/overlays/level_33/level/func_level_33_80095B78.s` |
| `func_level_43_8008D96C` | segmented vector query with original division and actor parameter | 102 | `4531d985b13eb3400e334a1eeb93a1e5c783552fa44da16c9d55d0ca01c41ace` | `asm/nonmatchings/overlays/level_43/level/func_level_43_8008D96C.s` |
| `func_level_44_8008AB08` | segmented vector query with original division and actor parameter | 102 | `4531d985b13eb3400e334a1eeb93a1e5c783552fa44da16c9d55d0ca01c41ace` | `asm/nonmatchings/overlays/level_44/level/func_level_44_8008AB08.s` |
| `func_level_46_8008BDAC` | segmented vector query with original division and actor parameter | 102 | `4531d985b13eb3400e334a1eeb93a1e5c783552fa44da16c9d55d0ca01c41ace` | `asm/nonmatchings/overlays/level_46/level/func_level_46_8008BDAC.s` |
| `func_level_47_800892DC` | segmented vector query with original division and actor parameter | 102 | `4531d985b13eb3400e334a1eeb93a1e5c783552fa44da16c9d55d0ca01c41ace` | `asm/nonmatchings/overlays/level_47/level/func_level_47_800892DC.s` |
| `func_level_50_800958EC` | segmented vector query with original division and actor parameter | 102 | `4531d985b13eb3400e334a1eeb93a1e5c783552fa44da16c9d55d0ca01c41ace` | `asm/nonmatchings/overlays/level_50/level/func_level_50_800958EC.s` |
| `func_level_35_8008C244` | three-mode camera initializer with original flag combinations | 73 | `40b392297452cd9597200f343bf45ab59697ee13c22a395ea6ba7a7225f87626` | `asm/nonmatchings/overlays/level_35/camera/func_level_35_8008C244.s` |
