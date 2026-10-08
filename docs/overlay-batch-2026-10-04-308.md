# Verified overlay batch 2026-10-04-308

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 15 functions, 2565 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch308.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: 15 copies of the original actor trigger dispatch. Uses the existing Moby and Spyro layouts and a partial tag layout justified by the listed instruction offsets. Retains level/global gates, both box-helper calls and limits, states 0/1/2/3, selected actor callback, archive table addressing, signed division by 0x800, and the original numeric CD helper arguments. State 0 tests the inner box result directly; state 2 tests the separate global flag after a successful expanded-box test. Empty constraints preserve allocation and scheduling; no instructions are embedded in C. Unknown helper semantics and CD runtime timing remain unverified.

Categories: {'actor trigger state and numeric CD helper dispatch': 15}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_11_8007A238` | actor trigger state and numeric CD helper dispatch | 171 | `4feae8d6f0731218beb139daf2f04bef64c8de57afe458c388744581b7bf9bed` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_8007A238.s` |
| `func_level_12_80081D84` | actor trigger state and numeric CD helper dispatch | 171 | `5876636b6456cdd15bfd82c559a4afa8fc44ddc6fc0ac6416887493cd114a9c2` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_80081D84.s` |
| `func_level_13_8007B14C` | actor trigger state and numeric CD helper dispatch | 171 | `e2be78906caa870220a4e64b10866313093048fca4f01774b8b3ebf31064d445` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_8007B14C.s` |
| `func_level_14_8007A22C` | actor trigger state and numeric CD helper dispatch | 171 | `0463bb4394d46a712c8ed43f574ff251f026c3ec9288ddb87cdfbf2ebf025945` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_8007A22C.s` |
| `func_level_21_80082A6C` | actor trigger state and numeric CD helper dispatch | 171 | `2f9bfe87c0366bd6e2fed63ef64cc599b2af5c79c52df1a677224a70c6c7b2d9` | `asm/nonmatchings/overlays/level_21/moby/func_level_21_80082A6C.s` |
| `func_level_22_8008316C` | actor trigger state and numeric CD helper dispatch | 171 | `d494912fcdebf326190b006dde4e9592900698b78aeda32b9955dd86a7ae5445` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_8008316C.s` |
| `func_level_23_8007ABC8` | actor trigger state and numeric CD helper dispatch | 171 | `97361cd02c5db749279c237c91a354cd557611968adc373e0a7faf9912287de7` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_8007ABC8.s` |
| `func_level_24_8007C7F4` | actor trigger state and numeric CD helper dispatch | 171 | `104a5cd1a6bf2f955e96c2bc592bcdc7ef98874c11e2b1d7568a714c67bc20c8` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8007C7F4.s` |
| `func_level_31_8007A1A8` | actor trigger state and numeric CD helper dispatch | 171 | `75f90a2f01b5862b1d2437bbd5c72af681e08a65890795de914f729e3b01ea2f` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_8007A1A8.s` |
| `func_level_33_8007C338` | actor trigger state and numeric CD helper dispatch | 171 | `9825f38da325a7c99c25bb04232770a242c14e3e8b630691b0fd26ae009ae86f` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_8007C338.s` |
| `func_level_34_8007D104` | actor trigger state and numeric CD helper dispatch | 171 | `c9b220bd8e75c29bd39014aa0aaa1b142d2b2164a5b34a9292c8166f87b7e4c9` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_8007D104.s` |
| `func_level_41_8007C358` | actor trigger state and numeric CD helper dispatch | 171 | `c8db1e520273388a803de2c1b103d3fcf50817ad2fabd1046232be67563a3603` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_8007C358.s` |
| `func_level_42_8007D724` | actor trigger state and numeric CD helper dispatch | 171 | `b2da7b41340b9002f3498c5418965ac9b38285584882efa91a8151289f494a1f` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_8007D724.s` |
| `func_level_43_8007A408` | actor trigger state and numeric CD helper dispatch | 171 | `0be1313768ac677821692f0e9dc08e7187aac6af9d782877e6593b41399a23a7` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_8007A408.s` |
| `func_level_44_8007A414` | actor trigger state and numeric CD helper dispatch | 171 | `bec44450ec4587c5ab693a34ceec636fcfbe12f933db8bfb68c241365534baa1` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_8007A414.s` |
