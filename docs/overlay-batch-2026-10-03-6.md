# Verified overlay batch 2026-10-03-6

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 74 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch6.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'class-gated helper after fragments': 1, 'position helper and global-gated deletion': 1, 'title centered text wrapper': 1, 'cutscene one-time spawn state': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_22_80087688` | class-gated helper after fragments | 17 | `16d93e7327231ee5e1aca22aaceecbf22c9c95bb1cd492854cf93941559c0ab0` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_80087688.s` |
| `func_level_47_80078518` | position helper and global-gated deletion | 20 | `1ba263b86f64aee027466c23bf089a791b30ae98eb1341cca24dfff7f02ed889` | `asm/nonmatchings/overlays/level_47/moby/func_level_47_80078518.s` |
| `func_title_80077BC4` | title centered text wrapper | 16 | `d62687c313b6542161f263cd0f8c5f0b6e3ed796d89a3534e7692ffc4e77e76a` | `asm/nonmatchings/overlays/title/title1/func_title_80077BC4.s` |
| `func_cutscene_78_80074788` | cutscene one-time spawn state | 21 | `842f44913652eba6f4b0b21a0c8da6bb77e565633b04b43b1cb45223758016a6` | `asm/nonmatchings/overlays/cutscene_78/moby/func_cutscene_78_80074788.s` |
