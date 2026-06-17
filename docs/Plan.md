# PunyInformDE — Project Plan

Our project: https://github.com/IkeC/PunyInformDE
Upstream: https://github.com/smartgrids-aau/punyinformde

## Goal

A complete, release-ready German localisation of PunyInform v6.5, with:
- All German-specific code isolated in `lib/de/` (minimal diff from upstream base files)
- A working example game (*Das Schiff der Sterne*)
- Automated test suite (PunyTest / pytest + dfrotz)
- Unicode build (`build/sterne.z5`) and ASCII build (`build/sterne.ascii.z5`)
- VS Code tasks for Build and interactive testing

Recent progress:
- German take success feedback now uses an object-aware line (`Du nimmst ...
  an dich.`) instead of the generic `In Ordnung.` fallback.
- Synced with PunyInform upstream dev branch (post-v6.5): z4 support,
  `describe=0` fix, `describe=2`, `PrintOrRun` return-value fix,
  `MoveFloatingObjects` optimisation, grammar property warning, message
  rearrangement — all already integrated.
- Fixed MSG_TAKE_SCENERY: now uses `(CTheyreorThats) noun, " nicht portabel."`
  (no more double-ist for scenery objects).
- Fixed MSG_SEARCH_IN_IT_ISARE: now uses `(DE_Der_Cap) noun, " enthält "`
  with Akkusativ PrintContents (Nominativ subject, no double-ist).
- Added `Abendsonne` object to `example/sterne.inf` (Oberdeck) as a `describe=2`
  demo: not listed in room but examinable via `untersuche sonne`.
- Test suite: 189 passed, 3 xfailed on the latest verified run (current baseline for the German localisation).
- **NEW**: Mixed-gender synonyms via `also_female`/`also_male`/`also_neuter`
  attributes. Objects known by multiple gender-specific names now activate all
  applicable pronouns simultaneously. Example: "das Gerät / die Kamera / der
  Apparat" with `has neuter also_female also_male` enables `nimm es`, `nimm sie`,
  `nimm ihn` to all work. Implemented in `lib/de/globals_de.h` and extended
  `PronounNotice` in `lib/parser.h` (LANG_DE block). 6 new tests in
  `test_pronouns.py` (184 tests passing). Walkthrough updated with demonstration.
- **NEW**: Plural synonym via `also_plural` attribute. An object with a primary
  singular name that also has a plural word (e.g. "das Tau / die Taue") can now
  be referred to with `sie` / `ihnen` (plural they/them) after the player uses
  either the singular or plural form. Sets `themobj` and `de_last_sie_target = 2`
  in `PronounNotice`. Demo object `Tau` added to Oberdeck in `sterne.inf`.
  5 new tests in `test_pronouns.py` (189 tests passing). Walkthrough extended.

## Architecture (current)
```
lib/
  globals.h     — PunyInform v6.5; Include "de/globals_de.h" first; all constants
                  wrapped in #IfNDef guards so de/ can override them
  parser.h      — PunyInform v6.5; YesOrNo extended for ja/nein/j//
  grammar.h     — PunyInform v6.5; banner = "PunyInformDE"; _ListObjsMsg /
                  _ListObjsInOnMsg / LISTOBJS_ROOM_SUFFIX overridable via #IfNDef
  puny.h        — PunyInform v6.5; includes de/ files; _PrintObjName outputs
                  die/das/der; _PrintAfterEntry translated; AND_LIST_STR constant
  scope.h       — Unchanged
  ext_*.h       — Unchanged
  de/
    globals_de.h  — Zcharacter (#IfNDef USE_ASCII), parser words, IS_STR/ARE_STR,
                    AND_LIST_STR, status-bar labels, direction constants,
                    abbreviations
    messages_de.h — All MSG_xxx in German; gender helper functions
    grammar_de.h  — German verbs; German _ListObjsMsg / _ListObjsInOnMsg;
                    includes grammar.h

example/
  sterne.inf              — Example game source (UTF-8, umlauts)
  sterne.ascii.inf        — Wrapper: Constant USE_ASCII; Include "sterne.inf";
  sterne.walkthrough.txt  — Master walkthrough (umlauts; input for Unicode build and temporary ASCII generation)

build/                      — Compiler output (git-ignored)
  sterne.z5
  sterne.ascii.z5
  ascii_lib/                — Preprocessed library sources for ASCII build
  ascii_src/                — Preprocessed game source for ASCII build

tests/
  conftest.py          — game (cp1252) and game_ascii fixtures
  test_walkthrough.py  — Full walkthrough (Unicode build)
  test_ascii_build.py  — Full walkthrough + no-high-bytes check (ASCII build)
  test_directions.py   — German direction commands
  test_lock_unlock.py  — Lock/unlock messages
  test_list_format.py  — Container listing, "und" separator
  test_articles.py     — Article case forms (Nom/Akk/Dat)
  test_pronouns.py     — German pronoun input (er/ihn/sie/es/ihnen)
  test_suffix_pruning.py — Input suffix stripping (kleinen→klein)
  test_umlauts.py      — ASCII digraph input (passing); umlaut input (xfail)
  test_unknown_word_display.py — Unknown-word error message regression
  test_room_noun.py    — Room objects addressable by name
  test_explicit_articles.py — Explicit DE_* article functions in messages (issue #8)
  test_debug_compile.py — DEBUG (-D) build compiles without ERR_UNSAFE_GRAMMAR_PROP error (issue #13)
  test_double_ist.py — No double 'ist' in CTheyreorThats-based messages (issues a/b)
  test_object_name_normalisation.py — Digraph input still resolves after removing explicit digraph name entries
  test_describe_property.py — describe=2 objects are not listed in room but remain examinable

.vscode/
  tasks.json    — Build, Test Dfrotz, Test Dfrotz (ASCII), Test Lectrote,
                  Test Lectrote (ASCII)
build/
  build.ps1     — Build script: Unicode compile, preprocess + ASCII compile,
                  ASCII walkthrough generation
```
