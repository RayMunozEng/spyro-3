# Verified overlay batch 2026-10-04-573

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 133 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch573.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream Moby and player structures, with the original level-43 instruction stream. The two linked-index list loops retain their halfword termination marker and low fifteen index bits. An empty constraint retains the original list-pointer register; integer address arithmetic retains original ADDU operand order. No emitted assembly instructions or inferred actor behavior were added.

Categories: {'bounds controlled linked actor substate lists': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_43_80088418` | bounds controlled linked actor substate lists | 133 | `6a79e82e304ff730a83cddc71b391e885c0cd5e265bd29478271688bc1ea9a98` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_80088418.s` |
