# Verified overlay batch 2026-10-03-152

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 139 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch152.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream `Moby`, `Vector3D`, `RECT`, particle/helper declarations and the original instructions. The random particle wrapper retains signed class 0x17A, global bit 0, two independent rand()&3 coordinates and integer Z=20. The state-0x32 deletion chain preserves helpers with literal selectors 4 and 0x18; its other branch preserves class 0x113 and the vector initialization helper before spawning. The smallest particle routine preserves the tag-word/substate OR gate and selects count 3 only for global word value 2, otherwise 2, with literal selector 0x45 and zero arguments. Empty constraints preserve the original constant/callback load order without emitting instructions. The image transfer retains signed 16-bit RECT values X=512,Y=(slot<<6)+128,W=512,H=64, synchronizes before and after LoadImage and either clears the completion halfword or schedules the next archive read with literal index 1. These are original integer and byte-width operations; particle source-domain units, image payload identity and invocation cadence remain unresolved. Next evidence target: archive-to-image data chain and particle selector/argument consumer provenance.

Categories: {'tag and substate gated particle count': 1, 'state deletion chain and class gated vector particle': 1, 'class and global bit gated random vector particle': 1, 'image transfer and archive read continuation': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_12_80079720` | tag and substate gated particle count | 29 | `6c319ccee57744cfde70f77c7798062fda4dd8472be0530ac870c13bf378524f` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_80079720.s` |
| `func_level_44_8008448C` | state deletion chain and class gated vector particle | 37 | `962b152a22467cdeaba0617789cb6fd6fd7ca3447dbc5fbdfb9333bc08248c3a` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_8008448C.s` |
| `func_level_15_80077F98` | class and global bit gated random vector particle | 37 | `15d40370d64afd714ed8a088b297a9dc860267f380951420beaf7a5b55e50b22` | `asm/nonmatchings/overlays/level_15/moby/func_level_15_80077F98.s` |
| `func_atlas_80075F2C` | image transfer and archive read continuation | 36 | `31cbb1b986664ef30af4043da4a86bf9af14772b6eab673afb8fada9895dbdb7` | `asm/nonmatchings/overlays/atlas/atlas1/func_atlas_80075F2C.s` |
