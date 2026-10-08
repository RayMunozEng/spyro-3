# Verified overlay batch 2026-10-04-645

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 6 functions, 1008 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch645.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream Moby fields, Colour type and spawn helper. Six copies were compiled individually with their own original seven-byte choice table. The original instructions define source-state overrides, random colours, spawn capacity, per-type lifetimes and aligned colour-word transfers. Empty allocation constraints emit no instructions; the unused eight-byte stack reservation preserves the recorded retail stack frame.

Categories: {'table selected fragment types colour and lifetime': 6}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_25_80080558` | table selected fragment types colour and lifetime | 168 | `e1f31e99ffb1a89d148beea81f9b36efaa2a95c6237356aa22fd88ca09770ef9` | `asm/nonmatchings/overlays/level_25/level/func_level_25_80080558.s` |
| `func_level_32_800906F0` | table selected fragment types colour and lifetime | 168 | `ae1b35031342c6842ed3db84039b19554e5573202d80c845d04f0a0a914a92ce` | `asm/nonmatchings/overlays/level_32/level/func_level_32_800906F0.s` |
| `func_level_35_800818DC` | table selected fragment types colour and lifetime | 168 | `b184479f59813c0691bd4df666334bd59be8e6a187da353f68d67da95cf16adb` | `asm/nonmatchings/overlays/level_35/level/func_level_35_800818DC.s` |
| `func_level_45_8007FE98` | table selected fragment types colour and lifetime | 168 | `c8dfc0e11600278f13181166099a8406cc56cf71298022798bb5e608300c116f` | `asm/nonmatchings/overlays/level_45/level/func_level_45_8007FE98.s` |
| `func_level_46_8008A08C` | table selected fragment types colour and lifetime | 168 | `105244878d0e816198e58b18b7d3d04dd9386ede9f4a4d9cd877a48797e5a88d` | `asm/nonmatchings/overlays/level_46/level/func_level_46_8008A08C.s` |
| `func_level_50_80092EA8` | table selected fragment types colour and lifetime | 168 | `0799d3d48772e2b28603249b1529fe52353d42445a1de0bc064094390c5ee94c` | `asm/nonmatchings/overlays/level_50/level/func_level_50_80092EA8.s` |
