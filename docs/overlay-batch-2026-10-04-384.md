# Verified overlay batch 2026-10-04-384

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 158 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch384.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: two leaf completion-record calculations, using a partial record layout backed by the original byte/halfword offsets. Preserves active-byte gate, all 39 signed score entries, all eight flag bits per entry, both excluded-index capacity tables, multiplication by 100 and signed division, and the nonzero-total minimum return of one. Empty constraints retain the bit-loop initialization schedule without emitting instructions. The original divisor-zero/overflow traps remain part of the matched instruction chain; no additional guards were invented. Percentage labels describe arithmetic and do not independently establish the meaning of each score or table byte.

Categories: {'completion record bit count and percentage arithmetic': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_options_80077B58` | completion record bit count and percentage arithmetic | 79 | `7e98c51ee634e809ce2d3033ca64c82ad906ca5fe2fedf589fe372cff8e60faa` | `asm/nonmatchings/overlays/options/options2/func_options_80077B58.s` |
| `func_title_8007928C` | completion record bit count and percentage arithmetic | 79 | `a2a8174261df5f4028240877b8bb9a364cefb214fed9a88b3b445871a6203cd4` | `asm/nonmatchings/overlays/title/title2/func_title_8007928C.s` |
