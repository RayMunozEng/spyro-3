# Verified overlay batch 2026-10-04-301

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 19 functions, 4199 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch301.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: 19 cutscene tick/update routines, using the original retail branches and the existing SDK archive structures. Preserves tick clamping, fade arithmetic and input gate, numeric sound-handle calls, alternating archive-buffer selection, division and remainder by 0x78, rollback when the requested record is not ready, asynchronous next-record loading, and even-frame application. The 0x100-minus-fade sound parameter is multiplied by 24; its runtime meaning is not newly inferred. Each overlay calls its own original end/load/apply routines. Empty compiler constraints preserve register allocation and scheduling without emitting instructions. No retail frame duration or helper semantics beyond these instructions are claimed.

Categories: {'cutscene tick fade sound-handle update and asynchronous archive prefetch': 19}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_cutscene_61_80076E40` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `2d83f06baf01fbc8ead374dce81568410874def7ca76f8bc5ef9d8fc523987d6` | `asm/nonmatchings/overlays/cutscene_61/camera/func_cutscene_61_80076E40.s` |
| `func_cutscene_62_8007746C` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `8ec9c20cc5fcc42a9bdd7efe547b616415143b47c3a64e93dbba6e99e342afde` | `asm/nonmatchings/overlays/cutscene_62/camera/func_cutscene_62_8007746C.s` |
| `func_cutscene_63_80076D14` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `365ae510198df463164df6151914dbc23ad59077fbe5c225ce0b42ba56177d9a` | `asm/nonmatchings/overlays/cutscene_63/camera/func_cutscene_63_80076D14.s` |
| `func_cutscene_64_80077274` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `25f5d30e2d68e4f1b902ade456a2b285969e3d713c98a5af36af4bee539a77c9` | `asm/nonmatchings/overlays/cutscene_64/camera/func_cutscene_64_80077274.s` |
| `func_cutscene_65_800769BC` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `0b3b70d3681d13642fe6d9f9262e2ae77f3eca591c48cb8dec1561e12edd50af` | `asm/nonmatchings/overlays/cutscene_65/camera/func_cutscene_65_800769BC.s` |
| `func_cutscene_66_800769BC` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `0b3b70d3681d13642fe6d9f9262e2ae77f3eca591c48cb8dec1561e12edd50af` | `asm/nonmatchings/overlays/cutscene_66/camera/func_cutscene_66_800769BC.s` |
| `func_cutscene_67_80076D14` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `365ae510198df463164df6151914dbc23ad59077fbe5c225ce0b42ba56177d9a` | `asm/nonmatchings/overlays/cutscene_67/camera/func_cutscene_67_80076D14.s` |
| `func_cutscene_68_800769BC` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `0b3b70d3681d13642fe6d9f9262e2ae77f3eca591c48cb8dec1561e12edd50af` | `asm/nonmatchings/overlays/cutscene_68/camera/func_cutscene_68_800769BC.s` |
| `func_cutscene_69_80076C10` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `e9ad6d9f80e05e96dc5211339bbabe8d2581fbdacd34dd450c7d11ecbdde9a62` | `asm/nonmatchings/overlays/cutscene_69/camera/func_cutscene_69_80076C10.s` |
| `func_cutscene_70_80077004` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `daa00afcb9dc89c5adaafdd7e84eb714149a5b641ca1a54b67b71bcecfcf7586` | `asm/nonmatchings/overlays/cutscene_70/camera/func_cutscene_70_80077004.s` |
| `func_cutscene_71_80076C54` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `0821be19a5938cfe895022fd4d8cd72dbc1b349f52440fd06447c2e565baa7c7` | `asm/nonmatchings/overlays/cutscene_71/camera/func_cutscene_71_80076C54.s` |
| `func_cutscene_73_8007778C` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `8b508e2b9aab627ca9a4717edf7e109a8aa63d88f77792b7c9581286561ebb85` | `asm/nonmatchings/overlays/cutscene_73/camera/func_cutscene_73_8007778C.s` |
| `func_cutscene_74_800769BC` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `0b3b70d3681d13642fe6d9f9262e2ae77f3eca591c48cb8dec1561e12edd50af` | `asm/nonmatchings/overlays/cutscene_74/camera/func_cutscene_74_800769BC.s` |
| `func_cutscene_75_80076AA4` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `4968f075a888b5646612459d94476cb035024881c9e37336c46bdba12f70db64` | `asm/nonmatchings/overlays/cutscene_75/camera/func_cutscene_75_80076AA4.s` |
| `func_cutscene_76_80076AA4` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `4968f075a888b5646612459d94476cb035024881c9e37336c46bdba12f70db64` | `asm/nonmatchings/overlays/cutscene_76/camera/func_cutscene_76_80076AA4.s` |
| `func_cutscene_77_80076AA4` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `4968f075a888b5646612459d94476cb035024881c9e37336c46bdba12f70db64` | `asm/nonmatchings/overlays/cutscene_77/camera/func_cutscene_77_80076AA4.s` |
| `func_cutscene_78_8007710C` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `6d699b6abf55d329c3f9a372bdc2ddf95b38d7bb8734dcfaf6cd8da0a906c327` | `asm/nonmatchings/overlays/cutscene_78/camera/func_cutscene_78_8007710C.s` |
| `func_cutscene_79_800769BC` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `0b3b70d3681d13642fe6d9f9262e2ae77f3eca591c48cb8dec1561e12edd50af` | `asm/nonmatchings/overlays/cutscene_79/camera/func_cutscene_79_800769BC.s` |
| `func_cutscene_80_8007708C` | cutscene tick fade sound-handle update and asynchronous archive prefetch | 221 | `79be964c7a3d4503f5eef118b9101bc06a7e10b58a06248a332813a4be0ddfbc` | `asm/nonmatchings/overlays/cutscene_80/camera/func_cutscene_80_8007708C.s` |
