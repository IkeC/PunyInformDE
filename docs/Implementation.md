# PunyInformDE — Implementation Notes

## Overview

PunyInformDE is a German localisation of PunyInform v6.5 for the Inform 6 compiler. It targets z5 story files and supports direct UTF-8 source encoding via the compiler's `-Cu` flag.

The design principle is **minimal diff from upstream**: all German-specific code lives in `lib/de/` so syncing to a new PunyInform release only requires updating the base files in `lib/`.

---

## File Structure

### Modified PunyInform Base Files (`lib/`)

| File | Modification |
|------|-------------|
| `globals.h` | `Include "de/globals_de.h"` at top; all overridable constants wrapped in `#IfNDef` guards |
| `parser.h` | `YesOrNo` extended to accept `ja`, `j//`, `nein` |
| `grammar.h` | Banner changed to `PunyInformDE v…`; `_ListObjsMsg` / `_ListObjsInOnMsg` and `LISTOBJS_ROOM_SUFFIX` made overridable via `#IfNDef` guards |
| `puny.h` | Includes `de/messages_de.h` and `de/grammar_de.h`; `_PrintObjName` outputs German gender articles (die/das/der); `_PrintAfterEntry` container/item state strings translated; list separator uses `AND_LIST_STR` constant |
| `scope.h` | Unchanged |
| `ext_*.h` | Unchanged |

### German-Specific Files (`lib/de/`)

These files do not exist in upstream PunyInform.

**`de/globals_de.h`** — Loaded first by `globals.h`. Contains:
- `Zcharacter` declarations for ä ö ü ß Ä Ö Ü, guarded by `#IfNDef USE_ASCII` (see ASCII Build below)
- German parser word constants: `ALL_WORD = 'alles'`, `EXCEPT_WORD1 = 'ausser'`, `EXCEPT_WORD2 = 'ohne'`, `AND_WORD = 'und'`, `THEN1__WD = 'dann'`
- `IS_STR = "ist "`, `ARE_STR = "sind "`, `AND_LIST_STR = " und "`
- `SOMETHING_STR`, `SOMEONE_STR`, `SOMEDIRECTION_STR` in German
- Status bar labels: `SCORE__TX = " Punkte: "`, `SCORE_SHORT__TX = " Pt:"`, `MOVES__TX = " Züge: "`, `MOVES_SHORT__TX = " Zg:"`
- `LISTOBJS_ROOM_SUFFIX = ".^"` (German prefix functions end with "ist"/"befinden sich")
- German direction constants (`DE_NORD` … `DE_RAUS`) and `EXTRA_DIRECTION_ROW` flag
- German abbreviation set (`CUSTOM_ABBREVIATIONS` prevents English ones loading)

**`de/messages_de.h`** — German translations of all `MSG_xxx` constants plus helper functions:
- `IsorAre(obj)` — prints "ist" or "sind"
- `CTheyreorIts(obj)` / `ItorThem(obj)` / `ThatorThose(obj)` — gender-sensitive pronoun helpers
- All messages may have `! TODO:` prefix comments marking items not yet reviewed by a native speaker

**`de/grammar_de.h`** — German verb definitions. Defines `_ListObjsMsg` and `_ListObjsInOnMsg` (German room-contents phrasing), then includes `grammar.h`, then adds German verbs:
- Meta: `erneut`, `nochmal`, `beende`, `lade`, `neustart`, `speicher`, `punkte`, `version`, `knapp`, `ausfuehrlich`, `superknapp`, `skript`, `transkript`
- Object: `nimm`/`hol`/`greif`, `lass`/`wirf`, `schau`/`seh`/`untersuche`
- Navigation: `geh`/`lauf`/`renn`/`wander` + direction words from `globals.h`
- Locks: `schliess`/`schließ X auf` (unlock), `schliess X zu` (close/lock), `mach X auf/zu`
- Wear: `anzieh`, `auszieh`, `zieh X an/aus`
- Communication: `frag`, `erzaehl`, `sag`, `gib`, `zeig`
- Senses: `hoer`, `rieche`, `beruehr`, `lies`
- Other: `trink`, `iss`, `warte`, `hau`, `kletter`

