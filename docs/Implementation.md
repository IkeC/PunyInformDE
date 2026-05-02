# PunyInformDE - Implementation Notes

This document contains the technical details for the current German-language
implementation strategy. The README is intentionally brief; this file is the
reference for internals.

## Scope

- Base library: PunyInform v6.5
- Compiler: Inform 6.44
- Targets: z5 (Unicode + ASCII build variants)
- Design rule: German-specific behavior lives in `lib/de/` whenever possible

## Credits and Source Algorithms

The implementation approach is based on the same core ideas used by:

1. deform 6/11 (2005-2010), Martin Oehm
   - Reference files: `c:/Source/informtest/deform/German.h`, `GermanG.h`
2. German.i7x (Team GerX, Frank Gerbig et al.)
   - Reference file: `c:/Source/fiction/Staub/Staub.materials/Extensions/Team GerX/German.i7x`

PunyInformDE adopts equivalent concepts but keeps them lightweight for
PunyInform's smaller footprint and architecture.

## Implemented Features

## §1 Article System

Implemented in:

- `lib/de/article_de.h`
- `lib/puny.h`
- `lib/de/messages_de.h`

Key elements:

- Gender derivation via attributes (`female`, `neuter`, `pluralname`, default masculine)
- Case-aware definite and indefinite article tables (Nom/Akk/Dat)
- Case print helpers: `DE_Der`, `DE_Den`, `DE_Dem`, `DE_Ein`, `DE_Einen`, `DE_Einem`, `DE_Der_Cap`
- `DE_Der_Cap` is the explicit capitalised-Nominativ replacement for `(The)` at sentence start
- All `(the)` / `(The)` calls in `messages_de.h` replaced with explicit German case functions;
  proper-named objects (`has proper`) always skip article printing via guard in `_DE_PrintDefWithName`
  and `_DE_PrintIndefWithName`
  - `article 0` suppresses indefinite article
  - `article "..."` is treated as string override

## §2 Pronoun Input

Implemented in:

- `lib/parser.h` (`PronounNotice` LANG_DE behavior)
- `lib/de/parser_de.h` (`BeforeParsing` call sequence)
- `lib/de/article_de.h` (`_DE_SubstitutePronouns` routine)

German pronouns are rewritten before parse resolution:

- `er`/`ihn`/`ihm` -> `him`
- `sie` -> `her` or `them` (slot-based fallback)
- `es` -> `it`
- `ihnen` -> `them`

## §3 Stage 1 Input Suffix Pruning

Implemented in:

- `lib/de/parser_de.h`

Added `_DE_PruneWordSuffixLen` and a post-tokenization pass for unknown words.
Recognized endings:

- Two-char: `-em`, `-en`, `-er`, `-es`
- One-char: `-e`, `-n`, `-s`

This allows commands like:

- `nimm kleinen schluessel`
- `untersuche altem kompass`

with stem-based dictionary entries.

## §3 Stage 2 Output Adjective Declension

Implemented in:

- `lib/de/article_de.h`
- `lib/puny.h`
- `lib/de/messages_de.h`
- `lib/de/globals_de.h` (case globals and `adj` property)

Key mechanisms:

- `short_name_case` global (`Nom`, `Akk`, `Dat`)
- Adjective suffix selection by mode/case/gender:
  - definite article
  - indefinite article
  - bare noun phrase (no article)
- `adj` property support for stem-based adjective rendering
- `_PrintObjName` delegates to `_DE_PrintObjByForm(...)`
- Messages that list contained items in accusative context now set and restore
  `short_name_case` around `PrintContents(...)`

This fixes outputs such as:

- `Du legst den alten Kompass auf den Schreibtisch.`
- `Du öffnest die Seekiste, und siehst einen kleinen Schlüssel.`

## Example Story Coverage

`example/sterne.inf` now contains explicit §3 demo objects and stems:

- `Kompass` with `adj "alt"`
- `Schluessel` with `adj "klein"`
- Dative/default-examine demo objects:
  - `Ring` (m), `Nadel` (f), `Tuch` (n)

