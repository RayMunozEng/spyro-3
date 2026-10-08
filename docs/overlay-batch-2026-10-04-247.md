# Verified overlay batch 2026-10-04-247

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 5 functions, 615 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch247.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- Five identical cutscene dispatchers restore the model-pointer table and retain the SDK cheat byte at offset 5, all twenty selector entries, the original helper arguments and the state-0x13 write.
- Distinct retail branches with repeated helper arguments remain distinct. Empty register constraints with selector identifiers prevent the compiler from merging those branches; they emit no instructions. The original table and every branch target were checked in each linked overlay.
- Existing relocation-header declarations and helper APIs are reused. No new meaning is assigned to numeric selectors.

Categories: {'cutscene table restoration and exact selector dispatch': 5}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_cutscene_65_80076820` | cutscene table restoration and exact selector dispatch | 123 | `f6cd32ff1a2e66810347809241e64e921fc8269e78e1b0cadc9f521ef2caf768` | `asm/nonmatchings/overlays/cutscene_65/camera/func_cutscene_65_80076820.s` |
| `func_cutscene_66_80076820` | cutscene table restoration and exact selector dispatch | 123 | `f6cd32ff1a2e66810347809241e64e921fc8269e78e1b0cadc9f521ef2caf768` | `asm/nonmatchings/overlays/cutscene_66/camera/func_cutscene_66_80076820.s` |
| `func_cutscene_68_80076820` | cutscene table restoration and exact selector dispatch | 123 | `f6cd32ff1a2e66810347809241e64e921fc8269e78e1b0cadc9f521ef2caf768` | `asm/nonmatchings/overlays/cutscene_68/camera/func_cutscene_68_80076820.s` |
| `func_cutscene_74_80076820` | cutscene table restoration and exact selector dispatch | 123 | `f6cd32ff1a2e66810347809241e64e921fc8269e78e1b0cadc9f521ef2caf768` | `asm/nonmatchings/overlays/cutscene_74/camera/func_cutscene_74_80076820.s` |
| `func_cutscene_79_80076820` | cutscene table restoration and exact selector dispatch | 123 | `f6cd32ff1a2e66810347809241e64e921fc8269e78e1b0cadc9f521ef2caf768` | `asm/nonmatchings/overlays/cutscene_79/camera/func_cutscene_79_80076820.s` |
