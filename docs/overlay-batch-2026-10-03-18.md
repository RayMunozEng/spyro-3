# Verified overlay batch 2026-10-03-18

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 82 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch18.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'linked actor transform copy': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_36_8007938C` | linked actor transform copy | 41 | `e3116740895ff317cf386e5e8794cfcb6b4cf68d5da7b565cbd9ed5ad8ec73d4` | `asm/nonmatchings/overlays/level_36/moby/func_level_36_8007938C.s` |
| `func_level_41_8007CAD0` | linked actor transform copy | 41 | `88f5c878501a06d7d9b31be0f26ac82a4270e2c9c2fa95547c55a0eb67651769` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_8007CAD0.s` |
