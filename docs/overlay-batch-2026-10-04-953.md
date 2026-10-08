# Verified overlay batch 2026-10-04-953

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 95 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch953.minimal.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Reuse baseline: the child-offset and factory sequence just verified in batch942 raw129, plus the state-byte savepoint pattern accepted in batch928. Rev1 machine-contract crosswalk identifies Haunted raw9470x8007A36C, but no dedicated raw947 decoder was available; original Rev0 instructions establish all gates and arguments. State0 calls the bounds helper with player vector, owner private pointer,0,512; a nonzero result sets numeric globals, issues the original sound/factory requests, and transitions owner state to1 even when the factory returns null. A successful child copies the player vector and applies the same signed16bit table sample times25 arithmetic-right7 offsets, including a fresh heading-byte read after X and Z+500 before Y. Nonzero states produce owner-state-byte address on that route, issue two ordered one-byte savepoint calls, and release the owner. The pointer lifetime placement fixes original prologue scheduling without register constraints. A memory-only empty barrier preserves the global heading reread. Bounds units, helper/factory side effects, sound identity, pointer validity, update cadence and runtime presentation remain open.

Categories: {'raw947 bounds gate with shared child offset and savepoints': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_43_8007A28C` | raw947 bounds gate with shared child offset and savepoints | 95 | `bc53c4638c0ec5f5ba6347bc124a30079c38882b58a82b191112a957d53c7b98` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_8007A28C.s` |
