# Verified overlay batch 2026-10-03-40

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 20 functions, 3440 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch40.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream `common.h`, `stdutil.h`, `str.h`, and `loaders.h` structures and helper declarations, with partial record layouts proved by the original assembly accesses.

Categories: {'cutscene archive header and actor-record setup': 20}.

## Header and actor setup evidence

The input header contains five 32-bit words followed by two lists indexed by the first count and a word containing the actor-array byte offset. The copy length is the model count times four bytes. CD read sizes and offsets remain bytes, including the original `0x800` adjustment and `WadHeader.cutscene[index].mdls.offset` access. No gameplay coordinate conversion is introduced.

Model headers retain the signed first word and optional byte offsets at `0x34` and `0x38`. Actor records are exactly `0x58` bytes. The routine preserves the signed halfword at actor offset `0x38` across clearing, writes the ordinal halfword at `0x36`, sets bytes `0x4C`, `0x4E`, and `0x52` to `0x20`, `0x40`, and `0xFF`, and marks the following actor's state byte `0x48` as `0xFF`. Original pointer reloads and the reused pointer for the first two stores are preserved.

The 56-byte retail stack frame includes eight unused bytes of unknown original purpose. All inline constraints are empty and emit no instructions; they preserve load scheduling and the signed halfword read. Field names inherited from upstream do not establish their cutscene-specific meanings. The next semantic targets are the record producer and consumers of these initialized fields; runtime playback has not been newly verified by this batch.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_cutscene_61_800771B4` | cutscene archive header and actor-record setup | 172 | `a216c4239dbd59d1df34d2d6c549ae587f6dcb7acb036f37b7d096113512e890` | `asm/nonmatchings/overlays/cutscene_61/camera/func_cutscene_61_800771B4.s` |
| `func_cutscene_62_800777E0` | cutscene archive header and actor-record setup | 172 | `85c11e7b08364bb8a57ad0d4cd06a6370c10ba9e8a81a2bc569afffab73c8f6b` | `asm/nonmatchings/overlays/cutscene_62/camera/func_cutscene_62_800777E0.s` |
| `func_cutscene_63_80077088` | cutscene archive header and actor-record setup | 172 | `f586db20acb8f450224a29677b5649a0f94ccb8898267e17f005890adfdbb772` | `asm/nonmatchings/overlays/cutscene_63/camera/func_cutscene_63_80077088.s` |
| `func_cutscene_64_800775E8` | cutscene archive header and actor-record setup | 172 | `445db1e50f55618c7ce87d384deecb9223f7b18fbcfadbe58be03bba78dde738` | `asm/nonmatchings/overlays/cutscene_64/camera/func_cutscene_64_800775E8.s` |
| `func_cutscene_65_80076D30` | cutscene archive header and actor-record setup | 172 | `df095a68066feb92f74db654f63b2f4d31db4ef196b22e2e253a33cc4f322eeb` | `asm/nonmatchings/overlays/cutscene_65/camera/func_cutscene_65_80076D30.s` |
| `func_cutscene_66_80076D30` | cutscene archive header and actor-record setup | 172 | `df095a68066feb92f74db654f63b2f4d31db4ef196b22e2e253a33cc4f322eeb` | `asm/nonmatchings/overlays/cutscene_66/camera/func_cutscene_66_80076D30.s` |
| `func_cutscene_67_80077088` | cutscene archive header and actor-record setup | 172 | `f586db20acb8f450224a29677b5649a0f94ccb8898267e17f005890adfdbb772` | `asm/nonmatchings/overlays/cutscene_67/camera/func_cutscene_67_80077088.s` |
| `func_cutscene_68_80076D30` | cutscene archive header and actor-record setup | 172 | `df095a68066feb92f74db654f63b2f4d31db4ef196b22e2e253a33cc4f322eeb` | `asm/nonmatchings/overlays/cutscene_68/camera/func_cutscene_68_80076D30.s` |
| `func_cutscene_69_80076F84` | cutscene archive header and actor-record setup | 172 | `c4316293c774130a61819010c3c341ba39ed3dedc8257664dcefda83dff3a1f0` | `asm/nonmatchings/overlays/cutscene_69/camera/func_cutscene_69_80076F84.s` |
| `func_cutscene_70_80077378` | cutscene archive header and actor-record setup | 172 | `8ee3fd351a49eb0f82a2acf2a8c8f709cafa93f819d739f80a5986ba17a24106` | `asm/nonmatchings/overlays/cutscene_70/camera/func_cutscene_70_80077378.s` |
| `func_cutscene_71_80076FC8` | cutscene archive header and actor-record setup | 172 | `2cd47d0d3bfdb66a3bba4d032c4e8a757b6aae22607a45002bbc0893fbb76b7a` | `asm/nonmatchings/overlays/cutscene_71/camera/func_cutscene_71_80076FC8.s` |
| `func_cutscene_73_80077B00` | cutscene archive header and actor-record setup | 172 | `d66963ba88c2f56eb6a12fda589225f34a7c22a6fe14acd5feabb4a9abfc21c2` | `asm/nonmatchings/overlays/cutscene_73/camera/func_cutscene_73_80077B00.s` |
| `func_cutscene_74_80076D30` | cutscene archive header and actor-record setup | 172 | `df095a68066feb92f74db654f63b2f4d31db4ef196b22e2e253a33cc4f322eeb` | `asm/nonmatchings/overlays/cutscene_74/camera/func_cutscene_74_80076D30.s` |
| `func_cutscene_75_80076E18` | cutscene archive header and actor-record setup | 172 | `e62aa3eb9f236f224e7383112737250af8704d6edf5d9787baaaca4ec6a5790c` | `asm/nonmatchings/overlays/cutscene_75/camera/func_cutscene_75_80076E18.s` |
| `func_cutscene_76_80076E18` | cutscene archive header and actor-record setup | 172 | `e62aa3eb9f236f224e7383112737250af8704d6edf5d9787baaaca4ec6a5790c` | `asm/nonmatchings/overlays/cutscene_76/camera/func_cutscene_76_80076E18.s` |
| `func_cutscene_77_80076E18` | cutscene archive header and actor-record setup | 172 | `e62aa3eb9f236f224e7383112737250af8704d6edf5d9787baaaca4ec6a5790c` | `asm/nonmatchings/overlays/cutscene_77/camera/func_cutscene_77_80076E18.s` |
| `func_cutscene_78_80077480` | cutscene archive header and actor-record setup | 172 | `f962381a0224536f2452019ac32b3390a088b2e548d001898c7b7079e3f26d67` | `asm/nonmatchings/overlays/cutscene_78/camera/func_cutscene_78_80077480.s` |
| `func_cutscene_79_80076D30` | cutscene archive header and actor-record setup | 172 | `df095a68066feb92f74db654f63b2f4d31db4ef196b22e2e253a33cc4f322eeb` | `asm/nonmatchings/overlays/cutscene_79/camera/func_cutscene_79_80076D30.s` |
| `func_cutscene_80_80077400` | cutscene archive header and actor-record setup | 172 | `8efcf5a349f24362db1dd8c11bada431a4aae024b4e37ac2769742d017d8ce85` | `asm/nonmatchings/overlays/cutscene_80/camera/func_cutscene_80_80077400.s` |
| `func_title_80079D30` | cutscene archive header and actor-record setup | 172 | `2f34382d93f9acb69d27bfd2876e23d84d18a3835810039ff6cb069c8b103442` | `asm/nonmatchings/overlays/title/title3/func_title_80079D30.s` |
