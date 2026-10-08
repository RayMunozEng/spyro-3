# Verified overlay batch 2026-10-04-928

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 744 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch928.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Source baseline: original indexed-controller instructions listed below; existing upstream Moby/vector declarations and Savepoint records savedData/unsavedData are reused. The private record stores word gate/source indices and a child pointer at +8. State 0 preserves byte visibility/update writes, the indexed actor state-bit-0x80 gate with 88-byte stride, spawn selector 132, post-spawn table reread, yaw copy, child-private signed-halfword zero, state/pointer writes, signed trig-table reads times 13 shifted by 5, and both writes to the vector Z slot. It preserves player +0x44 input, the vector helper, camera-helper argument 152 and yaw+128 byte mask, and the negative player +0x280 reset. State 1 requires child state bit 0x80 and global !=15, writes state2, then calls the upstream saved-memory helper twice with the state-byte address, length1, and savedData followed by unsavedData. State2 preserves spawn selector603 and the original unconditional dereference, vertical minus512, pitch0, actor visibility fields, and fall-through into state3. State3 preserves helper distance comparison768 and callback arguments0/global-8. Working labels do not establish actor identity or encounter meaning. Units, table/record producers, helper semantics, spawn guarantees, and caller cadence remain explicit evidence targets. Empty constraints preserve original load-delay filling, register allocation, overwritten stores, and callback ordering without emitting instructions. Confidence is exact linked instructions and complete binary hashes; runtime encounter completion is not claimed.

Categories: {'indexed actor gates and ordered state callbacks': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_18_8007DBA8` | indexed actor gates and ordered state callbacks | 186 | `0d71bbc5cc4cbc50c036427ae1af1ee1c2e7f2513cec9e10d5f148bdc625bf9e` | `asm/nonmatchings/overlays/level_18/moby/func_level_18_8007DBA8.s` |
| `func_level_28_8007C98C` | indexed actor gates and ordered state callbacks | 186 | `61c8f7160f8bc9f5fb05e8c42c694324e0d99504581d9e9202460a455da21c2a` | `asm/nonmatchings/overlays/level_28/moby/func_level_28_8007C98C.s` |
| `func_level_38_8007C900` | indexed actor gates and ordered state callbacks | 186 | `ba9f9480aca6e5da0d1254565b3555c32f0a743ce666113499e137681c629784` | `asm/nonmatchings/overlays/level_38/moby/func_level_38_8007C900.s` |
| `func_level_48_8007C9B4` | indexed actor gates and ordered state callbacks | 186 | `ea61d352811137b37998ab01937c56c577fe8ad94efeb8294342ecf45bcd23c4` | `asm/nonmatchings/overlays/level_48/moby/func_level_48_8007C9B4.s` |
