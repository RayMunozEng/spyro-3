# Verified overlay batch 2026-10-03-208

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 52 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch208.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The initializer reuses the verified SDK camera baseline. Modes 0xC and 0xD retain separate original address setups and byte 0x141 values 0 and 1 before joining the shared initialization tail. State word 0x50, flag bytes 0x140/0x142/0x145 and byte 0x5C are written with original widths, followed by the exact camera helper/vector-copy chain. Empty constraints preserve the original compiler allocation and emit no instructions. Camera coordinate units and new mode semantics are not inferred.

Categories: {'two-mode camera initialization with distinct byte flags': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_16_80086494` | two-mode camera initialization with distinct byte flags | 52 | `dee89be4d7045671daff44d238e146db98c7364d7276cb12ee7f4da0a0f94235` | `asm/nonmatchings/overlays/level_16/camera/func_level_16_80086494.s` |
