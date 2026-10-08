# Verified overlay batch 2026-10-04-371

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 500 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch371.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: four local vector/threshold queries using the existing Moby, Vector3D, SHORTMATRIX, ABS macro and math helper declarations. Preserves both output-pointer branches, strict absolute-value comparisons, the original optional right/left shift by three around the matrix transformation, output-vector copy, helper arguments and every return condition. The no-output branch applies its initial vector tests before transforming; the output branch copies the transformed vector even when it returns false. No units or geometric helper semantics beyond the original operations are newly asserted. No compiler constraints or instruction assembly are needed.

Categories: {'local vector transform and threshold query': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_15_80083604` | local vector transform and threshold query | 125 | `cc63c03f9bb7ce5cbeeebc411f37a2524153a2a9c18d3ed35c846c7e49916c5a` | `asm/nonmatchings/overlays/level_15/level/func_level_15_80083604.s` |
| `func_level_25_80083FBC` | local vector transform and threshold query | 125 | `7c3108ca48a8df5b4111f9294a526ccae5d4bb86b9a2e63ea43468a1d2e98fe1` | `asm/nonmatchings/overlays/level_25/level/func_level_25_80083FBC.s` |
| `func_level_35_80085340` | local vector transform and threshold query | 125 | `bcbecc38c041609d0cb94316e8b74c9a66d037319810ecb47ec9911dac092fcc` | `asm/nonmatchings/overlays/level_35/level/func_level_35_80085340.s` |
| `func_level_45_800838FC` | local vector transform and threshold query | 125 | `fca95dfbd547143ddeb3dff79782cde0df9687fc061ad0962dbe1d67ed6dded4` | `asm/nonmatchings/overlays/level_45/level/func_level_45_800838FC.s` |
