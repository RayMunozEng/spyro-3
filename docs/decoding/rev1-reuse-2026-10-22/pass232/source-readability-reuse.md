# Existing Rev 1 decoding applied to the fork

**AI generated; not human reviewed. Publication is recorded in the containing cleanup commit.**

This continuation names 232 already decoded operations across 228 C files. It replaces 6,555 private aliases (20,559 identifier instances). It adds zero unique decoding-word credit.

Every replacement preserves all other source bytes, including types, argument expressions, strings, linker labels, comments, and newline style. Actual MIPS preprocessing is identical after reversing only the identifier replacements. Each composed batch passes all 96 retained native commands and all 62 original BASE image hashes. The entire ELF and PSX executable remain bit-identical. Compiler, flags, filters, assertions, and reference hashes are unchanged.

The authority reuses complete original Rev 0 bodies and independently identified Rev 1 instructions and existing readable operations. Revision differences are enumerated individually. Original upstream C and original assembly provenance are distinguished. Semantic labels alone are not authority.

## Operation names

| Rev 0 entry | Local operation | Rev 1 entry |
| --- | --- | --- |
| `800135A4` | `CopyCameraPositionWithWrappedAngle` | `800135B8` |
| `800135F8` | `WriteSphericalOffsetVector` | `8001360C` |
| `800136F0` | `BuildCameraVectorOrientation` | `80013704` |
| `80013918` | `SelectSignedCameraOrbitRequest` | `8001392C` |
| `800139A4` | `UpdateCameraOrbitReturn` | `800139B8` |
| `80013ACC` | `SetCameraOwnerAndControlWord` | `80013AE0` |
| `80013AE4` | `PrepareCameraMode9Vectors` | `80013AF8` |
| `80013B7C` | `TransitionCameraModes9And10` | `80013B90` |
| `80013D44` | `SetCameraMode11Target` | `80013D58` |
| `80013E38` | `TestSubdividedSegmentPath` | `80013E4C` |
| `800142AC` | `SelectCameraModeFromFlag` | `800142C0` |
| `800142E0` | `RefreshCameraPlayerAnchor` | `800142F4` |
| `80014354` | `SelectCameraFollowProfile` | `80014368` |
| `8001830C` | `QueryWorldSegmentWithOptions` | `80018320` |
| `80018368` | `QueryWorldSegment` | `8001837C` |
| `80019138` | `QueryWorldSphereWithOptions` | `8001914C` |
| `80019194` | `QueryWorldSphere` | `800191A8` |
| `8001A310` | `QueryWorldHeightWithOptions` | `8001A324` |
| `8001A358` | `QueryWorldHeight` | `8001A36C` |
| `8001AD60` | `QueryDynamicObjectSegment` | `8001AD74` |
| `8001BA30` | `QueryDynamicMobyGeometry` | `8001BA44` |
| `8001C288` | `TestPlayerSphereOverlap` | `8001C29C` |
| `8001C368` | `EmitVisibleWorldTrianglePackets` | `8001C37C` |
| `8001E460` | `DispatchFrameRenderMask` | `8001E484` |
| `8001EBAC` | `ClearTwoDisplayRegions` | `8001EBD0` |
| `8001EDEC` | `EmitPortalVolumePackets` | `8001EE10` |
| `8001FB10` | `ConfigureDrawBufferRanges` | `8001FB34` |
| `8001FB74` | `EmitHighlightLinePair` | `8001FB98` |
| `8001FD00` | `BuildUiFramedPanel` | `8001FD24` |
| `800200A0` | `EmitScreenColorQuad` | `800200C4` |
| `80020168` | `InitializeDisplayBufferPair` | `8002018C` |
| `80020428` | `DrawNumericCounterText` | `8002044C` |
| `80021ED8` | `MaskLinkedRecordFlagsById` | `80021EFC` |
| `80021F3C` | `QueryShiftedLinkedRecordWordByByteId` | `80021F60` |
| `80021F8C` | `WriteMatchingLinkedSelectors` | `80021FB0` |
| `80027934` | `FindHudClassIndex` | `80027958` |
| `80027A60` | `SyncHudCounterTarget` | `80027A84` |
| `80027AC0` | `SnapHudCounterToSource` | `80027AE4` |
| `80027D60` | `InitializeHudCounterEntry` | `80027D84` |
| `80027E40` | `InitializeHudDecimalCounterLayout` | `80027E64` |
| `80027EE4` | `InitializeHudDoubleCounterLayout` | `80027F08` |
| `8002803C` | `ConfigureHudEntry` | `80028060` |
| `80028154` | `ResetHudEntryByHandle` | `80028178` |
| `800281D0` | `RefreshHudEntryByHandle` | `800281F4` |
| `80028378` | `SelectHudIconAnimationFrame` | `8002839C` |
| `800289C8` | `EmitHudTexturedQuads` | `800289EC` |
| `80028D30` | `EmitFlaggedHudTexturedQuads` | `80028D54` |
| `8002982C` | `DrawHudIcon` | `80029850` |
| `80029904` | `DrawHudIconAndDecimalCounter` | `80029928` |
| `80029AA0` | `DrawHudDoubleCounterWithIcon` | `80029AC4` |
| `8002A6B4` | `SubmitHudSoundByte16` | `8002A6D8` |
| `8002A6E4` | `SubmitHudSoundByte17` | `8002A708` |
| `8002A714` | `SubmitHudSoundByte18WithWord0C` | `8002A738` |
| `8002A754` | `SubmitHudSoundByte1AWithWord0C` | `8002A778` |
| `8002A9D0` | `InitializePadAndVSyncCallback` | `8002A9F4` |
| `8002AE00` | `ReloadResourceArenaAndResetPlayer` | `8002AE24` |
| `8002AF9C` | `RelocateAndPublishModel` | `8002AFC0` |
| `8002B31C` | `RelocateAndPublishResourceBlock` | `8002B340` |
| `8002B6C8` | `ApplyPendingTripletOffsets` | `8002B6EC` |
| `8002B768` | `InitializeParticleAndEffectPools` | `8002B78C` |
| `8002B810` | `InitializeLevelScene` | `8002B834` |
| `8002CA50` | `ServiceLevelResourceLoading` | `8002CA74` |
| `8002E748` | `EmitUiTextGlyphPackets` | `8002E76C` |
| `8002EBB0` | `MeasureEncodedTextAdvance` | `8002EBD4` |
| `8002EC50` | `AllocatePoolRecord20` | `8002EC74` |
| `8002F040` | `AllocatePoolRecord16` | `8002F064` |
| `8002F540` | `AllocatePoolRecord48` | `8002F564` |
| `80030258` | `RemapPrimitiveListScreenCoordinates` | `8003027C` |
| `80030478` | `BuildMobyRenderLists` | `8003049C` |
| `80031124` | `EmitMobyModelPackets` | `80031148` |
| `80033C5C` | `EmitVisibleRecordPackets` | `80033C80` |
| `80034F40` | `RequestMobyAnimation` | `80034F64` |
| `80034F80` | `SetMobyAnimation` | `80034FA4` |
| `80034FEC` | `SetDefaultMobyProperties` | `80035010` |
| `80035030` | `UpdateMobyBallisticMotion` | `80035054` |
| `80035194` | `UpdateMobyMotionDescriptor` | `800351B8` |
| `80035734` | `EmptyAnimationTransitionHook` | `80035758` |
| `8003573C` | `TurnMobyTowardPlayer` | `80035760` |
| `8003585C` | `TurnMobyTowardHeading` | `80035880` |
| `800359A4` | `CountTimerDown` | `800359C8` |
| `80035A80` | `UpdateMobyPathMotion` | `80035AA4` |
| `80035D38` | `ProbeGroundFromRaisedMoby` | `80035D5C` |
| `80035D84` | `ProbeGroundFromMobyWithOffset` | `80035DA8` |
| `80035DDC` | `ResolveMobyYawStep` | `80035E00` |
| `80035EE0` | `ResolveMobyHeadingStep` | `80035F04` |
| `80036018` | `ApproachAngle8` | `8003603C` |
| `800360A0` | `BlendByteAngle` | `800360C4` |
| `800360F8` | `BlendBoundedAngle8Step` | `8003611C` |
| `8003613C` | `SubAngle8` | `80036160` |
| `8003615C` | `SubAngle12` | `80036180` |
| `8003617C` | `AddAngle8` | `800361A0` |
| `80036188` | `WriteGlobalVectorAnglePair` | `800361AC` |
| `80036220` | `TestPaddedRotatedBox` | `80036244` |
| `8003636C` | `RandBetween` | `80036390` |
| `800363DC` | `RandSignedBetween` | `80036400` |
| `8003645C` | `GetClosestPathNode` | `80036480` |
| `80036518` | `GetClosestPathNodeByVectorLength` | `8003653C` |
| `800365E4` | `ComputeArcVerticalVelocity` | `80036608` |
| `800368A4` | `UpdateMobyHitColour` | `800368C8` |
| `800369B8` | `EmitMobyVertexParticles` | `800369DC` |
| `800369D8` | `CountListedMobysBelowState80` | `800369FC` |
| `80036A68` | `SpawnMobyFromValueSelector` | `80036A8C` |
| `80036E60` | `AwardMobyCollectionValue` | `80036E84` |
| `80037014` | `SetMobyZFromGroundProbe` | `80037038` |
| `80037058` | `SamplePlanarPhaseTable` | `8003707C` |
| `80037168` | `UpdateMobyWanderMotion` | `8003718C` |
| `80037BBC` | `UpdateMobyInteractionGate` | `80037BE0` |
| `80038000` | `ResolveMobyMotionCollision` | `80038024` |
| `800382F4` | `SelectPlanarEdgeRecord` | `80038318` |
| `80038B44` | `CalculateWeightedCompletionPercent` | `80038B68` |
| `80038BF8` | `InitializeMobyMotionState` | `80038C1C` |
| `80038F14` | `InitializeMobyMotionStateWithDeceleration` | `80038F38` |
| `800391E8` | `SpawnBallisticMobyBatch` | `8003920C` |
| `80039714` | `UpdateMobyPrivateBallisticMotion` | `80039738` |
| `80039974` | `RequestIndexedLevelDataSlice` | `80039998` |
| `800399E8` | `SpawnSurfaceType4LinkedMoby` | `80039A0C` |
| `80039B6C` | `UpdateLinkedMobyReflection` | `80039B90` |
| `8003A908` | `InitializePadInputState` | `8003A92C` |
| `8003B634` | `WriteTrackedSnapshot` | `8003B658` |
| `8003B74C` | `RestoreOrClearTrackedSnapshot` | `8003B770` |
| `8003B7B4` | `RegisterTrackedValue` | `8003B7D8` |
| `8003BA00` | `MarkMobyCollectionBit` | `8003BA24` |
| `8003BABC` | `PlayMobySoundEvent` | `8003BAE0` |
| `8003BB10` | `PlaySoundFromGlobalByteTable` | `8003BB34` |
| `8003BE70` | `TransitionSoundHandleTo3Or5` | `8003BE94` |
| `8003BEDC` | `TransitionUnmaskedSoundSlots` | `8003BF00` |
| `8003BF6C` | `SoundHandleMatchesIdInStates1Or2` | `8003BF90` |
| `8003BFC0` | `SoundHandleMatchesOwnerInStates1Or2` | `8003BFE4` |
| `8003C014` | `CopySoundSlotPosition` | `8003C038` |
| `8003C0B0` | `SetSoundHandleScaledDescriptorAverage` | `8003C0D4` |
| `8003C140` | `SetSoundHandleWord0CAndFlag10` | `8003C164` |
| `8003C184` | `UpdateSoundVoiceSlots` | `8003C1A8` |
| `8003CDA0` | `EmitPlayerModelPackets` | `8003CDC4` |
| `80040954` | `GetSurfaceTypeFromFlags` | `80040978` |
| `80040994` | `ProcessPlayerStateFlags` | `800409B8` |
| `80040BCC` | `ProcessPlayerContactFlags` | `80040BF0` |
| `80040D10` | `UpdatePlayerGroundInputTargets` | `80040D34` |
| `80040F48` | `BuildOrientedInputPair` | `80040F6C` |
| `800410F8` | `UpdateSmoothedInputPair` | `8004111C` |
| `80041404` | `ApplyPlayerRotationStep` | `80041428` |
| `80041580` | `ApproachPlayerTargetHeading` | `800415A4` |
| `800416F4` | `BlendPlayerHeadingFromInputVector` | `80041718` |
| `800417FC` | `ApproachPlayerTargetSpeed` | `80041820` |
| `80041848` | `BuildPlayerMovementVector` | `8004186C` |
| `80041930` | `ProbePlayerContactSegment` | `80041954` |
| `80041AE8` | `CapturePlayerPlanarVectorDifference` | `80041B0C` |
| `80041B64` | `BuildPlayerResponseVector` | `80041B88` |
| `80041C20` | `UpdatePlayerCollisionResponse` | `80041C44` |
| `80042A44` | `UpdatePlayerSurfaceState` | `80042A68` |
| `80043194` | `TestPlayerProbePattern` | `800431B8` |
| `80043728` | `ApplyPlayerGroundContactCorrection` | `8004374C` |
| `800438F4` | `ApplyPlayerMovingSurfaceDelta` | `80043918` |
| `80043A38` | `BuildNegatedNormalizedPlayerVector` | `80043A5C` |
| `80043E00` | `UpdatePlayerTiltFromVector` | `80043E24` |
| `800441F0` | `ClearPlayerMotionVectors` | `80044214` |
| `80044240` | `UpdatePlayerAnimationSubsteps` | `80044264` |
| `80047190` | `ResetPlayerRuntimeState` | `800471B4` |
| `80048210` | `BuildPlayerTargetControlInput` | `80048234` |
| `80048444` | `PullPlayerPoseTowardTarget` | `80048468` |
| `800492DC` | `SetClampedPlayerTargetAngles` | `80049300` |
| `80049484` | `ResolvePlayerPoint193` | `800494A8` |
| `80049590` | `MarkPlayerSegmentSurfaceType3Flags` | `800495B4` |
| `80049688` | `SelectPlayerAnimationLoopRequest` | `800496AC` |
| `800498C0` | `UpdatePlayerRetryState` | `800498E4` |
| `8004BEF8` | `DispatchPlayerStateRequest` | `8004BF1C` |
| `8004E4E4` | `EvaluateClampedPlayerRootCurve` | `8004E508` |
| `8004E56C` | `WriteBasisAngleTriplet` | `8004E590` |
| `8004E790` | `FillWordRange` | `8004E7B4` |
| `8004E7AC` | `FillWordRangeUnrolled4` | `8004E7D0` |
| `8004E7D4` | `CopyWordRangeUnrolled4` | `8004E7F8` |
| `8004E880` | `PlanarHeadingLookup` | `8004E8A4` |
| `8004E9E4` | `InterpolateSine` | `8004EA08` |
| `8004EA2C` | `InterpolateCosine` | `8004EA50` |
| `8004EA74` | `GetLeadingTransitionIndex` | `8004EA98` |
| `8004EA90` | `BuildPackedAngleBasisMatrix` | `8004EAB4` |
| `8004ECF4` | `TransposePackedHalfwordMatrix3x3` | `8004ED18` |
| `8004ED6C` | `TransformVectorByBasis` | `0x8004ED90` |
| `8004EDE8` | `MeasureVectorLength` | `0x8004EE0C` |
| `8004EF04` | `NormalizeVectorToLength` | `0x8004EF28` |
| `8004EF74` | `ComputeVectorPlaneResponse` | `8004EF98` |
| `8004F08C` | `ScaleVectorRatioQ15` | `0x8004F0B0` |
| `8004F0E8` | `ShiftVectorLeft` | `0x8004F10C` |
| `8004F110` | `ShiftVectorRightTowardZero` | `0x8004F134` |
| `8004F168` | `ClearVector` | `0x8004F18C` |
| `8004F178` | `CopyVector` | `0x8004F19C` |
| `8004F194` | `AddVector` | `0x8004F1B8` |
| `8004F1C8` | `SubtractVector` | `0x8004F1EC` |
| `8004F1FC` | `MultiplyVectorGpfSf0` | `0x8004F220` |
| `8004F228` | `DivideVector` | `0x8004F24C` |
| `8004F264` | `AbsoluteByteAngleDelta` | `0x8004F288` |
| `8004F284` | `Absolute12BitAngleDelta` | `0x8004F2A8` |
| `8004F2A4` | `SignedByteAngleDelta` | `0x8004F2C8` |
| `8004F2C8` | `Signed12BitAngleDelta` | `0x8004F2EC` |
| `8004F2EC` | `ApproachByteAngle` | `0x8004F310` |
| `8004F334` | `ApproximatePlanarDistance` | `0x8004F358` |
| `8004F388` | `EstimateSquareRootFromTable` | `8004F3AC` |
| `8004F408` | `ProjectPointWithGlobalGteMatrix` | `8004F42C` |
| `8004F504` | `PackVectorShiftRight2` | `8004F528` |
| `8004F52C` | `ExpandUnsignedHalfwordVectorTimes4` | `8004F550` |
| `8004F554` | `ExpandSignedHalfwordVector` | `8004F578` |
| `8004F570` | `NarrowWordVectorToHalfwords` | `8004F594` |
| `8004F58C` | `CopyHalfwordVector` | `8004F5B0` |
| `8004F5A8` | `AddHalfwordVectors` | `8004F5CC` |
| `8004F5DC` | `DecodePackedTriangleVertices` | `8004F600` |
| `8004F6B4` | `TriggerSignedAdditionOverflow` | `8004F6D8` |
| `8004F6C4` | `BuildEulerBasisPair` | `8004F6E8` |
| `8004F984` | `ConfigurePrimaryRangeRequest` | `8004F9A8` |
| `8004F9C0` | `ConfigureGuardedRangeRequest` | `8004F9E4` |
| `80050844` | `AllocateVectorTrailRecord` | `80050868` |
| `800509E8` | `ClearHistorySourceWord` | `80050A0C` |
| `80050B00` | `AllocateFiveWordSlot` | `80050B24` |
| `80050B88` | `ClearFiveWordSlotMarker` | `80050BAC` |
| `800527C4` | `SetState15OwnerContext` | `80052844` |
| `80053F50` | `PreparePortalLevelTransition` | `80053FD0` |
| `80055A7C` | `AllocateMoby` | `80055B0C` |
| `80055B18` | `DeleteMoby` | `80055BA8` |
| `80055C24` | `InitializeMobySpatialGridAndBasis` | `80055CB4` |
| `80055D24` | `RefreshMobySpatialGridAndBasis` | `80055DB4` |
| `80055E84` | `ReadSelectedFrameScalar` | `80055F14` |
| `80055F14` | `InterpolateMobyVertex` | `80055FA4` |
| `80056270` | `RefreshMobyQueryByte52` | `80056300` |
| `8005629C` | `RefreshMobyPackedQueryField` | `8005632C` |
| `80056434` | `AllocateParticleRecord` | `800564C4` |
| `80056504` | `ReleaseParticleRecord` | `80056594` |
| `800584BC` | `BeginLevelWarp` | `8005854C` |
| `8005E074` | `SyncCdCommandResult` | `8005E10C` |
| `8005E0BC` | `IssueCdControlCommand` | `8005E154` |
| `8005F35C` | `MultiplyPackedGteMatrices` | `8005F3F4` |
| `8005F5FC` | `WriteFormattedOutput` | `8005F694` |
| `80064A2C` | `SetSpuTransferAddress` | `80064AC4` |
| `80064A8C` | `WriteSpuTransferData` | `80064B24` |
| `80064AEC` | `CheckSpuTransferCompletion` | `80064B84` |

