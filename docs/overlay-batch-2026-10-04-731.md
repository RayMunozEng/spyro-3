# Verified overlay batch 2026-10-04-731

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 108 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch731.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Rev 1 reuse: SpyroCode `playable-charmed-raw947-direct-controller-runtime.md` identifies the initial player flag/bounds/height gates, child-pointer rebinding, and signed table multiply by 25 with arithmetic shift seven. The child receives player position plus the exact table offsets and Z+500. Nonzero owner states store the state byte through both persistence helpers and release the owner. Empty constraints emit no instructions; they preserve the global height load order, retained player-field base, and separate table-index reads across child stores. No complete actor or runtime timing claim is made.

Categories: {'player height gate and child offset initialization': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_34_8007CEA8` | player height gate and child offset initialization | 108 | `1ba7a7b234578f21297ba2f933db2087a9e426cf219c76288839bd5c4b47aa17` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_8007CEA8.s` |
