# Verified overlay batch 2026-10-04-603

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 300 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch603.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: newly verified level-30 dialogue handler, reused against each original instruction stream. Level 10 retains its initial global flag check and phase-five write. Level 42 retains its linked substate writes and null-actor sound call in the phase-four branch. Full original global accesses, target clearing order, and dialogue state transitions remain exact. These are AI-generated and still await human review.

Categories: {'dialogue threshold progression linked actor and target gates': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_42_8007B9D8` | dialogue threshold progression linked actor and target gates | 150 | `9164db362e18d89e3d1deaf4ef4a6975c1fc9e71d513a044ffca9d1f77236514` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_8007B9D8.s` |
| `func_level_10_80079B00` | dialogue threshold progression linked actor and target gates | 150 | `0c7c0bd4e16bef65019cc20b099dc52830ae45ab09a015cd652c364c3a0b88e8` | `asm/nonmatchings/overlays/level_10/moby/func_level_10_80079B00.s` |
