# Verified overlay batch 2026-10-03-11

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 15 functions, 1020 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch11.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'animation accumulator and byte frame wrap': 15}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_13_80085640` | animation accumulator and byte frame wrap | 68 | `60a49acf9e9e681f4a651e2a5747fd9b9862e1c2b74060b53d810b3c890f8628` | `asm/nonmatchings/overlays/level_13/level/func_level_13_80085640.s` |
| `func_level_18_800842E4` | animation accumulator and byte frame wrap | 68 | `2c3302558849376313d0aabcab2e01507998513f71d0d4ad8c9d2b35ed2f5f62` | `asm/nonmatchings/overlays/level_18/level/func_level_18_800842E4.s` |
| `func_level_22_80090138` | animation accumulator and byte frame wrap | 68 | `9d5fe2d18bcdb54909e237d2afafcb1a933ec88cdcef92543a36b65b259a3381` | `asm/nonmatchings/overlays/level_22/level/func_level_22_80090138.s` |
| `func_level_24_8008DE5C` | animation accumulator and byte frame wrap | 68 | `14acf251181d79d5ec967edc3caa1782b4837b494d329255ce4bb375d2eff874` | `asm/nonmatchings/overlays/level_24/level/func_level_24_8008DE5C.s` |
| `func_level_26_80085CD4` | animation accumulator and byte frame wrap | 68 | `27803a5a9ba9cff0ec71d7683507f3070965fe19f7f607d8907093c90270016d` | `asm/nonmatchings/overlays/level_26/level/func_level_26_80085CD4.s` |
| `func_level_28_80082454` | animation accumulator and byte frame wrap | 68 | `f9e649985dd42b1a797478827964653728f1fd7e92373e4b830212ff580ac9bd` | `asm/nonmatchings/overlays/level_28/level/func_level_28_80082454.s` |
| `func_level_30_80083AD8` | animation accumulator and byte frame wrap | 68 | `f1441774fee5a02cb090584396e1d1ca19f4a72696151a434f103fbc39e2c73d` | `asm/nonmatchings/overlays/level_30/level/func_level_30_80083AD8.s` |
| `func_level_33_80093D08` | animation accumulator and byte frame wrap | 68 | `67d8bc0895edc8f76c4e4f1737bf4509ed13fcdeb86bb51660a63eee4353c034` | `asm/nonmatchings/overlays/level_33/level/func_level_33_80093D08.s` |
| `func_level_34_800902E4` | animation accumulator and byte frame wrap | 68 | `a169d3d9da7930d7fc0ebae649d7e25bfa5a4aafa9dc081484fa8ede92bf093f` | `asm/nonmatchings/overlays/level_34/level/func_level_34_800902E4.s` |
| `func_level_36_8008077C` | animation accumulator and byte frame wrap | 68 | `1a8c485274f78e2732fe5caa0ec6cd534e58764bc104bd0bd98f67b61aac1b66` | `asm/nonmatchings/overlays/level_36/level/func_level_36_8008077C.s` |
| `func_level_41_80089D7C` | animation accumulator and byte frame wrap | 68 | `74a30005a68b6e3e06dd13110b759a24b761db94cf7d449e37f4dab6b2ed4d2b` | `asm/nonmatchings/overlays/level_41/level/func_level_41_80089D7C.s` |
| `func_level_43_8008BE00` | animation accumulator and byte frame wrap | 68 | `c313fda70a1e467dca7e886ad32860c95a1e7ed1d33122531e5d9dfc6ba5a8e0` | `asm/nonmatchings/overlays/level_43/level/func_level_43_8008BE00.s` |
| `func_level_44_800896DC` | animation accumulator and byte frame wrap | 68 | `a157b68e9075e05c68bb915bb5aef8d393a6f83760d34edf95f5de3ef37403ea` | `asm/nonmatchings/overlays/level_44/level/func_level_44_800896DC.s` |
| `func_level_46_80089F7C` | animation accumulator and byte frame wrap | 68 | `a3b8ff74eeb8466369f18a00fca569ea7744ac0ff5de79f52107279bb1680819` | `asm/nonmatchings/overlays/level_46/level/func_level_46_80089F7C.s` |
| `func_level_48_800836BC` | animation accumulator and byte frame wrap | 68 | `aff2d3c00aa75ba4fa3d7b2c7cb8277d09c11562037c3d71d6784336f43fe38b` | `asm/nonmatchings/overlays/level_48/level/func_level_48_800836BC.s` |
