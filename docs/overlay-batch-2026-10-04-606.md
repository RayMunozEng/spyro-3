# Verified overlay batch 2026-10-04-606

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 310 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch606.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: original level-11 instruction stream and its identical level-22 copy, with existing upstream Moby, animation, angle, and Vector3D structures. Both preserve animation-word comparisons, three stack vectors, model point queries, the original 275 multiplier with shift eleven, signed heading-dependent length, visibility writes, and linked-actor removal. Ordinary C compiles exactly without compiler constraints or emitted assembly.

Categories: {'linked animation gated model point position and orientation': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_11_80079CFC` | linked animation gated model point position and orientation | 155 | `f9ab1b08883dae6385c8ca7d827cc72ce8376b7a4e11fe2303d819c4edf04f42` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_80079CFC.s` |
| `func_level_22_80082CCC` | linked animation gated model point position and orientation | 155 | `ebc286268586510da54def155551a566cf74dd3eab4fe5be51cac1c66da8e52e` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_80082CCC.s` |
