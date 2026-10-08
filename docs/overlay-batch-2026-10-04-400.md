# Verified overlay batch 2026-10-04-400

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 3 functions, 184 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch400.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: animation dispatch reuses the previously verified animation-selector C structure and preserves this overlay’s additional 0xAF/0xB0 branches. The two actor handlers use existing Moby and Savepoint layouts for original damage/state gates, persistence calls, referenced actor reads, particle helper arguments, and deletion calls. Empty compiler constraints in the selector emit no instructions and only preserve retail scheduling.

Categories: {'animation state selection and vector/reset dispatch': 1, 'state and damage gated persistence and deletion chain': 1, 'linked actor damage gate and position update': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_15_80088804` | animation state selection and vector/reset dispatch | 52 | `d7dc0eeacd28092194f37d07993807be4a94d86a781616ed8dddd5fa6e3ef73c` | `asm/nonmatchings/overlays/level_15/animation/func_level_15_80088804.s` |
| `func_level_23_80088DAC` | state and damage gated persistence and deletion chain | 74 | `6b54f30d27283393aa21e8454c0d2a041ed16574ca4d9ca6947bd755a60b2178` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_80088DAC.s` |
| `func_level_47_8007CE50` | linked actor damage gate and position update | 58 | `3754510896247fd0de82a672c45fd5cd700548f9cf76b15180b6d8762c581ac8` | `asm/nonmatchings/overlays/level_47/moby/func_level_47_8007CE50.s` |
