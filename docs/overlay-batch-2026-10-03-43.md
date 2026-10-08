# Verified overlay batch 2026-10-03-43

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 8 functions, 308 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch43.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'four eight-byte sprite animation records': 4, 'camera state and animation table selection': 4}.

## Widths and scheduling

Sprite initialization writes four records with an eight-byte stride: a halfword index followed by byte animation type and frame. The camera selectors preserve the second read of the mode word, the animation-indexed table lookup, and the exact zero fallback. Empty constraints preserve compiler scheduling and emit no instructions. Constants and table indices come from the assembly listed below, once per invocation. Their wider gameplay interpretation remains outside this binary-match batch.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_15_80083190` | four eight-byte sprite animation records | 41 | `424723ab62d14972b9c30f16c879c633863b4c91803c4c0cf19e8e7820546519` | `asm/nonmatchings/overlays/level_15/level/func_level_15_80083190.s` |
| `func_level_25_80083B48` | four eight-byte sprite animation records | 41 | `424723ab62d14972b9c30f16c879c633863b4c91803c4c0cf19e8e7820546519` | `asm/nonmatchings/overlays/level_25/level/func_level_25_80083B48.s` |
| `func_level_35_80084ECC` | four eight-byte sprite animation records | 41 | `424723ab62d14972b9c30f16c879c633863b4c91803c4c0cf19e8e7820546519` | `asm/nonmatchings/overlays/level_35/level/func_level_35_80084ECC.s` |
| `func_level_45_80083488` | four eight-byte sprite animation records | 41 | `424723ab62d14972b9c30f16c879c633863b4c91803c4c0cf19e8e7820546519` | `asm/nonmatchings/overlays/level_45/level/func_level_45_80083488.s` |
| `func_level_18_800880F4` | camera state and animation table selection | 36 | `05d22b6b8943731ca8687162738f60942285ecbdbe4ba690361ad3bef1a9b7bf` | `asm/nonmatchings/overlays/level_18/camera/func_level_18_800880F4.s` |
| `func_level_28_80086244` | camera state and animation table selection | 36 | `05d22b6b8943731ca8687162738f60942285ecbdbe4ba690361ad3bef1a9b7bf` | `asm/nonmatchings/overlays/level_28/camera/func_level_28_80086244.s` |
| `func_level_38_80088474` | camera state and animation table selection | 36 | `05d22b6b8943731ca8687162738f60942285ecbdbe4ba690361ad3bef1a9b7bf` | `asm/nonmatchings/overlays/level_38/camera/func_level_38_80088474.s` |
| `func_level_48_800874AC` | camera state and animation table selection | 36 | `05d22b6b8943731ca8687162738f60942285ecbdbe4ba690361ad3bef1a9b7bf` | `asm/nonmatchings/overlays/level_48/camera/func_level_48_800874AC.s` |
