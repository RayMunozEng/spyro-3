# Verified overlay batch 2026-10-03-176

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 9 functions, 666 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch176.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Existing SDK camera, player, vector and Savepoint declarations provide the field baseline. Camera modes 0xD and 0x11 retain distinct initialization paths and the original camera copy-helper sequence. Private symbol aliases and empty register constraints preserve original address materialization without emitting instructions. The counter/vector routine preserves bounds and movement-state gates, a signed counter advanced by 3 while below 0x120, Q12 trigonometric products, and the original player flag/byte stores. The checkpoint routine preserves trigonometric products multiplied by 0x13 then arithmetically shifted by 5, angle subtraction by 0x80, the temporary actor-state clear/restore, and both saved-state calls. Coordinate domain meanings remain unestablished; these constants and shifts are supported by the listed Rev 0 instructions.

Categories: {'bounds-gated trigonometric checkpoint position and saved state': 3, 'camera two-mode initialization and vector copy chain': 3, 'bounds and movement gated counter trigonometric vector writes': 3}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_16_8007C960` | bounds-gated trigonometric checkpoint position and saved state | 76 | `f46d4fa3f36b2851912f16b88ff952b319bf7030bdb15505c044112458e28d6a` | `asm/nonmatchings/overlays/level_16/moby/func_level_16_8007C960.s` |
| `func_level_36_8007DD58` | bounds-gated trigonometric checkpoint position and saved state | 76 | `f46d4fa3f36b2851912f16b88ff952b319bf7030bdb15505c044112458e28d6a` | `asm/nonmatchings/overlays/level_36/moby/func_level_36_8007DD58.s` |
| `func_level_46_8007AAC0` | bounds-gated trigonometric checkpoint position and saved state | 76 | `f46d4fa3f36b2851912f16b88ff952b319bf7030bdb15505c044112458e28d6a` | `asm/nonmatchings/overlays/level_46/moby/func_level_46_8007AAC0.s` |
| `func_level_17_80083CA8` | camera two-mode initialization and vector copy chain | 74 | `9718bc3e852ce052697b5b4b4808229056ce2c0e9ca1a7d517e2d0bcf1724bd1` | `asm/nonmatchings/overlays/level_17/camera/func_level_17_80083CA8.s` |
| `func_level_27_8008999C` | camera two-mode initialization and vector copy chain | 74 | `d7e09c05c40b63ccbb19a437d2e26cb079edb09f50ca4fdcf4e132d8369e538b` | `asm/nonmatchings/overlays/level_27/camera/func_level_27_8008999C.s` |
| `func_level_37_8008B7F4` | camera two-mode initialization and vector copy chain | 74 | `f67a1c7757be2b06edc796b48f4ba2c1f3819c52ac54d454f9a966d10a6078f0` | `asm/nonmatchings/overlays/level_37/camera/func_level_37_8008B7F4.s` |
| `func_level_10_8008356C` | bounds and movement gated counter trigonometric vector writes | 72 | `0d7d2b0ba04be4ac4b06578bffaa8e6a468130f0942357824bdcab84acdeb9ae` | `asm/nonmatchings/overlays/level_10/moby/func_level_10_8008356C.s` |
| `func_level_11_80084910` | bounds and movement gated counter trigonometric vector writes | 72 | `9a5565bbbe144e37da0f6948be2b1770308ec17396c1b111f2b9e321d1a6a819` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_80084910.s` |
| `func_level_20_800840CC` | bounds and movement gated counter trigonometric vector writes | 72 | `2502c11cb9d037fc594d2c89818bef64f7622766dda8ffbf6a9c38d07c193517` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_800840CC.s` |
