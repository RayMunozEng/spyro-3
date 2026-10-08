# Verified overlay batch 2026-10-04-594

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 104 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch594.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: original level-18 instructions, using existing upstream Moby layout. The private volatile pointer alias preserves the two original player-actor reads and their ordering before the null check. Original input masks, player state, actor flag bit, packed linked indices, halfword termination marker, saved-state callback, and removal branches are preserved without semantic assumptions.

Categories: {'player input gate linked list completion and saved state release': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_18_80082B24` | player input gate linked list completion and saved state release | 104 | `cba6feff3a11e785f4ed35e35e859604c8d8afaacba346cda424e29c3ee952d4` | `asm/nonmatchings/overlays/level_18/moby/func_level_18_80082B24.s` |
