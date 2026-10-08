# Verified overlay batch 2026-10-03-93

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 6 functions, 372 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch93.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Existing upstream PathNode/Vector3D layout and the earlier verified path distance scan are the baseline.

## Widths, scheduling and remaining evidence

The path count is a signed halfword at +0 and its node pointer is a word at +0xC. Nodes have a 16-byte stride. The signed word center/radius calculation examines 2*radius candidates, computes the original signed remainder (center-radius+index+count)%count, calls func_8004F334 on the node position, and retains only strictly smaller results against initial 0xFFFFFF. Nonpositive extent returns index 0. No extra wrapping or empty-path guard is invented; original divide exception behavior is retained. Register bindings and empty constraints preserve the two-stage extent/loop counter and original 64-byte frame. Eight reserved stack bytes have an unknown source purpose. Next evidence target: path count/node producers and caller center/radius validity, including distance helper units.

Categories: {'signed path count and wrapped nearest node search': 6}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_15_800838A0` | signed path count and wrapped nearest node search | 62 | `1ee6213c09df3086264445aa0bdd4d627d82c4a05a8a2af390b9b6db711a7a07` | `asm/nonmatchings/overlays/level_15/level/func_level_15_800838A0.s` |
| `func_level_25_80084258` | signed path count and wrapped nearest node search | 62 | `1ee6213c09df3086264445aa0bdd4d627d82c4a05a8a2af390b9b6db711a7a07` | `asm/nonmatchings/overlays/level_25/level/func_level_25_80084258.s` |
| `func_level_35_800855DC` | signed path count and wrapped nearest node search | 62 | `1ee6213c09df3086264445aa0bdd4d627d82c4a05a8a2af390b9b6db711a7a07` | `asm/nonmatchings/overlays/level_35/level/func_level_35_800855DC.s` |
| `func_level_41_8008B120` | signed path count and wrapped nearest node search | 62 | `1ee6213c09df3086264445aa0bdd4d627d82c4a05a8a2af390b9b6db711a7a07` | `asm/nonmatchings/overlays/level_41/level/func_level_41_8008B120.s` |
| `func_level_43_8008CD10` | signed path count and wrapped nearest node search | 62 | `1ee6213c09df3086264445aa0bdd4d627d82c4a05a8a2af390b9b6db711a7a07` | `asm/nonmatchings/overlays/level_43/level/func_level_43_8008CD10.s` |
| `func_level_45_80083B98` | signed path count and wrapped nearest node search | 62 | `1ee6213c09df3086264445aa0bdd4d627d82c4a05a8a2af390b9b6db711a7a07` | `asm/nonmatchings/overlays/level_45/level/func_level_45_80083B98.s` |
