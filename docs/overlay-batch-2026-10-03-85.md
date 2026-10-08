# Verified overlay batch 2026-10-03-85

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 62 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch85.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Existing upstream Moby layout and the original state/countdown/deletion helper calls are the baseline.

## Widths, scheduling and remaining evidence

State at Moby +0x48 and animation ID at +0x3C are unsigned bytes; the global flag is a 32-bit word. The nonzero-state path passes the tag pointer and literal 4 to func_800359A4. Its nonzero result gates deletion. Empty compiler constraints retain the original argument move in the conditional branch delay slot and emit no instructions. No interpretation of the countdown units beyond this helper call is claimed. Next semantic evidence target: the helper's complete tag producer chain and synchronized actor runtime capture.

Categories: {'state and countdown gated actor deletion': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_43_8007E370` | state and countdown gated actor deletion | 31 | `3acda633d509f493a79a80df8cb78c86afd649195de9b81224b042d4d3dddf03` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_8007E370.s` |
| `func_level_46_800833C0` | state and countdown gated actor deletion | 31 | `af0b1dcef0e225ddc9bc073be4678b0fc84dfc9662606941ba7c9fcdb3c162ad` | `asm/nonmatchings/overlays/level_46/moby/func_level_46_800833C0.s` |
