# Verified overlay batch 2026-10-03-185

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 90 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch185.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The actor-tag copy uses the SDK player state layout: tag words at offsets 0 and 4 feed player offsets 0x254 and 0x264. Tag bit 8 selects the vector and three-word copy path; otherwise the actor position is copied. Original deletion follows both paths. The movement routine uses the original actor index at tag offset 0x18, deletes when the indexed actor state has bit 0x80, and otherwise gates the bounds helper on movement states 5 and 6 before setting player words 0x20C and 0x23C. Empty constraints preserve original register reuse and load ordering without emitting instructions. Unknown player-state meanings remain explicit.

Categories: {'actor-index deletion and bounded movement-state flag': 1, 'actor-tag copy into player state': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_80080DC8` | actor-index deletion and bounded movement-state flag | 46 | `aeebc4adfd317b58f29a2b3b53c77808ae9b00482f26f31f5d5a42b12f126b47` | `asm/nonmatchings/overlays/level_10/moby/func_level_10_80080DC8.s` |
| `func_level_22_800850F4` | actor-tag copy into player state | 44 | `30f78da7c488536300dc8b767f02338bde370141da51ea7ea7b115505d11f1ab` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_800850F4.s` |
