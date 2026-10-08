# Verified overlay batch 2026-10-03-237

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 283 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch237.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- Level 17 and Level 37 animation selectors reuse the verified Level 10 selector structure. Every sparse selector and the alignment word are checked against the original jump tables. The full linked audit caught and corrected an extra Level 37 vector case at 0x20 before acceptance.
- `func_level_25_800883CC` preserves the two distinct vector callbacks at player offsets 0xCC and 0x8C and all return-only selector entries.
- `func_level_31_800836FC` preserves the progress gates, state save, damage-bit OR frame-threshold condition, shared cleanup calls, and damage clearing. Numeric fields are retained without new semantic labels.

Categories: {'sparse animation selector and shared vector callback': 2, 'progress flags, animation frame and damage gated actor state': 1, 'sparse animation table with distinct vector callbacks': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_17_80082ECC` | sparse animation selector and shared vector callback | 71 | `790dc5db5509e0f79d73dd84f20a9585d759f4fc2e46879a2e24a661d56fa45e` | `asm/nonmatchings/overlays/level_17/animation/func_level_17_80082ECC.s` |
| `func_level_37_8008A218` | sparse animation selector and shared vector callback | 71 | `48bd1566132d4053e280cd61368978e48191dab139f291b6f81bcad1fa54bbc1` | `asm/nonmatchings/overlays/level_37/animation/func_level_37_8008A218.s` |
| `func_level_31_800836FC` | progress flags, animation frame and damage gated actor state | 69 | `c9abdaf1301b8d1ef9391013c1248541de6999faae9be221f3defde0187f2e6a` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_800836FC.s` |
| `func_level_25_800883CC` | sparse animation table with distinct vector callbacks | 72 | `256378ff71bd6a05697e259de378b65385e2e5762667f72be5e4cba9d9065e86` | `asm/nonmatchings/overlays/level_25/animation/func_level_25_800883CC.s` |
