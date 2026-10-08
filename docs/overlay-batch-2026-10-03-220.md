# Verified overlay batch 2026-10-03-220

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 3 functions, 166 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch220.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The gated spawn routine retains the signed tag halfword at 0xC, substate transition to 0x70, four-iteration limit, original slot-distance threshold 21, seven-argument helper and returned actor-byte writes. The bounds routine preserves independent entry and exit checks, the indexed table plus tag word at 0x18, and the player word at 0xF8; its meaning and units remain unknown. The linked-spawn routine preserves the stored actor state-bit gate, timer helper, retryable spawn state, three-word zero vector, spawned actor state 0x52, timer 0x14 and saved pointer. Empty constraints preserve original load/call scheduling and emit no instructions. Numeric class and selector meanings are not inferred.

Categories: {'gated four actor-piece spawns and fragment helper': 1, 'bounds entry and exit player-word update': 1, 'linked actor timer and conditional spawn setup': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_36_80079AE8` | gated four actor-piece spawns and fragment helper | 54 | `db47c728dcb11a0beecb2b0803266abafd8ddade7ed368dc071ee26dd0c769dc` | `asm/nonmatchings/overlays/level_36/moby/func_level_36_80079AE8.s` |
| `func_level_26_80083F90` | bounds entry and exit player-word update | 56 | `e051e6dc7320455dd4846ba90ddef4bacbec85f7291445b0b8de135fc081a927` | `asm/nonmatchings/overlays/level_26/moby/func_level_26_80083F90.s` |
| `func_level_43_800886F4` | linked actor timer and conditional spawn setup | 56 | `6fde7851e32ef9e87edbbabf69407ff42460802f177dce30953a931b7ba168a5` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_800886F4.s` |
