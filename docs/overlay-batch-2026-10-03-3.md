# Verified overlay batch 2026-10-03-3

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 52 functions, 1771 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch3.fixed.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Upstream baseline for fragment call wrappers: `src/overlays/level_10/moby.c`, `func_level_10_8007A8F0` and `func_level_10_8008334C`. Other additions use existing upstream structures and the exact retail instructions.

Categories: {'alpha and byte size update': 16, 'red green and byte size update': 16, 'position flag setup': 9, 'conditional deletion wrapper': 7, 'conditional fragment wrapper': 2, 'empty framed return': 1, 'byte yaw increment': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_15_80076C94` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_15/moby/func_level_15_80076C94.s` |
| `func_level_18_800773C8` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_18/moby/func_level_18_800773C8.s` |
| `func_level_20_80077934` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_80077934.s` |
| `func_level_24_800780A0` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_800780A0.s` |
| `func_level_25_80076FC8` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_80076FC8.s` |
| `func_level_28_80077380` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_28/moby/func_level_28_80077380.s` |
| `func_level_33_80078690` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_80078690.s` |
| `func_level_34_80077F8C` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_80077F8C.s` |
| `func_level_35_800771C8` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_35/moby/func_level_35_800771C8.s` |
| `func_level_37_80076AA8` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_37/moby/func_level_37_80076AA8.s` |
| `func_level_38_80077384` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_38/moby/func_level_38_80077384.s` |
| `func_level_42_800778EC` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_800778EC.s` |
| `func_level_45_80076F10` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_45/moby/func_level_45_80076F10.s` |
| `func_level_47_80076A94` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_47/moby/func_level_47_80076A94.s` |
| `func_level_48_800773A8` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_48/moby/func_level_48_800773A8.s` |
| `func_level_50_80077DA4` | alpha and byte size update | 47 | `93bfb6516909899c02736c9d7c5cbf0a66b8575b843e2e9e4a5a298632c7ec81` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_80077DA4.s` |
| `func_level_15_80076D50` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_15/moby/func_level_15_80076D50.s` |
| `func_level_18_80077484` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_18/moby/func_level_18_80077484.s` |
| `func_level_20_800779F0` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_800779F0.s` |
| `func_level_24_8007815C` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8007815C.s` |
| `func_level_25_80077084` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_25/moby/func_level_25_80077084.s` |
| `func_level_28_8007743C` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_28/moby/func_level_28_8007743C.s` |
| `func_level_33_8007874C` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_8007874C.s` |
| `func_level_34_80078048` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_34/moby/func_level_34_80078048.s` |
| `func_level_35_80077284` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_35/moby/func_level_35_80077284.s` |
| `func_level_37_80076B64` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_37/moby/func_level_37_80076B64.s` |
| `func_level_38_80077440` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_38/moby/func_level_38_80077440.s` |
| `func_level_42_800779A8` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_800779A8.s` |
| `func_level_45_80076FCC` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_45/moby/func_level_45_80076FCC.s` |
| `func_level_47_80076B50` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_47/moby/func_level_47_80076B50.s` |
| `func_level_48_80077464` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_48/moby/func_level_48_80077464.s` |
| `func_level_50_80077E60` | red green and byte size update | 45 | `e12091e5a7a99e4b6d5f255e73364830dcc4187a081f2ab633a16b46dce3bfc4` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_80077E60.s` |
| `func_level_10_800843C4` | position flag setup | 21 | `e2ec4ec08fdc56054994c037b339cdf7e6cf0c390587d9a311ba0cc1327fb6fd` | `asm/nonmatchings/overlays/level_10/level/func_level_10_800843C4.s` |
| `func_level_11_80085D24` | position flag setup | 21 | `e2ec4ec08fdc56054994c037b339cdf7e6cf0c390587d9a311ba0cc1327fb6fd` | `asm/nonmatchings/overlays/level_11/level/func_level_11_80085D24.s` |
| `func_level_17_8007F778` | position flag setup | 21 | `e2ec4ec08fdc56054994c037b339cdf7e6cf0c390587d9a311ba0cc1327fb6fd` | `asm/nonmatchings/overlays/level_17/level/func_level_17_8007F778.s` |
| `func_level_20_8008554C` | position flag setup | 21 | `e2ec4ec08fdc56054994c037b339cdf7e6cf0c390587d9a311ba0cc1327fb6fd` | `asm/nonmatchings/overlays/level_20/level/func_level_20_8008554C.s` |
| `func_level_24_8008DFE0` | position flag setup | 21 | `e2ec4ec08fdc56054994c037b339cdf7e6cf0c390587d9a311ba0cc1327fb6fd` | `asm/nonmatchings/overlays/level_24/level/func_level_24_8008DFE0.s` |
| `func_level_27_80084F8C` | position flag setup | 21 | `e2ec4ec08fdc56054994c037b339cdf7e6cf0c390587d9a311ba0cc1327fb6fd` | `asm/nonmatchings/overlays/level_27/level/func_level_27_80084F8C.s` |
| `func_level_30_80083C5C` | position flag setup | 21 | `e2ec4ec08fdc56054994c037b339cdf7e6cf0c390587d9a311ba0cc1327fb6fd` | `asm/nonmatchings/overlays/level_30/level/func_level_30_80083C5C.s` |
| `func_level_37_80085640` | position flag setup | 21 | `e2ec4ec08fdc56054994c037b339cdf7e6cf0c390587d9a311ba0cc1327fb6fd` | `asm/nonmatchings/overlays/level_37/level/func_level_37_80085640.s` |
| `func_level_40_800830BC` | position flag setup | 21 | `e2ec4ec08fdc56054994c037b339cdf7e6cf0c390587d9a311ba0cc1327fb6fd` | `asm/nonmatchings/overlays/level_40/level/func_level_40_800830BC.s` |
| `func_level_11_80084A30` | conditional deletion wrapper | 11 | `5cc87105dd2fb74d6bed471733136fb85ad367553225ca3a0046c2769839abf7` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_80084A30.s` |
| `func_level_20_800841EC` | conditional deletion wrapper | 11 | `5cc87105dd2fb74d6bed471733136fb85ad367553225ca3a0046c2769839abf7` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_800841EC.s` |
| `func_level_23_80089D20` | conditional deletion wrapper | 11 | `5cc87105dd2fb74d6bed471733136fb85ad367553225ca3a0046c2769839abf7` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_80089D20.s` |
| `func_level_30_80082438` | conditional deletion wrapper | 11 | `5cc87105dd2fb74d6bed471733136fb85ad367553225ca3a0046c2769839abf7` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_80082438.s` |
| `func_level_32_8008E95C` | conditional deletion wrapper | 11 | `5cc87105dd2fb74d6bed471733136fb85ad367553225ca3a0046c2769839abf7` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_8008E95C.s` |
| `func_level_40_80082480` | conditional deletion wrapper | 11 | `5cc87105dd2fb74d6bed471733136fb85ad367553225ca3a0046c2769839abf7` | `asm/nonmatchings/overlays/level_40/moby/func_level_40_80082480.s` |
| `func_level_42_80083320` | conditional deletion wrapper | 11 | `5cc87105dd2fb74d6bed471733136fb85ad367553225ca3a0046c2769839abf7` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_80083320.s` |
| `func_level_11_8008404C` | conditional fragment wrapper | 12 | `81f6a8ef4e132d2a929dea68c180079c27e8e1d606e492f2a3685e428a635b9f` | `asm/nonmatchings/overlays/level_11/moby/func_level_11_8008404C.s` |
| `func_level_47_80078568` | conditional fragment wrapper | 12 | `81f6a8ef4e132d2a929dea68c180079c27e8e1d606e492f2a3685e428a635b9f` | `asm/nonmatchings/overlays/level_47/moby/func_level_47_80078568.s` |
| `func_cutscene_73_80075210` | empty framed return | 4 | `ef903660de536978eaef54756e6891dce6e4fcd2887e21247c7613540cb072e8` | `asm/nonmatchings/overlays/cutscene_73/moby/func_cutscene_73_80075210.s` |
| `func_level_45_80079284` | byte yaw increment | 5 | `69143b02b3779ff4d59159d40bd1fdf8af226152a9b35232b868aebf989ac7fe` | `asm/nonmatchings/overlays/level_45/moby/func_level_45_80079284.s` |
