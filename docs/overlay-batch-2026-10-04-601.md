# Verified overlay batch 2026-10-04-601

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 292 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch601.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream Moby and helper interfaces, plus original level-30 and level-13 instruction streams. The level-30 implementation is reused only where the second stream proves the same operations. Level 13 retains its additional target call and linked substate write. Both routines preserve signed threshold reads, progression gates, target reloads, index clearing before the target helper, and dialogue transitions. No emitted assembly or inferred constants were added.

Categories: {'dialogue threshold progression linked actor and target gates': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_13_8007ADAC` | dialogue threshold progression linked actor and target gates | 148 | `2255efb0ad99ce1c455071e44a66d7f1494bad66f1bb0905b4258ada6afb61b3` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_8007ADAC.s` |
| `func_level_30_80079D80` | dialogue threshold progression linked actor and target gates | 144 | `1bbbfec103b16a3dfd3017987b744b69e924a33de319a1d210401f722edba8de` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_80079D80.s` |
