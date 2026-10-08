# Verified overlay batch 2026-10-04-607

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 318 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch607.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: the verified linked model-point handlers in batch 606, using existing upstream Moby and Vector structures. These two variants preserve the additional visibility guard and shared removal branch. No instruction-emitting assembly or compiler constraints were needed.

Categories: {'linked animation gated model point position and orientation': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_32_80089724` | linked animation gated model point position and orientation | 159 | `5e558666ee8ac80b191b96a52dc9358d72bf16369b88608af13b9078e5fa285e` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_80089724.s` |
| `func_level_50_80084F34` | linked animation gated model point position and orientation | 159 | `04d0c715b5c386397bf4d74c39c9f321de7fb406f56796a2ce2454db15e633f1` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_80084F34.s` |
