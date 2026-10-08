# Verified overlay batch 2026-10-04-554

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 127 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch554.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes: ordinary C preserves the path callback, position query and initial fallthrough, cached actor coordinates, sound-handle validity checks, original strength increments/decrements and clamp, release path and the two saved-coordinate writes. No new sound identity is inferred. Calls, access widths and stack layout match without scheduling constraints.

Categories: {'path initialization grounded actor movement sound strength and saved coordinates': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_41_80087658` | path initialization grounded actor movement sound strength and saved coordinates | 127 | `4db8d7f399bc64b202e42f777e92d4bd44c69eb16f6328e1aa093e5698c43c0a` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_80087658.s` |
