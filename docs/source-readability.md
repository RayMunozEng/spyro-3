# Native source readability

This pass is AI generated and has not been human reviewed. It applies to the
Rev 0 matching fork, not to the browser engine's gameplay implementation.

## Original repository examples

The baseline is The MobyCollective's `spyro-3`, commit
`4c5d4f34cbf91c4c67a993bca66cb051b2b52a04`:

- `src/mobyutil.c`: four-space indentation, attached braces, descriptive
  operations, existing `Moby` and vector types, and explicit unknown fields.
- `include/overlays/moby/260.inc.h`: a readable typed implementation shared by
  repeated actor callbacks. Reuse requires checking each actual function's
  instructions and resolved targets; a matching actor number alone is not proof.
- `src/overlays/level_10/moby.c`: retain original declarations, comments and
  source ownership when improving the fork's additions.

Only added/replaced source spans relative to **both** the common fork base
`2d32df6d18617449053b07ccf75c0f5b7f2ac0e9` and that upstream commit are eligible
for bulk formatting. Existing upstream code is preserved byte for byte.

## Conventions

- Use one statement per line and normal indentation. Preserve string and comment
  spelling, macro expansion, includes and local newline spelling.
- Name a helper after the operation proved by its original instructions. Keep
  its assembly/linker identity, declaration type and calling convention intact.
- Keep per-function alias prefixes and ABI view suffixes when needed to keep
  distinct original declarations separate.
- Keep address-based names and field offsets where their meanings are unknown.
  A plausible name or another actor's structure is insufficient evidence for a
  type or semantic conversion.
- State compiler constraints separately from gameplay intent. Empty assembly
  annotations can affect allocation and scheduling even though their templates
  emit no CPU instructions. Original CPU assembly remains explicitly assembly.
- Do not add initial values, bounds, branches or arithmetic corrections during
  readability work. Unknown producers and runtime assumptions remain open.

Three short `if/else` clauses in `func_level_23_800823A4` and
`func_level_24_8008B488` retain both arms on one physical source line. Moving their
identical observer calls onto distinct lines changes the frozen compiler's
branch merging. The source marks these exceptions with `clang-format off/on`;
preserve them. Original and repaired whole objects were checked for identical
allocated sections and actual relocations.

The helper naming authority is the complete original Rev 0/Rev 1 instruction
bodies and the canonical correction ledger. In particular, `MultiplyVectorGpfSf0`
does **not** shift its product internally, and `ApproximatePlanarDistance` is not
a heading calculation. Names describe local operations; they do not establish
world units, update cadence, every input domain or caller behavior.

## Changes in this pass

| Change | Scope |
| --- | --- |
| Format the fork's additions using original-repository examples | 2,791 definitions in 384 C files |
| Replace address-coded private helper aliases with proved operation names | 4,490 aliases; 18 original helper bodies; 771 caller functions |
| Replace repeated empty constraint syntax with exact-expansion macros | 46,505 annotation sites in 322 files before the typed callback replacements |
| Reuse the typed original actor-260 implementation with readable local names | 36 callbacks; 6,948 original instruction words; no assembly in the new bodies |

The typed callbacks remove their previous explicit register bindings and 468
empty annotations. Their minimal field aliases refer to existing camera or
collision storage. They introduce no storage definitions or new field layouts.
Existing unknown field names and unused original temporary declarations remain.

`include/matching.h` explains the remaining compiler annotations. Their assembly
templates contribute no explicit CPU instruction; their constraints can still
affect the loads, copies, spills and scheduling emitted by the compiler. Complex
constraints and original CPU instructions remain explicit in the source.

## Acceptance

Whitespace changes must preserve preprocessing tokens, directive boundaries,
function-like macro adjacency, protected stringification and unchanged source
bytes. Identifier changes must be injective, collision checked and invertible.
Annotation wrappers must expand to the exact original constraint tokens.

These checks accompany the frozen compiler and all retained native gates.
Acceptance requires all original instruction words, resolved targets, owned
tables, stack-frame checks and all 62 BASE reference image hashes. The reference
images precede antipiracy checksum correction and encryption; they are not a
claim of runtime or semantic completeness.

