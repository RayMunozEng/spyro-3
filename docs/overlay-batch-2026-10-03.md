# Overlay batch: 248 verified C matches

Date: 2026-10-03. Status: AI-generated integration, not yet human-reviewed.

## Scope and provenance

- 102 cutscene call wrappers follow the existing upstream `src/overlays/cutscene_61/cutscene.c` C implementation. Each performs the one retail call shown in its own disassembly.
- 38 input selectors store `&pad.store[index]` to the existing pointer at `0x8006C570`. The retail base is `0x8006E548`, with a 16-byte PadState stride. Test vectors: indices 0, 1, 3 produce addresses `0x8006E548`, `0x8006E558`, `0x8006E578`.
- 101 empty functions reproduce exactly `jr ra; nop` and have no side effects.
- Seven level overlays reuse upstream `include/overlay/animation.inc.h` unchanged. Level 15 contains a nontrivial sound-dispatch routine; the six other accepted variants compile to empty returns. Existing upstream semantic labels are retained, not newly established sound-payload identifications.

The upstream baseline is TheMobyCollective/spyro-3 at `fc206c745091a11a9ff7e96072e7afcf8b435be0`. Retail authority is the original SCUS-94467 USA Rev 0 assembly bytes at the paths below. Updates happen once per call; access widths, branches, calls and integer arithmetic are preserved. Confidence: exact compiled bytes.

## Acceptance evidence

- `python3 build_multiproc.py`, fresh combined run: matching executable and every overlay.
- EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.
- Complete overlay hashes, including relocation targets and tables, equal the existing retail reference hashes.
- Reproducible falsification: rebuild and compare the EXE plus every overlay hash; the original per-function word hashes below identify the source vectors.
- This verifies binary preservation. No additional browser-engine or audible semantic verification is claimed.

## Remaining exact target

Thirty other upstream sound-template variants failed the overlay hash gate and were restored to INCLUDE_ASM. The first next target is `func_level_10_80089B9C`: compare the compiled upstream template against its original instruction sequence and jump table. Scratch candidates and the rejected build log remain under ignored `build/overlay_sound_trial` and `build/overlay_sound.full.log`. Larger duplicate actor/level families remain untranslated.

## Accepted source vectors

