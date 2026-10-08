# Verified overlay batch 2026-10-04-702

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 99 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch702.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Reuses the verified camera initializer structure for the original level 46 modes. The player actor tag is read from player offset 592; its words at offsets 80, 84 and 88 receive the exact original values. A pointer allocation constraint and a memory constraint preserve the original address/load schedule; volatile tag writes preserve store order. Constraints emit no instructions. No runtime interpretation of the unknown tag fields is claimed.

Categories: {'camera reset and player actor tag initialization': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_46_80091658` | camera reset and player actor tag initialization | 99 | `3b6e43fcff2cb7d1709337134305772151cbe7342fd4d3229973280a78a00394` | `asm/nonmatchings/overlays/level_46/camera/func_level_46_80091658.s` |
