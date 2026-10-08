# Verified overlay batch 2026-10-04-277

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 22 functions, 4488 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch277.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- Twenty-two identical linked-actor handlers preserve all four states, indexed actor access, byte-0x80 tests, position copies, timer and counter writes, callback return checks and optional sound-handle update.
- A private typed alias preserves the pointer-returning ABI of `func_80036A68` for these call sites. The state-3 null return skips deletion, as the original branch requires.
- The packed collection word uses the original signed index arithmetic, level stride 32 and bit selection. Empty constraints retain table-base load and index scheduling without emitting instructions.
- Existing SDK actor fields are reused. The sound selector remains the original table byte at offset 0x1A; its semantic audio meaning is not independently verified.

Categories: {'linked actor state transitions and callback-driven replacement': 22}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_11_8007AE4C` | linked actor state transitions and callback-driven replacement | 204 | `7a055bd1e14d32240023c1099c0ccbfed1afedb416abd648490d14c1b5e00f45` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_8007AE4C.s` |
| `func_level_13_800829C8` | linked actor state transitions and callback-driven replacement | 204 | `1160caa09ee7a939719fc18754160037b0d13c446fe8ae082550a54951743c96` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_800829C8.s` |
| `func_level_14_8007B1BC` | linked actor state transitions and callback-driven replacement | 204 | `895ddcb13922dcecdd7e5962ed15f6836eda466662b78f8b6e6375b955393fc7` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_8007B1BC.s` |
| `func_level_16_8007CA90` | linked actor state transitions and callback-driven replacement | 204 | `5d6efe2b041341a2bcbf01723be1bbf10154eefe8bc201ca8e432c2f76bf3c72` | `asm/nonmatchings/overlays/level_16/moby/func_level_16_8007CA90.s` |
| `func_level_20_800827DC` | linked actor state transitions and callback-driven replacement | 204 | `82476bef80194bccca3ef566b005031afe6c76336d28b3c41d8fc7719e3f2d1a` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_800827DC.s` |
| `func_level_21_800836C4` | linked actor state transitions and callback-driven replacement | 204 | `97e2afe60ca90ba41efa5490a342952fc05b24955d68e0c0b9ad96f2e7a86c70` | `asm/nonmatchings/overlays/level_21/moby/func_level_21_800836C4.s` |
| `func_level_22_80084DC4` | linked actor state transitions and callback-driven replacement | 204 | `5841b103dc08ec77b3eb2d9fd015882408886fa048f4e0e8e18ffe55e0cf30e5` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_80084DC4.s` |
| `func_level_23_8007B720` | linked actor state transitions and callback-driven replacement | 204 | `9090663038e5e39efcdb3d7f8bd98e6ddfd6a50e405d5f9b76aa2f373962a1fb` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_8007B720.s` |
| `func_level_24_8007D8C0` | linked actor state transitions and callback-driven replacement | 204 | `a895e57e45d841bb4036bedbd171e3eab2f807f63342819c6e91725fb6f4fa6e` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8007D8C0.s` |
| `func_level_26_8007C3C8` | linked actor state transitions and callback-driven replacement | 204 | `9287a7d20e67dceb329e7537653b6f7088bde82b27d7e23e575328cf53301a62` | `asm/nonmatchings/overlays/level_26/moby/func_level_26_8007C3C8.s` |
| `func_level_30_80080D94` | linked actor state transitions and callback-driven replacement | 204 | `deb2d196dc343777dd66b75eaac72ac6db26415f3cc3dfd0e819bf90241889b3` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_80080D94.s` |
| `func_level_31_8007D9E8` | linked actor state transitions and callback-driven replacement | 204 | `bc8bc69251062a0e17211836f3daaa150e26c48d20d3d9d1dce7fd35237e0bf3` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_8007D9E8.s` |
| `func_level_32_8008BD98` | linked actor state transitions and callback-driven replacement | 204 | `c7505274972749a8c7aa9b5d9b4ff7d3000e8dcfd64308c083a6005f000a3818` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_8008BD98.s` |
| `func_level_33_8007D2C0` | linked actor state transitions and callback-driven replacement | 204 | `1847fe17ed654c6016f2a76ea8e4aff61553d2e0c817042c1d43a7af3acb0480` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_8007D2C0.s` |
| `func_level_34_8007E780` | linked actor state transitions and callback-driven replacement | 204 | `e4eb32aeb1ab4e48eca8865a182fb3de1f25b1b07ab872baf9add1089b52300f` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_8007E780.s` |
| `func_level_36_8007DE88` | linked actor state transitions and callback-driven replacement | 204 | `7133da4ede7efea9804d305e6b865c2ce892c050805082a3795fbd48fdac765f` | `asm/nonmatchings/overlays/level_36/moby/func_level_36_8007DE88.s` |
| `func_level_40_800806A8` | linked actor state transitions and callback-driven replacement | 204 | `7bd4f784366ccf6cd039ad4dd769514abac3a976fa41e2a35ff12207eb87dfbb` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_800806A8.s` |
| `func_level_41_8007D260` | linked actor state transitions and callback-driven replacement | 204 | `a337fb6b3fd6c19198920024d7a1fa0c9c531606454786d62810197d78ecc61d` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_8007D260.s` |
| `func_level_42_80081754` | linked actor state transitions and callback-driven replacement | 204 | `b894c3b9f3c8df60d51779efb097924104a2f3e7ef2747cf0063668316a73ec4` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_80081754.s` |
| `func_level_44_8007B778` | linked actor state transitions and callback-driven replacement | 204 | `994f670bcbf69396751a26c22402c02f3444eee7a481f22c7811318d9b6f147f` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_8007B778.s` |
| `func_level_46_8007ABF0` | linked actor state transitions and callback-driven replacement | 204 | `b0091987c77b48f59be0729634672b7c2ea67ea4cd7cc636a62098a5468cabf9` | `asm/nonmatchings/overlays/level_46/moby/func_level_46_8007ABF0.s` |
| `func_level_50_80086F98` | linked actor state transitions and callback-driven replacement | 204 | `2d5186329af6e6d8907fad65bbb6d49d6220236e0136cb65a889b3e8fb066aa5` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_80086F98.s` |
