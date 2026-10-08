# Verified overlay batch 2026-10-04-637

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 164 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch637.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream Moby, Vector3D and collision helpers, with the original level 25 routine defining aiming, matrix movement, two timers, actor and world collision queries, spawn capacity and removal. Ordinary C compiled exactly without compiler constraints.

Categories: {'directed projectile timers collision and removal': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_25_8007D0C8` | directed projectile timers collision and removal | 164 | `36ee325524c47173cef058fd895995f9cbdd189f7e742785e594b6b25fb5bd08` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_8007D0C8.s` |
