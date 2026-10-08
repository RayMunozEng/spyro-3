# Verified overlay batch 2026-10-03-166

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 236 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch166.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: upstream `Moby`, `Spyro`, `Savepoint`, vector and actor helper declarations, and original instructions. The distance-gated routines compare the helper result against signed tag word +4, conditionally call the original helper, clear tag selector +0 and state byte, and record four bytes through the original savepoint helper before animation/colour handling. The cleanup routines preserve state/animation/global gates, call deletion, then still examine linked actor data and clear any of four matching pointers. They intentionally do not return immediately after deletion because retail continues the pointer cleanup. State-nonzero paths retain the original tag helper and conditional deletion. Comparisons and access widths are exact; tag selector interpretation, helper distance units and invocation cadence remain unresolved. Next evidence target: tag producers, deletion lifetime rules and savepoint replay consumer.

Categories: {'distance-gated tag reset savepoint and actor colour': 2, 'animation-gated actor deletion and four linked pointers cleanup': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_18_8007E7D8` | distance-gated tag reset savepoint and actor colour | 62 | `955ebf25ce1d734302b42f3a0ad6718dd88259e5a59e30001fbeb3cf9826d0c3` | `asm/nonmatchings/overlays/level_18/moby/func_level_18_8007E7D8.s` |
| `func_level_28_8007CC74` | distance-gated tag reset savepoint and actor colour | 62 | `93e7226e4c84f83ce79706b2cb95b59e4a75a15cf36ee8be972067d0928509ea` | `asm/nonmatchings/overlays/level_28/moby/func_level_28_8007CC74.s` |
| `func_level_28_8007E6EC` | animation-gated actor deletion and four linked pointers cleanup | 56 | `9a6bbfc2fdda373227a7cb83a77e1501582851285ab8a628c9fc7f8540b10950` | `asm/nonmatchings/overlays/level_28/moby/func_level_28_8007E6EC.s` |
| `func_level_48_8007D948` | animation-gated actor deletion and four linked pointers cleanup | 56 | `b0589bcab30d8bc74d1562d4cd612e6116df54eb80c7c482480a24c0debb5aeb` | `asm/nonmatchings/overlays/level_48/moby/func_level_48_8007D948.s` |
