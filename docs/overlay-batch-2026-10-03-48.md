# Verified overlay batch 2026-10-03-48

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 23 functions, 2277 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch48.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Existing upstream Moby fields and original class/model table accesses are the baseline.

## Widths, scheduling and remaining evidence

The partial tag has three signed words at +0/+4/+8. The scan follows the exact retail Moby range and 0x58-byte stride. Class reads are signed halfwords; state, animation, roll, pitch, difficulty and flag fields use their original byte widths; damage and tag counters are words. The model table read reaches its frame-count byte through offset +0x3C. Every byte access relative to the pitch pointer corresponds to an original recorded offset, including negative offsets. No meaning is assigned to unnamed flags. Next evidence target: complete producers of the tag reset/countdown words and model frame table.

Categories: {'actor reset with signed class and byte animation fields': 23}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_80079820` | actor reset with signed class and byte animation fields | 99 | `5afba4caffd8205a59d2ebb8db396f4787c202a0244521bc50ae2ccbd5cd5e01` | `asm/nonmatchings/overlays/level_10/moby/func_level_10_80079820.s` |
| `func_level_11_80079884` | actor reset with signed class and byte animation fields | 99 | `f17f7fb762edc349d36a4c71be0761b019299cc1778a610f8c3ecf4c2b513143` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_80079884.s` |
| `func_level_12_80079594` | actor reset with signed class and byte animation fields | 99 | `88d77eca26c30ebf9ac6c7897c9b0f488428a725fefa40464a1192bb263f796a` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_80079594.s` |
| `func_level_13_8007AC20` | actor reset with signed class and byte animation fields | 99 | `7e02af5f0dadbec1a91ea1501ebf190bf2b00511478d7bbc4b6e05dd557403c3` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_8007AC20.s` |
| `func_level_14_80079DFC` | actor reset with signed class and byte animation fields | 99 | `df2a2f04ab7b37a918b2bc2ef00f2f7feee40009b6f30c64fefc057b7507a395` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_80079DFC.s` |
| `func_level_20_8007A854` | actor reset with signed class and byte animation fields | 99 | `99e3a23d785c4c5c2f4658c8ebd146fea179234d6f4ec7e6aa24879dd1352cf2` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_8007A854.s` |
| `func_level_21_8007A010` | actor reset with signed class and byte animation fields | 99 | `56594cac2da0d1a8ec33999f7d43c55df2ead8405dd42445432c7f941a7f912e` | `asm/nonmatchings/overlays/level_21/moby/func_level_21_8007A010.s` |
| `func_level_22_8007AB84` | actor reset with signed class and byte animation fields | 99 | `286f19601f91119e58e52d5242e9964ffc0b0be29ee42f093b5b9a423d9a0937` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_8007AB84.s` |
| `func_level_23_8007A5B0` | actor reset with signed class and byte animation fields | 99 | `8ee869fdec29df438790e73010f7088043fda012c27c5ab1b0591aa3769f3303` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_8007A5B0.s` |
| `func_level_24_8007B648` | actor reset with signed class and byte animation fields | 99 | `608982b2c31137e758b6c8fc228c0c22a62e42c33b4d02a158f12495092edb11` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8007B648.s` |
| `func_level_26_80079BB0` | actor reset with signed class and byte animation fields | 99 | `90dc1061b3daddee2eba9ff805c2bee3d896a26f711b402e02d53cca9cea6d94` | `asm/nonmatchings/overlays/level_26/moby/func_level_26_80079BB0.s` |
| `func_level_30_80079AA0` | actor reset with signed class and byte animation fields | 99 | `3b1bea546773586566369574c805202937951048d5f09cd9871802d6439bd3b2` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_80079AA0.s` |
| `func_level_31_80079C10` | actor reset with signed class and byte animation fields | 99 | `ac01ba3b324309ff674fd274c97f6bc9c9e542f73f8e3064a30e88abf50aa703` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_80079C10.s` |
| `func_level_32_8007A768` | actor reset with signed class and byte animation fields | 99 | `6afe3677a774c43752878b4074ba12c8db9ddb377f7a600f07fbe02546325582` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_8007A768.s` |
| `func_level_33_8007B300` | actor reset with signed class and byte animation fields | 99 | `b96459be3555a131045c299ce7d551fb16dc66023205cb38eaf370aa65124bfa` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_8007B300.s` |
| `func_level_34_8007C32C` | actor reset with signed class and byte animation fields | 99 | `82ecc6bde45baeb62b26a34364c38f36b76cff271ea6f958c4fd0c27f4fe3c2d` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_8007C32C.s` |
| `func_level_36_80078D90` | actor reset with signed class and byte animation fields | 99 | `f5608a4281d1f903c77e3a641aa99ab987050ae00aaa1c618bf8b5a4f5bec267` | `asm/nonmatchings/overlays/level_36/moby/func_level_36_80078D90.s` |
| `func_level_40_800792B8` | actor reset with signed class and byte animation fields | 99 | `4b0370533fe9d77e326175810b600f92613a1966741f025da093450bf49788d3` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_800792B8.s` |
| `func_level_41_8007B448` | actor reset with signed class and byte animation fields | 99 | `9181e4013712c2fc380816776523448d790361688e705b531ece917d58651068` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_8007B448.s` |
| `func_level_42_8007A944` | actor reset with signed class and byte animation fields | 99 | `55d37cf3524f2a7ad097d944e60e2ee995516b04c8ae8f9cbac3085cd87ce79d` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_8007A944.s` |
| `func_level_43_80079FB0` | actor reset with signed class and byte animation fields | 99 | `8e0d1b993047db0952997cdadd574b5dce1c8f5fa5987faf3925330a0737e2e9` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_80079FB0.s` |
| `func_level_44_80079F54` | actor reset with signed class and byte animation fields | 99 | `dc8ee561c65a575f56e170304fdec8baf7180108f4df902eb7e4bbe9c16508ec` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_80079F54.s` |
| `func_level_46_80079784` | actor reset with signed class and byte animation fields | 99 | `5d05d7aaf83f397adc0106c2f6736b73e56fbcb201d47f781e5b7a2a54839550` | `asm/nonmatchings/overlays/level_46/moby/func_level_46_80079784.s` |
