# Verified overlay batch 2026-10-04-422

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 160 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch422.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: uses upstream EnemyTag and Moby structures. Preserves the indirect damage callback, enemy-byte updates, signed player-field shift and collision-field clear in the first handler. The six-state handler preserves its original damage gate, signed halfword updates, shared state branches, and helper/deletion chain. Its original jump-table entries are audited against the linked overlay.

Categories: {'damage transition callback and enemy state update': 1, 'damage transition and six-state enemy dispatch': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_25_8007A238` | damage transition callback and enemy state update | 79 | `04ed0d8cffb3a06e2a83daf7890e07e6a9c3fd505cab8b20a8fbf4d5d60a641a` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_8007A238.s` |
| `func_level_44_8007FA30` | damage transition and six-state enemy dispatch | 81 | `1483f7ca659947d8048ac69d6b793248905cc560b00dab05a8b9e805edce6013` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_8007FA30.s` |
