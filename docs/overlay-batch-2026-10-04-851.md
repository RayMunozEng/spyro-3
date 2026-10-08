# Verified overlay batch 2026-10-04-851

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 15 functions, 2700 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch851.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The fifteen copies implement the same six-segment HUD drawing routine. They read signed 16-bit placement values, derive the third local component from the movement byte using `(byte + 10) >> 1` when nonzero, and call the existing movement helpers. Sprite record dimensions are unsigned byte differences. The routine centers the first sprite using a signed arithmetic half-width, preserves the original 22- and 2-unit spacing, computes six times the segment height, and divides the signed displayed-value product by the unsigned 16-bit maximum promoted to int. Both original division trap checks are retained.

The first loop draws records while the fill value is less than the remaining height. The original route then performs two clipped draws with flags `((fill - height) << 16) | 8` and `((height - fill) << 16) | 8`, advances the segment cursor, draws the remaining records, and draws the final record. It does not add a value clamp or change the retail division-by-zero behavior. The local placement stores and sprite-table reloads retain the original instruction order. Empty constraints emit no instructions.

Units and cadence: these are integer layout coordinates and byte-sized sprite dimensions passed directly to the original helpers, once per invocation; caller frequency and precise render-coordinate interpretation remain unverified. Semantic confidence is limited to these accesses and arithmetic; all 180 linked words in each copy are exact. No browser-runtime parity is claimed. Next evidence target: trace the movement and clipped-draw helper contracts, HUD producers and live call cadence.

Categories: {'six-segment HUD sprite fill and clipped transition': 15}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_80084C00` | six-segment HUD sprite fill and clipped transition | 180 | `d4ca6ea0eb27f18784460bc1b3182d893314c3c8b513057c1c7734d1fefa2024` | `asm/nonmatchings/overlays/level_10/level/func_level_10_80084C00.s` |
| `func_level_12_800855F0` | six-segment HUD sprite fill and clipped transition | 180 | `8492201c7be4381d6b8f49dcb3595699d5dea82c7b688e1c52d436b1c2bcc988` | `asm/nonmatchings/overlays/level_12/level/func_level_12_800855F0.s` |
| `func_level_18_800852FC` | six-segment HUD sprite fill and clipped transition | 180 | `b8b2ca1a660ff521e6102af98e460ac26e93ac39998789eea53dea0079d8ae6a` | `asm/nonmatchings/overlays/level_18/level/func_level_18_800852FC.s` |
| `func_level_20_80085D88` | six-segment HUD sprite fill and clipped transition | 180 | `48df52795e8f2bc6a735ed82dc747a56597781652a252d5abe0b446bd190b9a9` | `asm/nonmatchings/overlays/level_20/level/func_level_20_80085D88.s` |
| `func_level_24_8008ED14` | six-segment HUD sprite fill and clipped transition | 180 | `11560a3ca0d12fde7abaaa5cf708a9520e58a5b4931e9133590f11da087a05ff` | `asm/nonmatchings/overlays/level_24/level/func_level_24_8008ED14.s` |
| `func_level_28_8008346C` | six-segment HUD sprite fill and clipped transition | 180 | `58c9c32ff77a1842a3733d36f714df5dd4f9dbe2f203ae369d5a94bfb9dff595` | `asm/nonmatchings/overlays/level_28/level/func_level_28_8008346C.s` |
| `func_level_30_800847F0` | six-segment HUD sprite fill and clipped transition | 180 | `c40d661a5bedae1bb249dfb4c05463bdf88451b0a2315c044780cbbfefb1afdd` | `asm/nonmatchings/overlays/level_30/level/func_level_30_800847F0.s` |
| `func_level_32_80091F88` | six-segment HUD sprite fill and clipped transition | 180 | `b2a45a820fc118ea45d92ec8fff1f30d99b919c7f0aab066155c7b38ada7bea8` | `asm/nonmatchings/overlays/level_32/level/func_level_32_80091F88.s` |
| `func_level_33_800955B4` | six-segment HUD sprite fill and clipped transition | 180 | `5f367d84dbce72440bb89d5ae3f283854fd6a727d60166cd58770a75b1759223` | `asm/nonmatchings/overlays/level_33/level/func_level_33_800955B4.s` |
| `func_level_34_80090E78` | six-segment HUD sprite fill and clipped transition | 180 | `c2f43545c8808b276a46b152e0650cff69e9fda6e30d15371b4a57aaa4ee0816` | `asm/nonmatchings/overlays/level_34/level/func_level_34_80090E78.s` |
| `func_level_37_8008659C` | six-segment HUD sprite fill and clipped transition | 180 | `bff100459511831b2c9ae43288ea09144b4f1e183bac18c4d3dd8b51f975fba0` | `asm/nonmatchings/overlays/level_37/level/func_level_37_8008659C.s` |
| `func_level_38_80084DC0` | six-segment HUD sprite fill and clipped transition | 180 | `fc21c8f10f26fbfe9b70e97d8b01babda6f01026e60ef8cf66f40758a5b0ea1a` | `asm/nonmatchings/overlays/level_38/level/func_level_38_80084DC0.s` |
| `func_level_41_8008B310` | six-segment HUD sprite fill and clipped transition | 180 | `36faa9eb2e060aa369db3fd944479f253230f67589ae0e9f5675db0270acf7b8` | `asm/nonmatchings/overlays/level_41/level/func_level_41_8008B310.s` |
| `func_level_48_800846D4` | six-segment HUD sprite fill and clipped transition | 180 | `cee68f3bee07f20d4eee02eb5959789aac0e09ad3f1132be447775656ef2c04e` | `asm/nonmatchings/overlays/level_48/level/func_level_48_800846D4.s` |
| `func_level_50_80094774` | six-segment HUD sprite fill and clipped transition | 180 | `d8cccc5de08bdd1e5b5cccbe998250ab352253d918acb2fd9d5e942685d2c060` | `asm/nonmatchings/overlays/level_50/level/func_level_50_80094774.s` |
