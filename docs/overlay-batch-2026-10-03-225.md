# Verified overlay batch 2026-10-03-225

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 228 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch225.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The actor update retains the original two progress-bit gates, Z-word colour copy, state transition, signed counter increment 0x20, Z decrement 0x20, helper selector 2 and deletion threshold 0x1000. The cutscene routine retains its global threshold 0x2BC, exactly eight iterations, three independent rand() masks 0x3FF minus 0x200, vector helper selector 0x14, position Z offset -0x80 and numeric particle arguments. The options dispatcher follows the original nested switches and numeric helper calls. The sparse animation selector retains its 26-entry table including original return gaps, selectors 0x13/0x2B/0x2C, and record stride 16. No new labels for particle meaning, colour semantics or animation behavior are inferred; source instructions and table entries are the authority.

Categories: {'progress gate and actor vertical countdown': 1, 'cutscene gated eight random vector particles': 1, 'options mode and menu drawing dispatcher': 1, 'animation sparse selector and record pointer': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_13_80081CD8` | progress gate and actor vertical countdown | 57 | `dbed79e7a29b9489eec13829dfd11d010eb3b887b0c14aea6db7b17faa17949c` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_80081CD8.s` |
| `func_cutscene_77_80074788` | cutscene gated eight random vector particles | 58 | `9b3dfbabfedbe60a257e41abbf9cad21ac3b346ac851a8d0c8ec30812b62cf32` | `asm/nonmatchings/overlays/cutscene_77/moby/func_cutscene_77_80074788.s` |
| `func_options_80075A38` | options mode and menu drawing dispatcher | 56 | `6dccffd5b389c43e7e1dd0ff6cd1357380a310199926437145dda5ff768a84f4` | `asm/nonmatchings/overlays/options/options1/func_options_80075A38.s` |
| `func_level_10_80089CA4` | animation sparse selector and record pointer | 57 | `8cc9abc27c5d392a0227d0eee286ec69a932a4c8879032daeae9522e11b089fa` | `asm/nonmatchings/overlays/level_10/animation/func_level_10_80089CA4.s` |
