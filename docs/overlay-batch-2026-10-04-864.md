# Verified overlay batch 2026-10-04-864

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 14 functions, 3612 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch864.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Fourteen copies share this period-selected path displacement routine. The six arguments are an actor, a path record, a retained displacement vector, a counter pointer, an integer period, and flags. Period thresholds 9/7/5 select weight-table byte offsets 0x28/0x10/0 and counter thresholds 7/5/3; the remaining route uses D_8006C410 and threshold 1. Path count, index and signed step are 16-bit fields, and each point record has 16-byte stride.

When the counter reaches the period, the original selected-point minus actor-position helper supplies the displacement; that vector is copied to the retained vector, the path index uses the original signed remainder expression, the return flags record the update and the signed-step wrap condition, and the counter is reset. The two lower-counter routes retain their separate three signed divisions by `period - (counter - 1)`, including all division trap checks. The weighted route applies the two signed halfword weights with the original scale helper, adds the retained weighted vector, shifts through the original helper with 10, and increments the counter. Bit 2 clears displacement Z and gates func_80037014. The final angle-helper calls, displacement add and func_80055D24 call with 2 remain in original order. Empty constraints emit no instructions; no instruction-bearing inline assembly is added.

Units and cadence: path-coordinate scale and helper numeric domains remain unresolved; the integer period/counter and shifts above are proven by the instructions. One counter update occurs per invocation, but live caller frequency is not verified. Confidence: every one of the 258 linked words per copy is exact. No browser-runtime parity is claimed. Next evidence target: trace the path/weight producers, vector-helper scale contracts and counter caller cadence before reusing this behavior in Rev1.

Categories: {'period-selected weighted path displacement and angle update': 14}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_80084F94` | period-selected weighted path displacement and angle update | 258 | `fd05e0b374468e5c5ab46227b4a0dec11ce1f4e003778680658369ebf3fae4af` | `asm/nonmatchings/overlays/level_10/level/func_level_10_80084F94.s` |
| `func_level_15_80083DD4` | period-selected weighted path displacement and angle update | 258 | `d01ac2ca08522a6c011e083388fbc6f7f6b8d0b659cd86b5104d70343f734336` | `asm/nonmatchings/overlays/level_15/level/func_level_15_80083DD4.s` |
| `func_level_20_8008611C` | period-selected weighted path displacement and angle update | 258 | `c969a7006d3a81153dcd154637f14883d2aa04c2e109a5ddc36aafa85b3de0ef` | `asm/nonmatchings/overlays/level_20/level/func_level_20_8008611C.s` |
| `func_level_21_80087154` | period-selected weighted path displacement and angle update | 258 | `3ee68d49c9f7799556773bfd976bb52469da51243f15b20c4b9e8d63a976994b` | `asm/nonmatchings/overlays/level_21/level/func_level_21_80087154.s` |
| `func_level_22_80091A24` | period-selected weighted path displacement and angle update | 258 | `5582f5b1fb9cb023d63b724d40e4606bbe7e5d301b3a4103091c6718fb319702` | `asm/nonmatchings/overlays/level_22/level/func_level_22_80091A24.s` |
| `func_level_25_80084350` | period-selected weighted path displacement and angle update | 258 | `b967c0d18a3d1cd82c786a5ecd0176e07c3677eba3e6deb86b8c1fdbda0df738` | `asm/nonmatchings/overlays/level_25/level/func_level_25_80084350.s` |
| `func_level_30_80084B84` | period-selected weighted path displacement and angle update | 258 | `86ee3fea02a967195ee16804be19446f9c9b317688a27959372619b46075ac15` | `asm/nonmatchings/overlays/level_30/level/func_level_30_80084B84.s` |
| `func_level_32_80092958` | period-selected weighted path displacement and angle update | 258 | `191f68a04ee81ffb9e2819dcb0d93ea0f6d4347c60e027d2892129e06d3b0d7a` | `asm/nonmatchings/overlays/level_32/level/func_level_32_80092958.s` |
| `func_level_34_800912E4` | period-selected weighted path displacement and angle update | 258 | `54b5b6438d889e08b781bdc950bc3072c97d681baf68ca7c92f0fdf5b4d1a020` | `asm/nonmatchings/overlays/level_34/level/func_level_34_800912E4.s` |
| `func_level_35_800857AC` | period-selected weighted path displacement and angle update | 258 | `090b5a82b3c173553c77ce9401d82d35f7a96a3aa11766a6a4fe38ed62c8868e` | `asm/nonmatchings/overlays/level_35/level/func_level_35_800857AC.s` |
| `func_level_40_80083800` | period-selected weighted path displacement and angle update | 258 | `07795c7b3443b9e56e0465bdaa3219beb0d7bdbfb00768dfdc5ce28b360ac33d` | `asm/nonmatchings/overlays/level_40/level/func_level_40_80083800.s` |
| `func_level_42_80085F48` | period-selected weighted path displacement and angle update | 258 | `959c7c1f518164ac47a4ace3e65e4f5c2a6081a37627a9c13b3ef67ec043d58d` | `asm/nonmatchings/overlays/level_42/level/func_level_42_80085F48.s` |
| `func_level_45_80083C90` | period-selected weighted path displacement and angle update | 258 | `fb6b3ee6ff48962f5abebc60319da92092be3e4f2ee86d753c9e26b260dca765` | `asm/nonmatchings/overlays/level_45/level/func_level_45_80083C90.s` |
| `func_level_50_80095194` | period-selected weighted path displacement and angle update | 258 | `1a8dfa9b4dd24dce47cfcc3aec083eb2e443681816dd6c6998ba3198a6e07b4d` | `asm/nonmatchings/overlays/level_50/level/func_level_50_80095194.s` |
