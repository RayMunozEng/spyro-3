# Verified overlay batch 2026-10-03-231

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 128 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch231.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- `func_level_41_80087854` preserves the state-save callback, environment selector, high-byte gate and low-nibble cleanup test. Numeric selectors retain their original values; their semantic meaning remains unreviewed.
- `func_loading_80076EE8` preserves the buffer helpers, timer threshold, both text tables, style selection and fade call. A private alias gives the fade call its original four full-width arguments. Empty constraints emit no instructions and preserve the original second-table load order.

Categories: {'saved state and environment-word gated callback cleanup': 1, 'loading buffer clear, gated text and full-width fade call': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_41_80087854` | saved state and environment-word gated callback cleanup | 63 | `a9af5f3407649b0a8565c32a6925ff2de1bf9332e7b54351ec41e94fe2475195` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_80087854.s` |
| `func_loading_80076EE8` | loading buffer clear, gated text and full-width fade call | 65 | `3ee23b1de822f3a4cfd52040fe66bdf238b1829a92f224482d2ff1b748599663` | `asm/nonmatchings/overlays/loading/loading3/func_loading_80076EE8.s` |
