# Verified overlay batch 2026-10-03-147

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 6 functions, 187 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch147.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: upstream `WadHeader`, `LevelWadHeader`, `Moby`, particle callback and CD/animation helper declarations. Both archive loaders retain their original byte lengths (0x10000 and 0x4800), buffer/archive offset formulas and signed 16-bit completion stores. The first uses level-WAD offset +0x308 and vram/SPU header word +0, plus index<<16 and 0x20000; the second uses the original atlas image field +0x5A0. Empty constraints in the first preserve its original load/register order. Actor transitions retain byte states 0 ->2 and 2 ->1 with the original substate/global gates and helper selector. Particle routines preserve first-invocation counts 0x40/0x80, subsequent counts 1/2 and selector 0xE. Their literal third argument 1 is retained without claiming it represents a valid vector pointer. The colour routine clears word +8 on every invocation and assigns the original byte values for states 0/1/2. Invocation cadence, particle callback argument semantics and archive payload identity remain unresolved. Next evidence target: particle selector/argument consumer chain and archive payload provenance.

Categories: {'archive read and halfword completion index': 1, 'two actor state transitions and animation helper': 1, 'first and subsequent particle counts': 2, 'archive read with selected buffer and halfword slot': 1, 'actor state colour and draw-byte assignment': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_atlas_80075EB0` | archive read and halfword completion index | 31 | `91d84be4d798f0230e9f3d53c81a656284de565d1348419d90ff0be82a1143a2` | `asm/nonmatchings/overlays/atlas/atlas1/func_atlas_80075EB0.s` |
| `func_level_12_8007F144` | two actor state transitions and animation helper | 30 | `e0fe5882c79f8ad06a06babfca6a381ec4af692175dd288090c922444a009cf7` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_8007F144.s` |
| `func_level_31_80079D9C` | first and subsequent particle counts | 31 | `a0b85b1a9a14f01482313d9ceb9bf56ad68c95da63c5e15cf37f68fe8f26f62e` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_80079D9C.s` |
| `func_level_50_8007A6DC` | first and subsequent particle counts | 31 | `a3a43163a48c263feb7b95004c42a1c099dd94320f252ba738c09556239ad43a` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_8007A6DC.s` |
| `func_atlas_8007594C` | archive read with selected buffer and halfword slot | 32 | `6da07e42e563f6e67d8ca3918e327e71161bf3b735cb7f6b568cd21a785b0116` | `asm/nonmatchings/overlays/atlas/atlas1/func_atlas_8007594C.s` |
| `func_level_30_80082E74` | actor state colour and draw-byte assignment | 32 | `6d1739d0d4baa1072465a9d29a98af7e214b463b7631c18a8f2c8a3a7f21eb37` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_80082E74.s` |
