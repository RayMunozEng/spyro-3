# Verified overlay batch 2026-10-04-693

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 104 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch693.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation follows the original three-mode level 40 initializer. Existing upstream CameraPosition and Vector3D structures retain all call argument layouts. Empty allocation constraints preserve original saved pointer registers; alternate declarations for the same settling address preserve separate original argument materialization. The constraints emit no instructions. No new camera interpretation is claimed.

Categories: {'three-mode camera initialization': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_40_80087024` | three-mode camera initialization | 104 | `e03d5d5d51c9d32aeaa637c10ece60f6b885d361303276959f705159f7f8988e` | `asm/nonmatchings/overlays/level_40/camera/func_level_40_80087024.s` |
