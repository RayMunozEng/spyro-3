# Verified overlay batch 2026-10-03-223

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 111 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch223.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The camera-request state handler uses the SDK movement-state field, original bounds helper, override-word reloads across calls, and exact request/release gates for movement states 0xD, 3 and 7. The damage-state handler retains bit 0x100000, state transition 1, six-argument callback in state 0 and fragment/post-fragment/deletion calls in state 1. A private typed alias for the upstream TODO callback declaration retains the original six-argument call site; it names the same pointer slot and does not introduce a new implementation. Empty constraints preserve original shared address bases and emit no instructions. Unknown callback and selector meanings remain explicit.

Categories: {'bounds-gated camera request and movement-state release': 1, 'damage-state callback or fragment deletion': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_42_80081240` | bounds-gated camera request and movement-state release | 55 | `ebd2171aff048321dab8c21412cbf7bcf9ca224a4aa68536bf67716f6aeb63ab` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_80081240.s` |
| `func_level_42_8007CFC8` | damage-state callback or fragment deletion | 56 | `ce1f306e6f0d7fd53613a941ad8fb8d87f6e35690384e9a63b93c643b9bb3cea` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_8007CFC8.s` |
