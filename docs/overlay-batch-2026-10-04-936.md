# Verified overlay batch 2026-10-04-936

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 140 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch936.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Reuse baseline: SpyroCode `docs/yotd-re/playable-desert-raw965-direct-controller-runtime.md` and its source-local decoder, Rev1 handler 0x800810F0..0x8008131C. The normalized crosswalk agrees with Rev0 0x80081010..0x80081240; every original Rev0 linked word is audited independently. Byte bit-0 gates, signed 32-bit post-helper reads, private offset +0x28, 88-byte actor stride, six-argument callback stack slots, and repeated reads remain literal. The last timer write at 0x80081214 uses S1 (indexed actor private data), not S0 (owner private data); the existing Rev1 prose labels this destination incorrectly. No Rev1 decoder file was changed. Timer 120 is a literal word write, not a proven duration; units, helper/callback outcomes, dynamic producers, caller cadence and runtime presentation remain open. Upstream Moby and SpawnFragments declarations are reused; empty assembly constraints are unnecessary for this function.

Categories: {'Rev1 raw965 gate and fragments controller': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_42_80081010` | Rev1 raw965 gate and fragments controller | 140 | `906e6adfb149dc4da579f0e873c99cc79504bbbb94ff6c6ff1f585fd8ce18988` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_80081010.s` |