| Function | Kind | Retail words (including tables) | SHA-256 of original words | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_cutscene_61_800769AC` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_61/animation/func_cutscene_61_800769AC.s` |
| `func_cutscene_61_800769CC` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_61/animation/func_cutscene_61_800769CC.s` |
| `func_cutscene_61_800769D4` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_61/animation/func_cutscene_61_800769D4.s` |
| `func_cutscene_61_800769DC` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_61/animation/func_cutscene_61_800769DC.s` |
| `func_cutscene_61_800769FC` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_61/animation/func_cutscene_61_800769FC.s` |
| `func_cutscene_61_80076A04` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_61/animation/func_cutscene_61_80076A04.s` |
| `func_cutscene_61_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_61/moby/func_cutscene_61_80074780.s` |
| `func_cutscene_62_80076FD8` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_62/animation/func_cutscene_62_80076FD8.s` |
| `func_cutscene_62_80076FF8` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_62/animation/func_cutscene_62_80076FF8.s` |
| `func_cutscene_62_80077000` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_62/animation/func_cutscene_62_80077000.s` |
| `func_cutscene_62_80077008` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_62/animation/func_cutscene_62_80077008.s` |
| `func_cutscene_62_80077028` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_62/animation/func_cutscene_62_80077028.s` |
| `func_cutscene_62_80077030` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_62/animation/func_cutscene_62_80077030.s` |
| `func_cutscene_62_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_62/moby/func_cutscene_62_80074780.s` |
| `func_cutscene_62_800751F8` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_62/moby/func_cutscene_62_800751F8.s` |
| `func_cutscene_63_80076880` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_63/animation/func_cutscene_63_80076880.s` |
| `func_cutscene_63_800768A0` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_63/animation/func_cutscene_63_800768A0.s` |
| `func_cutscene_63_800768A8` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_63/animation/func_cutscene_63_800768A8.s` |
| `func_cutscene_63_800768B0` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_63/animation/func_cutscene_63_800768B0.s` |
| `func_cutscene_63_800768D0` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_63/animation/func_cutscene_63_800768D0.s` |
| `func_cutscene_63_800768D8` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_63/animation/func_cutscene_63_800768D8.s` |
| `func_cutscene_63_80074BF8` | cutscene call wrapper | 8 | `aeb08657748dc5fe228ef752172d6c80ff62d9a5fb35f9f4e93b809fa9afca79` | `asm/nonmatchings/overlays/cutscene_63/cutscene/func_cutscene_63_80074BF8.s` |
| `func_cutscene_63_80074C18` | cutscene call wrapper | 8 | `ac7747a5e04e17eacb306f464b2be700e2d098f575694f58e9b59978d90e3130` | `asm/nonmatchings/overlays/cutscene_63/cutscene/func_cutscene_63_80074C18.s` |
| `func_cutscene_63_80074C38` | cutscene call wrapper | 8 | `dfde1241f21bcb335b5b4a7ef0996a7c4e191f0bb907380ca0e337b0e6a408e0` | `asm/nonmatchings/overlays/cutscene_63/cutscene/func_cutscene_63_80074C38.s` |
| `func_cutscene_63_80074C58` | cutscene call wrapper | 8 | `1104e5142e01f611b442a32bcbdf67a5c37878f7e9e86379d8170b03f987f09a` | `asm/nonmatchings/overlays/cutscene_63/cutscene/func_cutscene_63_80074C58.s` |
| `func_cutscene_63_80074C78` | cutscene call wrapper | 8 | `ed496378284c6ef7460a4370c6b1ffadba5ad26480a896d0b27634d4f4ae0f61` | `asm/nonmatchings/overlays/cutscene_63/cutscene/func_cutscene_63_80074C78.s` |
| `func_cutscene_63_80074C98` | cutscene call wrapper | 8 | `48f133787de6a837b2c91e75f0229edd187badb3b9b605b382504e1950c9d4a5` | `asm/nonmatchings/overlays/cutscene_63/cutscene/func_cutscene_63_80074C98.s` |
| `func_cutscene_63_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_63/moby/func_cutscene_63_80074780.s` |
| `func_cutscene_63_80074AA0` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_63/moby/func_cutscene_63_80074AA0.s` |
| `func_cutscene_64_80076DE0` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_64/animation/func_cutscene_64_80076DE0.s` |
| `func_cutscene_64_80076E00` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_64/animation/func_cutscene_64_80076E00.s` |
| `func_cutscene_64_80076E08` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_64/animation/func_cutscene_64_80076E08.s` |
| `func_cutscene_64_80076E10` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_64/animation/func_cutscene_64_80076E10.s` |
| `func_cutscene_64_80076E30` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_64/animation/func_cutscene_64_80076E30.s` |
| `func_cutscene_64_80076E38` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_64/animation/func_cutscene_64_80076E38.s` |
| `func_cutscene_64_80075158` | cutscene call wrapper | 8 | `29ac31d63dbd938f93b5435a5fe4273f8e6e63827b63bd0831e6521d09b161b6` | `asm/nonmatchings/overlays/cutscene_64/cutscene/func_cutscene_64_80075158.s` |
| `func_cutscene_64_80075178` | cutscene call wrapper | 8 | `830109e604f752743a2af086b04b3e0461b6c37009d4b0c9a5bc11b17e619ec7` | `asm/nonmatchings/overlays/cutscene_64/cutscene/func_cutscene_64_80075178.s` |
| `func_cutscene_64_80075198` | cutscene call wrapper | 8 | `a68d95a5e10183c860d916d1d8f994bc2896c52dc2401a624a29f812e94afcc6` | `asm/nonmatchings/overlays/cutscene_64/cutscene/func_cutscene_64_80075198.s` |
| `func_cutscene_64_800751B8` | cutscene call wrapper | 8 | `5bb5c1bfd05166641f2f796b859a87bee542f2a76591d41ea4d422f6cc562e61` | `asm/nonmatchings/overlays/cutscene_64/cutscene/func_cutscene_64_800751B8.s` |
| `func_cutscene_64_800751D8` | cutscene call wrapper | 8 | `9443468ea332c9806b01a0b11e9067c163da2b7607ec9b00a8e4cc53528238e1` | `asm/nonmatchings/overlays/cutscene_64/cutscene/func_cutscene_64_800751D8.s` |
| `func_cutscene_64_800751F8` | cutscene call wrapper | 8 | `537e46a5b9774b06b111ff5e27bd01553c47a318df9b26f42e3daa29b7c0a464` | `asm/nonmatchings/overlays/cutscene_64/cutscene/func_cutscene_64_800751F8.s` |
| `func_cutscene_64_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_64/moby/func_cutscene_64_80074780.s` |
| `func_cutscene_64_800749DC` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_64/moby/func_cutscene_64_800749DC.s` |
| `func_cutscene_65_80076528` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_65/animation/func_cutscene_65_80076528.s` |
| `func_cutscene_65_80076548` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_65/animation/func_cutscene_65_80076548.s` |
| `func_cutscene_65_80076550` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_65/animation/func_cutscene_65_80076550.s` |
| `func_cutscene_65_80076558` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_65/animation/func_cutscene_65_80076558.s` |
| `func_cutscene_65_80076578` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_65/animation/func_cutscene_65_80076578.s` |
| `func_cutscene_65_80076580` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_65/animation/func_cutscene_65_80076580.s` |
| `func_cutscene_65_800748A0` | cutscene call wrapper | 8 | `6c1713a80d4819711885b58b6864fdc85701e98f025d06134af6b8da4222da02` | `asm/nonmatchings/overlays/cutscene_65/cutscene/func_cutscene_65_800748A0.s` |
| `func_cutscene_65_800748C0` | cutscene call wrapper | 8 | `9ecdad749fce163233aa94c720371ac93643e319b34008cce8a609b765092330` | `asm/nonmatchings/overlays/cutscene_65/cutscene/func_cutscene_65_800748C0.s` |
| `func_cutscene_65_800748E0` | cutscene call wrapper | 8 | `d77ef9029f73c700dcf13652aa2891900fad998825df61f7a5cf02031d9cf6a5` | `asm/nonmatchings/overlays/cutscene_65/cutscene/func_cutscene_65_800748E0.s` |
| `func_cutscene_65_80074900` | cutscene call wrapper | 8 | `217a72fd12e16452fbf5f4d130f605fafb9e484a003affb8a7985c6ce7525512` | `asm/nonmatchings/overlays/cutscene_65/cutscene/func_cutscene_65_80074900.s` |
| `func_cutscene_65_80074920` | cutscene call wrapper | 8 | `8ea982566d8584a059f22d9f7f776f7c935a02fae9f42676820e7f579db6ee1d` | `asm/nonmatchings/overlays/cutscene_65/cutscene/func_cutscene_65_80074920.s` |
| `func_cutscene_65_80074940` | cutscene call wrapper | 8 | `9660196fef09fa8c4237fc8eec26e38ef54bec8d988e29534f119838d5aa5f31` | `asm/nonmatchings/overlays/cutscene_65/cutscene/func_cutscene_65_80074940.s` |
| `func_cutscene_65_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_65/moby/func_cutscene_65_80074780.s` |
| `func_cutscene_66_80076528` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_66/animation/func_cutscene_66_80076528.s` |
| `func_cutscene_66_80076548` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_66/animation/func_cutscene_66_80076548.s` |
| `func_cutscene_66_80076550` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_66/animation/func_cutscene_66_80076550.s` |
| `func_cutscene_66_80076558` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_66/animation/func_cutscene_66_80076558.s` |
| `func_cutscene_66_80076578` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_66/animation/func_cutscene_66_80076578.s` |
| `func_cutscene_66_80076580` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_66/animation/func_cutscene_66_80076580.s` |
| `func_cutscene_66_800748A0` | cutscene call wrapper | 8 | `6c1713a80d4819711885b58b6864fdc85701e98f025d06134af6b8da4222da02` | `asm/nonmatchings/overlays/cutscene_66/cutscene/func_cutscene_66_800748A0.s` |
| `func_cutscene_66_800748C0` | cutscene call wrapper | 8 | `9ecdad749fce163233aa94c720371ac93643e319b34008cce8a609b765092330` | `asm/nonmatchings/overlays/cutscene_66/cutscene/func_cutscene_66_800748C0.s` |
| `func_cutscene_66_800748E0` | cutscene call wrapper | 8 | `d77ef9029f73c700dcf13652aa2891900fad998825df61f7a5cf02031d9cf6a5` | `asm/nonmatchings/overlays/cutscene_66/cutscene/func_cutscene_66_800748E0.s` |
| `func_cutscene_66_80074900` | cutscene call wrapper | 8 | `217a72fd12e16452fbf5f4d130f605fafb9e484a003affb8a7985c6ce7525512` | `asm/nonmatchings/overlays/cutscene_66/cutscene/func_cutscene_66_80074900.s` |
| `func_cutscene_66_80074920` | cutscene call wrapper | 8 | `8ea982566d8584a059f22d9f7f776f7c935a02fae9f42676820e7f579db6ee1d` | `asm/nonmatchings/overlays/cutscene_66/cutscene/func_cutscene_66_80074920.s` |
| `func_cutscene_66_80074940` | cutscene call wrapper | 8 | `9660196fef09fa8c4237fc8eec26e38ef54bec8d988e29534f119838d5aa5f31` | `asm/nonmatchings/overlays/cutscene_66/cutscene/func_cutscene_66_80074940.s` |
| `func_cutscene_66_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_66/moby/func_cutscene_66_80074780.s` |
| `func_cutscene_67_80076880` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_67/animation/func_cutscene_67_80076880.s` |
| `func_cutscene_67_800768A0` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_67/animation/func_cutscene_67_800768A0.s` |
| `func_cutscene_67_800768A8` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_67/animation/func_cutscene_67_800768A8.s` |
| `func_cutscene_67_800768B0` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_67/animation/func_cutscene_67_800768B0.s` |
| `func_cutscene_67_800768D0` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_67/animation/func_cutscene_67_800768D0.s` |
| `func_cutscene_67_800768D8` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_67/animation/func_cutscene_67_800768D8.s` |
| `func_cutscene_67_80074BF8` | cutscene call wrapper | 8 | `aeb08657748dc5fe228ef752172d6c80ff62d9a5fb35f9f4e93b809fa9afca79` | `asm/nonmatchings/overlays/cutscene_67/cutscene/func_cutscene_67_80074BF8.s` |
| `func_cutscene_67_80074C18` | cutscene call wrapper | 8 | `ac7747a5e04e17eacb306f464b2be700e2d098f575694f58e9b59978d90e3130` | `asm/nonmatchings/overlays/cutscene_67/cutscene/func_cutscene_67_80074C18.s` |
| `func_cutscene_67_80074C38` | cutscene call wrapper | 8 | `dfde1241f21bcb335b5b4a7ef0996a7c4e191f0bb907380ca0e337b0e6a408e0` | `asm/nonmatchings/overlays/cutscene_67/cutscene/func_cutscene_67_80074C38.s` |
| `func_cutscene_67_80074C58` | cutscene call wrapper | 8 | `1104e5142e01f611b442a32bcbdf67a5c37878f7e9e86379d8170b03f987f09a` | `asm/nonmatchings/overlays/cutscene_67/cutscene/func_cutscene_67_80074C58.s` |
| `func_cutscene_67_80074C78` | cutscene call wrapper | 8 | `ed496378284c6ef7460a4370c6b1ffadba5ad26480a896d0b27634d4f4ae0f61` | `asm/nonmatchings/overlays/cutscene_67/cutscene/func_cutscene_67_80074C78.s` |
| `func_cutscene_67_80074C98` | cutscene call wrapper | 8 | `48f133787de6a837b2c91e75f0229edd187badb3b9b605b382504e1950c9d4a5` | `asm/nonmatchings/overlays/cutscene_67/cutscene/func_cutscene_67_80074C98.s` |
| `func_cutscene_67_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_67/moby/func_cutscene_67_80074780.s` |
| `func_cutscene_67_80074AA0` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_67/moby/func_cutscene_67_80074AA0.s` |
| `func_cutscene_68_80076528` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_68/animation/func_cutscene_68_80076528.s` |
| `func_cutscene_68_80076548` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_68/animation/func_cutscene_68_80076548.s` |
| `func_cutscene_68_80076550` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_68/animation/func_cutscene_68_80076550.s` |
| `func_cutscene_68_80076558` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_68/animation/func_cutscene_68_80076558.s` |
| `func_cutscene_68_80076578` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_68/animation/func_cutscene_68_80076578.s` |
| `func_cutscene_68_80076580` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_68/animation/func_cutscene_68_80076580.s` |
| `func_cutscene_68_800748A0` | cutscene call wrapper | 8 | `6c1713a80d4819711885b58b6864fdc85701e98f025d06134af6b8da4222da02` | `asm/nonmatchings/overlays/cutscene_68/cutscene/func_cutscene_68_800748A0.s` |
| `func_cutscene_68_800748C0` | cutscene call wrapper | 8 | `9ecdad749fce163233aa94c720371ac93643e319b34008cce8a609b765092330` | `asm/nonmatchings/overlays/cutscene_68/cutscene/func_cutscene_68_800748C0.s` |
| `func_cutscene_68_800748E0` | cutscene call wrapper | 8 | `d77ef9029f73c700dcf13652aa2891900fad998825df61f7a5cf02031d9cf6a5` | `asm/nonmatchings/overlays/cutscene_68/cutscene/func_cutscene_68_800748E0.s` |
| `func_cutscene_68_80074900` | cutscene call wrapper | 8 | `217a72fd12e16452fbf5f4d130f605fafb9e484a003affb8a7985c6ce7525512` | `asm/nonmatchings/overlays/cutscene_68/cutscene/func_cutscene_68_80074900.s` |
| `func_cutscene_68_80074920` | cutscene call wrapper | 8 | `8ea982566d8584a059f22d9f7f776f7c935a02fae9f42676820e7f579db6ee1d` | `asm/nonmatchings/overlays/cutscene_68/cutscene/func_cutscene_68_80074920.s` |
| `func_cutscene_68_80074940` | cutscene call wrapper | 8 | `9660196fef09fa8c4237fc8eec26e38ef54bec8d988e29534f119838d5aa5f31` | `asm/nonmatchings/overlays/cutscene_68/cutscene/func_cutscene_68_80074940.s` |
| `func_cutscene_68_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_68/moby/func_cutscene_68_80074780.s` |
| `func_cutscene_69_8007677C` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_69/animation/func_cutscene_69_8007677C.s` |
| `func_cutscene_69_8007679C` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_69/animation/func_cutscene_69_8007679C.s` |
| `func_cutscene_69_800767A4` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_69/animation/func_cutscene_69_800767A4.s` |
| `func_cutscene_69_800767AC` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_69/animation/func_cutscene_69_800767AC.s` |
| `func_cutscene_69_800767CC` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_69/animation/func_cutscene_69_800767CC.s` |
| `func_cutscene_69_800767D4` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_69/animation/func_cutscene_69_800767D4.s` |
| `func_cutscene_69_80074AF4` | cutscene call wrapper | 8 | `a9b71e1f710f37e2575f7a7737714f4ea125456bb2de9b7f0f4692c326591eb9` | `asm/nonmatchings/overlays/cutscene_69/cutscene/func_cutscene_69_80074AF4.s` |
| `func_cutscene_69_80074B14` | cutscene call wrapper | 8 | `d4adba8fc0239e8edf4516dcb90c46d92662f88d13fee56486f365ea5dbcf653` | `asm/nonmatchings/overlays/cutscene_69/cutscene/func_cutscene_69_80074B14.s` |
| `func_cutscene_69_80074B34` | cutscene call wrapper | 8 | `7f07c880ac28bc688cbd2f4eb13a48b64c4e90b3c2886c0daeb0b788a702bff5` | `asm/nonmatchings/overlays/cutscene_69/cutscene/func_cutscene_69_80074B34.s` |
| `func_cutscene_69_80074B54` | cutscene call wrapper | 8 | `eed9c5d470e6df2e8143d44a6ed607eab998c91ae8e2f0b14321eb9c2a1480c0` | `asm/nonmatchings/overlays/cutscene_69/cutscene/func_cutscene_69_80074B54.s` |
| `func_cutscene_69_80074B74` | cutscene call wrapper | 8 | `c71bd1f330f6ab3101e813e71c13ebce3c928c82f7b6f63f8c09b565cc348733` | `asm/nonmatchings/overlays/cutscene_69/cutscene/func_cutscene_69_80074B74.s` |
| `func_cutscene_69_80074B94` | cutscene call wrapper | 8 | `d19e0f2006313b6d6d5d3ca8a36fe4b510a7cb0f489f1f5a7d1d207a5842c4c0` | `asm/nonmatchings/overlays/cutscene_69/cutscene/func_cutscene_69_80074B94.s` |
| `func_cutscene_69_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_69/moby/func_cutscene_69_80074780.s` |
| `func_cutscene_70_80076B70` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_70/animation/func_cutscene_70_80076B70.s` |
| `func_cutscene_70_80076B90` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_70/animation/func_cutscene_70_80076B90.s` |
| `func_cutscene_70_80076B98` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_70/animation/func_cutscene_70_80076B98.s` |
| `func_cutscene_70_80076BA0` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_70/animation/func_cutscene_70_80076BA0.s` |
| `func_cutscene_70_80076BC0` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_70/animation/func_cutscene_70_80076BC0.s` |
| `func_cutscene_70_80076BC8` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_70/animation/func_cutscene_70_80076BC8.s` |
| `func_cutscene_70_800748A0` | cutscene call wrapper | 8 | `7f07c880ac28bc688cbd2f4eb13a48b64c4e90b3c2886c0daeb0b788a702bff5` | `asm/nonmatchings/overlays/cutscene_70/cutscene/func_cutscene_70_800748A0.s` |
| `func_cutscene_70_800748C0` | cutscene call wrapper | 8 | `875a8e254ed1ccc6d0668628ac1768b830cd853315b829e484f67d34f0fff11c` | `asm/nonmatchings/overlays/cutscene_70/cutscene/func_cutscene_70_800748C0.s` |
| `func_cutscene_70_800748E0` | cutscene call wrapper | 8 | `59213371e38dabef7d71d4904a5c8715255a6bd7a558ec2c97a79ea365390a90` | `asm/nonmatchings/overlays/cutscene_70/cutscene/func_cutscene_70_800748E0.s` |
| `func_cutscene_70_80074900` | cutscene call wrapper | 8 | `e139c43733309b0aee2ec94ed2415cbb7ebec1643f4cd847ea079e7480dc5669` | `asm/nonmatchings/overlays/cutscene_70/cutscene/func_cutscene_70_80074900.s` |
| `func_cutscene_70_80074920` | cutscene call wrapper | 8 | `44ab6c5d1d54ae8a0b5f8d32c6a054b3570005c458638087226e5c6f691c8b1f` | `asm/nonmatchings/overlays/cutscene_70/cutscene/func_cutscene_70_80074920.s` |
| `func_cutscene_70_80074940` | cutscene call wrapper | 8 | `9e6269ca34e8fdeab494f5831be409eb8924e22ff1a6850f1872ef56cc93f698` | `asm/nonmatchings/overlays/cutscene_70/cutscene/func_cutscene_70_80074940.s` |
| `func_cutscene_70_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_70/moby/func_cutscene_70_80074780.s` |
| `func_cutscene_71_800767C0` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_71/animation/func_cutscene_71_800767C0.s` |
| `func_cutscene_71_800767E0` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_71/animation/func_cutscene_71_800767E0.s` |
| `func_cutscene_71_800767E8` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_71/animation/func_cutscene_71_800767E8.s` |
| `func_cutscene_71_800767F0` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_71/animation/func_cutscene_71_800767F0.s` |
| `func_cutscene_71_80076810` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_71/animation/func_cutscene_71_80076810.s` |
| `func_cutscene_71_80076818` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_71/animation/func_cutscene_71_80076818.s` |
| `func_cutscene_71_800748CC` | cutscene call wrapper | 8 | `5c0c685e9fbfe5e78e350021b20a90919f67564efcbc882ed82b39b256b5efda` | `asm/nonmatchings/overlays/cutscene_71/cutscene/func_cutscene_71_800748CC.s` |
| `func_cutscene_71_800748EC` | cutscene call wrapper | 8 | `25901e0a34bb93e04396d19537fb02f69f27d001ee0cfda2bd8ffd4b9d55800b` | `asm/nonmatchings/overlays/cutscene_71/cutscene/func_cutscene_71_800748EC.s` |
| `func_cutscene_71_8007490C` | cutscene call wrapper | 8 | `34ca1e6b563b54e23b10007079bc8d00b87daf8399d00c5997093c21f2cda705` | `asm/nonmatchings/overlays/cutscene_71/cutscene/func_cutscene_71_8007490C.s` |
| `func_cutscene_71_8007492C` | cutscene call wrapper | 8 | `8f7b2d6b14021c224b7d5f359482ca5368df61aa2e558ae338423ec15d87856a` | `asm/nonmatchings/overlays/cutscene_71/cutscene/func_cutscene_71_8007492C.s` |
| `func_cutscene_71_8007494C` | cutscene call wrapper | 8 | `65016cea0ccfa3c06c49fd0bfdd7a2cc563e5421c078a592cf55ce104f30c7ca` | `asm/nonmatchings/overlays/cutscene_71/cutscene/func_cutscene_71_8007494C.s` |
| `func_cutscene_71_8007496C` | cutscene call wrapper | 8 | `8028c5a558a75284c908719554928e1fd1824a900d1048bcd4397226f3298284` | `asm/nonmatchings/overlays/cutscene_71/cutscene/func_cutscene_71_8007496C.s` |
| `func_cutscene_71_800747AC` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_71/moby/func_cutscene_71_800747AC.s` |
| `func_cutscene_73_800772F8` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_73/animation/func_cutscene_73_800772F8.s` |
| `func_cutscene_73_80077318` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_73/animation/func_cutscene_73_80077318.s` |
| `func_cutscene_73_80077320` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_73/animation/func_cutscene_73_80077320.s` |
| `func_cutscene_73_80077328` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_73/animation/func_cutscene_73_80077328.s` |
| `func_cutscene_73_80077348` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_73/animation/func_cutscene_73_80077348.s` |
| `func_cutscene_73_80077350` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_73/animation/func_cutscene_73_80077350.s` |
| `func_cutscene_73_800753B8` | cutscene call wrapper | 8 | `49d5b9dd20ca8a4f7e883b54b342e705a5d103b050b861fe4ea9cddfe9d2143d` | `asm/nonmatchings/overlays/cutscene_73/cutscene/func_cutscene_73_800753B8.s` |
| `func_cutscene_73_800753D8` | cutscene call wrapper | 8 | `5f1733b87152bb2d5ad9eb71b7d599c7127ff2a8e9884e45a7dca4a2a43cbc9e` | `asm/nonmatchings/overlays/cutscene_73/cutscene/func_cutscene_73_800753D8.s` |
| `func_cutscene_73_800753F8` | cutscene call wrapper | 8 | `3c10c0c1510013418e6dbf0d48f265b492fe8627cc76233eb0821836d9db3f4a` | `asm/nonmatchings/overlays/cutscene_73/cutscene/func_cutscene_73_800753F8.s` |
| `func_cutscene_73_80075418` | cutscene call wrapper | 8 | `a99661237562d0fd629f0e09734870a71b51efa6abdd3868a6ce7dc3ab1e5cfc` | `asm/nonmatchings/overlays/cutscene_73/cutscene/func_cutscene_73_80075418.s` |
| `func_cutscene_73_80075438` | cutscene call wrapper | 8 | `8a8b77ab39004d0dd238a3e0a680398245930d44ab5148bab065091b52602448` | `asm/nonmatchings/overlays/cutscene_73/cutscene/func_cutscene_73_80075438.s` |
| `func_cutscene_73_80075458` | cutscene call wrapper | 8 | `c0e8487c3e1f05f43a7437407f3f8d8605c76bbbc5b9361c27f7e460a7515707` | `asm/nonmatchings/overlays/cutscene_73/cutscene/func_cutscene_73_80075458.s` |
| `func_cutscene_73_80074800` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_73/moby/func_cutscene_73_80074800.s` |
| `func_cutscene_73_80074D94` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_73/moby/func_cutscene_73_80074D94.s` |
| `func_cutscene_74_80076528` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_74/animation/func_cutscene_74_80076528.s` |
| `func_cutscene_74_80076548` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_74/animation/func_cutscene_74_80076548.s` |
| `func_cutscene_74_80076550` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_74/animation/func_cutscene_74_80076550.s` |
| `func_cutscene_74_80076558` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_74/animation/func_cutscene_74_80076558.s` |
| `func_cutscene_74_80076578` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_74/animation/func_cutscene_74_80076578.s` |
| `func_cutscene_74_80076580` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_74/animation/func_cutscene_74_80076580.s` |
| `func_cutscene_74_800748A0` | cutscene call wrapper | 8 | `6c1713a80d4819711885b58b6864fdc85701e98f025d06134af6b8da4222da02` | `asm/nonmatchings/overlays/cutscene_74/cutscene/func_cutscene_74_800748A0.s` |
| `func_cutscene_74_800748C0` | cutscene call wrapper | 8 | `9ecdad749fce163233aa94c720371ac93643e319b34008cce8a609b765092330` | `asm/nonmatchings/overlays/cutscene_74/cutscene/func_cutscene_74_800748C0.s` |
| `func_cutscene_74_800748E0` | cutscene call wrapper | 8 | `d77ef9029f73c700dcf13652aa2891900fad998825df61f7a5cf02031d9cf6a5` | `asm/nonmatchings/overlays/cutscene_74/cutscene/func_cutscene_74_800748E0.s` |
| `func_cutscene_74_80074900` | cutscene call wrapper | 8 | `217a72fd12e16452fbf5f4d130f605fafb9e484a003affb8a7985c6ce7525512` | `asm/nonmatchings/overlays/cutscene_74/cutscene/func_cutscene_74_80074900.s` |
| `func_cutscene_74_80074920` | cutscene call wrapper | 8 | `8ea982566d8584a059f22d9f7f776f7c935a02fae9f42676820e7f579db6ee1d` | `asm/nonmatchings/overlays/cutscene_74/cutscene/func_cutscene_74_80074920.s` |
| `func_cutscene_74_80074940` | cutscene call wrapper | 8 | `9660196fef09fa8c4237fc8eec26e38ef54bec8d988e29534f119838d5aa5f31` | `asm/nonmatchings/overlays/cutscene_74/cutscene/func_cutscene_74_80074940.s` |
| `func_cutscene_74_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_74/moby/func_cutscene_74_80074780.s` |
| `func_cutscene_75_80076610` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_75/animation/func_cutscene_75_80076610.s` |
| `func_cutscene_75_80076630` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_75/animation/func_cutscene_75_80076630.s` |
| `func_cutscene_75_80076638` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_75/animation/func_cutscene_75_80076638.s` |
| `func_cutscene_75_80076640` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_75/animation/func_cutscene_75_80076640.s` |
| `func_cutscene_75_80076660` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_75/animation/func_cutscene_75_80076660.s` |
| `func_cutscene_75_80076668` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_75/animation/func_cutscene_75_80076668.s` |
| `func_cutscene_75_80074988` | cutscene call wrapper | 8 | `f74a31ec2cbb89c1b57724dc2c77001db834ed61a46bc48f993295d23c738512` | `asm/nonmatchings/overlays/cutscene_75/cutscene/func_cutscene_75_80074988.s` |
| `func_cutscene_75_800749A8` | cutscene call wrapper | 8 | `754c729684f33169e5dd576259df2df767f6c6d7d3bb32b3103525efe9e3b3fa` | `asm/nonmatchings/overlays/cutscene_75/cutscene/func_cutscene_75_800749A8.s` |
| `func_cutscene_75_800749C8` | cutscene call wrapper | 8 | `9a00951cfa3ae5e549829acb71288f434051a53bc1c91f356315c6528c67c7a6` | `asm/nonmatchings/overlays/cutscene_75/cutscene/func_cutscene_75_800749C8.s` |
| `func_cutscene_75_800749E8` | cutscene call wrapper | 8 | `058ee423c8b7c592da6af0553e50af1183a8bc86d9d25038e4b8380e968d8ec2` | `asm/nonmatchings/overlays/cutscene_75/cutscene/func_cutscene_75_800749E8.s` |
| `func_cutscene_75_80074A08` | cutscene call wrapper | 8 | `b70d1c7019f7d071629f1c26e305c1f095c29f61400dca9fb185222610198b13` | `asm/nonmatchings/overlays/cutscene_75/cutscene/func_cutscene_75_80074A08.s` |
| `func_cutscene_75_80074A28` | cutscene call wrapper | 8 | `bcd889c7afecbc9fcad5a997aec6427de221bdb7f7de3659099213e1c7419390` | `asm/nonmatchings/overlays/cutscene_75/cutscene/func_cutscene_75_80074A28.s` |
| `func_cutscene_75_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_75/moby/func_cutscene_75_80074780.s` |
| `func_cutscene_76_80076610` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_76/animation/func_cutscene_76_80076610.s` |
| `func_cutscene_76_80076630` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_76/animation/func_cutscene_76_80076630.s` |
| `func_cutscene_76_80076638` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_76/animation/func_cutscene_76_80076638.s` |
| `func_cutscene_76_80076640` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_76/animation/func_cutscene_76_80076640.s` |
| `func_cutscene_76_80076660` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_76/animation/func_cutscene_76_80076660.s` |
| `func_cutscene_76_80076668` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_76/animation/func_cutscene_76_80076668.s` |
| `func_cutscene_76_80074988` | cutscene call wrapper | 8 | `f74a31ec2cbb89c1b57724dc2c77001db834ed61a46bc48f993295d23c738512` | `asm/nonmatchings/overlays/cutscene_76/cutscene/func_cutscene_76_80074988.s` |
| `func_cutscene_76_800749A8` | cutscene call wrapper | 8 | `754c729684f33169e5dd576259df2df767f6c6d7d3bb32b3103525efe9e3b3fa` | `asm/nonmatchings/overlays/cutscene_76/cutscene/func_cutscene_76_800749A8.s` |
| `func_cutscene_76_800749C8` | cutscene call wrapper | 8 | `9a00951cfa3ae5e549829acb71288f434051a53bc1c91f356315c6528c67c7a6` | `asm/nonmatchings/overlays/cutscene_76/cutscene/func_cutscene_76_800749C8.s` |
| `func_cutscene_76_800749E8` | cutscene call wrapper | 8 | `058ee423c8b7c592da6af0553e50af1183a8bc86d9d25038e4b8380e968d8ec2` | `asm/nonmatchings/overlays/cutscene_76/cutscene/func_cutscene_76_800749E8.s` |
| `func_cutscene_76_80074A08` | cutscene call wrapper | 8 | `b70d1c7019f7d071629f1c26e305c1f095c29f61400dca9fb185222610198b13` | `asm/nonmatchings/overlays/cutscene_76/cutscene/func_cutscene_76_80074A08.s` |
| `func_cutscene_76_80074A28` | cutscene call wrapper | 8 | `bcd889c7afecbc9fcad5a997aec6427de221bdb7f7de3659099213e1c7419390` | `asm/nonmatchings/overlays/cutscene_76/cutscene/func_cutscene_76_80074A28.s` |
| `func_cutscene_76_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_76/moby/func_cutscene_76_80074780.s` |
| `func_cutscene_77_80076610` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_77/animation/func_cutscene_77_80076610.s` |
| `func_cutscene_77_80076630` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_77/animation/func_cutscene_77_80076630.s` |
| `func_cutscene_77_80076638` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_77/animation/func_cutscene_77_80076638.s` |
| `func_cutscene_77_80076640` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_77/animation/func_cutscene_77_80076640.s` |
| `func_cutscene_77_80076660` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_77/animation/func_cutscene_77_80076660.s` |
| `func_cutscene_77_80076668` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_77/animation/func_cutscene_77_80076668.s` |
| `func_cutscene_77_80074988` | cutscene call wrapper | 8 | `f74a31ec2cbb89c1b57724dc2c77001db834ed61a46bc48f993295d23c738512` | `asm/nonmatchings/overlays/cutscene_77/cutscene/func_cutscene_77_80074988.s` |
| `func_cutscene_77_800749A8` | cutscene call wrapper | 8 | `754c729684f33169e5dd576259df2df767f6c6d7d3bb32b3103525efe9e3b3fa` | `asm/nonmatchings/overlays/cutscene_77/cutscene/func_cutscene_77_800749A8.s` |
| `func_cutscene_77_800749C8` | cutscene call wrapper | 8 | `9a00951cfa3ae5e549829acb71288f434051a53bc1c91f356315c6528c67c7a6` | `asm/nonmatchings/overlays/cutscene_77/cutscene/func_cutscene_77_800749C8.s` |
| `func_cutscene_77_800749E8` | cutscene call wrapper | 8 | `058ee423c8b7c592da6af0553e50af1183a8bc86d9d25038e4b8380e968d8ec2` | `asm/nonmatchings/overlays/cutscene_77/cutscene/func_cutscene_77_800749E8.s` |
| `func_cutscene_77_80074A08` | cutscene call wrapper | 8 | `b70d1c7019f7d071629f1c26e305c1f095c29f61400dca9fb185222610198b13` | `asm/nonmatchings/overlays/cutscene_77/cutscene/func_cutscene_77_80074A08.s` |
| `func_cutscene_77_80074A28` | cutscene call wrapper | 8 | `bcd889c7afecbc9fcad5a997aec6427de221bdb7f7de3659099213e1c7419390` | `asm/nonmatchings/overlays/cutscene_77/cutscene/func_cutscene_77_80074A28.s` |
| `func_cutscene_77_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_77/moby/func_cutscene_77_80074780.s` |
| `func_cutscene_78_80076C78` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_78/animation/func_cutscene_78_80076C78.s` |
| `func_cutscene_78_80076C98` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_78/animation/func_cutscene_78_80076C98.s` |
| `func_cutscene_78_80076CA0` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_78/animation/func_cutscene_78_80076CA0.s` |
| `func_cutscene_78_80076CA8` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_78/animation/func_cutscene_78_80076CA8.s` |
| `func_cutscene_78_80076CC8` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_78/animation/func_cutscene_78_80076CC8.s` |
| `func_cutscene_78_80076CD0` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_78/animation/func_cutscene_78_80076CD0.s` |
| `func_cutscene_78_80074D68` | cutscene call wrapper | 8 | `1959b18827a54075710a0ce22a0ac357d2bef42b63ec81bf0fbd29a16bf4ec6d` | `asm/nonmatchings/overlays/cutscene_78/cutscene/func_cutscene_78_80074D68.s` |
| `func_cutscene_78_80074D88` | cutscene call wrapper | 8 | `ac3e81ce47c854c543efd84b2849f2b0e958879be8df0aecf8f574fc8a057961` | `asm/nonmatchings/overlays/cutscene_78/cutscene/func_cutscene_78_80074D88.s` |
| `func_cutscene_78_80074DA8` | cutscene call wrapper | 8 | `64003bdfe802e94d42c48dde25df517d9dd492dc0a353be7735df5105dd21209` | `asm/nonmatchings/overlays/cutscene_78/cutscene/func_cutscene_78_80074DA8.s` |
| `func_cutscene_78_80074DC8` | cutscene call wrapper | 8 | `5c02843507de66adad379c04c51ac11a948be6344fbe379afc677b865ea57afe` | `asm/nonmatchings/overlays/cutscene_78/cutscene/func_cutscene_78_80074DC8.s` |
| `func_cutscene_78_80074DE8` | cutscene call wrapper | 8 | `05c66c6291cc2fbbc306ca89cd0283ccfe423042589c3114b7ad17aabb82dcb0` | `asm/nonmatchings/overlays/cutscene_78/cutscene/func_cutscene_78_80074DE8.s` |
| `func_cutscene_78_80074E08` | cutscene call wrapper | 8 | `9da885f7ea4e9b44da19926c6ed538549a2fabdf94b0c5b1364a75030fa8e444` | `asm/nonmatchings/overlays/cutscene_78/cutscene/func_cutscene_78_80074E08.s` |
| `func_cutscene_78_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_78/moby/func_cutscene_78_80074780.s` |
| `func_cutscene_78_80074BC0` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_78/moby/func_cutscene_78_80074BC0.s` |
| `func_cutscene_79_80076528` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_79/animation/func_cutscene_79_80076528.s` |
| `func_cutscene_79_80076548` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_79/animation/func_cutscene_79_80076548.s` |
| `func_cutscene_79_80076550` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_79/animation/func_cutscene_79_80076550.s` |
| `func_cutscene_79_80076558` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_79/animation/func_cutscene_79_80076558.s` |
| `func_cutscene_79_80076578` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_79/animation/func_cutscene_79_80076578.s` |
| `func_cutscene_79_80076580` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_79/animation/func_cutscene_79_80076580.s` |
| `func_cutscene_79_800748A0` | cutscene call wrapper | 8 | `6c1713a80d4819711885b58b6864fdc85701e98f025d06134af6b8da4222da02` | `asm/nonmatchings/overlays/cutscene_79/cutscene/func_cutscene_79_800748A0.s` |
| `func_cutscene_79_800748C0` | cutscene call wrapper | 8 | `9ecdad749fce163233aa94c720371ac93643e319b34008cce8a609b765092330` | `asm/nonmatchings/overlays/cutscene_79/cutscene/func_cutscene_79_800748C0.s` |
| `func_cutscene_79_800748E0` | cutscene call wrapper | 8 | `d77ef9029f73c700dcf13652aa2891900fad998825df61f7a5cf02031d9cf6a5` | `asm/nonmatchings/overlays/cutscene_79/cutscene/func_cutscene_79_800748E0.s` |
| `func_cutscene_79_80074900` | cutscene call wrapper | 8 | `217a72fd12e16452fbf5f4d130f605fafb9e484a003affb8a7985c6ce7525512` | `asm/nonmatchings/overlays/cutscene_79/cutscene/func_cutscene_79_80074900.s` |
| `func_cutscene_79_80074920` | cutscene call wrapper | 8 | `8ea982566d8584a059f22d9f7f776f7c935a02fae9f42676820e7f579db6ee1d` | `asm/nonmatchings/overlays/cutscene_79/cutscene/func_cutscene_79_80074920.s` |
| `func_cutscene_79_80074940` | cutscene call wrapper | 8 | `9660196fef09fa8c4237fc8eec26e38ef54bec8d988e29534f119838d5aa5f31` | `asm/nonmatchings/overlays/cutscene_79/cutscene/func_cutscene_79_80074940.s` |
| `func_cutscene_79_80074780` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_79/moby/func_cutscene_79_80074780.s` |
| `func_cutscene_80_80076BF8` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_80/animation/func_cutscene_80_80076BF8.s` |
| `func_cutscene_80_80076C18` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_80/animation/func_cutscene_80_80076C18.s` |
| `func_cutscene_80_80076C20` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_80/animation/func_cutscene_80_80076C20.s` |
| `func_cutscene_80_80076C28` | stored pad selector | 8 | `4521f24ee65109ad8f2ba63adc35416e63877de0c3c435d3429d9bada887e61f` | `asm/nonmatchings/overlays/cutscene_80/animation/func_cutscene_80_80076C28.s` |
| `func_cutscene_80_80076C48` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_80/animation/func_cutscene_80_80076C48.s` |
| `func_cutscene_80_80076C50` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_80/animation/func_cutscene_80_80076C50.s` |
| `func_cutscene_80_800748CC` | cutscene call wrapper | 8 | `ef3a3bbf9f059ee104fcea3083d163e207782b3f9a096c7e4d6ba9de8e306422` | `asm/nonmatchings/overlays/cutscene_80/cutscene/func_cutscene_80_800748CC.s` |
| `func_cutscene_80_800748EC` | cutscene call wrapper | 8 | `ccc12a6c938344ca4d4440af313d9f8bbfaa65937c8a3743ab86eadb5de64898` | `asm/nonmatchings/overlays/cutscene_80/cutscene/func_cutscene_80_800748EC.s` |
| `func_cutscene_80_8007490C` | cutscene call wrapper | 8 | `835d7f00e24722ff2c349bacd03dad65923cf0399a8b4078fc14451d8f6d878e` | `asm/nonmatchings/overlays/cutscene_80/cutscene/func_cutscene_80_8007490C.s` |
| `func_cutscene_80_8007492C` | cutscene call wrapper | 8 | `950fcee3e02a3eddff48787bd046369a3c18829f287926e10aec8b1d558ca2af` | `asm/nonmatchings/overlays/cutscene_80/cutscene/func_cutscene_80_8007492C.s` |
| `func_cutscene_80_8007494C` | cutscene call wrapper | 8 | `d58d39e7e3af71f1f6571c9d833c9676d05731355dcfdf11f30266f012dc5aa2` | `asm/nonmatchings/overlays/cutscene_80/cutscene/func_cutscene_80_8007494C.s` |
| `func_cutscene_80_8007496C` | cutscene call wrapper | 8 | `f9d41aa6ea140d8998cd476983902667a6c7c2e1629107406817557e8ad98af9` | `asm/nonmatchings/overlays/cutscene_80/cutscene/func_cutscene_80_8007496C.s` |
| `func_cutscene_80_800747AC` | empty return | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/cutscene_80/moby/func_cutscene_80_800747AC.s` |
| `func_level_15_800886FC` | upstream animation template | 75 | `6df46638c3efc94bb166c87e1c1170cc060a3c9bc1e48848d665155b22e66b17` | `asm/nonmatchings/overlays/level_15/animation/func_level_15_800886FC.s` |
| `func_level_16_80084B04` | upstream animation template | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/level_16/animation/func_level_16_80084B04.s` |
| `func_level_18_80087D6C` | upstream animation template | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/level_18/animation/func_level_18_80087D6C.s` |
| `func_level_28_80085EBC` | upstream animation template | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/level_28/animation/func_level_28_80085EBC.s` |
| `func_level_38_800880EC` | upstream animation template | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/level_38/animation/func_level_38_800880EC.s` |
| `func_level_40_80086564` | upstream animation template | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/level_40/animation/func_level_40_80086564.s` |
| `func_level_48_80087124` | upstream animation template | 2 | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` | `asm/nonmatchings/overlays/level_48/animation/func_level_48_80087124.s` |
