# Verified overlay batch 2026-10-03-133

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 5 functions, 227 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch133.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: upstream `SpriteDefinition`, `SpriteData`, `WadHeader`, `Spyro` and camera/drawing/CD helper declarations. The rectangle routines read unsigned byte bounds, add one to width/height, centre integer X at 256 using signed right shift, then call the original three drawing helpers. Empty constraints preserve register allocation and scheduling without emitting instructions. The camera routines preserve mode 3, override/bit-test priority, word-indexed animation-state lookup and zero-result fallback to mode 6; the current mode is reloaded in its original location. The archive read uses buffer byte displacement (index&1)*0xB800 and archive byte displacement index*0xB800. Its original WAD field is +0x5A8, named `epilogueImgs.offset` by upstream; an initially wrong +0x5A0 candidate was rejected by the complete hash gate and corrected before acceptance. Units are original integer drawing coordinates and archive bytes; no external asset interpretation is inferred. Invocation cadence is unresolved. Next evidence target: sprite producers, camera override/table consumers, and archive payload identity.

Categories: {'sprite rectangle and draw sequence': 2, 'camera state selection': 2, 'atlas asynchronous archive read': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_options_80078010` | sprite rectangle and draw sequence | 52 | `9333f1f9e3db8513d4869a0db1f94f9f785f4e6ddd518bbef3b1927f45b65a49` | `asm/nonmatchings/overlays/options/options3/func_options_80078010.s` |
| `func_title_8007AA54` | sprite rectangle and draw sequence | 52 | `9333f1f9e3db8513d4869a0db1f94f9f785f4e6ddd518bbef3b1927f45b65a49` | `asm/nonmatchings/overlays/title/title4/func_title_8007AA54.s` |
| `func_level_15_80089C64` | camera state selection | 48 | `40458c363dc613b330edcb4db06fa2f3ba529c4d4a1197911eba645bd2d462fc` | `asm/nonmatchings/overlays/level_15/camera/func_level_15_80089C64.s` |
| `func_level_45_800899F8` | camera state selection | 48 | `40458c363dc613b330edcb4db06fa2f3ba529c4d4a1197911eba645bd2d462fc` | `asm/nonmatchings/overlays/level_45/camera/func_level_45_800899F8.s` |
| `func_atlas_80075C3C` | atlas asynchronous archive read | 27 | `499cbab11230eaeb6e323e4ded6979e00b7253948dbf04c4ce0a302ad35bbb62` | `asm/nonmatchings/overlays/atlas/atlas1/func_atlas_80075C3C.s` |
