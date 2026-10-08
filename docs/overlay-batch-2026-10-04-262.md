# Verified overlay batch 2026-10-04-262

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 148 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch262.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation notes:

- Two identical camera initializers preserve modes 4 and 0x11, their distinct flag writes, target-vector copy, state-word clear and helper call order. The mode-4 position address is materialized in the original helper delay slot.
- Private aliases of the current and target camera addresses prevent the compiler from sharing addresses where retail rematerializes them for separate calls. They refer to the same verified symbols and introduce no new data or instructions.
- Empty pointer constraints preserve register allocation. All original jumps, pointer offsets and complete overlay hashes were audited.

Categories: {'two-mode camera initialization with target-vector copy': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_20_8008C310` | two-mode camera initialization with target-vector copy | 74 | `7e61f3385f3a9c16a5bdf1125b989bedc704588b3c5eecf782e19ab45a796072` | `asm/nonmatchings/overlays/level_20/camera/func_level_20_8008C310.s` |
| `func_level_30_8008D098` | two-mode camera initialization with target-vector copy | 74 | `8bd343fa99ad626d5ab45a5358039649fd4685fbcb165d797a0c70f0cc055889` | `asm/nonmatchings/overlays/level_30/camera/func_level_30_8008D098.s` |
