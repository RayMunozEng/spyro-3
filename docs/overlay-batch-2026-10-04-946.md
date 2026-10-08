# Verified overlay batch 2026-10-04-946

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 141 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch946.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Reuse baseline: SpyroCode `docs/yotd-re/playable-spike-raw989-direct-controller-runtime.md` and its pinned Rev1 local handler0x80082568..0x80082798. Rev0 original words independently establish the141-word source at0x8008246C..0x800826A0. Private offsets0/4/16 and16-byte stack-slot strides retain the original pointer/vector layout. Exact timer return2/other-nonzero/zero routes and byte rereads after both particle callbacks are preserved. Each callback return is dereferenced without inventing a null guard. Phase is signed32bit sum arithmetic-right4 then masked255; signed16bit trig samples multiply25 and arithmetic-right10 with original32bit wrap. The source pointer at player+0x64 advances by0x34 for the vector copy, without inferring a universal scale. The second temporary Z is explicitly cleared after copy. Empty constraints emit no instructions and retain the original wrapped phase operations and three saved register assignments. Helpers, previous-particle producer and pointer validity, per-update cadence, payload meanings, and runtime presentation remain open.

Categories: {'Rev1 raw989 two ordered particle callbacks': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_27_8008246C` | Rev1 raw989 two ordered particle callbacks | 141 | `0c37c3a152215b28339928c1a482a019c0bcf427dcc4d7a89ec70a26d2821464` | `asm/nonmatchings/overlays/level_27/moby/func_level_27_8008246C.s` |
