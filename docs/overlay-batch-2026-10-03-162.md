# Verified overlay batch 2026-10-03-162

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 158 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch162.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: upstream `Moby`, `Spyro`, `SpriteData`, particle/drawing helpers and exact assembly/table entries. The parent/child routine preserves literal class 0x13A, global clearing, draw/difficulty-byte changes and the two helper calls before setting both state bytes to one. The critter-mode routine preserves tag word +0, update-distance byte 0xFF, states 0/1 and literal world-helper arguments 0xFC/0. The animation routine stores the 16-byte record address then uses all ten original table entries (states 0x64..0x6D) to select Spyro vector +0xCC or null for the helper. The table audit checks original linked targets as well as text. The atlas routine keeps two independent loads through aliases of the same sprite-data global, centres using integer bound differences shifted right once, and preserves original full-width coordinates at the draw call; a private call-site declaration avoids narrowing introduced by the upstream short-argument prototype. Empty constraints retain argument setup order. These operations are confirmed at the instruction/address level; semantic animation labels, particle payload meaning, sprite units and invocation cadence remain unresolved. Next evidence target: table consumers, sprite coordinate domains and parent/child helper state provenance.

Categories: {'atlas sprite centering and two draw helper sequence': 1, 'spawned actor helper and parent child state chain': 1, 'critter-mode gated world helper and actor state': 1, 'animation record selection and table-controlled vector helper': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_atlas_80077EB8` | atlas sprite centering and two draw helper sequence | 38 | `ff3e21f5707280301c226caf31631bbe5fb7c881e093e9780ba7c80ca94aa3ba` | `asm/nonmatchings/overlays/atlas/atlas1/func_atlas_80077EB8.s` |
| `func_level_31_800860F0` | spawned actor helper and parent child state chain | 40 | `63d7d4eaf7eb8b71b0e8808460a2909ef9aa4841994060fedd5c27cbe9000440` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_800860F0.s` |
| `func_level_22_8008EA8C` | critter-mode gated world helper and actor state | 39 | `32fd4d84c4f7fd47c42b96bebfa753cbde8b66b67fab0c084a6192976754865c` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_8008EA8C.s` |
| `func_level_26_80089CEC` | animation record selection and table-controlled vector helper | 41 | `e251f04212b7d6d315a8d4ec83c94a4e329caf0f0613ee3f39b872c165fce1b5` | `asm/nonmatchings/overlays/level_26/animation/func_level_26_80089CEC.s` |
