# Verified overlay batch 2026-10-04-406

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 3 functions, 229 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch406.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: uses existing Spyro, Moby, Colour, angle-table, and helper declarations. The candidate selector preserves its 16-byte records, signed count, maximum-distance test, and original heading-difference threshold. The colour updater preserves target acceleration and original byte-write order. The angular handler preserves both state branches, timer clamp, ABS comparisons, and signed turn limits; an empty constraint keeps the first helper result in its original call delay slot and emits no instructions.

Categories: {'candidate distance maximum filtered by heading difference': 1, 'random target colour step with byte timer': 1, 'two-state angular step and bounded alignment': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_50_80094BA4` | candidate distance maximum filtered by heading difference | 74 | `c72132688927a6295908498929925e7b8da5e4d1ddb7747f78a7e99abf25229d` | `asm/nonmatchings/overlays/level_50/level/func_level_50_80094BA4.s` |
| `func_level_35_8007FF14` | random target colour step with byte timer | 76 | `dbc780ab925346f36cf73f797ccc60a95cfd9467fa72f8420873cf263007ec91` | `asm/nonmatchings/overlays/level_35/moby/func_level_35_8007FF14.s` |
| `func_level_21_8007FC58` | two-state angular step and bounded alignment | 79 | `cd791f920cc4fd356df5534bd22058ddb4a9b2045403af7318a2809f3d460035` | `asm/nonmatchings/overlays/level_21/moby/func_level_21_8007FC58.s` |
