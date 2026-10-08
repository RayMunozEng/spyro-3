# Verified overlay batch 2026-10-04-741

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 118 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch741.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Rev 1 reuse: SpyroCode `playable-lost-fleet-raw213-direct-controller-runtime.md` supplied the immediate state/global-bit release routes, private-word yaw selector, ten child requests, animation-table setup, post-helper position rereads, and damage-only persistence route. Rev 0 original instructions show the random animation selector is refreshed inside each iteration. State one and global-bit exits call only release, skipping persistence. Computing the animation-progress value before the animation-field stores reproduces the original table read and store schedule. Ordinary C matches all 118 words, with no register constraints. Model table contents, numeric type semantics, helper effects, and live factory results remain unknown.

Categories: {'persistent damage spawn animation table initialization and random positions': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_32_800852A8` | persistent damage spawn animation table initialization and random positions | 118 | `3b29711685e912082dd1f8a098eef3018b8406737c07753f3efb51447779f4b8` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_800852A8.s` |