---

## German Article System

Inform 6's built-in article system prints `(a)`/`(the)`/`(The)`. PunyInformDE hooks into this via:

- **`article` property** — set the indefinite article string directly (`article "eine"`, `article "ein"`, etc.)
- **`female` attribute** — causes gender helpers to use "sie"/"Sie"
- **`neuter` attribute** — causes gender helpers to use "es"/"Es"
- Default — masculine ("er"/"Er")
- **`_PrintObjName`** in `puny.h` reads these attributes to select die/das/der for `(the)` output

The definite article produced by `(the)` only covers Nominativ. For Akkusativ/Dativ contexts, game authors should write explicit article strings or use `proper` to suppress the article.

---

## UTF-8 and Special Characters

Source files are encoded as **UTF-8 without BOM**. The compiler flag `!% -Cu` enables UTF-8 source mode. Umlauts and ß are used directly in all source files.

`de/globals_de.h` extends the Z-machine character table:

```inform6
#IfV5;
#IfNDef USE_ASCII;
Zcharacter 'ä'; Zcharacter 'ö'; Zcharacter 'ü';
Zcharacter 'ß'; Zcharacter 'Ä'; Zcharacter 'Ö'; Zcharacter 'Ü';
#EndIf;
#EndIf;
```

This must come before any string or dictionary word using these characters — `globals_de.h` is first in the include chain.

---

## ASCII Build

For interpreters without Unicode output support, a separate `beispiel_ascii.z5` is produced. The approach is **build-time preprocessing**: the build script substitutes all umlauts in every source file to digraph equivalents before compilation, so the compiled story file contains only ASCII bytes.

### Why `USE_ASCII` Is Still Needed

Although preprocessing replaces all umlaut characters in string literals, the `Zcharacter` declarations in `globals_de.h` use umlaut characters as dictionary tokens (`Zcharacter 'ä'`). After preprocessing these would become `Zcharacter 'ae'`, which is invalid Inform 6 syntax. The `#IfNDef USE_ASCII` guard skips the entire block, so `USE_ASCII` remains necessary as a compile-time signal to suppress those declarations.

### How the ASCII Build Works

The build script ([`.vscode/build.ps1`](../.vscode/build.ps1)) performs these steps for the ASCII target:

1. **Preprocess** the following files into `build/ascii_lib/` and `build/ascii_src/`, replacing ä→ae, ö→oe, ü→ue, ß→ss, Ä→Ae, Ö→Oe, Ü→Ue:
   - `lib/de/globals_de.h` → `build/ascii_lib/de/globals_de.h` (status-bar label `" Züge: "` etc.)
   - `lib/de/messages_de.h` → `build/ascii_lib/de/messages_de.h` (all parser messages)
   - `lib/puny.h` → `build/ascii_lib/puny.h` (`" (enthält"` etc.)
   - `example/beispiel.inf` → `build/ascii_src/beispiel.inf` (all game text)
2. **Compile** `example/beispiel_ascii.inf` (which defines `Constant USE_ASCII` then includes `beispiel.inf`) with the preprocessed tree first on the include path.

`lib/de/grammar_de.h` is deliberately **not** preprocessed because it defines dictionary words like `'öffne'` alongside ASCII alternatives like `'oeffne'` in the same `Verb` statement — preprocessing both would create duplicate-word errors.

### Digraph Mapping

| Umlaut | Digraph |
|--------|---------|
| ä      | ae      |
| ö      | oe      |
| ü      | ue      |
| ß      | ss      |
| Ä      | Ae      |
| Ö      | Oe      |
| Ü      | Ue      |

---

## Direction Words

German direction shortcuts (`nord`, `sued`, `ost`, `west`, `rauf`, `runter`, `rein`, `raus`) are defined in `globals_de.h` and wired into the `_direction_dict_words` 3-row table via the `EXTRA_DIRECTION_ROW` constant. `globals.h` selects between the 2-row (English) and 3-row (German) variants at compile time.

