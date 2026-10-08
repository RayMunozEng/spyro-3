# Verified overlay batch 2026-10-03-226

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 3 functions, 180 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch226.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The two initializers reuse the verified SDK camera baseline with original selector groups: 3/0xC/0x17 versus 0xD in level 12, and 4 versus 0xD/0x13 in level 14. Distinct byte-0x141 values and original constant/address setup order are retained before the shared helper chain. The level 40 selector retains mode 0x11 versus modes 0x15/0x17, their distinct override conditions, animation-table loads and selector-6 fallback. Private aliases and empty constraints preserve original repeated address materialization without emitting instructions. Unknown camera coordinate units and further semantic mode interpretations remain unestablished.

Categories: {'four-mode camera initializer with distinct flags': 1, 'three-mode camera initializer with distinct flags': 1, 'camera mode selector with distinct override fallback paths': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_12_8008B9D4` | four-mode camera initializer with distinct flags | 60 | `7fc9f7116bd99588c9fc37c6ce1008800aa52eae290fdcc8fe89e10a86beb10f` | `asm/nonmatchings/overlays/level_12/camera/func_level_12_8008B9D4.s` |
| `func_level_14_80099478` | three-mode camera initializer with distinct flags | 60 | `4800a3b54caf60381f1986c1969a7f43d8324ed5b03cdc2891170de3281d8640` | `asm/nonmatchings/overlays/level_14/camera/func_level_14_80099478.s` |
| `func_level_40_800871C4` | camera mode selector with distinct override fallback paths | 60 | `4a87a352e3485edc570c6f1348d691d3d6f5c4805298e9785c280207521cd8b0` | `asm/nonmatchings/overlays/level_40/camera/func_level_40_800871C4.s` |
