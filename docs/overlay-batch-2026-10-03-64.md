# Verified overlay batch 2026-10-03-64

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 3 functions, 459 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch64.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Existing upstream CameraPosition and Spyro layouts, plus original overlay routines, are the baseline.

## Widths, scheduling and remaining evidence

Camera subrecord offsets +0x14/+0x28/+0x3C are byte offsets, not typed pointer element counts. The original signed pitch clamp is -0xC0 through +0xC0; its duplicate comparison and negative absolute-value register operation remain exact. The animation switch preserves original case labels, common block placement, jump table entries and padding. Next evidence target: camera state/table producers and animation transition runtime cadence.

Categories: {'camera signed pitch clamp and byte-offset table consumers': 2, 'animation switch reusing upstream fields and original block order': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_15_80089968` | camera signed pitch clamp and byte-offset table consumers | 142 | `bc570c502665a89de9b6600e8293a842ea90c4c46083772e67aaed2befa17ae7` | `asm/nonmatchings/overlays/level_15/camera/func_level_15_80089968.s` |
| `func_level_45_800896FC` | camera signed pitch clamp and byte-offset table consumers | 142 | `53f18ea23d6d8f4c05d3958fbb4b29563dc5cafcc685f74eb43179c92e9d5332` | `asm/nonmatchings/overlays/level_45/camera/func_level_45_800896FC.s` |
| `func_level_27_8008874C` | animation switch reusing upstream fields and original block order | 175 | `d9b4f62fe8bda84459a5bb744bf1b1bffd8bd143ffb1122bd54a09bd99594fa3` | `asm/nonmatchings/overlays/level_27/animation/func_level_27_8008874C.s` |