## Scope and evidence

The [portable naming ledger](helper-naming-reuse.json) contains complete original words, exact revision differences, operation facts, source identities, current source pins, and each batch summary. The per-batch authority and acceptance files beside it preserve the detailed history.

Some source annotations retain historical unresolved wording. This ledger supplies the newer local naming authority. It does not assign unknown physical units, sound or animation meanings, field lifetimes, caller domains, or naturally unobserved gameplay states. Frame scalars, numeric slot states, raw selectors, and width-dependent arithmetic retain those limits.

Native matching remains 337 executable functions and 3,098 overlay functions. Readability and exact binary reproduction do not establish whole-game semantic completion. Remaining producer, alias, asset/event, and runtime obligations remain explicit in the existing decoding frontier.

## Source corrections and preserved limits

The descriptor halfword at +4 in InitializeMobyMotionState is a planar heading-displacement operand. The old duration interpretation is superseded by qualification43579; physical units remain unproved.

The accompanying correction index separates two applied corrections to the Rev 1 decoder models from label, entry, extent and revision qualifications. The retry calculation uses the native signed quotient multiplied by ten. The HUD counter truncates to low16 before its unsigned maximum comparison. Independent original-word tests support both corrections. These model fixes do not change the fork game bytes.

The residual pass reuses the same operation authorities to clean missed identifier shapes. Repeated authority rows are checked for identical operation, entry and complete original words; they are not counted as newly decoded operations.

The final readability acceptance file separately records the composed source after parameter cleanup and protected whitespace formatting. Its 480 source pins are the current pins; helper-stage pins remain as history. It passes the same unchanged native chain and original image hashes.
