# Verified overlay batch 2026-10-04-522

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 99 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch522.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes: ordinary C preserves the original X/Y/Z lower bounds, X/Y upper bounds, tagged velocity/gravity, player attraction vector normalized through the existing helpers, floor clamp and delayed class 0x2FB spawn. No scheduling constraints are needed. This build also verifies removing a duplicate partial-tag typedef introduced by the two level 47 collision additions; their instruction bytes remain unchanged.

Categories: {'bounded tagged movement attraction vector floor transition and actor spawn': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_47_80081120` | bounded tagged movement attraction vector floor transition and actor spawn | 99 | `e156207421d2524b2089bf672ac478f10ca27e05003a489e56d6fd1ee2cb45bc` | `asm/nonmatchings/overlays/level_47/moby/func_level_47_80081120.s` |
