# Verified overlay batch 2026-10-03-119

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 6 functions, 364 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch119.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream `HudEntry`, `SpriteDefinition`, `SpriteData`, `Moby`, `Vector3D` and math helper declarations. HUD values are truncated to unsigned 16 bits before their unsigned clamp; sprite bounds are unsigned bytes. The ratio routine copies the actor position, adds integer 0x200 to Z, subtracts tag vector +0x64 and calls the recorded helpers. Zero divisors become 1; signed intermediate values are shifted by 14 and then 12 around two divisions, preserving the original MFLO register chain. Selector +0x5C and result +0x60 are signed words. Helper output units and vector source-domain scale remain unresolved. Empty register constraints emit no instructions. Next evidence target: helper output representations and producers/consumers of this tag record.

Categories: {'HUD word source halfword clamp and unsigned sprite dimension setup': 2, 'original tag vector and signed two-stage shifted division chain': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_11_80088190` | HUD word source halfword clamp and unsigned sprite dimension setup | 44 | `d9fb2780e125a192d5cc2b66916b1e674ab571786f5e7fdd3e6e0540f0cd7eba` | `asm/nonmatchings/overlays/level_11/level/func_level_11_80088190.s` |
| `func_level_22_80093108` | HUD word source halfword clamp and unsigned sprite dimension setup | 44 | `c793e7f0d15077fd0309a9f9209c0ef5b2bba701e61f76cee80ee4407bb51db0` | `asm/nonmatchings/overlays/level_22/level/func_level_22_80093108.s` |
| `func_level_33_800943A0` | original tag vector and signed two-stage shifted division chain | 69 | `60a44581822ef9949ecf1c8db75b800c075efbf956ec32be04df1fc85c516f47` | `asm/nonmatchings/overlays/level_33/level/func_level_33_800943A0.s` |
| `func_level_43_8008C498` | original tag vector and signed two-stage shifted division chain | 69 | `60a44581822ef9949ecf1c8db75b800c075efbf956ec32be04df1fc85c516f47` | `asm/nonmatchings/overlays/level_43/level/func_level_43_8008C498.s` |
| `func_level_44_80089D74` | original tag vector and signed two-stage shifted division chain | 69 | `60a44581822ef9949ecf1c8db75b800c075efbf956ec32be04df1fc85c516f47` | `asm/nonmatchings/overlays/level_44/level/func_level_44_80089D74.s` |
| `func_level_46_8008A8B4` | original tag vector and signed two-stage shifted division chain | 69 | `60a44581822ef9949ecf1c8db75b800c075efbf956ec32be04df1fc85c516f47` | `asm/nonmatchings/overlays/level_46/level/func_level_46_8008A8B4.s` |
