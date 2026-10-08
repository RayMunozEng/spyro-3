# Verified overlay batch 2026-10-03-96

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 7 functions, 296 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch96.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Existing upstream Moby layout, HUD/animation helper calls and fragment wrapper code are the baseline.

## Widths, scheduling and remaining evidence

The actor list uses 16-bit entries: the low 15 bits select a 0x58-byte Moby, while the signed sign bit terminates the list after processing that entry. State is an unsigned byte at +0x48; next animation ID, progress and next frame are bytes at +0x3D/+0x40/+0x3F. The original int state comparison remains wider than its byte stores. Progress literal 0x72 is loaded in the branch rather than hoisted. The deletion wrapper compares state with 0x32, preserves callback selectors 4 and 0x20, and passes particle selectors 8/0x46 plus literal fourth argument 0x10 without interpreting that argument as an actual dereferenced vector. Empty compiler constraints emit no instructions. Next evidence target: list producers and callback/particle fourth-argument consumers and runtime event timing.

Categories: {'signed actor list terminator and state plus animation update': 4, 'state and fragment gated callbacks particle and deletion': 3}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_18_800857F0` | signed actor list terminator and state plus animation update | 50 | `68dd7bc5c3dafaa127031d76368f018bc56beabe018c08509bdc9996181c45c2` | `asm/nonmatchings/overlays/level_18/level/func_level_18_800857F0.s` |
| `func_level_28_80083960` | signed actor list terminator and state plus animation update | 50 | `68dd7bc5c3dafaa127031d76368f018bc56beabe018c08509bdc9996181c45c2` | `asm/nonmatchings/overlays/level_28/level/func_level_28_80083960.s` |
| `func_level_38_800852B4` | signed actor list terminator and state plus animation update | 50 | `68dd7bc5c3dafaa127031d76368f018bc56beabe018c08509bdc9996181c45c2` | `asm/nonmatchings/overlays/level_38/level/func_level_38_800852B4.s` |
| `func_level_48_80084BC8` | signed actor list terminator and state plus animation update | 50 | `68dd7bc5c3dafaa127031d76368f018bc56beabe018c08509bdc9996181c45c2` | `asm/nonmatchings/overlays/level_48/level/func_level_48_80084BC8.s` |
| `func_level_14_800898B4` | state and fragment gated callbacks particle and deletion | 32 | `161fa151c84cafae1104a714400c5605f3d8b1a64dea38c1c020c335a34e11d6` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_800898B4.s` |
| `func_level_34_80089028` | state and fragment gated callbacks particle and deletion | 32 | `161fa151c84cafae1104a714400c5605f3d8b1a64dea38c1c020c335a34e11d6` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_80089028.s` |
| `func_level_43_8007E3EC` | state and fragment gated callbacks particle and deletion | 32 | `161fa151c84cafae1104a714400c5605f3d8b1a64dea38c1c020c335a34e11d6` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_8007E3EC.s` |
