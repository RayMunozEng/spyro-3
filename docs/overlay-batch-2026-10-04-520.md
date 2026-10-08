# Verified overlay batch 2026-10-04-520

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 188 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch520.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes: the level 12 routine retains three vector temporaries, the matrix and byte angles at their original stack offsets; four random matrix-transformed particle payloads precede the class 0x2C0 spawn and exact tag writes. The level 11 routine uses the original animation byte, two damage-mask branches, seven fragment attempts and seven random velocity payloads, including signed halfword halving and the colour byte writes. Both compile as ordinary C without scheduling constraints.

Categories: {'four matrix-transformed particle vectors and spawned actor tag initialization': 1, 'animation and damage gated seven fragment and random particle payloads': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_12_8007F57C` | four matrix-transformed particle vectors and spawned actor tag initialization | 96 | `18d805d00131b70cef131db8b7912a667c4bc59160837d96444d390444fa0337` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_8007F57C.s` |
| `func_level_11_8007D748` | animation and damage gated seven fragment and random particle payloads | 92 | `d29ff8e87e06f1ccc88dd2be1a1c25bdeb7b675a24316fb9fde5879aa3099469` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_8007D748.s` |
