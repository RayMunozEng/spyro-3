# Verified overlay batch 2026-10-03-190

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 96 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch190.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The attachment routine uses existing SDK Moby and Vector3D fields, retrieves attachment vectors 0 and 1, subtracts them, narrows the angle-helper result minus 0x40 to the actor yaw byte, calls the vector helper with selector 1, and sums the vectors into actor position. An attached actor state bit 0x80 instead deletes the current actor. The camera selector preserves mode 0xD gating, input flag tests, the byte read at player offset 0x1B9, fallback animation-table selection, and the repeated current-mode read. Helper and field meanings beyond those existing declarations remain unknown; no runtime coordinate or camera interpretation is newly claimed.

Categories: {'two attachment vectors and actor position/yaw': 1, 'camera mode selection from flags and animation table': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_31_8007D8BC` | two attachment vectors and actor position/yaw | 48 | `8b5231c255e749f506e254add4be4534b3b79360c1c5140a519da71d2e29cd23` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_8007D8BC.s` |
| `func_level_36_80086734` | camera mode selection from flags and animation table | 48 | `6bf8250d19e0ad20b4cc53200eb2384fe9aa5390226119453ac0bc449f25e629` | `asm/nonmatchings/overlays/level_36/camera/func_level_36_80086734.s` |
