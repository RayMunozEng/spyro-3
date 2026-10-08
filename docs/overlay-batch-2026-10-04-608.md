# Verified overlay batch 2026-10-04-608

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 288 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch608.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: the verified dialogue gate handler in batch 600, using existing upstream Moby fields. The remaining identical copies preserve threshold activation, toll checks, linked actor state 9, target cleanup, and dialogue transitions. All linked instruction words and complete overlay hashes matched; no compiler constraints were needed.

Categories: {'dialogue threshold progression linked actor and target gates': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_20_8007AB34` | dialogue threshold progression linked actor and target gates | 144 | `dc94c2af82c2cdc9fc7fb533b08e6e0c95c55b834bd882dd6014552af6924f42` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_8007AB34.s` |
| `func_level_40_80079444` | dialogue threshold progression linked actor and target gates | 144 | `b1f3c7b21d3765ffdddae7ad3d640a954c162247a803e07f853da9136cbd0b89` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_80079444.s` |
