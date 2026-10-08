# Verified overlay batch 2026-10-03-56

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 180 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch56.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Existing upstream Spyro layout and original animation/callback declarations are the baseline.

## Widths, scheduling and remaining evidence

The routine compares the original animation state against 0x98 and 0x99, queries the callback with literal 1, and tests bit 0x80 of the original word input state before selecting the opposite animation. The callback alias retains the existing absolute overlay-header symbol. No new semantic interpretation of that input bit is claimed. Next evidence target: callback producer and animation state timing in retail captures.

Categories: {'animation selector callback and pad bit transition': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_18_80087E90` | animation selector callback and pad bit transition | 45 | `b84005d639fe6827ce27163ee1d77e23191378b3be19e139ecd5b60e0309d7d3` | `asm/nonmatchings/overlays/level_18/animation/func_level_18_80087E90.s` |
| `func_level_28_80085FE0` | animation selector callback and pad bit transition | 45 | `c6fdc7318093d2f71c5d263fd0fed4354d087a8519566fde7b0ebf9426caa0f0` | `asm/nonmatchings/overlays/level_28/animation/func_level_28_80085FE0.s` |
| `func_level_38_80088210` | animation selector callback and pad bit transition | 45 | `90cdbe47f7d0df9c006c7de785bb3cc2dde38a0d2e34a0a299dcb10e86a679e4` | `asm/nonmatchings/overlays/level_38/animation/func_level_38_80088210.s` |
| `func_level_48_80087248` | animation selector callback and pad bit transition | 45 | `988fa18a08b6f646984b086bd8f8ed7c46ce612032ff88fcb76f027f8f5ced27` | `asm/nonmatchings/overlays/level_48/animation/func_level_48_80087248.s` |
