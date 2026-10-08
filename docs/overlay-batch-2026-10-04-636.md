# Verified overlay batch 2026-10-04-636

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 165 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch636.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream Moby and Vector3D types and particle helpers. The original level 27 routine defines both burst loops, random ranges, distance and angle guards, player flags and timer-driven removal. Ordinary C compiled exactly without compiler constraints.

Categories: {'timed directional particle burst and player flags': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_27_8007CE84` | timed directional particle burst and player flags | 165 | `e830f60446e13dc96e5d191bd940187147357892d46f02b1550a62e2949775e3` | `asm/nonmatchings/overlays/level_27/moby/func_level_27_8007CE84.s` |
