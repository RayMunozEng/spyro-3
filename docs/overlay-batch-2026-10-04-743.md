# Verified overlay batch 2026-10-04-743

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 128 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch743.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Rev 1 reuse: SpyroCode `playable-evening-raw628-direct-controller-runtime.md` supplies the local state routes and pointer-selector chain. The original Rev0 words establish that the second pool index is private-data word +0x30, not first actor record word +0x30 as the prose states: lw v0,0(a1) at 0x8007E850 reads the private pointer, then lw v1,0x30(v0) selects the index. The second private record word +0x0C selects a byte in D_80071570. State zero copies owner position to the first actor, increments Z by 256, copies yaw, and draws with mode two; state one sets state two when the selected byte is nonzero; state two calls the numeric (6,79) helper and releases. Explicit private-field structures retain exact offsets. Ordinary C; no register constraints. Pool identities, flag meaning and helper effects remain unknown.

Categories: {'nested pool tag selector and three-state transition': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_30_8007E7D8` | nested pool tag selector and three-state transition | 128 | `4c7802ea0540e4905d54bd2e6be36f2f3d0c5feab7f21ed192684faafb5d7f87` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_8007E7D8.s` |
