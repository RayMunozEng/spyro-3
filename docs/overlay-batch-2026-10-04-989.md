# Verified overlay batch 2026-10-04-989

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 74 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch989.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The source baseline is the original Rev0 race-reference visibility controller, func_level_25_8007D904, 0x8007D904..0x8007DA2C. Existing upstream Moby layout and native C ABS supply the field accesses and signed absolute difference. Strict less/greater comparisons leave equality on its original branch. Visible/hidden byte stores and the low-draw byte 63 are preserved. The packed colour word is 0x6080 or 0xC0FF according to (global & 63) >=25, followed by a separate alpha-byte clear. The accepted C uses ordinary branches and no register constraints. Reference/limit units, global producers, colour consumer, helper semantics and update cadence remain unresolved.

Categories: {'race reference distance visibility gate': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_25_8007D904` | race reference distance visibility gate | 74 | `e20a0e7cca2d01df00de513c9f260324071a2abf253f4c896e0949da4969fe4e` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_8007D904.s` |
