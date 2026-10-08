# Verified overlay batch 2026-10-04-657

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 3 functions, 525 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch657.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream Moby, Colour and HUD helpers. Three copies were compiled individually with their original four-entry HUD table. Ordinary C preserves the state 0 fallthrough, colour branches, save-state calls, conditional object spawn, HUD allocation and deletion. No compiler constraints were required.

Categories: {'collectible colour save state and HUD allocation': 3}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_18_8007A5E8` | collectible colour save state and HUD allocation | 175 | `915acb31bdc80f90a9e4342c91bd18468e9b183abc5dd669d3ffbd45f2c2669c` | `asm/nonmatchings/overlays/level_18/moby/func_level_18_8007A5E8.s` |
| `func_level_28_8007A414` | collectible colour save state and HUD allocation | 175 | `90fabc9d22306cab0aef95b64b8d992418c1a1d5a077dca40c6140fe793e4fd0` | `asm/nonmatchings/overlays/level_28/moby/func_level_28_8007A414.s` |
| `func_level_48_8007A43C` | collectible colour save state and HUD allocation | 175 | `01a6cf67841dfb8acee55b8a47efcbc0cb8a0f30db7efc7ba2cfe967f9dd206e` | `asm/nonmatchings/overlays/level_48/moby/func_level_48_8007A43C.s` |
