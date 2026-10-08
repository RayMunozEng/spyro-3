# Verified overlay batch 2026-10-04-537

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 115 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch537.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes: ordinary C preserves five actor states, signed halfword timer storage, byte substate initialization, timer decrement calls, completion-gated transitions and both random timer formulas. The original dense switch table and all state-change animation calls match without compiler scheduling constraints.

Categories: {'five-state actor halfword timers completion gate and random reloads': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_34_8008750C` | five-state actor halfword timers completion gate and random reloads | 115 | `6bcff9e8d306612d84857c02a6f2d94d2e8e7e3d9f485f92524896f629bbedb9` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_8008750C.s` |
