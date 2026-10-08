# Verified overlay batch 2026-10-08-B

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Original access widths, constants and branch conditions are preserved. Raw units, helper meanings and runtime cadence remain unresolved. Confidence: exact compiled bytes.

Accepted 3 functions, 2040 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch3923.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Actual verified C baselines: src/overlays/level_18/moby.c func_level_18_80074A54 for actors20/31, and src/overlays/level_46/moby.c func_level_46_80087AE8 for actor44. Original differences: build/sibling3917.*.json. Empty constraints retain original callback register6 and frame/register roles; no literal opcode assembly or patches. Native-exact probes3921/3922; accepted combined batch3923. Cumulative3924: 521 functions, 184 sources, 321377 original owned words, zero mismatches. Strict gate: three translation units, zero failures; full EXE and every overlay hash and owned-format audit passed.

Categories: {'Verified actor18 sibling C plus original3917 register roles and 399E8/39B6C paths; raw units/helper meanings unresolved': 2, 'Verified actor46 sibling C plus original3917 removed initialization and distance/angle cleanup path; raw units/helper meanings unresolved': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_20_80074E2C` | Verified actor18 sibling C plus original3917 register roles and 399E8/39B6C paths; raw units/helper meanings unresolved | 814 | `2b1512f3b66320410ee96e025b4e55d5ab15da49cc1cdc1c62537ac0b9811aca` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_80074E2C.s` |
| `func_level_31_800757BC` | Verified actor18 sibling C plus original3917 register roles and 399E8/39B6C paths; raw units/helper meanings unresolved | 814 | `07fd98d70dd1e69b66f27458ae5bbab930c7df66b32f91fc2c589b1d34c0ffce` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_800757BC.s` |
| `func_level_44_80086D50` | Verified actor46 sibling C plus original3917 removed initialization and distance/angle cleanup path; raw units/helper meanings unresolved | 412 | `d9bfd85f9081adf79f76adf0280559b351f6732452ec0928dfd76056a7bab841` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_80086D50.s` |
