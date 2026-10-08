# Verified overlay batch 2026-10-03-5

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 12 functions, 320 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch5.fixed.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'partial record reset': 4, 'conditional partial record reset': 4, 'global state setup': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_11_800880C4` | partial record reset | 22 | `1f64d00402b73c48b9e453417e8bb2201d0eea7b26e7bc8761ebdf5717388684` | `asm/nonmatchings/overlays/level_11/level/func_level_11_800880C4.s` |
| `func_level_22_8009303C` | partial record reset | 22 | `1f64d00402b73c48b9e453417e8bb2201d0eea7b26e7bc8761ebdf5717388684` | `asm/nonmatchings/overlays/level_22/level/func_level_22_8009303C.s` |
| `func_level_32_800936D4` | partial record reset | 22 | `1f64d00402b73c48b9e453417e8bb2201d0eea7b26e7bc8761ebdf5717388684` | `asm/nonmatchings/overlays/level_32/level/func_level_32_800936D4.s` |
| `func_level_50_800962D8` | partial record reset | 22 | `1f64d00402b73c48b9e453417e8bb2201d0eea7b26e7bc8761ebdf5717388684` | `asm/nonmatchings/overlays/level_50/level/func_level_50_800962D8.s` |
| `func_level_11_8008811C` | conditional partial record reset | 29 | `b46856dd1d3b70caa897b696197b73a153223c52fa29b007ca70bbaa0c7a5e3e` | `asm/nonmatchings/overlays/level_11/level/func_level_11_8008811C.s` |
| `func_level_22_80093094` | conditional partial record reset | 29 | `b46856dd1d3b70caa897b696197b73a153223c52fa29b007ca70bbaa0c7a5e3e` | `asm/nonmatchings/overlays/level_22/level/func_level_22_80093094.s` |
| `func_level_32_8009372C` | conditional partial record reset | 29 | `b46856dd1d3b70caa897b696197b73a153223c52fa29b007ca70bbaa0c7a5e3e` | `asm/nonmatchings/overlays/level_32/level/func_level_32_8009372C.s` |
| `func_level_50_80096330` | conditional partial record reset | 29 | `b46856dd1d3b70caa897b696197b73a153223c52fa29b007ca70bbaa0c7a5e3e` | `asm/nonmatchings/overlays/level_50/level/func_level_50_80096330.s` |
| `func_level_11_800885CC` | global state setup | 29 | `eeb580a8de795ae0eb4dce49e19b0d4967a7e709a8db05bc003fa92f8764f8bd` | `asm/nonmatchings/overlays/level_11/level/func_level_11_800885CC.s` |
| `func_level_22_80093544` | global state setup | 29 | `eeb580a8de795ae0eb4dce49e19b0d4967a7e709a8db05bc003fa92f8764f8bd` | `asm/nonmatchings/overlays/level_22/level/func_level_22_80093544.s` |
| `func_level_32_800937A0` | global state setup | 29 | `eeb580a8de795ae0eb4dce49e19b0d4967a7e709a8db05bc003fa92f8764f8bd` | `asm/nonmatchings/overlays/level_32/level/func_level_32_800937A0.s` |
| `func_level_50_800963A4` | global state setup | 29 | `eeb580a8de795ae0eb4dce49e19b0d4967a7e709a8db05bc003fa92f8764f8bd` | `asm/nonmatchings/overlays/level_50/level/func_level_50_800963A4.s` |
