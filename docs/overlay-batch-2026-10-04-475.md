# Verified overlay batch 2026-10-04-475

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 7 functions, 906 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch475.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The six-actor handler preserves the original capacity check before every spawn, including early exit with the last spawn result retained. Signed spacing arithmetic, byte and halfword actor initialization, selector dispatch, final sound call and deletion follow the original instructions. The two cutscene allocators share the matching C baseline from this batch; each retains its own class constants, initialization helper and parent-tag assignment. Four particle-routine copies preserve model-point midpoints, signed Q12 trig-table products with separate original random calls, both particle dispatches, and conditional effect-tag allocation. All helper IDs remain numeric where semantics are unproven. Empty constraints emit no instructions and retain signed division scheduling. SDK Moby/vector fields are reused with identified original widths.

Categories: {'selector-gated six-actor spawn and original grid offsets': 1, 'cutscene actor allocation, linked parent index and class-specific initialization': 2, 'cutscene model-point midpoint particles and tagged effect initialization': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_23_8008ABAC` | selector-gated six-actor spawn and original grid offsets | 104 | `af879fa26a7352d6c5a366bbe19de84070ff4cdea99d32757401ab37d2f2ec7e` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_8008ABAC.s` |
| `func_cutscene_73_80075220` | cutscene actor allocation, linked parent index and class-specific initialization | 102 | `ec0af3af5b0c26adabfed093cd2c84bc1622b682542fa378f4141a6d42ff6544` | `asm/nonmatchings/overlays/cutscene_73/moby/func_cutscene_73_80075220.s` |
| `func_cutscene_78_80074BC8` | cutscene actor allocation, linked parent index and class-specific initialization | 104 | `2cd040799423622196501f24e17b7ed9889ddad7b34e8e1a49e69bb96530cf50` | `asm/nonmatchings/overlays/cutscene_78/moby/func_cutscene_78_80074BC8.s` |
| `func_cutscene_62_80074788` | cutscene model-point midpoint particles and tagged effect initialization | 149 | `3bbb8c94c344add84c778f862a6903e0e97aa10ef7e1a35457b35cd6d027bd3c` | `asm/nonmatchings/overlays/cutscene_62/moby/func_cutscene_62_80074788.s` |
| `func_cutscene_64_80074788` | cutscene model-point midpoint particles and tagged effect initialization | 149 | `3bbb8c94c344add84c778f862a6903e0e97aa10ef7e1a35457b35cd6d027bd3c` | `asm/nonmatchings/overlays/cutscene_64/moby/func_cutscene_64_80074788.s` |
| `func_cutscene_69_80074788` | cutscene model-point midpoint particles and tagged effect initialization | 149 | `3bbb8c94c344add84c778f862a6903e0e97aa10ef7e1a35457b35cd6d027bd3c` | `asm/nonmatchings/overlays/cutscene_69/moby/func_cutscene_69_80074788.s` |
| `func_cutscene_73_80074808` | cutscene model-point midpoint particles and tagged effect initialization | 149 | `3bbb8c94c344add84c778f862a6903e0e97aa10ef7e1a35457b35cd6d027bd3c` | `asm/nonmatchings/overlays/cutscene_73/moby/func_cutscene_73_80074808.s` |
