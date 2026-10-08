# Verified overlay batch 2026-10-04-920

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 792 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch920.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Source baseline: original path-controller instructions listed below and existing upstream actor/vector/callback declarations. Path records have a signed halfword count at +0 and point-table pointer at +12; point stride is 16 bytes. Private actor records retain path pointer +0 and word point index +4. State 0 preserves global-mode 2 gating, the initial nearest-point helper, nine ordered child spawns with +3 index increments, path/point copies, draw distances, update distance 255, and state 1. State 1 preserves both camera-angle conversions, the negative-global guard, three distinct path/count reads, all signed remainder traps, and both writes to the escaped stack point-index slot. Its transition compares the signed second remainder against signed half-count, adds 30 with signed remainder, and sets state 2. State 2 preserves low-nibble accumulation with the global step, threshold 16, word-zero versus three byte-zero stores, alpha encoding OR 48, indexed vector copy, and angle refresh. Units, record producers, helper semantics, child identity, global cadence, and runtime presentation remain open evidence targets. Empty constraints preserve original count rereads, overwritten stores, byte load/register allocation, and branch order without emitting instructions. Confidence is exact linked words and full retail hashes; no browser-level behavior completion is claimed.

Categories: {'path point child setup and signed wrap transition': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_15_8007AFD0` | path point child setup and signed wrap transition | 198 | `89c003bf1adfad648ada43811f668a4ed2cb4d8bff9da823264898692f108244` | `asm/nonmatchings/overlays/level_15/moby/func_level_15_8007AFD0.s` |
| `func_level_25_8007A9A4` | path point child setup and signed wrap transition | 198 | `bba376bbc67df3eaca6493b96b14e437ba5b9099c54fbcab5e2115b2f7d37e4b` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_8007A9A4.s` |
| `func_level_35_80079758` | path point child setup and signed wrap transition | 198 | `eeafc917cba8c0c7bad9a894c53cd864360ab4f8fa46935e36e312c20e967492` | `asm/nonmatchings/overlays/level_35/moby/func_level_35_80079758.s` |
| `func_level_45_800798C8` | path point child setup and signed wrap transition | 198 | `458aa347abaa1d8897effef2f7a577bdfa7d210d1854c2c4a0b0ddd87958e0a9` | `asm/nonmatchings/overlays/level_45/moby/func_level_45_800798C8.s` |

## Declaration revalidation

The typed path helper now uses source-local `DecodedChainFindPoint` bound to original symbol `func_80036518`, avoiding conflicts with earlier generic helper declarations in the same translation units. The executable and every overlay passed a fresh full build in `build/overlay_batch920.alias.full.log`. A second focused audit against the later complete build `build/overlay_batch942.full.log` rechecked all four functions and792 original words with zero mismatches. No behavior or progress count changed.
