# Verified overlay batch 2026-10-04-487

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 6 functions, 602 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch487.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The camera-trigger copies share the verified C baseline: bounds margin, linked actor index, required-state halfword and final-state word use their original widths. Camera release and deletion preserve the original pointer access order. The two wobble updates retain unsigned halfword loads followed by signed conversion, phase masking, shifts by 7/8/12, absolute downward offset and both velocity-decay helpers. The atlas mapping preserves byte XOR decoding and every original letter, digit and punctuation index, including the -1 fallback. The three-actor spawn retains a capacity check before every attempt, the original matrix, heading, animation IDs and three exact vector constants. Empty constraints preserve access widths and register allocation and emit no instructions; helper and particle semantics beyond these instructions are unproven.

Categories: {'bounds and linked-actor state camera trigger with deletion release': 2, 'timer-driven signed trigonometric offsets and velocity decay': 2, 'XOR-decoded character to atlas glyph index mapping': 1, 'damage-gated three-actor spawn with original matrix offsets': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_14_8008C07C` | bounds and linked-actor state camera trigger with deletion release | 101 | `c1778edec8086a3f9c80987272d2a0c24fef3d82c913f8608d61b911d96dd68a` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_8008C07C.s` |
| `func_level_34_8008EA04` | bounds and linked-actor state camera trigger with deletion release | 101 | `e1334f4e16dba34f1bc9bf4a4c03a645f6438b99a8627742962b64694fcd79d0` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_8008EA04.s` |
| `func_level_21_8008270C` | timer-driven signed trigonometric offsets and velocity decay | 108 | `b43b158990059ae9174cc4b6f8f9c677d1bde7468238f4dfdcb02ac9b53e129a` | `asm/nonmatchings/overlays/level_21/moby/func_level_21_8008270C.s` |
| `func_level_32_80089DE0` | timer-driven signed trigonometric offsets and velocity decay | 108 | `d14fea7b4baed5396f9a0c1af6b2ce4ca30e6e41391e9d34fb8ae0d8180bc91d` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_80089DE0.s` |
| `func_atlas_80075FBC` | XOR-decoded character to atlas glyph index mapping | 91 | `edde36aba01df41b0c1b6272b58b4b1184a077355cc92bc35359ced43d14319b` | `asm/nonmatchings/overlays/atlas/atlas1/func_atlas_80075FBC.s` |
| `func_level_24_8008B220` | damage-gated three-actor spawn with original matrix offsets | 93 | `66a3d31d4804a767b51bd16d630a764124f5212ce21a0fb3f91f58f5f0bc7c38` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8008B220.s` |
