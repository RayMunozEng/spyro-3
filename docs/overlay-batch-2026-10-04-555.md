# Verified overlay batch 2026-10-04-555

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 130 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch555.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes: the sound/fragment prefix reuses the verified level 25 callback/tag layout, with this routine's original sound indices, fragment class and motion parameters. Ordinary C preserves the first-update byte angle save/reset/restore, model update and position query whose low 24 result bits form the original colour word. No semantic sound or colour interpretation is claimed. All instructions match without scheduling constraints.

Categories: {'sound fragment damage motion temporary angle reset and position-derived colour': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_35_8007C4B0` | sound fragment damage motion temporary angle reset and position-derived colour | 130 | `59ab3cbf28820e8ccc0c1d51afd262ef252ab52bf17f470526cebfba2bf37978` | `asm/nonmatchings/overlays/level_35/moby/func_level_35_8007C4B0.s` |
