# Verified overlay batch 2026-10-03-105

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 9 functions, 492 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch105.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Existing upstream Moby, HudEntry, SpriteAnimationData, SpriteData and Camera layouts are the baseline.

## Widths, scheduling and remaining evidence

The three-state actor routine preserves byte wrapping before both size comparisons: subtract 8 and compare against 0x20; the second state selects size 0x21/state 2; the third adds 8 and deletes only when the stored byte reaches 0x7F. HUD coordinate inputs are signed halfwords, helper outputs are words, records are eight bytes, and sprite dimensions are unsigned bytes. Each of four iterations conditionally draws on word state 8 and advances X by 0x22, including skipped draws. The camera initializer compares mode 3, preserves word and byte reset stores, and consumes camera positions through byte offsets +0x2C/+0x54 from the retained +0x50 address base. Empty constraints preserve scheduling and emit no instructions. Next evidence target: size/state producers, HUD state/layout producer chain, and camera position physical units.

Categories: {'byte-wrapped size and three actor state transitions': 3, 'camera mode-gated word and byte reset plus original byte-offset position consumers': 2, 'four eight-byte HUD records with original state gates and sprite dimensions': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_11_80083F84` | byte-wrapped size and three actor state transitions | 50 | `d22d949ee538d62ef0230700068d051cd87f85025666407b033c99973cc165cc` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_80083F84.s` |
| `func_level_26_80083EC8` | byte-wrapped size and three actor state transitions | 50 | `662e5f7ef7ae8f4ae417ffa6db8668091b7e6f5012fbdd75add738cd3af4d91e` | `asm/nonmatchings/overlays/level_26/moby/func_level_26_80083EC8.s` |
| `func_level_41_8007EE64` | byte-wrapped size and three actor state transitions | 50 | `0e584ea578ab66098a489a163241d09f8a3d7692ab41e8bacc6aa4bf183e154f` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_8007EE64.s` |
| `func_level_15_80089BC8` | camera mode-gated word and byte reset plus original byte-offset position consumers | 39 | `47eeefbd2a08ae73c0cf12d4dd17bd487e5bd56f9b06905d58667132df18d941` | `asm/nonmatchings/overlays/level_15/camera/func_level_15_80089BC8.s` |
| `func_level_45_8008995C` | camera mode-gated word and byte reset plus original byte-offset position consumers | 39 | `47eeefbd2a08ae73c0cf12d4dd17bd487e5bd56f9b06905d58667132df18d941` | `asm/nonmatchings/overlays/level_45/camera/func_level_45_8008995C.s` |
| `func_level_15_80083088` | four eight-byte HUD records with original state gates and sprite dimensions | 66 | `2ed472d09ed2705ac5d71f36e78070a43b70a44ba6e658ae4f2ba0cb068bab12` | `asm/nonmatchings/overlays/level_15/level/func_level_15_80083088.s` |
| `func_level_25_80083A40` | four eight-byte HUD records with original state gates and sprite dimensions | 66 | `2ed472d09ed2705ac5d71f36e78070a43b70a44ba6e658ae4f2ba0cb068bab12` | `asm/nonmatchings/overlays/level_25/level/func_level_25_80083A40.s` |
| `func_level_35_80084DC4` | four eight-byte HUD records with original state gates and sprite dimensions | 66 | `2ed472d09ed2705ac5d71f36e78070a43b70a44ba6e658ae4f2ba0cb068bab12` | `asm/nonmatchings/overlays/level_35/level/func_level_35_80084DC4.s` |
| `func_level_45_80083380` | four eight-byte HUD records with original state gates and sprite dimensions | 66 | `2ed472d09ed2705ac5d71f36e78070a43b70a44ba6e658ae4f2ba0cb068bab12` | `asm/nonmatchings/overlays/level_45/level/func_level_45_80083380.s` |
