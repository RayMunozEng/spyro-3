# Verified overlay batch 2026-10-03-98

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 196 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch98.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Existing upstream Spyro and Vector3D layouts are the baseline.

## Widths, scheduling and remaining evidence

The original two signed comparisons admit state 0x98 or 0x99 and still contain a subsequent 0x57 comparison, which is retained exactly even though it cannot succeed for that admitted input. An empty constraint prevents GCC from replacing the two comparisons with an unsigned range test. The movement word at +0x50 becomes 1; the unknown word at +0x4C, vector fields +0x8C/+0x98, word +0xB0, byte fields +0x1B4/+0x1B9/+0x1BA and word +0x144 retain original accesses and ordering. The helper receives literal 0xC00. No physical unit or additional branch purpose is inferred. Next evidence target: caller state producer, helper result units, and runtime initialization cadence.

Categories: {'original animation range gate and Spyro word/vector/byte initialization': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_18_80087DCC` | original animation range gate and Spyro word/vector/byte initialization | 49 | `8e3d2f647f272e1727ba4aa1803222f03b83503f36e6243f243ddffbd2d659f3` | `asm/nonmatchings/overlays/level_18/animation/func_level_18_80087DCC.s` |
| `func_level_28_80085F1C` | original animation range gate and Spyro word/vector/byte initialization | 49 | `37ddadc9300398437049fab9290b695b5b5e610156ed9310696482f21289d371` | `asm/nonmatchings/overlays/level_28/animation/func_level_28_80085F1C.s` |
| `func_level_38_8008814C` | original animation range gate and Spyro word/vector/byte initialization | 49 | `9529a955738af2c07b6906256d3518aae1925c05f5e51e565229ef09a8e56147` | `asm/nonmatchings/overlays/level_38/animation/func_level_38_8008814C.s` |
| `func_level_48_80087184` | original animation range gate and Spyro word/vector/byte initialization | 49 | `10d06517b2e7121883e67a007d152c6a05f96a27f8b267b3fb0be5d4729bc443` | `asm/nonmatchings/overlays/level_48/animation/func_level_48_80087184.s` |
