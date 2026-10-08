# Verified overlay batch 2026-10-04-744

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 128 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch744.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Rev 1 reuse: SpyroCode `playable-midnight-raw498-direct-controller-runtime.md` identifies the four changed behavior words relative to Evening raw628: two private-data +0x2C loads, Z increment 128, and helper argument 80. Rev0 instructions confirm those differences and the same nested private-data/pool selector chain. The second index is read from the first actor private record, correcting the prose reference to the actor record itself. Reused ordinary C with named private-field structures matches all 128 original words; no register constraints. Pool identities, selector meaning and helper effects remain unknown.

Categories: {'nested pool tag selector and three-state transition': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_40_8007BFC0` | nested pool tag selector and three-state transition | 128 | `47a57e3313a5a3940474e0fd5a1a141593510cd6ae0288cb84cd6c25544bfd13` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_8007BFC0.s` |
