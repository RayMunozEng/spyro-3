# Verified overlay batch 2026-10-04-431

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 344 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch431.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: reuses upstream Moby, Spyro, sound, vector, and fragment callback conventions. Preserves sound handle testing/release, fragment and motion callback arguments, standing-on-actor state gates, original player-field writes, and vector offsets. The two direction helpers use the same verified C and preserve thresholds, signed axis reduction, and exact per-overlay table symbols. Empty constraints emit no instructions and preserve original address order.

Categories: {'sound handle fragment damage and motion callbacks': 1, 'standing actor state and player offset-vector update': 1, 'two-axis hysteresis and signed direction lookup': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_25_8007A0E8` | sound handle fragment damage and motion callbacks | 84 | `88679516a4ec25c07994c8f45d58e2cfdd255a370dc1c966c2172c8345081465` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_8007A0E8.s` |
| `func_level_24_80082BEC` | standing actor state and player offset-vector update | 84 | `f8acb9ac4dc0ae889d90e3c15e230dcf5417df981c03f9dbe89158103bd932c8` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_80082BEC.s` |
| `func_level_18_80085690` | two-axis hysteresis and signed direction lookup | 88 | `ff722a4e8c6af01f645030790b5baa335e78fb08e8937f88b661e7a1834dcf0d` | `asm/nonmatchings/overlays/level_18/level/func_level_18_80085690.s` |
| `func_level_28_80083800` | two-axis hysteresis and signed direction lookup | 88 | `5524b50729287cb333396d94e903a12cfb0eb05913c8a832c19f1a302e300422` | `asm/nonmatchings/overlays/level_28/level/func_level_28_80083800.s` |
