# Verified overlay batch 2026-10-04-963

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 99 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch963.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream Moby/HUD/Savepoint declarations, previously verified state-save/camera-target patterns, and the Rev1 raw289 machine-contract crosswalk. No dedicated raw289 behavior decoder was available; original Rev0 instructions remain the source for all99 words. Owner private byte+5 and signed actor index+0x30 are distinct from the linked player actor private flags+0x1C and signed handle+0x36. State0 retains a separate one constant across two helper calls; state1 reads its selector again after the global gate-byte store, indexes88-byte actor records and calls the camera helper with original yaw-byte,0,152 arguments. State2 follows the player-link private chain, clears only mask0x1E from the32bit flags and conditionally issues the original HUD helper request for handle!=-1; the alternate route uses the existing saved-data spawn-vector API. Empty constraints emit no instructions and retain original constants, camera argument ordering and the post-store selector reread. Helper/event identities, gate producers, input units, actor validity, caller cadence and runtime presentation remain open.

Categories: {'raw289 indexed state and linked private cleanup': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_18_8007A45C` | raw289 indexed state and linked private cleanup | 99 | `d532fa64ca914b452978fa39710439b433dbc805d4ea0da863a4f27e3191f1aa` | `asm/nonmatchings/overlays/level_18/moby/func_level_18_8007A45C.s` |
