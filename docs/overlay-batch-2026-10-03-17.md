# Verified overlay batch 2026-10-03-17

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 6 functions, 269 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch17.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'typed small routine reconstructed from retail instructions': 6}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_24_8007CF6C` | typed small routine reconstructed from retail instructions | 41 | `39d0ad5f68952ea0e4b77d317ccf39f2f8774f94304d08f77d1e0172189b6e9e` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8007CF6C.s` |
| `func_level_33_8009649C` | typed small routine reconstructed from retail instructions | 58 | `cdaa1030173f360d24e45e97355e387133b73301c296e5fee6382f3504459114` | `asm/nonmatchings/overlays/level_33/level/func_level_33_8009649C.s` |
| `func_level_20_80080904` | typed small routine reconstructed from retail instructions | 34 | `9ae3b542f7872b1f1e76cd00d872537a7dee67d9dde238b4836a4f16951cb358` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_80080904.s` |
| `func_level_37_80080FC0` | typed small routine reconstructed from retail instructions | 41 | `7c8d6a89699575a1823b28896307e631548c5bdd1a479c98f7d4e832444ffd43` | `asm/nonmatchings/overlays/level_37/moby/func_level_37_80080FC0.s` |
| `func_level_23_8008628C` | typed small routine reconstructed from retail instructions | 43 | `739c0c79bca2c517d6ee413de627ffbf1e546c952adabac84b28a7a2b6d64aac` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_8008628C.s` |
| `func_level_44_80085D68` | typed small routine reconstructed from retail instructions | 52 | `32dc86a918272675264820747176e6fca19cfe75015bed6596cae526852ea9a7` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_80085D68.s` |
