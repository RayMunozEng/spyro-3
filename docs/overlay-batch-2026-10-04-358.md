# Verified overlay batch 2026-10-04-358

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 396 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch358.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: four interaction gate routines decoded directly from the listed original assembly, using the existing Moby layout and a partial tag layout. Preserves numeric class tests (including unsigned range 0x2AB..0x2AC and signed comparisons), referenced-actor state gate, input bit 0x10, both interaction-helper calls, activation helper, status clearing and states 0/1. No empty compiler constraints or instruction assembly are needed in these additions. Field labels describe access and control flow; they do not establish helper or gameplay semantics.

Categories: {'actor interaction gate and state dispatch': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_80079D58` | actor interaction gate and state dispatch | 99 | `244b2338c1f7b778a54ec333458f6d2b29a13ad64c0af90beb8f54b1b203c663` | `asm/nonmatchings/overlays/level_10/moby/func_level_10_80079D58.s` |
| `func_level_20_8007AD74` | actor interaction gate and state dispatch | 99 | `763c88d98c4163bec0ea7771b1a9d6761225d199adf0485b16f849c7be6ca133` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_8007AD74.s` |
| `func_level_30_80079FC0` | actor interaction gate and state dispatch | 99 | `91f6943fffd6ac71692945bbfc9bae9caa0cba49795b1a834f624e05db99c73e` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_80079FC0.s` |
| `func_level_40_80079684` | actor interaction gate and state dispatch | 99 | `1a5d5ad5e95f25abf89661ad2a242b1a0ab7d61ecb5fb5b103a81a638b264d96` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_80079684.s` |
