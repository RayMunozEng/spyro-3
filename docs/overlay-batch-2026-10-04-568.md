# Verified overlay batch 2026-10-04-568

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 135 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch568.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream Moby and Vector3D structures. Original level-33 instructions establish all control flow and constants. The routine preserves signed six-eighths reflection arithmetic, gravity subtraction of ten per invocation, four-tick timer call, ordered player/actor/world queries, and the unconditional state-two removal branch. No gameplay interpretation beyond these operations is claimed.

Categories: {'velocity gravity timed impact reflection and removal': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_33_80085AD0` | velocity gravity timed impact reflection and removal | 135 | `99f30d02886783fbfa3c794309a0c590e7395c4f806cc2c434e54df894019402` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_80085AD0.s` |
