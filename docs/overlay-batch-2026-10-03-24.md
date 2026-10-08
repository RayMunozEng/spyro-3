# Verified overlay batch 2026-10-03-24

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 84 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch24.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'HUD clamped 144-unit ratio': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_32_80091640` | HUD clamped 144-unit ratio | 42 | `d235f2aa401495cb966e52536c5feed310edbbd1c1ba869cca39898618dcdf64` | `asm/nonmatchings/overlays/level_32/level/func_level_32_80091640.s` |
| `func_level_50_80093E2C` | HUD clamped 144-unit ratio | 42 | `d235f2aa401495cb966e52536c5feed310edbbd1c1ba869cca39898618dcdf64` | `asm/nonmatchings/overlays/level_50/level/func_level_50_80093E2C.s` |
