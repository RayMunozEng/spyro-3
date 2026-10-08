# Verified overlay batch 2026-10-04-546

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 244 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch546.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes: both routines match as ordinary C. The level 31 routine preserves the two damage masks, vector callbacks, class 0x10 spawn, conditional halfword adjustments, three states, timer reload and completion deletion. The level 34 routine preserves standing-on-actor checks, damage transitions, collision-field clearing, animation calls and completion deletion. No invented behavior or scheduling constraints are added.

Categories: {'damage vector callbacks three-state timer movement and deletion': 1, 'damage and player standing gated platform states collision fields and deletion': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_31_8007DD18` | damage vector callbacks three-state timer movement and deletion | 121 | `ccd7da283b12bc334cd7db5350aa5635afcc8fc9136f39c545836f2fa147661e` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_8007DD18.s` |
| `func_level_34_8008CBFC` | damage and player standing gated platform states collision fields and deletion | 123 | `75a66037e54e6fe5fa2394f322134bfc0eafd904f99e3275943cebb0a3fd2408` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_8008CBFC.s` |
