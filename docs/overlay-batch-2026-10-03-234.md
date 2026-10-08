# Verified overlay batch 2026-10-03-234

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 266 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch234.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- `func_level_13_8008C2B4` reuses the verified camera initializer structure. Mode 0xD and modes 0x1E/0x26 clear different byte fields; the shared vector helpers preserve the original offsets and call order.
- `func_level_12_80081A0C` preserves vector addition, the Z increment capped at 0xF0, unsigned byte size wrapping, and deletion conditions. No new movement or size interpretation is claimed.
- `func_level_31_800824C0` preserves the alpha gate, animation jump table, linked actor damage forwarding and player-pointer mask. The existing SDK `animationState` field and the executable's integer return type for `func_80039714` are used.
- `func_level_31_8008838C` reuses `DecodedActorTransition` from the paired verified restore routine. Its typedef moves before both uses. Spawn, position adjustment, colour bytes, saved state and byte-0x47 update retain the original access widths.

Categories: {'three-mode camera initializer with distinct field clears': 1, 'vector update, byte-size changes and bounded deletion': 1, 'animation-state damage forwarding and update callbacks': 1, 'spawned actor setup and saved-state transition': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_13_8008C2B4` | three-mode camera initializer with distinct field clears | 64 | `0f0495fe38f8ee59801958f5c3c7852e8193cfed05e2b97aeb21bbb8b014aae6` | `asm/nonmatchings/overlays/level_13/camera/func_level_13_8008C2B4.s` |
| `func_level_12_80081A0C` | vector update, byte-size changes and bounded deletion | 68 | `9572052109655faf5e687a31d1f21b012b085f89bb1dfa75c506052d3601ee9c` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_80081A0C.s` |
| `func_level_31_800824C0` | animation-state damage forwarding and update callbacks | 66 | `fd153c587edee5815bb2532d5a8306aa5f16070b80e188cb563885ee7fb50bff` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_800824C0.s` |
| `func_level_31_8008838C` | spawned actor setup and saved-state transition | 68 | `a7032234b22db4c7cfa51c38e53f4c5c02589ce6e66a7ad9766a8183a662361e` | `asm/nonmatchings/overlays/level_31/level/func_level_31_8008838C.s` |
