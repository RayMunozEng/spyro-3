# Verified overlay batch 2026-10-04-243

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 143 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch243.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- `func_level_50_8008A900` preserves the timer and signed halfword velocity, its clamp and decrement, two distinct particle calls, helper arguments and shared deletion path. A partial tag describes only the accessed fields; the numeric particle selectors retain their original values.
- `func_level_11_80081D2C` reuses the existing animation-header setup pattern from the verified respawn routine. The animation pointer at model offset 0x44 remains a partial declaration, independent of the existing offset-0x3C model field. Four animation bytes and the original arithmetic progress value are preserved. An empty constraint retains the boolean arithmetic without emitting instructions.

Categories: {'vertical timer and particle callbacks with original branch cleanup': 1, 'four-state animation setup and saved-state callback': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_50_8008A900` | vertical timer and particle callbacks with original branch cleanup | 73 | `cc6684fef249378de0f51c957ef864edb479e12ea22d69ae9f1509c0e5919d70` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_8008A900.s` |
| `func_level_11_80081D2C` | four-state animation setup and saved-state callback | 70 | `6c7f55ee3e10cb112e2233ce1373e7618e191ee5c88422f8c4d85364ca19b240` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_80081D2C.s` |
