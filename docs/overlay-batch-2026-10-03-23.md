# Verified overlay batch 2026-10-03-23

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 9 functions, 684 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch23.fixed2.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline: `include/overlay/animation.inc.h`, `PlaySpyroSounds`; the shared critter selector uses integer locals. Each added routine keeps its own exact retail sound condition and existing upstream types. Sound-table field names are inherited labels, not independent proof of audible meaning.

Categories: {'upstream animation selector with retail sound condition': 9}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_80089B9C` | upstream animation selector with retail sound condition | 76 | `4606213c4db28da128eb8dbc6387f0a01d6891e0c738524d27d6397e71978024` | `asm/nonmatchings/overlays/level_10/animation/func_level_10_80089B9C.s` |
| `func_level_12_80089FE4` | upstream animation selector with retail sound condition | 76 | `f225b563aff276cd99e8839b8410d2f8f0d47a816e9a55f28bb5bfe682bbf099` | `asm/nonmatchings/overlays/level_12/animation/func_level_12_80089FE4.s` |
| `func_level_14_80096874` | upstream animation selector with retail sound condition | 76 | `36eda7263a6aca153396be2ef75c67ff33f96cc5963e3a4968901cb659ad1eea` | `asm/nonmatchings/overlays/level_14/animation/func_level_14_80096874.s` |
| `func_level_17_80082DC4` | upstream animation selector with retail sound condition | 76 | `28ec499571c96b7dca8af69294f7f151d75ee67eaacb8a799d9c37478c621e39` | `asm/nonmatchings/overlays/level_17/animation/func_level_17_80082DC4.s` |
| `func_level_25_800882C4` | upstream animation selector with retail sound condition | 76 | `aaa0fb54064e5c5b7eaac94ca4900512322c5868d3c78eec4dcaa13f64f0a07a` | `asm/nonmatchings/overlays/level_25/animation/func_level_25_800882C4.s` |
| `func_level_27_80088940` | upstream animation selector with retail sound condition | 76 | `3503afd8b25a852a88c48dfa9aa5694128962e76370637ac224b19a7fc675763` | `asm/nonmatchings/overlays/level_27/animation/func_level_27_80088940.s` |
| `func_level_35_8008A808` | upstream animation selector with retail sound condition | 76 | `0592527fd8e5ac2af94a647f584dac4f1be8698ae6a2a40f60e041def828e3f5` | `asm/nonmatchings/overlays/level_35/animation/func_level_35_8008A808.s` |
| `func_level_45_800882C8` | upstream animation selector with retail sound condition | 76 | `2ab3bbcfe714fee1e712ed935fa6ed4bc8e132365faa2622ca4b5c0b6d28ec6d` | `asm/nonmatchings/overlays/level_45/animation/func_level_45_800882C8.s` |
| `func_level_47_8008CC44` | upstream animation selector with retail sound condition | 76 | `d1fb987f54ce9584936b7d07497933b0d6656c8dceecef689a3a71cbbb83e19f` | `asm/nonmatchings/overlays/level_47/animation/func_level_47_8008CC44.s` |

## Overlay table build correction

The preliminary object comparison had included `.rodata` words in its instruction stream. The corrected scratch comparison checks text separately; acceptance still verifies all original instruction and table words plus complete retail hashes.

The build previously collected compiler tables in `.rodata.jtbl` after the assembly `.rodata` tables. `build_multiproc.py` now supplies the overlay source identity to `tools/fix_jtbl_align.py`. The filter preserves table declaration order in `.rodata`, checks its entry count against the corresponding original function assembly, and emits only the explicitly recorded zero padding. Missing metadata or different entry counts stop compilation. The EXE section policy stays unchanged.

Evidence examples: `func_level_10_80089B9C.s` records nine entries at `0x80074AF0` and a zero word at `0x80074B14`; `func_level_15_800886FC.s` records nine entries at `0x80074988` without a trailing zero word. Both cases are covered by `tools/test_fix_jtbl_align.py`, alongside the existing EXE policy and rejection of a wrong entry count. The final complete hash gate is recorded above.
