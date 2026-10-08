# Verified overlay batch 2026-10-04-752

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 129 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch752.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Rev 1 reuse: SpyroCode `playable-enchanted-raw982-direct-controller-runtime.md` establishes the four local state routes, exact-one global gates, player-actor reset sequence and indexed camera selector. The original Rev0 instructions preserve the unknown fourth save-helper argument by using a three-argument alias. State two captures the initial player actor and its private pointer, then deliberately reloads the global actor for later accesses; its global pointer is volatile to retain those reads. Empty constraints emit no instructions and preserve the initial private-pointer load before stores and copy-argument setup. State three keeps separate observations of player word +0x244 around the helper call. All 129 linked words are exact. Global producers, helper effects, runtime pointer validity and invocation cadence remain unknown.

Categories: {'four-state player actor reset and indexed camera selector': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_22_8008471C` | four-state player actor reset and indexed camera selector | 129 | `98786b14231a49938b9da7516fe74bec888e7242812967c462b2db751b6da58c` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_8008471C.s` |
