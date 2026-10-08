# Verified overlay batch 2026-10-04-509

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 221 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch509.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes: these two related level 47 routines grow the tagged radius by the original cadence times 20 or 30, then perform the original player, actor and linked-object collision queries. The second routine excludes its tagged parent from the actor query and passes null to the link query. Signed player heading clamping, byte actor heading clamping and the original 0x950000 link flags are preserved. Empty compiler constraints preserve original register allocation and scheduling and emit no instructions.

Categories: {'expanding radius player actor and link collision flags': 1, 'expanding radius parent-filtered actor and link collision flags': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_47_800796EC` | expanding radius player actor and link collision flags | 110 | `0bab3353f0455da618476aa15d7ed61d69ca6dfa446f10ac33f5bc6b739197ce` | `asm/nonmatchings/overlays/level_47/moby/func_level_47_800796EC.s` |
| `func_level_47_800812AC` | expanding radius parent-filtered actor and link collision flags | 111 | `6b8704c1848672bbefaab1da2cfd6bdd736fef588a96fee87ca72f72a4acf617` | `asm/nonmatchings/overlays/level_47/moby/func_level_47_800812AC.s` |
