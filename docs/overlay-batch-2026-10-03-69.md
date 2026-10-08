# Verified overlay batch 2026-10-03-69

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 7 functions, 378 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch69.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Existing upstream Vector3D layout and original sine/cosine tables are the baseline.

## Widths, scheduling and remaining evidence

The partial record contains signed 32-bit origin values and words at +0xC/+0x10/+0x14. Scaling uses the recorded arithmetic shift 7; rotation uses signed 16-bit table entries and arithmetic shift 12. No universal world or model coordinate conversion is inferred. The original multiplication order and angle read preceding scaled X assignment are retained. A nonvolatile empty compiler constraint retains cosine base/index scheduling while allowing the original multiply latency overlap. Next evidence target: exact producers and consumers establishing the physical units of these record words.

Categories: {'word scale and signed table vector transform': 7}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_13_80085EB4` | word scale and signed table vector transform | 54 | `f52c6c9803e242813d06e452a39324225622aacb4da9697e8cf59af1378c513a` | `asm/nonmatchings/overlays/level_13/level/func_level_13_80085EB4.s` |
| `func_level_26_800864D4` | word scale and signed table vector transform | 54 | `f52c6c9803e242813d06e452a39324225622aacb4da9697e8cf59af1378c513a` | `asm/nonmatchings/overlays/level_26/level/func_level_26_800864D4.s` |
| `func_level_31_80089D30` | word scale and signed table vector transform | 54 | `f52c6c9803e242813d06e452a39324225622aacb4da9697e8cf59af1378c513a` | `asm/nonmatchings/overlays/level_31/level/func_level_31_80089D30.s` |
| `func_level_32_80092444` | word scale and signed table vector transform | 54 | `f52c6c9803e242813d06e452a39324225622aacb4da9697e8cf59af1378c513a` | `asm/nonmatchings/overlays/level_32/level/func_level_32_80092444.s` |
| `func_level_34_8009120C` | word scale and signed table vector transform | 54 | `f52c6c9803e242813d06e452a39324225622aacb4da9697e8cf59af1378c513a` | `asm/nonmatchings/overlays/level_34/level/func_level_34_8009120C.s` |
| `func_level_35_800856D4` | word scale and signed table vector transform | 54 | `f52c6c9803e242813d06e452a39324225622aacb4da9697e8cf59af1378c513a` | `asm/nonmatchings/overlays/level_35/level/func_level_35_800856D4.s` |
| `func_level_42_80085A34` | word scale and signed table vector transform | 54 | `f52c6c9803e242813d06e452a39324225622aacb4da9697e8cf59af1378c513a` | `asm/nonmatchings/overlays/level_42/level/func_level_42_80085A34.s` |
