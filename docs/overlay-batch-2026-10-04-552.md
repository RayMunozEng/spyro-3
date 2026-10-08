# Verified overlay batch 2026-10-04-552

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 125 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch552.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes: the two initial particle attempts, RGB fade, packed alpha calculation and final sixteen-attempt burst preserve the original byte and halfword wrapping. Empty constraints retain the original order of random-result masking, particle halfword subtraction/addition and stores, without emitted instructions. Return values and all original words match.

Categories: {'colour fade two particle attempts and final sixteen-particle burst': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_31_80088738` | colour fade two particle attempts and final sixteen-particle burst | 125 | `ba0533c8fb0d1c96c1c8684fc8cde608bb88562ba226f17707bf07e5cf1c2e56` | `asm/nonmatchings/overlays/level_31/level/func_level_31_80088738.s` |
