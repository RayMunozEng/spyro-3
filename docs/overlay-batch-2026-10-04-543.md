# Verified overlay batch 2026-10-04-543

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 120 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch543.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes: ordinary C preserves the damage-mask byte flag, saved actor state and animation, dialogue flag update, random particle vector and returned particle halfword addition, completion gate and animation/state restoration. The original three-word vector stack slot and all calls match without scheduling constraints.

Categories: {'damage saved state dialogue flags random particle and animation restore': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_11_80080900` | damage saved state dialogue flags random particle and animation restore | 120 | `5b06b4cf5cfe444d56bac9d56421286a0070d4da980a5542fa447ee4ca453c71` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_80080900.s` |
