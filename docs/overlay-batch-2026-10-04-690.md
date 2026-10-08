# Verified overlay batch 2026-10-04-690

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 89 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch690.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation follows the original level 47 selector directly. Camera modes 13, 14 and 23 retain distinct input, override and player-animation fallback branches. The player accesses remain at byte 441 and word 72; the mode table selector remains an int. No instruction assembly or allocation constraints are used.

Categories: {'camera selector and player fallback': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_47_8008DDF8` | camera selector and player fallback | 89 | `4b41a8b3aecbb2f685d5c840244d3c9ac13e416a150712ba557716f56dcc61e4` | `asm/nonmatchings/overlays/level_47/camera/func_level_47_8008DDF8.s` |
