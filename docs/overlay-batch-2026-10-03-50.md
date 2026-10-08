# Verified overlay batch 2026-10-03-50

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 132 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch50.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Existing upstream SpeedwayRecord layout and the original speedway class lookup are the baseline.

## Widths, scheduling and remaining evidence

The selected class is a signed Moby halfword. The index and counter are 32-bit values; records have the original 44-byte stride. Empty compiler constraints retain the recorded index-shift/base-add ordering and destination register without emitting instructions. No time unit is inferred for the counter. Next evidence target: the class table producer and the selected record counter consumer.

Categories: {'speedway class table and counter selection': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_15_80082BFC` | speedway class table and counter selection | 33 | `a6e9a6497c1a44616d449f92148ffa9ceb11e4c33641e73e0e58a7a8a31ec852` | `asm/nonmatchings/overlays/level_15/level/func_level_15_80082BFC.s` |
| `func_level_25_800835B4` | speedway class table and counter selection | 33 | `f0e2abcee17e4750002000550ac24a71baf6e107d85508f8fbbf79cdef9a6ef0` | `asm/nonmatchings/overlays/level_25/level/func_level_25_800835B4.s` |
| `func_level_35_80084938` | speedway class table and counter selection | 33 | `d16803390f2dc3a896fab5aaaff7174999d13690b16e1f1dad8e6c3e1387cb7d` | `asm/nonmatchings/overlays/level_35/level/func_level_35_80084938.s` |
| `func_level_45_80082EF4` | speedway class table and counter selection | 33 | `96ede079d93f12d503e3a56429267ec944378745c861292eabbb413a20fcf54e` | `asm/nonmatchings/overlays/level_45/level/func_level_45_80082EF4.s` |
