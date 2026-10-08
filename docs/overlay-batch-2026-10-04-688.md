# Verified overlay batch 2026-10-04-688

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 62 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch688.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation follows the original title sprite routine directly, using existing upstream sprite definitions. Frame access is byte-sized; centering uses the original endpoint difference and arithmetic half-width shift. Sine table reads remain unsigned halfwords with explicit signed shifts at 26 and 27 bits. No instruction assembly or allocation constraints are used.

Categories: {'title sprite width centering and sine offsets': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_title_80077C04` | title sprite width centering and sine offsets | 62 | `c45015ccd78c17fb9eabbb826af8e2ab96127b0a525547ebdc57fe0e58f58cda` | `asm/nonmatchings/overlays/title/title1/func_title_80077C04.s` |
