# Verified overlay batch 2026-10-03-59

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 180 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch59.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Existing upstream camera, Spyro and Vector3D layouts are the baseline.

## Widths, scheduling and remaining evidence

The routine preserves original word countdown arithmetic, word vector operations and halfword stores. The empty return-address clobber forces the original save/restore placement and emits no instruction itself. No coordinate conversion or countdown-to-seconds conversion is introduced. Next evidence target: the countdown producer and downstream camera vector consumers.

Categories: {'camera word countdown and vector plus halfword setup': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_18_80087F44` | camera word countdown and vector plus halfword setup | 45 | `7ec72089a3f50a915e3e66df7be279480a7a250b16ebc9942d827028e4aefa10` | `asm/nonmatchings/overlays/level_18/camera/func_level_18_80087F44.s` |
| `func_level_28_80086094` | camera word countdown and vector plus halfword setup | 45 | `7ec72089a3f50a915e3e66df7be279480a7a250b16ebc9942d827028e4aefa10` | `asm/nonmatchings/overlays/level_28/camera/func_level_28_80086094.s` |
| `func_level_38_800882C4` | camera word countdown and vector plus halfword setup | 45 | `7ec72089a3f50a915e3e66df7be279480a7a250b16ebc9942d827028e4aefa10` | `asm/nonmatchings/overlays/level_38/camera/func_level_38_800882C4.s` |
| `func_level_48_800872FC` | camera word countdown and vector plus halfword setup | 45 | `7ec72089a3f50a915e3e66df7be279480a7a250b16ebc9942d827028e4aefa10` | `asm/nonmatchings/overlays/level_48/camera/func_level_48_800872FC.s` |
