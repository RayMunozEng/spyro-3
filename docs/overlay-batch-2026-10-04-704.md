# Verified overlay batch 2026-10-04-704

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 129 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch704.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Reuses the verified camera initializer structure for the exact level 42 mode dispatch and original table. Modes 4, 23, 32 and 16 keep separate flag combinations and saved address preparation; mode 15 retains the relative pointer calls. Empty volatile pointer constraints retain otherwise dead original address preparation, and symbol aliases preserve independent global argument materialization. Constraints emit no instructions.

Categories: {'three-mode camera initialization': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_42_8008FB90` | three-mode camera initialization | 129 | `72006ee5b3a0c5d2f1667bcdc8ef13536c79095a11feddb17775baef3b9abbdd` | `asm/nonmatchings/overlays/level_42/camera/func_level_42_8008FB90.s` |
