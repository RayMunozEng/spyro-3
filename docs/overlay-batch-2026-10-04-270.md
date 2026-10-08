# Verified overlay batch 2026-10-04-270

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 168 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch270.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- Two identical callback routines preserve actor class 0x2AC, progress byte and per-level bit selection, tag byte gates, input flag 0x10, helper callbacks and state-1 restoration.
- The input-flag false branch skips the byte-7 clear; the original branch target is retained. The helper-success path enters the shared callback block, while the second helper failure clears byte 7.
- Empty constraints preserve the selector register and the byte-clear/reload order. Partial tag fields remain numeric; no new event or input interpretation is claimed.

Categories: {'progress and input gated actor callback states': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_13_8007AFFC` | progress and input gated actor callback states | 84 | `8e024156c48e83afb39341dc77b380d6def90636d197965ee7a651519e4e04b2` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_8007AFFC.s` |
| `func_level_34_8007C4B8` | progress and input gated actor callback states | 84 | `3e8f5abbc360b296d63383458695e910bcb6cfedde97f45a771800bd1f5a8245` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_8007C4B8.s` |