Walkthrough (`example/beispiel.walkthrough.txt`) includes commands that exercise:

- Pronoun replacement
- Suffix-pruned input forms
- Accusative and dative adjective output paths

## Test Coverage

### Test Harness Setup

PunyTest is maintained as a separate public repository:

- `https://github.com/IkeC/PunyTest`

Expected local layout:

- `C:/Source/PunyInformDE`
- `C:/Source/PunyTest`

`tests/conftest.py` prepends the parent folder (for example `C:/Source`) to
`sys.path`, so importing `PunyTest.*` works without copying framework files
into this repository.

Key files:

- `tests/test_articles.py`
- `tests/test_pronouns.py`
- `tests/test_suffix_pruning.py`
- `tests/test_stage3_known_limitations.py`
- `tests/test_walkthrough.py`

Current suite status (latest run):

- 81 passed → 143 passed (as of issue #8 explicit-articles refactoring)
- 143 passed → 145 passed (as of issue #13: DEBUG compile fix)
- 145 passed → 163 passed (double-ist fix + digraph-name cleanup + normaliser stale-address fix)
- 3 xfailed (known dfrotz umlaut-pipe limitation on Windows)

## USE_ASCII and the ASCII Preprocessing Pass

### Why USE_ASCII exists

The Unicode build targets Z5 with a custom `Zcharacter` table (declared in
`lib/de/chartable_de.h`). That table remaps the seven German umlaut characters
(ä ö ü ß Ä Ö Ü) into the cheapest Z-character encoding row (A0), so each
umlaut encodes as a single Z-character byte rather than a multi-byte Unicode
escape. This saves story-file space and enables efficient umlaut output on any
V5+ interpreter that supports extended character sets.

`USE_ASCII` is a compile-time constant that disables this Unicode machinery for
targets that cannot display characters outside the 7-bit ASCII range — primarily
Z3 (8-bit machines) and any interpreter without Unicode support. When defined:

- `chartable_de.h` skips the `Zcharacter` declaration entirely.
- `parser_de.h` omits the `_DE_IsVowelByte` and `_DE_NormaliseDigraphsOnly`
  runtime functions, which are only needed to fold digraph player input (e.g.
  `ae`) back into umlaut bytes (`ä`) before dictionary lookup in the Unicode
  build. In the ASCII build player input stays in digraph form, so no
  normalisation is needed.
- The `BeforeParsing` digraph→umlaut conversion pass is skipped.

### Why a source-level preprocessing pass is also needed

Defining `USE_ASCII` alone is not sufficient to produce a fully ASCII story
file. The reason is how Inform 6 handles string literals: **the compiler stores
the raw byte values of string characters from the source file**. If the source
contains `ä` (UTF-8 0xC3 0xA4, or Latin-1 0xE4), that character ends up
encoded in the story file using whatever mechanism the active Zcharacter table
or Unicode support provides. Without the custom Zcharacter table, umlauts fall
back to the Z-machine's 10-bit Unicode escape mechanism — they still appear as
umlaut characters in interpreter output, just less efficiently.

There is no way to instruct Inform 6 to silently replace non-ASCII characters
in string literals at compile time. The only reliable approach is to replace
every umlaut in every string literal in every source file with its two-letter
ASCII digraph **before compilation**. This is what the preprocessing pass in
`build.ps1` does:

1. It reads each source file containing German strings as UTF-8.
2. It substitutes each umlaut character: ä→ae, ö→oe, ü→ue, ß→ss, Ä→Ae,
   Ö→Oe, Ü→Ue.
3. It writes the result, UTF-8-without-BOM, into a shadow directory
   (`build/ascii_lib/` mirroring `lib/` and `build/ascii_src/` mirroring
   `example/`).
4. Those shadow directories are placed first on the include path for the ASCII
   and Z3 compiler invocations, so they silently override the umlaut originals.

The files that require preprocessing are those that contain German string
literals in their source:

| Original file | Shadow location | Content replaced |
|---|---|---|
| `lib/de/globals_de.h` | `build/ascii_lib/de/` | Status-bar label `" Züge: "` |
| `lib/de/messages_de.h` | `build/ascii_lib/de/` | All parser messages |
| `lib/de/grammar_de.h` | `build/ascii_lib/de/` | Verb dictionary words |
| `lib/de/article_de.h` | `build/ascii_lib/de/` | Article/adjective strings |
| `lib/de/parser_de.h` | `build/ascii_lib/de/` | Normalisation code comments |
| `lib/de/chartable_de.h` | `build/ascii_lib/de/` | Umlaut chars in `Zcharacter` (becomes dead code under `USE_ASCII`) |
| `lib/de/ext_talk_menu_inline_de.h` | `build/ascii_lib/de/` | Conversation menu strings |
| `lib/puny.h` | `build/ascii_lib/` | ` (enthält` container suffix |
| `example/sterne.inf` | `build/ascii_src/` | All room/object/NPC text |

Files that contain no German string literals (e.g. `lib/parser.h`,
`lib/grammar.h`, `lib/scope.h`) are not preprocessed and are read directly from
their original location via the lower-priority include path entries.

## Object Name Lists and Digraph Normalisation

### The rule: umlaut-only entries in `name` properties

In the Unicode build, `BeforeParsing` (`lib/de/parser_de.h`) runs
`_DE_NormaliseDigraphsOnly` on every word that is NOT already in the dictionary.
For a word like `tuer`, the function collapses `ue` → `ü`, producing `tür` (3
bytes). If `tür` is in the dictionary, the normalised form replaces the original
in the input buffer before the parser runs.

In the ASCII build, the preprocessing pass converts every umlaut in dictionary
entries (i.e., inside `name '...'` property strings) from umlaut to digraph at
compile time. So `'tür'` in source becomes `'tuer'` in the compiled dictionary,
and player input `tuer` matches directly.

**Consequence**: object `name` properties need to list only the umlaut form. The
digraph form is handled automatically by either the runtime normaliser (Unicode)
or the compile-time preprocessor (ASCII). Listing both forms is redundant and
increases the dictionary size. The only exception is a word like `'tur'`
(truncated form without any digraph) that cannot be recovered from the umlaut
form by normalisation.

### Normaliser stale-address bug (fixed)

`BeforeParsing` Pass 1 iterates over all words in the parse table. When a word
is normalised (e.g., `oeffne` → `öffne`, 6 bytes → 5 bytes), the code shifts
the input buffer left by 1 byte to close the gap. Without an immediate
re-tokenise, the parse-table entry for the **next** word still holds the
**old** byte offset into the buffer (pointing one byte too far). The next
iteration then reads the wrong bytes and fails to normalise the second word.

The fix: after applying each normalisation inside the loop, call
`@tokenise buffer parse` immediately. This updates all word addresses in the
parse table before the next iteration.

This means that compound commands where BOTH the verb and the object require
digraph normalisation (e.g., `oeffne tuer`, `schliess tuer mit schluessel auf`)
now work correctly even when both words are absent from the dictionary.

## §4 Gender-Sensitive Message Helpers

## Build and Transcript Loop

Build task (`.vscode/build.ps1`) does all of:

1. Compile Unicode story
2. Generate ASCII source tree and compile ASCII story
3. Generate ASCII walkthrough
4. Run walkthrough through dfrotz and emit transcripts

Artifacts used for validation:

- `build/sterne.transcript.txt`
- `build/sterne.transcript.ascii.txt`

## Architectural Decisions

1. Attribute-based gender (not a new grammatical_gender property)
2. Pronoun substitution in `BeforeParsing` instead of deep parser replacement
3. Stem + suffix model via `adj` property for adjective output
4. Keep `article` as optional override for edge cases
5. Keep technical complexity primarily in `lib/de/article_de.h`

## Known Limits

1. Noun declension beyond adjective endings (for example weak noun class behavior)
   is not fully modeled.
2. Genitive system is intentionally limited.
3. Advanced deform/German.i7x features remain out of scope for now:
   - contraction tables (`ins`, `vom`, etc.)
   - compound splitting tables
   - pronominal adverbs (`damit`, `daraus`)
   - runtime gender mutation system
