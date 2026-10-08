# Verified overlay batch 2026-10-04-245

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 5 functions, 500 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch245.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- Five identical routines retain the delta-time timer, 0x3C lifetime, signed Z decrement, vector addition and integer colour scaling. Existing `Colour` supplies the four-byte layout; a partial tag records only accessed fields.
- The optional secondary pointer keeps its callback on expiration and the original three byte writes at offsets 0x68..0x6A. Their broader semantic interpretation remains unreviewed.
- All five copies compiled from the same body and were audited independently at their original linked addresses.

Categories: {'timed vector and colour updates with secondary callback': 5}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_8007D62C` | timed vector and colour updates with secondary callback | 100 | `ed37256fa4f1fee37aa1de08900bbc2c3fb06c0453e8345e71b27eeadf2e752f` | `asm/nonmatchings/overlays/level_10/moby/func_level_10_8007D62C.s` |
| `func_level_20_8007D094` | timed vector and colour updates with secondary callback | 100 | `5b36bba258a8a8c39fabfd4e11db3f33e09e08ab63fcfff5c70be5713fc1ec45` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_8007D094.s` |
| `func_level_30_8007C6D4` | timed vector and colour updates with secondary callback | 100 | `a2cac705b8235afb138bd47616ed2d643fe4666f28e5aec3845d96e5ed8230d5` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_8007C6D4.s` |
| `func_level_40_8007BE30` | timed vector and colour updates with secondary callback | 100 | `8a5371eff917ac2e04055f6a3618514228d89c8b933566c1f9df9ddec8ecc8aa` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_8007BE30.s` |
| `func_level_50_80086E08` | timed vector and colour updates with secondary callback | 100 | `c9ebbf7fc801740ce1189bdd6de83317c1db4b43b9501ba98b90906b6d7ac769` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_80086E08.s` |
