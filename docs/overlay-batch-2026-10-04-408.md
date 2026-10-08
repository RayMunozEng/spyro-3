# Verified overlay batch 2026-10-04-408

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 76 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch408.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: reuses upstream Moby, Spyro, Vector3D, Savepoint, and angle-table layouts. A partial checkpoint-tag view records the original signed 32-bit heading at offset 0x48 and position at 0x4C. Preserves the 13/32 table scaling, heading subtraction, temporary actor-state zero, save registration, state restoration, checkpoint update and reset. Empty constraints preserve original load/scheduling order and emit no instructions.

Categories: {'checkpoint bounds and heading offset persistence': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_26_8007BDEC` | checkpoint bounds and heading offset persistence | 76 | `8db419df0c110915b453b0f10a9e95a45eea942d1ec41d5315269422b9757f69` | `asm/nonmatchings/overlays/level_26/moby/func_level_26_8007BDEC.s` |
