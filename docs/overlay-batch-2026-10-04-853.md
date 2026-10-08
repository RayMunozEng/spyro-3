# Verified overlay batch 2026-10-04-853

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 472 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch853.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Four copies share this three-sample orientation/placement routine. The helper samples consecutive source indices, forms the next-point difference, computes an angle with `func_8004E880`, then forms the first-point minus the third-point difference. It rotates that difference in XY using signed 16-bit cosine/sine table values and arithmetic shifts by 12. It passes the sum of rotated X squared and original Z squared to `func_8004F388`, stores the two negated angle-helper results at bytes 0x44 and 0x45, and calls the existing matrix-update helper with 4. Finally, it transforms `(0, 0, 0x60)` by the actor matrix and adds the result to the first sample. The padded local workspace reproduces the original stack layout; this family uses ordinary C and no empty or instruction-bearing inline assembly.

Units: table multiplication is Q12, proved by signed table loads and shifts. The sampled-coordinate domain, matrix-helper scale, angle-helper interpretation and significance of offset 0x60 remain unresolved. Cadence: one sampling/orientation/placement sequence per invocation; caller timing is not verified. Confidence: all 118 words in each copy are exact. No browser-runtime parity is claimed. Next evidence target: trace the sample and matrix helper producers and consumers before applying this routine to Rev1 browser behavior.

Categories: {'three-sample orientation and matrix-offset placement': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_33_800952E4` | three-sample orientation and matrix-offset placement | 118 | `2d15954f34e2d37e3559dbad21c50473661ad3544fccc289b41c8a17b7537bd7` | `asm/nonmatchings/overlays/level_33/level/func_level_33_800952E4.s` |
| `func_level_43_8008CE08` | three-sample orientation and matrix-offset placement | 118 | `2d15954f34e2d37e3559dbad21c50473661ad3544fccc289b41c8a17b7537bd7` | `asm/nonmatchings/overlays/level_43/level/func_level_43_8008CE08.s` |
| `func_level_44_8008A5CC` | three-sample orientation and matrix-offset placement | 118 | `2d15954f34e2d37e3559dbad21c50473661ad3544fccc289b41c8a17b7537bd7` | `asm/nonmatchings/overlays/level_44/level/func_level_44_8008A5CC.s` |
| `func_level_46_8008B0B8` | three-sample orientation and matrix-offset placement | 118 | `2d15954f34e2d37e3559dbad21c50473661ad3544fccc289b41c8a17b7537bd7` | `asm/nonmatchings/overlays/level_46/level/func_level_46_8008B0B8.s` |
