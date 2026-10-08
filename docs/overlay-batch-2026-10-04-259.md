# Verified overlay batch 2026-10-04-259

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 14 functions, 1834 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch259.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- Fourteen identical descriptor-update routines preserve descriptor stride 20, selector-byte indirection, enabled byte 0x10, threshold halfword 0xA, distance and signed Z calculations, the original `(value << 2) - value` scaling, timer ranges and callback handles.
- The attachment helper writes an index used with a 16-byte record stride. The copied position is exactly the original producer/consumer path; no new world-coordinate conversion is inferred.
- Partial declarations describe only the fields read by this routine. Empty constraints preserve actor, Z, distance and comparison register allocation without emitting instructions. Existing callback names remain unreviewed semantic labels.

Categories: {'descriptor gated callback, timer selector and attachment position': 14}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_80081AA0` | descriptor gated callback, timer selector and attachment position | 131 | `33b738d8ddf813cc26bf9925e996293c440eec5d8f5b0c89fe3f8b73b6dd34c8` | `asm/nonmatchings/overlays/level_10/moby/func_level_10_80081AA0.s` |
| `func_level_11_8007B17C` | descriptor gated callback, timer selector and attachment position | 131 | `87fd113688a2e04663c1a9cc98fa928709f3909dd9d9fd4d24c440c7268b7894` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_8007B17C.s` |
| `func_level_12_80082828` | descriptor gated callback, timer selector and attachment position | 131 | `4b2bc7292ea933cdc36875d897e5b4342d99bff8b282995a732f0b4d93112605` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_80082828.s` |
| `func_level_16_8007CDC0` | descriptor gated callback, timer selector and attachment position | 131 | `5204f93204ed01134743b9a03c753121095e50bcd011e58ba5a36f706988d6e3` | `asm/nonmatchings/overlays/level_16/moby/func_level_16_8007CDC0.s` |
| `func_level_20_80082B0C` | descriptor gated callback, timer selector and attachment position | 131 | `20b0fb06b1593f08da835e74d07190dcb08ab0396b1dc6320c69bd80b355db48` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_80082B0C.s` |
| `func_level_21_800839F4` | descriptor gated callback, timer selector and attachment position | 131 | `c75302dc2d3266f2b42ef9b375acf69052c95c0e0302031a3ce161e9f97a081b` | `asm/nonmatchings/overlays/level_21/moby/func_level_21_800839F4.s` |
| `func_level_23_8007BA50` | descriptor gated callback, timer selector and attachment position | 131 | `d0eb38425d34b2191ee5be99a7e3be655f35bb7db2c0d259098f86a842aaab13` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_8007BA50.s` |
| `func_level_24_8007DBF0` | descriptor gated callback, timer selector and attachment position | 131 | `9ed00fb22178ba288195b47038fb0d11d31c3277db389d85eb93352b2ea3306d` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8007DBF0.s` |
| `func_level_25_8007E224` | descriptor gated callback, timer selector and attachment position | 131 | `430a969e05cb39185ac8a0ec4047eb58d802be338ca566465cbcf1fd9c19c890` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_8007E224.s` |
| `func_level_32_8008C0C8` | descriptor gated callback, timer selector and attachment position | 131 | `3b836a9e18150360baa235784b55c25c8a3fb8a6f4a23fd19c75242ef59bd04c` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_8008C0C8.s` |
| `func_level_35_8007D140` | descriptor gated callback, timer selector and attachment position | 131 | `85e23e90f9a2f873a949e19f191b2cd5b3c42e354ed30cd30efbed77aa6d0d11` | `asm/nonmatchings/overlays/level_35/moby/func_level_35_8007D140.s` |
| `func_level_40_800809D8` | descriptor gated callback, timer selector and attachment position | 131 | `46524a611f7bb51d02da8c8aea2d7b4e2b181337d4ae05c63c1897e7ccc1dbf2` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_800809D8.s` |
| `func_level_45_8007CA3C` | descriptor gated callback, timer selector and attachment position | 131 | `68ed8e225dc201d357ec5793e72ce534c626c5f09e46ca72a936df5f4d617d4e` | `asm/nonmatchings/overlays/level_45/moby/func_level_45_8007CA3C.s` |
| `func_level_50_800872C8` | descriptor gated callback, timer selector and attachment position | 131 | `d63a6371d31c6e32e688b0cfbd6e4d0ff5c08d49eedb7522c72d2bf217744576` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_800872C8.s` |
