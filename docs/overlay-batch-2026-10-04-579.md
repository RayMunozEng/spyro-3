# Verified overlay batch 2026-10-04-579

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 140 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch579.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream Moby, animation, vector, and sound interfaces, with original level-43 instructions. Empty compiler constraints preserve the original ordering and register reuse for fragment halfword and byte writes; they emit no instructions. Damage handling exits before the state switch, and the original timer decrement, random ranges, animation progress, and fragment-completion branches remain exact.

Categories: {'timed animation actor damage and fragment transition': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_43_80082594` | timed animation actor damage and fragment transition | 140 | `5a474f4aedcf52b48bd0d9e38bf12930d4f81625302e23c1f6e56b4872c8d6dd` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_80082594.s` |