---

## Building

The VS Code **Build** task (`Ctrl+Shift+B`) runs [`.vscode/build.ps1`](../.vscode/build.ps1), which:

1. Compiles `build/beispiel.z5` (Unicode build)
2. Preprocesses German sources and compiles `build/beispiel_ascii.z5` (ASCII build)
3. Generates `example/beispiel.walkthrough.ascii.txt` from the umlaut walkthrough

Manual compilation:
```
tools\inform6.exe +include_path=lib example\beispiel.inf build\beispiel.z5
```

- Compiler: Inform 6.44+ required
- Target: z5
- Source encoding: UTF-8 without BOM, `-Cu` flag declared in `!%` header

---

## Tests

Automated tests use the [PunyTest](../../fiction/PunyTest/) framework (pytest-based) and dfrotz:

```
python -m pytest tests\ -v
```

| Test file | Coverage |
|-----------|----------|
| `test_walkthrough.py` | Full walkthrough against Unicode build |
| `test_ascii_build.py` | Full walkthrough + no-high-bytes assertion against ASCII build |
| `test_directions.py` | German direction commands |
| `test_lock_unlock.py` | Lock/unlock commands and messages |
| `test_list_format.py` | Container listing format, `und` separator |
| `test_umlauts.py` | ASCII digraph input (passing) + umlaut input (xfail — dfrotz piped-stdin limitation on Windows) |

The `test_ascii_output_has_no_high_bytes` test scans the entire ASCII walkthrough output and fails if any character with `ord > 127` appears, catching any preprocessed file that was missed.

---

## VS Code Tasks

| Task | Shortcut | Action |
|------|----------|--------|
| Build | `Ctrl+Shift+B` | Compiles both builds, generates ASCII walkthrough |
| Test Dfrotz | Run Task | Interactive dfrotz session (Unicode build) |
| Test Dfrotz (ASCII) | Run Task | Interactive dfrotz session (ASCII build) |
| Test Lectrote | Run Task | Opens Lectrote (Unicode build) |
| Test Lectrote (ASCII) | Run Task | Opens Lectrote (ASCII build) |

---

## Example Game: Das Schiff der Sterne

A three-room puzzle adventure demonstrating the library features:

| Feature | Implementation |
|---------|---------------|
| Rooms | `Kajuete`, `Schiffsgang`, `Oberdeck` |
| Supporter | `Schreibtisch` with `Karte` on top |
| Container | `Kiste` (openable) with `Schluessel` inside |
| Enterable object | `Koje` |
| Lockable door | `Kajuentuer` (locked, `with_key Schluessel`) |
| Scoring | `OPTIONAL_SCORED`, `MAX_SCORE = 3` |
| Win condition | Examining `Fernrohr` sets `deadflag = 2` |

Walkthrough: `example/beispiel.walkthrough.txt` (umlauts) and `example/beispiel.walkthrough.ascii.txt` (digraphs, auto-generated by Build).

---

## Known Limitations / TODOs

1. **`(the)` / `(The)` in non-Nominativ contexts** — only Nominativ is handled by `_PrintObjName`. Akkusativ/Dativ require either `proper` or explicit article strings in game code.
2. **Adjective inflection** — not implemented. No systematic declension support.
3. **`ihm` / `dem` / `ihn`** — Dativ/Akkusativ pronouns not understood by the parser.
4. **`! TODO:` messages** in `de/messages_de.h` — need native-speaker review before release.


## Overview

PunyInformDE is a German localisation of PunyInform v6.5 for the Inform 6 compiler. It targets z5 story files and supports direct UTF-8 source encoding via the compiler's `-Cu` flag.

The design principle is **minimal diff from upstream**: all German-specific code lives in `lib/de/` so syncing to a new PunyInform release only requires updating the base files in `lib/`.

---

## File Structure

### Modified PunyInform Base Files (`lib/`)

