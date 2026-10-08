# Verified overlay batch 2026-10-03-227

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 3 functions, 186 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch227.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The motion routine retains its timer-at-tag-0xC deletion branch, signed X/Y/Z halfwords, Z decrement 10 with signed-halfword wrap before clamp -200, and independent byte-angle additions at tag offsets 6/8/0xA. The actor/progress check preserves original state 0 and 1 branches, the eight-argument helper constants, its bit-2 result test and common deletion path. The saved-state handler retains substate gating, both one-byte save calls, signed -1 sentinels, timer word reload and two environment selectors. Existing Moby/Savepoint declarations provide the field baseline; unknown tag semantics and update cadence beyond one invocation remain unestablished.

Categories: {'signed halfword motion and byte-angle increments': 1, 'actor/progress gates and eight-argument result deletion': 1, 'saved actor state and timer-gated environment selectors': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_24_8008B394` | signed halfword motion and byte-angle increments | 61 | `e760dfb82f40be4d71c9274bdf732fa5114c1cf19524e01edc115fb263967b6d` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8008B394.s` |
| `func_level_11_800846B8` | actor/progress gates and eight-argument result deletion | 62 | `033c2a291986a74994e5569273e1f541eedb4c1e0f9ccb9a114651193a5c35ba` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_800846B8.s` |
| `func_level_12_80081C88` | saved actor state and timer-gated environment selectors | 63 | `eb57a9b659f77bb16deb3b9662098c27aa00bc65a43964701f984cbdd9aaaffa` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_80081C88.s` |
