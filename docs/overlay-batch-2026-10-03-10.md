# Verified overlay batch 2026-10-03-10

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 8 functions, 272 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch10.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'damage flag and state gated animation': 4, 'animation range gated EXE helper sequence': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_16_800795C4` | damage flag and state gated animation | 36 | `7b7848a6db0a0aa4602cab7833d58b2d3246d7f116eadfd3712f75fe940f5d76` | `asm/nonmatchings/overlays/level_16/moby/func_level_16_800795C4.s` |
| `func_level_32_8007D748` | damage flag and state gated animation | 36 | `7b7848a6db0a0aa4602cab7833d58b2d3246d7f116eadfd3712f75fe940f5d76` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_8007D748.s` |
| `func_level_44_8007A0E0` | damage flag and state gated animation | 36 | `7b7848a6db0a0aa4602cab7833d58b2d3246d7f116eadfd3712f75fe940f5d76` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_8007A0E0.s` |
| `func_level_46_80079910` | damage flag and state gated animation | 36 | `7b7848a6db0a0aa4602cab7833d58b2d3246d7f116eadfd3712f75fe940f5d76` | `asm/nonmatchings/overlays/level_46/moby/func_level_46_80079910.s` |
| `func_level_18_80087CEC` | animation range gated EXE helper sequence | 32 | `3e50e31e37d856367e0d35c90e0f3b12f39c5f46be0553e9961d7ec1c6a780b1` | `asm/nonmatchings/overlays/level_18/animation/func_level_18_80087CEC.s` |
| `func_level_28_80085E3C` | animation range gated EXE helper sequence | 32 | `3e50e31e37d856367e0d35c90e0f3b12f39c5f46be0553e9961d7ec1c6a780b1` | `asm/nonmatchings/overlays/level_28/animation/func_level_28_80085E3C.s` |
| `func_level_38_8008806C` | animation range gated EXE helper sequence | 32 | `3e50e31e37d856367e0d35c90e0f3b12f39c5f46be0553e9961d7ec1c6a780b1` | `asm/nonmatchings/overlays/level_38/animation/func_level_38_8008806C.s` |
| `func_level_48_800870A4` | animation range gated EXE helper sequence | 32 | `3e50e31e37d856367e0d35c90e0f3b12f39c5f46be0553e9961d7ec1c6a780b1` | `asm/nonmatchings/overlays/level_48/animation/func_level_48_800870A4.s` |
