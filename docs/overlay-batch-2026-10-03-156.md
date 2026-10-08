# Verified overlay batch 2026-10-03-156

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 8 functions, 304 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch156.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: upstream `Spyro`, `Camera`, `Moby` and math/particle helpers, and the previously hash-verified camera initializer from batch 105. The three initializer variants preserve exact mode gates, byte writes at camera +0x140/+0x141/+0x142/+0x145 and optional +0x5C clearing, then the original copy/update helper chain and offsets from camera +0x50. Both atlas searches use signed-byte level entries and unsigned-byte lookup flags with original bounds, direction and sentinel -1. They preserve the original lookup-before-final-bound-check behavior, including terminal table accesses; no extra guard was invented. The particle wrapper retains the exact animation-state exclusion and literal callback arguments. Draw-byte state handling preserves states 0/1/2 and state-2 helper transition to 3. The animation routine reads the first unsigned byte through model header +0x44, sets state/animation bytes and produces progress 0x30 only when the byte is at least two, using the original branch-free mask. An empty constraint prevents the compiler replacing that mask with branches. Header/frame-count semantics, camera coordinate units and invocation cadence remain unresolved. Next evidence target: atlas table bounds/producers, model animation header schema and camera helper source domains.

Categories: {'actor state animation frame count progress setup': 1, 'forward signed-byte atlas table selection': 1, 'reverse signed-byte atlas table selection': 1, 'camera mode initializer using verified SDK field chain': 3, 'animation-gated first and subsequent particle counts': 1, 'actor draw-byte state selection and helper transition': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_50_800833B4` | actor state animation frame count progress setup | 31 | `06f5dbd7fc7976fa48da875e89e169a0c566521a879f3eb9c83fe8889ca15878` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_800833B4.s` |
| `func_atlas_80075824` | forward signed-byte atlas table selection | 35 | `a62d2029ff6088a3b239c96fda2b8e9484efea53209fc5736400db98252cbba6` | `asm/nonmatchings/overlays/atlas/atlas1/func_atlas_80075824.s` |
| `func_atlas_800758B0` | reverse signed-byte atlas table selection | 39 | `2d98d3a389821bc89b9cfc793d60c832ad0735429fef88b1b70c3456014a8477` | `asm/nonmatchings/overlays/atlas/atlas1/func_atlas_800758B0.s` |
| `func_level_36_80086698` | camera mode initializer using verified SDK field chain | 39 | `d47042b41dd681d726d4625fca8cf48c4802cd5c0c3d6528f9338e64f50845cc` | `asm/nonmatchings/overlays/level_36/camera/func_level_36_80086698.s` |
| `func_level_26_8008ABD4` | camera mode initializer using verified SDK field chain | 40 | `6ca07377b86d38cb0305b75710b2f12f0abd81d45fcd11e5fff38349494450ef` | `asm/nonmatchings/overlays/level_26/camera/func_level_26_8008ABD4.s` |
| `func_level_25_80089760` | camera mode initializer using verified SDK field chain | 42 | `111d4b3aec712f07eb2773e820fc28420aa0cdd503118130e3517db0106fbf9a` | `asm/nonmatchings/overlays/level_25/camera/func_level_25_80089760.s` |
| `func_level_21_8007A19C` | animation-gated first and subsequent particle counts | 39 | `4adc39ef467d951ad601e634ebf21ce196089858eca5cceaab95247ca5a45035` | `asm/nonmatchings/overlays/level_21/moby/func_level_21_8007A19C.s` |
| `func_level_34_8008D624` | actor draw-byte state selection and helper transition | 39 | `4b543be84d9bec458ea9a56475aafbee693f457a980d7457b4ea2aef04956565` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_8008D624.s` |
