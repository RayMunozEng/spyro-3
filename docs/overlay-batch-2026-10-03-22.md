# Verified overlay batch 2026-10-03-22

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 5 functions, 258 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch22.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'camera initialization with retail byte offsets': 4, 'indexed actor camera helper and byte flag': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_18_80088020` | camera initialization with retail byte offsets | 53 | `d104a277e906494aee61bfd84c10b4043088de9448cf1ee446e2ab089f35578d` | `asm/nonmatchings/overlays/level_18/camera/func_level_18_80088020.s` |
| `func_level_28_80086170` | camera initialization with retail byte offsets | 53 | `b5551c7de468803980250e39e5c86060f7766088dc4815f75664634a760397ff` | `asm/nonmatchings/overlays/level_28/camera/func_level_28_80086170.s` |
| `func_level_38_800883A0` | camera initialization with retail byte offsets | 53 | `2bc21f9fcec56c01a2af5434858002b2db7416b0389d39753cd9041fe689088b` | `asm/nonmatchings/overlays/level_38/camera/func_level_38_800883A0.s` |
| `func_level_48_800873D8` | camera initialization with retail byte offsets | 53 | `1161f6061d0b2f8e6fded80f0b70472fe34dc5fdd8bab0d8d882cae136117426` | `asm/nonmatchings/overlays/level_48/camera/func_level_48_800873D8.s` |
| `func_level_18_80082A6C` | indexed actor camera helper and byte flag | 46 | `f38a0e594dcb2194e37615b4caa2133e462902e193bc4c649803e2055722c885` | `asm/nonmatchings/overlays/level_18/moby/func_level_18_80082A6C.s` |
