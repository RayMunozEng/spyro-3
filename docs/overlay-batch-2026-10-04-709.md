# Verified overlay batch 2026-10-04-709

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 101 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch709.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Reuses the verified camera initializer structure for original level 31 modes 5 and 34. The target delta, horizontal heading plus 1024, vector normalization, player-relative addition and Z offset preserve the exact helper calls and order. Empty argument and pointer constraints retain original allocation and emit no instructions. No new runtime meaning is claimed for unknown fields.

Categories: {'three-mode camera initialization': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_31_8008F894` | three-mode camera initialization | 101 | `45fce1f2c543a8ac594e09e628492367d75fcbedb4638d355d178b4e536f01fc` | `asm/nonmatchings/overlays/level_31/camera/func_level_31_8008F894.s` |
