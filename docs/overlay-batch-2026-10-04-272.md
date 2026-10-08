# Verified overlay batch 2026-10-04-272

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 19 functions, 2850 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch272.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- Nineteen cutscene initializers retain the WAD model entry's size and offset, archive header/frame loaders, state resets, colour-byte copies, actor-record clearing and return values.
- The threshold-0x3C branch encloses both the particle-buffer helper and the 0x1000-byte clear. The branch target is checked against original instructions; the clear is not moved outside the gate.
- Each copy uses its own local loader function addresses and was compiled independently before integration. Existing SDK WAD and actor layouts are reused; all complete overlay hashes and linked words match.

Categories: {'cutscene archive initialization and actor-state clearing': 19}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_cutscene_61_80076A4C` | cutscene archive initialization and actor-state clearing | 150 | `f5a24b79841c29eba6a55a8d78c6a2f98c93f7e6b057cf6133c7e022c990ba32` | `asm/nonmatchings/overlays/cutscene_61/camera/func_cutscene_61_80076A4C.s` |
| `func_cutscene_62_80077078` | cutscene archive initialization and actor-state clearing | 150 | `6e2039725d06c47ca33811337b5fde61399d3d662c0df7d01a0656b8828eb379` | `asm/nonmatchings/overlays/cutscene_62/camera/func_cutscene_62_80077078.s` |
| `func_cutscene_63_80076920` | cutscene archive initialization and actor-state clearing | 150 | `3b1c72e003c6b9f9ac2fdc480626002d71f7a572e088f5bbe7fafb25db0648d4` | `asm/nonmatchings/overlays/cutscene_63/camera/func_cutscene_63_80076920.s` |
| `func_cutscene_64_80076E80` | cutscene archive initialization and actor-state clearing | 150 | `2693e53e163f04548360bb4942a8b65080fea7bb23bc33182581f508d11b7475` | `asm/nonmatchings/overlays/cutscene_64/camera/func_cutscene_64_80076E80.s` |
| `func_cutscene_65_800765C8` | cutscene archive initialization and actor-state clearing | 150 | `d497def681211d8a7c5816eda038b35319782dbaedaf5c350b159fde9a46a7fc` | `asm/nonmatchings/overlays/cutscene_65/camera/func_cutscene_65_800765C8.s` |
| `func_cutscene_66_800765C8` | cutscene archive initialization and actor-state clearing | 150 | `d497def681211d8a7c5816eda038b35319782dbaedaf5c350b159fde9a46a7fc` | `asm/nonmatchings/overlays/cutscene_66/camera/func_cutscene_66_800765C8.s` |
| `func_cutscene_67_80076920` | cutscene archive initialization and actor-state clearing | 150 | `3b1c72e003c6b9f9ac2fdc480626002d71f7a572e088f5bbe7fafb25db0648d4` | `asm/nonmatchings/overlays/cutscene_67/camera/func_cutscene_67_80076920.s` |
| `func_cutscene_68_800765C8` | cutscene archive initialization and actor-state clearing | 150 | `d497def681211d8a7c5816eda038b35319782dbaedaf5c350b159fde9a46a7fc` | `asm/nonmatchings/overlays/cutscene_68/camera/func_cutscene_68_800765C8.s` |
| `func_cutscene_69_8007681C` | cutscene archive initialization and actor-state clearing | 150 | `c57dec158e1847239e357451a5833db2e2a770fdda64881b728a16249ae387a6` | `asm/nonmatchings/overlays/cutscene_69/camera/func_cutscene_69_8007681C.s` |
| `func_cutscene_70_80076C10` | cutscene archive initialization and actor-state clearing | 150 | `a5820cfeb9421d9c2843054148197339529924971dfe1ad3bceb5adca322ddf5` | `asm/nonmatchings/overlays/cutscene_70/camera/func_cutscene_70_80076C10.s` |
| `func_cutscene_71_80076860` | cutscene archive initialization and actor-state clearing | 150 | `31e68bc26c9b212ed87b4ff937366ffdc7da10dbb2686eed697454604e5c8517` | `asm/nonmatchings/overlays/cutscene_71/camera/func_cutscene_71_80076860.s` |
| `func_cutscene_73_80077398` | cutscene archive initialization and actor-state clearing | 150 | `1da4cca1e7b5ba62c53193ac773e1d3bd7ac2f122ab91393bd2353ba1b80f1f7` | `asm/nonmatchings/overlays/cutscene_73/camera/func_cutscene_73_80077398.s` |
| `func_cutscene_74_800765C8` | cutscene archive initialization and actor-state clearing | 150 | `d497def681211d8a7c5816eda038b35319782dbaedaf5c350b159fde9a46a7fc` | `asm/nonmatchings/overlays/cutscene_74/camera/func_cutscene_74_800765C8.s` |
| `func_cutscene_75_800766B0` | cutscene archive initialization and actor-state clearing | 150 | `eedcf4f23063e284d604c2aabf43b4032d78cd68f7f5ab84150734789043b69b` | `asm/nonmatchings/overlays/cutscene_75/camera/func_cutscene_75_800766B0.s` |
| `func_cutscene_76_800766B0` | cutscene archive initialization and actor-state clearing | 150 | `eedcf4f23063e284d604c2aabf43b4032d78cd68f7f5ab84150734789043b69b` | `asm/nonmatchings/overlays/cutscene_76/camera/func_cutscene_76_800766B0.s` |
| `func_cutscene_77_800766B0` | cutscene archive initialization and actor-state clearing | 150 | `eedcf4f23063e284d604c2aabf43b4032d78cd68f7f5ab84150734789043b69b` | `asm/nonmatchings/overlays/cutscene_77/camera/func_cutscene_77_800766B0.s` |
| `func_cutscene_78_80076D18` | cutscene archive initialization and actor-state clearing | 150 | `8dc14efb15e918f5cfb9da87ca1240b2b04d1d590590fe6cda31c060494f8ae7` | `asm/nonmatchings/overlays/cutscene_78/camera/func_cutscene_78_80076D18.s` |
| `func_cutscene_79_800765C8` | cutscene archive initialization and actor-state clearing | 150 | `d497def681211d8a7c5816eda038b35319782dbaedaf5c350b159fde9a46a7fc` | `asm/nonmatchings/overlays/cutscene_79/camera/func_cutscene_79_800765C8.s` |
| `func_cutscene_80_80076C98` | cutscene archive initialization and actor-state clearing | 150 | `217feaac360573f17cddeef1e95aaf965e2f523c215a5563f352e08eaba419cc` | `asm/nonmatchings/overlays/cutscene_80/camera/func_cutscene_80_80076C98.s` |
