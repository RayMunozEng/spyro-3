# Verified overlay batch 2026-10-04-674

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 177 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch674.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation follows `func_level_43_800822D0` directly. The tag retains its timer and linked index at offsets 0 and 4; reset counters retain halfword stores at four-byte strides. Spawn state, substate, yaw and counter updates preserve original order. This ordinary C implementation uses no allocation constraints or instruction assembly.

Categories: {'linked counter damage and timed spawn': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_43_800822D0` | linked counter damage and timed spawn | 177 | `af7c919f40cc5e36ca66a23fb814ef9466e14174575de3b73a5fa9a1bfc84b9b` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_800822D0.s` |
