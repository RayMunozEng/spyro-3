# Verified overlay batch 2026-10-03-189

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 90 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch189.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Both animation dispatchers reuse the SDK animation/player declarations and the previously verified animation-record pointer setup at D_8006E548 + index * 16. Their original comparison trees are retained: shared states 0x2B, 0x2C, 0x35, 0x36, 0x37 and 0x3D call the vector helper at player offset 0xCC, together with state 0x1E in level 35 or 0x14 in level 45. State 0x19 calls the other helper with player offset 0x8C. Empty register constraints emit no instructions and preserve the original allocation and schedule. Callback semantics and animation names remain unestablished. This full gate also verifies removal of the unreachable duplicate assignment in the level 36 selector.

Categories: {'animation-record selection and two vector callbacks': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_35_8008A910` | animation-record selection and two vector callbacks | 45 | `9b3524fb200ee1cb060a9c0ada7a3fae41ef341af667ce87e9ddb49104643546` | `asm/nonmatchings/overlays/level_35/animation/func_level_35_8008A910.s` |
| `func_level_45_800883D0` | animation-record selection and two vector callbacks | 45 | `b23b66493553bd74db55f64199f9f622364548cdcef1e86178653376a7f8b741` | `asm/nonmatchings/overlays/level_45/animation/func_level_45_800883D0.s` |