All 337 executable functions and 3,098 overlay functions were matched before
this pass. Readability work must retain that result. Matching alone does not
resolve every helper contract, private layout, asset meaning or runtime chain.

## Verified result

The final combined pass retained all 95 native checks and passed all 62 BASE
reference image hashes. All 337 executable and 3,098 overlay function matches
remain intact. The frozen compiler, flags and filters were retained.

All 411 translation units passed actual-preprocessor equivalence after reversing
only the helper identifier renames, before the 36 typed-body replacements. Those
replacements separately passed all 193 original instructions, resolved control
and data targets, and frame-56 checks; the final combined image hashes then
confirmed the polished local names and their actual source contexts.

The pass changes 384 C files. Its publication is recorded in the cleanup commit. It is AI
generated and has not been human reviewed. Unknown gameplay meanings and runtime
producer/lifecycle assumptions remain open; no new browser-specific behavior or
tentative gameplay approximation was added.

The next semantic evidence target remains raw588's foreign private-field stores
at Rev 0 `0x8007F3F8`, `0x8007F468` and `0x8007F4EC`, together with the retained
prior-callback/nested-frame producer frontier. See the decoding frontier notes;
source readability does not close those gaps.

## Remaining cleanup completed

The follow-up pass finished the wrapping and indentation introduced by the new
helper names and annotation macros. All 411 C translation units and the project
headers were inspected; the three source-line exceptions remain protected.
Original strings, comments, macro-sensitive expressions and upstream anchors
remain unchanged by bulk formatting.

Another 4,183 helper aliases were given proved operation names, followed by a
four-helper supplement. The complete naming authority now covers 45 original
helper operations, including animation requests, exact timer countdowns,
inclusive random ranges, deletion, sound-event dispatch, heading/trig lookup,
vertex interpolation and the actual spatial-grid/basis updates. Names describe
local operations; they do not establish unknown gameplay units or sound IDs.

The seven existing actor-651 variants received scoped, neutral local names and
consistent formatting. They retain their individual fields, control flow and
tables: 4,009 original instructions, 60 selector words and original frames were
independently checked before composition. There was no transfer of behavior
between unequal variants.

All four original shared actor includes are accounted for:

| Original include | Finished state |
| --- | --- |
| `260.inc.h` | Existing clean callback plus 36 typed replacements verified in the preceding pass |
| `290.inc.h` | All 49 matching one-call wrappers were already ordinary C |
| `651.inc.h` | All seven typed variants have consistent local names and formatting |
| `999_cutscene.inc.h` | Matching empty callbacks were already empty ordinary C |

The pass also removed 338 unused private helper prototypes from 70 files. Each
identifier appeared only in its declaration under the real MIPS preprocessor.
Deleting those declarations was checked against the entire preprocessed token
stream; no other token changed. Public prototypes, definitions, owned data,
types and gameplay behavior were preserved.

Remaining address-based helper names are deliberately unresolved. The naming
inventory distinguishes available original C bodies requiring a further audit
from missing producer/consumer contracts. For example, handle flag tests do not
alone prove playback-state semantics. Renaming those predicates as sound states
would overstate the evidence. See the naming authority and open-target inventory
under `docs/decoding/`.

This completes the available source cleanup against the original repository's
existing code. It does not complete the game's semantic decode. The raw588
private-field and cold-frame producer frontier remains the next exact evidence
target described above. All changes remain AI generated and not human reviewed.

The final supplement applied 442 live aliases; seven aliases had already been removed as unused.

## Finished verification

The final composed cleanup passed every retained native check (all 95 commands)
and all 62 BASE reference image hashes. All 3,435 inventoried function matches
remain intact. The compiler, flags, metadata filters and original hash values
were retained. Source/header hashes were checked again after verification.

The remaining cleanup is complete against the existing original shared code and
the currently proved helper operations. Unknown address-based helpers retain
explicit evidence gaps. This result does not claim semantic completeness or
human review. Publication is recorded in the cleanup commit.
