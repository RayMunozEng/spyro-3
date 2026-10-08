# Verified overlay batch 2026-10-03-102

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 7 functions, 381 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch102.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Existing upstream Moby, Spyro, angle and Vector3D layouts, plus the prior verified camera-follow wrapper, are the baseline.

## Widths, scheduling and remaining evidence

The follow tag reads signed halfwords at +0/+2, a signed Z-offset word at +4 and a parent pointer at +8. Camera yaw input is a signed interpretation of a 16-bit value shifted right 4 then offset by -128; pitch input is an unsigned 16-bit value shifted right 4. Resulting Moby angle stores wrap to bytes. Retail continues after its deletion helper, selects the original helper for parent class 0x170, and then adds the original Z offset. The timed vector tag has three words at +0/+4/+8 and a word countdown at +0xC; the temporary vector receives original Z addition 0x20 and helper parameter 8. Roll reads an unsigned table halfword at byte offset (timer*8)&0x1F8 and shifts logically by 7. No physical coordinate/time conversion is inferred. Next evidence target: tag and camera producer domains, parent class behavior, and countdown-to-table consumer timing.

Categories: {'camera halfword angles and exact parent record follow including deletion continuation': 4, 'tag vector and countdown with unsigned cosine halfword roll selector': 3}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_18_80081E24` | camera halfword angles and exact parent record follow including deletion continuation | 60 | `136e9f7b74022333b3c6cab45c413d20ca8b89d55e6c7c5057ae6092a0930dc0` | `asm/nonmatchings/overlays/level_18/moby/func_level_18_80081E24.s` |
| `func_level_28_80080838` | camera halfword angles and exact parent record follow including deletion continuation | 60 | `6bd48cf0ca371add39c771bb9e9b375f1cba55ca8c7d804a66584d12b8ce6bb6` | `asm/nonmatchings/overlays/level_28/moby/func_level_28_80080838.s` |
| `func_level_38_80082030` | camera halfword angles and exact parent record follow including deletion continuation | 60 | `addf03b0706b9ef3c4a03aeaaf0d746a2e01f16faff131c2903264dcde0b3112` | `asm/nonmatchings/overlays/level_38/moby/func_level_38_80082030.s` |
| `func_level_48_8007DA28` | camera halfword angles and exact parent record follow including deletion continuation | 60 | `800a3722e2d5748e678698a9723d918ef31cf48feb0d9423a4911e104a1e9430` | `asm/nonmatchings/overlays/level_48/moby/func_level_48_8007DA28.s` |
| `func_level_11_8007AD24` | tag vector and countdown with unsigned cosine halfword roll selector | 47 | `7d2a878175f5b678bcf33cfef44c8c4e8c6b98108658d7ba6bcec879a4f2ae83` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_8007AD24.s` |
| `func_level_13_80081E94` | tag vector and countdown with unsigned cosine halfword roll selector | 47 | `a79426b9c0d4e208f822e4e5ae99c3bfeeb490b7ec1bf1936ac70ff7d7f4a116` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_80081E94.s` |
| `func_level_46_8007AA04` | tag vector and countdown with unsigned cosine halfword roll selector | 47 | `ae6c68b723ef798ab7cdb571702520146d915ff4250d4a89aba0f68a03e5285d` | `asm/nonmatchings/overlays/level_46/moby/func_level_46_8007AA04.s` |