| File | Modification |
|------|-------------|
| `globals.h` | Adds `Include "de/globals_de.h"` at top; all constants wrapped in `#IfNDef` guards so `de/globals_de.h` can override them |
| `parser.h` | `YesOrNo` extended to accept `ja`, `j//`, `nein` |
| `grammar.h` | Banner changed to `PunyInformDE v...`; `_ListObjsMsg`, `_ListObjsInOnMsg` translated; `" here.^"` → `" hier.^"` |
| `puny.h` | Includes `de/messages_de.h` and `de/grammar_de.h` instead of originals; `_PrintAfterEntry` container/item state strings translated |
| `scope.h` | Unchanged |
| `ext_*.h` | Unchanged |

### German-Specific Files (`lib/de/`)

These files do not exist in upstream PunyInform.

**`de/globals_de.h`** — Loaded first by `globals.h`. Contains:
- `Zcharacter` declarations for ä ö ü ß Ä Ö Ü (guarded by `#IfNDef USE_ASCII` and `#IfV5`)
- German parser word constants: `ALL_WORD = 'alles'`, `EXCEPT_WORD1 = 'ausser'`, `EXCEPT_WORD2 = 'ohne'`, `AND_WORD = 'und'`, `THEN1__WD = 'dann'`
- `IS_STR = "ist "`, `ARE_STR = "sind "`
- `SOMETHING_STR`, `SOMEONE_STR`, `SOMEDIRECTION_STR` in German
- German abbreviation set (`CUSTOM_ABBREVIATIONS` constant prevents English ones)
- `PrintDE(str)` runtime helper when `USE_ASCII` is defined

**`de/messages_de.h`** — German translations of all `MSG_xxx` constants plus helper functions:
- `IsorAre(obj)` — prints "ist" or "sind"
- `CTheyreorIts(obj)` — prints "Sie ist" / "Es ist" / "Er ist" based on gender attributes
- `ThatorThose(obj)` — prints "Das" or "Die" based on plural
- All messages prefixed `! TODO:` for review

**`de/grammar_de.h`** — German verb definitions. Includes `grammar.h` then adds:
- Meta verbs: `erneut`, `nochmal`, `beende`, `lade`, `neustart`, `speicher`, `punkte`
- Object verbs: `nimm`, `hol`, `greif`, `lass`, `wirf`, `schau`, `seh`, `untersuche`
- Navigation: `geh`, `lauf`, `renn`, `wander` (+ direction words via `globals.h`)
- Locks: `aufschliess`, `abschliess`, `verriegel`, `oeffne X mit Y`
- Switch: `schalte X an/aus`, `mach X auf/zu/an/aus`
- Wear: `anzieh`, `auszieh`, `zieh X an/aus`
- Communication: `frag`, `erzaehl`, `sag`, `gib`, `zeig`
- Senses: `hoer`, `rieche`, `beruehr`, `lies`
- Other: `trink`, `iss`, `warte`, `hau` (attack), `kletter`

---

## German Article System

Inform 6's built-in article system prints `(a)`/`(the)`/`(The)`. PunyInformDE hooks into this via:

- **`article` property** on objects — set the indefinite article string directly  
  e.g. `article "eine"` for feminine nouns, `article "ein"` for masculine/neuter
- **`female` attribute** — causes `CTheyreorIts` to print "Sie ist"
- **`neuter` attribute** — causes `CTheyreorIts` to print "Es ist"
- Default (no attribute) — prints "Er ist" (masculine)

The `(the)` print rule still outputs "the" / "The" — this is a known limitation. For full German article handling, game authors should use `proper` attribute or override via `before [Examine: ...]` patterns.

---

## UTF-8 and Special Characters

Source files are encoded as **UTF-8 without BOM**. The compiler flag `!% -Cu` enables UTF-8 source mode. Umlauts and ß can be used directly everywhere in source.

The Z-machine character table must be extended for umlauts to render correctly at runtime. `de/globals_de.h` declares:

