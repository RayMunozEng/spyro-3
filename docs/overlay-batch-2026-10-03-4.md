# Verified overlay batch 2026-10-03-4

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 21 functions, 467 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch4.verified.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'table bit test and cleanup': 11, 'stored input and angle helper': 4, 'signed bound and flag reset': 4, 'state gated deletion': 1, 'first update animation setup': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_11_8007ADE0` | table bit test and cleanup | 27 | `ea01aedd330dbf4027fadb8711e6a895bee4c9553b579b0b50257c379819042d` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_8007ADE0.s` |
| `func_level_13_80082524` | table bit test and cleanup | 27 | `ea01aedd330dbf4027fadb8711e6a895bee4c9553b579b0b50257c379819042d` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_80082524.s` |
| `func_level_14_8007AD18` | table bit test and cleanup | 27 | `ea01aedd330dbf4027fadb8711e6a895bee4c9553b579b0b50257c379819042d` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_8007AD18.s` |
| `func_level_22_80084920` | table bit test and cleanup | 27 | `ea01aedd330dbf4027fadb8711e6a895bee4c9553b579b0b50257c379819042d` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_80084920.s` |
| `func_level_23_8007B6B4` | table bit test and cleanup | 27 | `ea01aedd330dbf4027fadb8711e6a895bee4c9553b579b0b50257c379819042d` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_8007B6B4.s` |
| `func_level_24_8007D41C` | table bit test and cleanup | 27 | `ea01aedd330dbf4027fadb8711e6a895bee4c9553b579b0b50257c379819042d` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8007D41C.s` |
| `func_level_31_8007D97C` | table bit test and cleanup | 27 | `ea01aedd330dbf4027fadb8711e6a895bee4c9553b579b0b50257c379819042d` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_8007D97C.s` |
| `func_level_33_8007D254` | table bit test and cleanup | 27 | `ea01aedd330dbf4027fadb8711e6a895bee4c9553b579b0b50257c379819042d` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_8007D254.s` |
| `func_level_34_8007E714` | table bit test and cleanup | 27 | `ea01aedd330dbf4027fadb8711e6a895bee4c9553b579b0b50257c379819042d` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_8007E714.s` |
| `func_level_43_8007B2C8` | table bit test and cleanup | 27 | `ea01aedd330dbf4027fadb8711e6a895bee4c9553b579b0b50257c379819042d` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_8007B2C8.s` |
| `func_level_44_8007B2D4` | table bit test and cleanup | 27 | `ea01aedd330dbf4027fadb8711e6a895bee4c9553b579b0b50257c379819042d` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_8007B2D4.s` |
| `func_level_18_80087D74` | stored input and angle helper | 22 | `6186f6123b973cd78b183960d14634db2850cf246c9dab5588a9b61f7cdd9640` | `asm/nonmatchings/overlays/level_18/animation/func_level_18_80087D74.s` |
| `func_level_28_80085EC4` | stored input and angle helper | 22 | `6186f6123b973cd78b183960d14634db2850cf246c9dab5588a9b61f7cdd9640` | `asm/nonmatchings/overlays/level_28/animation/func_level_28_80085EC4.s` |
| `func_level_38_800880F4` | stored input and angle helper | 22 | `6186f6123b973cd78b183960d14634db2850cf246c9dab5588a9b61f7cdd9640` | `asm/nonmatchings/overlays/level_38/animation/func_level_38_800880F4.s` |
| `func_level_48_8008712C` | stored input and angle helper | 22 | `6186f6123b973cd78b183960d14634db2850cf246c9dab5588a9b61f7cdd9640` | `asm/nonmatchings/overlays/level_48/animation/func_level_48_8008712C.s` |
| `func_level_11_80088640` | signed bound and flag reset | 14 | `e426899b7146fb55a81dc282463d33cc6212f3257d1a2e87eeb0fad2da4db98a` | `asm/nonmatchings/overlays/level_11/level/func_level_11_80088640.s` |
| `func_level_14_8008B798` | state gated deletion | 12 | `b98d81786892d30abc6605fb0f147000a3bd6ca7b87af114c9fecebefc5e1d6c` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_8008B798.s` |
| `func_level_22_800935B8` | signed bound and flag reset | 14 | `9914553167083216cb901e24eae61c2b97237aeeb3d597ea422db171ccad9387` | `asm/nonmatchings/overlays/level_22/level/func_level_22_800935B8.s` |
| `func_level_23_80088A34` | first update animation setup | 14 | `5aa1a1095b62631f8097e791a31585a31c426e43fa038d91ad1a0eb6800560fd` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_80088A34.s` |
| `func_level_32_80093814` | signed bound and flag reset | 14 | `6d0954af82bfee229a83ec2368793ec05dccd582275d0ea01d638177efbfcfb7` | `asm/nonmatchings/overlays/level_32/level/func_level_32_80093814.s` |
| `func_level_50_80096418` | signed bound and flag reset | 14 | `374ce18d17207e2cc72f47825a1ef86f31831e9942911471a98d12f13cea75c2` | `asm/nonmatchings/overlays/level_50/level/func_level_50_80096418.s` |
