# Verified overlay batch 2026-10-03-12

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 140 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch12.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'vector limit and spawned record setup': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_18_80082CC4` | vector limit and spawned record setup | 35 | `2a29f6daec6ab15e87e432fcfbed9a7090502b52db6043ece1a1343361eb4fc4` | `asm/nonmatchings/overlays/level_18/moby/func_level_18_80082CC4.s` |
| `func_level_28_80080928` | vector limit and spawned record setup | 35 | `2a29f6daec6ab15e87e432fcfbed9a7090502b52db6043ece1a1343361eb4fc4` | `asm/nonmatchings/overlays/level_28/moby/func_level_28_80080928.s` |
| `func_level_38_80082780` | vector limit and spawned record setup | 35 | `2a29f6daec6ab15e87e432fcfbed9a7090502b52db6043ece1a1343361eb4fc4` | `asm/nonmatchings/overlays/level_38/moby/func_level_38_80082780.s` |
| `func_level_48_80081D1C` | vector limit and spawned record setup | 35 | `2a29f6daec6ab15e87e432fcfbed9a7090502b52db6043ece1a1343361eb4fc4` | `asm/nonmatchings/overlays/level_48/moby/func_level_48_80081D1C.s` |
