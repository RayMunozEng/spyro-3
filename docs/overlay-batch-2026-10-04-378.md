# Verified overlay batch 2026-10-04-378

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 6 functions, 840 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch378.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: six segmented vector-query routines using existing Vector3D and Moby layouts. Preserves global clearing, optional +0x80 Z, step count (vector helper result >>10)+1, signed component division before all three stores, both query-helper calls and every flag-dependent return/step-copy branch. The critter/reference actor pointer uses the original Spyro field address +0x250 via a private ABI alias. Empty constraints preserve the original saved-register ordering without emitting instructions. Helper outcomes and flag meanings remain numeric; no new collision or runtime semantics are claimed.

Categories: {'segmented vector query with numeric flags': 6}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_33_80095948` | segmented vector query with numeric flags | 140 | `ebf82804af95fbe8aaeca544a9ae755a885452d694b52cba80be00d2d047d5bf` | `asm/nonmatchings/overlays/level_33/level/func_level_33_80095948.s` |
| `func_level_43_8008D73C` | segmented vector query with numeric flags | 140 | `80d2d1e2ca60507425435df2e274ef40574a85126fb9eb46c2b1da6adfe28b74` | `asm/nonmatchings/overlays/level_43/level/func_level_43_8008D73C.s` |
| `func_level_44_8008A8D8` | segmented vector query with numeric flags | 140 | `15774e5ab146589cb10097e61a4123775b11fe14b0144c7d5805a499e3f3b741` | `asm/nonmatchings/overlays/level_44/level/func_level_44_8008A8D8.s` |
| `func_level_46_8008BB7C` | segmented vector query with numeric flags | 140 | `ea158463f525582f18ceb9ada3ebc5c64ec632c3ad1d115f900c5ddefc9e986e` | `asm/nonmatchings/overlays/level_46/level/func_level_46_8008BB7C.s` |
| `func_level_47_800890AC` | segmented vector query with numeric flags | 140 | `051071501b697317bad3868f68b3679b80f8a86b83c1a4353c2840c2ef7febfd` | `asm/nonmatchings/overlays/level_47/level/func_level_47_800890AC.s` |
| `func_level_50_800956BC` | segmented vector query with numeric flags | 140 | `66c178d16372c41d03502f683d3d1216753c504d61b9ba47ec115c7098029eee` | `asm/nonmatchings/overlays/level_50/level/func_level_50_800956BC.s` |
