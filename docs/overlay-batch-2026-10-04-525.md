# Verified overlay batch 2026-10-04-525

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 103 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch525.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes: camera states 13/21, 23 and 30/38 preserve their original flag stores, shared initialization call, relative camera-position pointers and conversion calls. Explicit no-op states retain the original table extent. Empty compiler constraints preserve the separate retail blocks and original register allocation without emitted instructions.

Categories: {'camera mode flag initialization and original position conversion': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_34_80098490` | camera mode flag initialization and original position conversion | 103 | `146549fb85173cef65de6ec816371537a9f92fea13a80d67897149f2a7c4b762` | `asm/nonmatchings/overlays/level_34/camera/func_level_34_80098490.s` |
