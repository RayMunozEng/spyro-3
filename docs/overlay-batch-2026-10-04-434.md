# Verified overlay batch 2026-10-04-434

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 19 functions, 2233 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch434.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: reuses the verified direction-lookup C in two further overlays and decodes the additional animation selector from its original table. Sixteen finish/transition dispatchers reuse the verified func_cutscene_65_80076820 implementation. All preserve original restoration-copy sizes, cheat-byte handling, mode-specific transition pairs and shared return paths. Unique case inputs to empty compiler constraints preserve distinct original switch blocks without emitting instructions. The linked audit covers original table addresses, entries, and padding for every copy; helper and data addresses are verified, not merely masked during object diagnostics.

Categories: {'two-axis hysteresis and signed direction lookup': 2, 'animation selector with state-dependent vector/reset dispatch': 1, 'cutscene finish and mode-specific transition dispatcher': 16}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_38_80085154` | two-axis hysteresis and signed direction lookup | 88 | `b740adb0adbf1dee2637c34961a09cdbd578b1e93c7cd96f180381a18df721f9` | `asm/nonmatchings/overlays/level_38/level/func_level_38_80085154.s` |
| `func_level_48_80084A68` | two-axis hysteresis and signed direction lookup | 88 | `f18e76c927fc40ac526349efdac4523d5f57c9724e374921a87fc5e218c46b76` | `asm/nonmatchings/overlays/level_48/level/func_level_48_80084A68.s` |
| `func_level_12_8008A0EC` | animation selector with state-dependent vector/reset dispatch | 89 | `8e871d9d698f618d639c8bce5bd845e5acfa115b282d86eb6cca32be638b8158` | `asm/nonmatchings/overlays/level_12/animation/func_level_12_8008A0EC.s` |
| `func_cutscene_61_80076CA4` | cutscene finish and mode-specific transition dispatcher | 123 | `613b7ce8dfc5a8ecaf9360b53027b85c52f832d9793fa279aa53aa4598f34179` | `asm/nonmatchings/overlays/cutscene_61/camera/func_cutscene_61_80076CA4.s` |
| `func_cutscene_62_800772D0` | cutscene finish and mode-specific transition dispatcher | 123 | `0f29fd7c2df0c2b0cf4d99b79735ebaf8c3939b9dcd7059f144a8e325f8f095e` | `asm/nonmatchings/overlays/cutscene_62/camera/func_cutscene_62_800772D0.s` |
| `func_cutscene_63_80076B78` | cutscene finish and mode-specific transition dispatcher | 123 | `c0a3cba51e00ac868b36ec2cbb6f1ee6d720d25ad7822b729efd6d51da9be680` | `asm/nonmatchings/overlays/cutscene_63/camera/func_cutscene_63_80076B78.s` |
| `func_cutscene_64_800770D8` | cutscene finish and mode-specific transition dispatcher | 123 | `c51a266c828f8e0af48c0156a2b5724227054fd6187b82c51179a3e202029be6` | `asm/nonmatchings/overlays/cutscene_64/camera/func_cutscene_64_800770D8.s` |
| `func_cutscene_67_80076B78` | cutscene finish and mode-specific transition dispatcher | 123 | `c0a3cba51e00ac868b36ec2cbb6f1ee6d720d25ad7822b729efd6d51da9be680` | `asm/nonmatchings/overlays/cutscene_67/camera/func_cutscene_67_80076B78.s` |
| `func_cutscene_69_80076A74` | cutscene finish and mode-specific transition dispatcher | 123 | `64968c1c71fcf047d11adfc6ed44419efe383cc2d59740a7e9d2364c1e101d34` | `asm/nonmatchings/overlays/cutscene_69/camera/func_cutscene_69_80076A74.s` |
| `func_cutscene_70_80076E68` | cutscene finish and mode-specific transition dispatcher | 123 | `ef4e6adc19bc8764204d4c3c1826b0a0cc05b96c0f2e0fa9370c3a8394cdb577` | `asm/nonmatchings/overlays/cutscene_70/camera/func_cutscene_70_80076E68.s` |
| `func_cutscene_71_80076AB8` | cutscene finish and mode-specific transition dispatcher | 123 | `1a5225078d970130802a9203974d8ba44c7ee93699b13dcc86fc57239180a27b` | `asm/nonmatchings/overlays/cutscene_71/camera/func_cutscene_71_80076AB8.s` |
| `func_cutscene_73_800775F0` | cutscene finish and mode-specific transition dispatcher | 123 | `e9de75e67e47c7dfa14603f978e2ca2213bdebb75eed0f51b203222c5c43e321` | `asm/nonmatchings/overlays/cutscene_73/camera/func_cutscene_73_800775F0.s` |
| `func_cutscene_75_80076908` | cutscene finish and mode-specific transition dispatcher | 123 | `bc5d4731bff6eb32252061325563694ac456ec66c0869991db9f8fddc0ea3318` | `asm/nonmatchings/overlays/cutscene_75/camera/func_cutscene_75_80076908.s` |
| `func_cutscene_76_80076908` | cutscene finish and mode-specific transition dispatcher | 123 | `bc5d4731bff6eb32252061325563694ac456ec66c0869991db9f8fddc0ea3318` | `asm/nonmatchings/overlays/cutscene_76/camera/func_cutscene_76_80076908.s` |
| `func_cutscene_77_80076908` | cutscene finish and mode-specific transition dispatcher | 123 | `bc5d4731bff6eb32252061325563694ac456ec66c0869991db9f8fddc0ea3318` | `asm/nonmatchings/overlays/cutscene_77/camera/func_cutscene_77_80076908.s` |
| `func_cutscene_78_80076F70` | cutscene finish and mode-specific transition dispatcher | 123 | `1fd0504c5114b36d8e645ab67d518068dea5b21ad2a48b22e3f10d2502ce96ff` | `asm/nonmatchings/overlays/cutscene_78/camera/func_cutscene_78_80076F70.s` |
| `func_cutscene_80_80076EF0` | cutscene finish and mode-specific transition dispatcher | 123 | `7a7d670eb7f84b551681de2b36b6fff3c45c66aaeef8536a4b4d2609d3278732` | `asm/nonmatchings/overlays/cutscene_80/camera/func_cutscene_80_80076EF0.s` |
| `func_loading_80079A0C` | cutscene finish and mode-specific transition dispatcher | 123 | `f3ba34f596cf9a74f5e7c179240bc7ee0f9c4982d73c1b76800427b1ac5c9a34` | `asm/nonmatchings/overlays/loading/loading6/func_loading_80079A0C.s` |
| `func_title_80079B94` | cutscene finish and mode-specific transition dispatcher | 123 | `b10e2f542763584274294dffec3cc49195081692a435b6379127e8bf1f6c95d4` | `asm/nonmatchings/overlays/title/title3/func_title_80079B94.s` |
