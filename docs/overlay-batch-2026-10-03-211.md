# Verified overlay batch 2026-10-03-211

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 212 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch211.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

These routines reuse existing actor/vector and RECT/GPU declarations. The attachment update preserves its two class selectors, the unsigned halfword loads followed by original signed yaw narrowing, counter increment 0xE0, deletion threshold 0x400, and colour alpha formula. The paired-actor gate preserves the combined state/substate halfword comparison to 0x162, numeric fragment arguments and post-fragment calls. The title loop retains all 12 iterations (4..15), decode-size selector (15-index)*2, arithmetic shifts 11/10, both image transfers with Y delta 0xE4, VSync and DrawSync. The progress timer preserves global bit-4 gates, signed division by 10 before and after the delta update, environment callback on quotient change, and deletion only in the original branches. Meanings of the selectors and unknown tags remain unestablished.

Categories: {'attachment position, camera angles and counter colour': 1, 'paired actor state gate and fragment deletion sequence': 1, 'title image-size transfer loop': 1, 'progress timer quotient and environment update': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_25_8007D358` | attachment position, camera angles and counter colour | 53 | `8bf4caf5e59d6441099a1793dfb498e6224214d13696d60a0afc61218e2be6f7` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_8007D358.s` |
| `func_level_26_80083B58` | paired actor state gate and fragment deletion sequence | 53 | `173b9f77f0f0f3b23a4b1c183c3422eef821b8d3de2e9cd573d5a743fc9f1718` | `asm/nonmatchings/overlays/level_26/moby/func_level_26_80083B58.s` |
| `func_title_80078848` | title image-size transfer loop | 52 | `7fc62401e440fec8b15a8cd52215e9aa055165a31208e8e250ddffe20acbcecc` | `asm/nonmatchings/overlays/title/title1/func_title_80078848.s` |
| `func_level_13_80082D54` | progress timer quotient and environment update | 54 | `49a370167deece5f8fe8de5cea182ba702ae4ec3690ad2d78ed57b756d92b08d` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_80082D54.s` |
