# Verified overlay batch 2026-10-03-27

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 8 functions, 1252 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch27.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: the original upstream `include/overlay/animation.inc.h` implementation, instantiated using the existing level macro and original function symbol. Binary matching verifies these sound-selector slots; it does not establish a complete semantic audio decode.

Categories: {'existing upstream animation sound template': 8}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_20_8008AC84` | existing upstream animation sound template | 200 | `b6120f67f53c17e79fc915f5fc5d1e04742ced5fcf97a969463ca07826989d0b` | `asm/nonmatchings/overlays/level_20/animation/func_level_20_8008AC84.s` |
| `func_level_23_800937D4` | existing upstream animation sound template | 133 | `45028ed4f1c1c4095d0006367f1f43e6aff9b896bc8dd436f26a83b3408748d1` | `asm/nonmatchings/overlays/level_23/animation/func_level_23_800937D4.s` |
| `func_level_30_8008A778` | existing upstream animation sound template | 153 | `36f779f46103a312655e99b556b6e7eea376ed455dc8642dfbc1ddc1bb5bd8e4` | `asm/nonmatchings/overlays/level_30/animation/func_level_30_8008A778.s` |
| `func_level_33_8009B598` | existing upstream animation sound template | 164 | `8c6c758f90cc5cd45f7413cb68dedd124f94970bd7f206672ee333a2e2e7e179` | `asm/nonmatchings/overlays/level_33/animation/func_level_33_8009B598.s` |
| `func_level_34_80096828` | existing upstream animation sound template | 138 | `27406951cccf2540d388b4257d8e55db33bf95b543519b5b4cb8d5b1290d309d` | `asm/nonmatchings/overlays/level_34/animation/func_level_34_80096828.s` |
| `func_level_42_8008C968` | existing upstream animation sound template | 158 | `43d5b4b45bea5079ca139c8a80dd52cdf8db958225f601d3fdb29723165fb689` | `asm/nonmatchings/overlays/level_42/animation/func_level_42_8008C968.s` |
| `func_level_43_800930D4` | existing upstream animation sound template | 153 | `c1e9aaa5a51e04ee344390f9b66fd0ef4e8d2837e1225bb74089b8762c51c6be` | `asm/nonmatchings/overlays/level_43/animation/func_level_43_800930D4.s` |
| `func_level_44_8009090C` | existing upstream animation sound template | 153 | `27d4d75bf78388653b38cc075ed7683682d58ad26b1e87ff38266dede68bf22a` | `asm/nonmatchings/overlays/level_44/animation/func_level_44_8009090C.s` |