```inform6
#IfV5;
#IfNDef USE_ASCII;
Zcharacter 'ä'; Zcharacter 'ö'; Zcharacter 'ü';
Zcharacter 'ß'; Zcharacter 'Ä'; Zcharacter 'Ö'; Zcharacter 'Ü';
#EndIf;
#EndIf;
```

This must come before any string or dictionary word using these characters (it is first in the include chain).

### USE_ASCII Mode

Define `Constant USE_ASCII;` in your game file before `Include "globals.h"` to suppress `Zcharacter` declarations. This suits interpreters that do not support Unicode output.

The `PrintDE(str)` function is compiled in when `USE_ASCII` is set. It uses `PrintAnyToArray` to expand a string and then transliterates UTF-8 byte sequences for ä/ö/ü/ß/Ä/Ö/Ü into digraphs:

| Character | Digraph |
|-----------|---------|
| ä | ae |
| ö | oe |
| ü | ue |
| ß | ss |
| Ä | Ae |
| Ö | Oe |
| Ü | Ue |

**Limitation**: Library messages in `de/messages_de.h` use compiled string literals and are **not** automatically transliterated by `PrintDE()`. Only game code that explicitly calls `PrintDE()` benefits from transliteration.

---

## Direction Words

German direction shortcuts are defined in `globals.h` via the `direction_dict_words` array mechanism (3-row table: abbreviation, English, German). Supported: `nord`, `sued`, `ost`, `west`, `rauf`, `runter`, `rein`, `raus`.

---

## Building

```
inform6 +include_path=lib example\beispiel.inf build\beispiel.z5
```

- Compiler: Inform 6.44+ required (`#IfnDef VN_1644` guard in `globals.h`)
- Target: z5 (z8 also supported)
- Output: `build/` directory
- Source encoding: UTF-8 without BOM, `-Cu` flag in `!%` header

VS Code tasks (`Ctrl+Shift+B` = Build, `Ctrl+Shift+P` → Run Test Task = Test):
- **Build** — compiles to `build/beispiel.z5`
- **Test** — runs Build, then opens dfrotz interactively in a dedicated terminal

---

## Example Game: Das Schiff der Sterne

A three-room puzzle adventure demonstrating the library features:

| Feature | Implementation |
|---------|---------------|
| Rooms | `Kajuete`, `Schiffsgang`, `Oberdeck` |
| Supporter | `Schreibtisch` with `Karte` on top |
| Container | `Kiste` (openable) with `Schluessel` inside |
| Enterable object | `Koje` |
| Lockable door | `Kajuentuer` (locked, `with_key Schluessel`) |
| Scoring | `OPTIONAL_SCORED`, `MAX_SCORE = 3` |
| Win condition | Examining `Fernrohr` sets `deadflag = 2` |

### Puzzle Walkthrough

```
schau                            ! inspect the room
untersuche schreibtisch          ! see the Seekarte on top
nimm karte / untersuche karte    ! optional: read the hint
untersuche koje                  ! notice the Kiste
untersuche kiste
oeffne kiste                     ! reveals Schluessel (+0 pts)
nimm schluessel                  ! +1 pt
aufschliess tuer mit schluessel  ! +1 pt (or: oeffne tuer mit schluessel)
oeffne tuer
nord
rauf                             ! now on Oberdeck
nimm fernrohr
untersuche fernrohr              ! +1 pt, win!
```

---

## Known Limitations / TODOs

1. **`(the)` / `(The)` print rules** still output English "the". Full German article handling requires gender-sensitive print rules for all cases (Nominativ/Akkusativ/Dativ).
2. **Adjective inflection** not implemented. Parser accepts some compound forms but not systematic declension.
3. **`ihm` / `dem` / `ihn`** (Dativ/Akkusativ pronouns) not understood by the parser.
4. **All `! TODO:` messages** in `de/messages_de.h` need native-speaker review.
5. **`PrintDE()`** only covers game-side strings; library messages are not transliterated in `USE_ASCII` mode.
