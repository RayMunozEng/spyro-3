# Verified overlay batch 2026-10-03-183

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 3 functions, 131 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch183.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The animation selector follows the previously verified SDK animation-record baseline: 13 cases from 0x55 through 0x61, including the three null-vector branches, with the original extra zero table-padding word retained. The random-particle routine gates on class 0x2E5 and signed frame value modulo 3, draws two independent rand() values masked to 3, uses Z=0x20, and calls the fragment helper afterward. The damage-state routine preserves state 0's bit 0x04000000 transition and state 1's callback, six-argument fragment call, post-fragment helper, and deletion sequence. Particle and fragment selectors remain numeric; no visual or sound meaning is inferred.

Categories: {'animation record and thirteen-entry vector helper selection': 1, 'class and signed modulo gated random particle then fragments': 1, 'damage-state fragment and deletion sequence': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_36_800854A4` | animation record and thirteen-entry vector helper selection | 45 | `a43773afb6413e3e96e2818da5829b1caa96fe94825a87d18aea1d90717483a5` | `asm/nonmatchings/overlays/level_36/animation/func_level_36_800854A4.s` |
| `func_level_23_8007A9CC` | class and signed modulo gated random particle then fragments | 43 | `717e69c9689d86a2dc6ced46282ec7e37b7a3e73b6040889f7bb58de2bc1cc3d` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_8007A9CC.s` |
| `func_level_36_8007D3C0` | damage-state fragment and deletion sequence | 43 | `85226dfaf2c1500f22906a44cdf64a403146d01f79791fe8eeda7a509e4fba1c` | `asm/nonmatchings/overlays/level_36/moby/func_level_36_8007D3C0.s` |
