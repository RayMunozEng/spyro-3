# Verified overlay batch 2026-10-04-440

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 18 functions, 2332 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch440.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: the already verified animation selectors use the upstream Spyro structures and helper declarations. Cases and helper arguments were recovered from each original jump table and instruction block. The level 31 selector increments and clamps its tagged counter at 60; level 14 retains the original signed division by 96. Level 44 preserves its explicit boundary no-op case, and levels 32 and 50 spell out the original no-op entries to preserve jump-table density and extent under GCC 2.7.2. Empty register constraints in the state-dependent selectors emit no instructions. Raw field offsets retain their original widths; no new semantic interpretation is asserted.

Categories: {'animation selector with state-dependent vector/reset dispatch': 1, 'retail table-driven animation selector and helper dispatch': 14, 'retail animation selector including explicit boundary no-op entries': 1, 'retail animation selector preserving original no-op cases and table extent': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_27_80088A48` | animation selector with state-dependent vector/reset dispatch | 89 | `0819b57a0e4e10098e01ca22b3f3b0e7f5a56fd0a9ac1737f1d286cad0936669` | `asm/nonmatchings/overlays/level_27/animation/func_level_27_80088A48.s` |
| `func_level_11_8008E86C` | retail table-driven animation selector and helper dispatch | 96 | `4bf0fd968dbf365e08f0b92b8d6aabc70af5660fb62fc72769118ef7839b41b5` | `asm/nonmatchings/overlays/level_11/animation/func_level_11_8008E86C.s` |
| `func_level_13_8008A750` | retail table-driven animation selector and helper dispatch | 128 | `3696af9c795cec5ba3538b3e4a4d25f079d2d946330b7f56fb887362e59a5714` | `asm/nonmatchings/overlays/level_13/animation/func_level_13_8008A750.s` |
| `func_level_14_8009697C` | retail table-driven animation selector and helper dispatch | 119 | `8c105f2aefd30c2ab008f314fae46908b80e3dab5cbbb16e01149d425db39d48` | `asm/nonmatchings/overlays/level_14/animation/func_level_14_8009697C.s` |
| `func_level_21_8008D100` | retail table-driven animation selector and helper dispatch | 90 | `8a064db5f05424f256e2ab3643db8d52fdfbdfe570a520306b25f53fdcf7da48` | `asm/nonmatchings/overlays/level_21/animation/func_level_21_8008D100.s` |
| `func_level_22_8009852C` | retail table-driven animation selector and helper dispatch | 123 | `540dd2ff776c5e11d58509fe645c2a0f8ddec069b49ad1bc8f8eaa0d2d2c5770` | `asm/nonmatchings/overlays/level_22/animation/func_level_22_8009852C.s` |
| `func_level_23_800939C0` | retail table-driven animation selector and helper dispatch | 102 | `e5539d3d504803a3471bcc3e06c2b5eda59db0695caab68c48e34e434f1e9ab1` | `asm/nonmatchings/overlays/level_23/animation/func_level_23_800939C0.s` |
| `func_level_24_800946C4` | retail table-driven animation selector and helper dispatch | 109 | `d58edc9e9eb31cd6cb3903970207213c268a0c72ee924eac850834d643f2b8e0` | `asm/nonmatchings/overlays/level_24/animation/func_level_24_800946C4.s` |
| `func_level_30_8008A9B4` | retail table-driven animation selector and helper dispatch | 148 | `079049f7d5f5e7e92fc9a64766b0d93156a4e1fb384657567f3be130846e131d` | `asm/nonmatchings/overlays/level_30/animation/func_level_30_8008A9B4.s` |
| `func_level_31_8008DE1C` | retail table-driven animation selector and helper dispatch | 179 | `2f4ed7193118715b25a1ca7749385d89fe9a0cabc16d289f4223cacfd4bc9957` | `asm/nonmatchings/overlays/level_31/animation/func_level_31_8008DE1C.s` |
| `func_level_33_8009B800` | retail table-driven animation selector and helper dispatch | 156 | `ed6766506a94f5e4fe9c15d3e90918982618b54cf023ecaeaa1db6008358f640` | `asm/nonmatchings/overlays/level_33/animation/func_level_33_8009B800.s` |
| `func_level_34_80096A28` | retail table-driven animation selector and helper dispatch | 130 | `3b5c9a0a5c5e4de1ba926e2f491d29cf212e7b02693c008c50b1169ad7c9219f` | `asm/nonmatchings/overlays/level_34/animation/func_level_34_80096A28.s` |
| `func_level_41_80093130` | retail table-driven animation selector and helper dispatch | 111 | `79e18fbef5cad0613e08ab02ec5eda5bc78150a062a402e6053ecdf5504b3a66` | `asm/nonmatchings/overlays/level_41/animation/func_level_41_80093130.s` |
| `func_level_42_8008CB78` | retail table-driven animation selector and helper dispatch | 102 | `77af48bd01d4fc2b83c258971b3791f32708febf7515b372ee406f391a9e9e39` | `asm/nonmatchings/overlays/level_42/animation/func_level_42_8008CB78.s` |
| `func_level_43_80093310` | retail table-driven animation selector and helper dispatch | 163 | `7a23c212f65a5c79c94790336c176521e58505c68bcd8f8c403a20405122fa76` | `asm/nonmatchings/overlays/level_43/animation/func_level_43_80093310.s` |
| `func_level_44_80090B48` | retail animation selector including explicit boundary no-op entries | 136 | `ada5c2640857c02b76be0c25e8f967875a9b48f37a24e580e55cd164c751725d` | `asm/nonmatchings/overlays/level_44/animation/func_level_44_80090B48.s` |
| `func_level_32_80099E1C` | retail animation selector preserving original no-op cases and table extent | 183 | `0c48daf797281c228e185974ea6573bf28fdf7e1272e9aaf8adca499c3061877` | `asm/nonmatchings/overlays/level_32/animation/func_level_32_80099E1C.s` |
| `func_level_50_8009D6E0` | retail animation selector preserving original no-op cases and table extent | 168 | `28647742c23d44ff28150afe7fe7ce3352ef4687203989f7679adadee6c13172` | `asm/nonmatchings/overlays/level_50/animation/func_level_50_8009D6E0.s` |
