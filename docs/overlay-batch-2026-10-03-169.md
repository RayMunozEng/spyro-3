# Verified overlay batch 2026-10-03-169

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 8 functions, 656 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch169.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: upstream `Moby`, `Spyro`, `SpeechProps`, memory and actor helper declarations. Allocation preserves the original uninitialized tag pointer before clearing the actor, restores it, clears exactly 24 tag bytes and assigns class/parent index; pointer differences use the original 88-byte actor stride and unsigned range test below 256. Special class 0x2C3A retains its unguarded parent-position copy, class/distance fields and helper chain; other classes copy parent/Spyro position and call the original helper. No invented null guard is added. Dialogue routines preserve deletion gates and exact byte fields. In the manual-talk path, talkable byte +7 is cleared only after input bit 0x10 is set and the helper fails; a missing bit bypasses that store. Automatic-talk byte +5 is reloaded afterwards, and the shared start helper/state transition is retained. An empty memory constraint keeps original store/load order without emitting instructions. Tag word +0x20 remains semantically unnamed. Runtime dialogue interpretation, tag allocation schema and invocation cadence remain unresolved. Next evidence target: speech helper state mutations and tag/parent index producers.

Categories: {'cutscene actor allocation tag reset and parent position chain': 4, 'speech tag gating helper calls and actor state transition': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_cutscene_62_80075200` | cutscene actor allocation tag reset and parent position chain | 84 | `2e40e42c7cb7421ce321d4060e604d581cbc52ff4a7df58e0652411f3e55ce29` | `asm/nonmatchings/overlays/cutscene_62/moby/func_cutscene_62_80075200.s` |
| `func_cutscene_63_80074AA8` | cutscene actor allocation tag reset and parent position chain | 84 | `6919ae2af40b3cb58175529ea077cd1ead2477fd0723dc26356a62e86d31c154` | `asm/nonmatchings/overlays/cutscene_63/moby/func_cutscene_63_80074AA8.s` |
| `func_cutscene_64_80075008` | cutscene actor allocation tag reset and parent position chain | 84 | `a7090236b66a45ace8d33f2dc0d1e65c32a09eede58ac51b9dcd8a620244f70d` | `asm/nonmatchings/overlays/cutscene_64/moby/func_cutscene_64_80075008.s` |
| `func_cutscene_67_80074AA8` | cutscene actor allocation tag reset and parent position chain | 84 | `6919ae2af40b3cb58175529ea077cd1ead2477fd0723dc26356a62e86d31c154` | `asm/nonmatchings/overlays/cutscene_67/moby/func_cutscene_67_80074AA8.s` |
| `func_level_15_80079DD0` | speech tag gating helper calls and actor state transition | 80 | `181a3e8ffbbcaf15489de1ed91805fc1eb0cb95930ed1782a8a930c73e6611f5` | `asm/nonmatchings/overlays/level_15/moby/func_level_15_80079DD0.s` |
| `func_level_25_80077FB0` | speech tag gating helper calls and actor state transition | 80 | `65d363c3daf47f52b6e786bf96b698ba7042c7e90a2b32813ede60ad7621c5d8` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_80077FB0.s` |
| `func_level_32_800863F0` | speech tag gating helper calls and actor state transition | 80 | `c63863f6ba70ee6f6f361d3bb5255c50c4e3f56c7dc5d3b04ac5a62ee76a2e17` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_800863F0.s` |
| `func_level_35_800784CC` | speech tag gating helper calls and actor state transition | 80 | `d36d89877cd61f7815a19a8bd02543f41db556942e976e073a1f2749cc64f574` | `asm/nonmatchings/overlays/level_35/moby/func_level_35_800784CC.s` |
