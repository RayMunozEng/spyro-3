# Verified overlay batch 2026-10-03-9

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 10 functions, 540 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch9.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'tag countdown and byte size update': 10}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_80079EE4` | tag countdown and byte size update | 54 | `8d8c30ff6fbccbe8d7657f500d6baab238bb190646c81e7c78a975632927ce0d` | `asm/nonmatchings/overlays/level_10/moby/func_level_10_80079EE4.s` |
| `func_level_12_8007F844` | tag countdown and byte size update | 54 | `c8140b213ea1b6103c8152b301d790019dc2b1dd6841ffe161736bdee8518a2f` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_8007F844.s` |
| `func_level_20_8007AF00` | tag countdown and byte size update | 54 | `96e0b0ad1cd153d4151571bb7f7db8728dfc9f1da0a917209ea8c4b494ef8dbf` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_8007AF00.s` |
| `func_level_24_8007BF54` | tag countdown and byte size update | 54 | `7fc9ddaaa15576b75a35060bcb60aadc768c837a29caa88856a861f4ce92c42c` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8007BF54.s` |
| `func_level_30_8007A14C` | tag countdown and byte size update | 54 | `cb091c28218cf53d184a4f5746f3fdaaceb8e01da77d118abd79664ead7c116a` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_8007A14C.s` |
| `func_level_32_80086530` | tag countdown and byte size update | 54 | `52836613d596c89e347cfbd22aa8f8be6decfaec499970db3f2468b19a14145f` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_80086530.s` |
| `func_level_33_8007BA98` | tag countdown and byte size update | 54 | `6e52347eab220d134037770ec29f78e9828b2167ea98d481019759dc9f6a0ff0` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_8007BA98.s` |
| `func_level_34_8007C608` | tag countdown and byte size update | 54 | `896877bf99cd24f052b74b45fa3fac3bdda8fb47af67aca981cfca0b64631e32` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_8007C608.s` |
| `func_level_41_8007BAB8` | tag countdown and byte size update | 54 | `fca1701ec0e62b739e991c52438be6dd2a0ea3e1890aa6d454497fe2610ebfe7` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_8007BAB8.s` |
| `func_level_50_80083430` | tag countdown and byte size update | 54 | `a1459183bfc7221da32d6627890bac1b24f7781e1143af9b5757cbc82ffa8668` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_80083430.s` |
