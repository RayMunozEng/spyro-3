# Verified overlay batch 2026-10-04-391

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 121 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch391.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: reuses the upstream Savepoint structure and savedData/unsavedData globals for the selector handler. The referenced-actor routine preserves retail writes of JR RA and NOP to the trigger helper, repeated tag-index reads, yaw copying, vector copying, and the original 0x400 Z addition. Corrected a conflicting legacy declaration of func_80039714 to its verified integer return type; full hashes confirm no byte change to neighboring functions.

Categories: {'selector state handler and callback registration': 1, 'retail trigger-code patch and referenced actor position copy': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_46_80086D08` | selector state handler and callback registration | 52 | `a3b9be1be48f2f26fb5e2ea07f3adbf7de164564e1b635dbff51a687abd83905` | `asm/nonmatchings/overlays/level_46/moby/func_level_46_80086D08.s` |
| `func_level_31_80083810` | retail trigger-code patch and referenced actor position copy | 69 | `3a12d52f24e02d23b247d9ffc55c3f302416efcb92e7b5ee4ed4c4c8892e8aee` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_80083810.s` |
