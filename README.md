# PunyInformDE

A German localisation of PunyInform v6.5, based on the original translation by Lea Santner and A. Pulvermacher (https://github.com/smartgrids-aau/punyinformde).

## Status

Release candidate. Tracks PunyInform v6.5.  
German-specific code lives entirely in `lib/de/` — future upstream updates only require touching the base files in `lib/`.

## Architecture

```
lib/
  globals.h        — PunyInform v6.5 base; #IfNDef guards allow German overrides
  parser.h         — PunyInform v6.5 base; YesOrNo extended for ja/nein
  grammar.h        — PunyInform v6.5 base; overridable listing functions
  puny.h           — PunyInform v6.5 base; German articles, container text,
                     list separator
  scope.h          — Unchanged from PunyInform v6.5
  ext_*.h          — Unchanged extension files from PunyInform v6.5
  de/
    globals_de.h   — Zcharacter declarations, German parser words, IS_STR/ARE_STR,
                     status-bar labels, direction constants, abbreviations
    messages_de.h  — All MSG_xxx constants in German
    grammar_de.h   — German verb definitions and room-listing functions
```

Files in `lib/de/` do not exist in upstream PunyInform and are purely DE additions.

## Building

Requires `tools/inform6.exe` (Inform 6.44+). The VS Code **Build** task (`Ctrl+Shift+B`) compiles both game variants and generates the ASCII walkthrough:

```powershell
powershell -ExecutionPolicy Bypass -File .vscode\build.ps1
```

Output:

| File | Description |
|------|-------------|
| `build/beispiel.z5` | Unicode build — umlauts rendered natively |
| `build/beispiel_ascii.z5` | ASCII build — all umlauts replaced with digraphs |
| `example/beispiel.walkthrough.ascii.txt` | ASCII walkthrough (auto-generated) |

The ASCII build works by preprocessing source files (replacing umlauts with digraphs) before compilation. `USE_ASCII` is defined in `beispiel_ascii.inf` to suppress `Zcharacter` declarations.

## Running

```
tools\dfrotz.exe build\beispiel.z5
```

Or use the VS Code **Run Task** menu: `Test Dfrotz`, `Test Lectrote`, `Test Dfrotz (ASCII)`, `Test Lectrote (ASCII)`.

## Tests

```
python -m pytest tests\ -v
```

The test suite runs against both builds using dfrotz and the [PunyTest](../fiction/PunyTest/) framework. Results: **39 pass, 3 xfail** (the xfails are a dfrotz Windows piped-stdin limitation for umlaut input — not a game bug; ASCII build tests provide equivalent coverage).

## German Commands

**Navigation**: `nord`, `sued`, `ost`, `west`, `rauf`, `runter`, `rein`, `raus`  
**Looking**: `schau`, `untersuche <ding>`, `schau in <ding>`  
**Objects**: `nimm`, `lass`, `oeffne`, `schliess`, `leg <X> in/auf <Y>`  
**Locks**: `schliess <X> mit <Y> auf`, `schliess <X> zu`  
**Meta**: `inventar`, `punkte`, `speicher`, `lade`, `neustart`, `beende`, `version`  
**Clothing**: `anzieh`, `auszieh`

Umlaut verbs also accepted where supported: `öffne`, `schließ … auf`.

## German Article System

- **`article` property** — set the indefinite article string (`article "eine"`, `article "ein"`, etc.)
- **`female` attribute** — marks feminine nouns (sie/Sie, die)
- **`neuter` attribute** — marks neuter nouns (es/Es, das)
- Default — masculine (er/Er, der)

`(the)` outputs die/das/der in Nominativ. For Akkusativ/Dativ contexts use `proper` or explicit article strings.

## Notes

- Dativ/Akkusativ pronouns (`ihm`, `ihn`, `dem`) are not understood by the parser
- Adjective inflection is not implemented


A German localisation of PunyInform v6.5, based on the original translation by Lea Santner and A. Pulvermacher (https://github.com/smartgrids-aau/punyinformde).

## Example Game: Das Schiff der Sterne

A short puzzle adventure aboard the sailing ship *Sternwind*. The player wakes up locked in the captain's cabin and must find a key, unlock the door, reach the deck, and use a brass telescope to spot a treasure island.

**Rooms**: Die Kapitänskajüte → Der Schiffsgang → Das Oberdeck  
**Scoring**: 3 points (key taken, door unlocked, island discovered)  
**Win condition**: Examine the telescope on deck

Walkthrough: see `example/beispiel.walkthrough.txt`

## German Commands

**Navigation**: `nord`, `sued`, `ost`, `west`, `rauf`, `runter`, `rein`, `raus`  
**Looking**: `schau`, `untersuche <ding>`, `schau in <ding>`  
**Objects**: `nimm`, `lass`, `oeffne`, `schliess`, `leg <X> in/auf <Y>`  
**Locks**: `aufschliess <X> mit <Y>`, `abschliess <X> mit <Y>`, `oeffne <X> mit <Y>`  
**Meta**: `inventar`, `punkte`, `speicher`, `lade`, `neustart`, `beende`, `version`  
**Clothing**: `anzieh`, `auszieh`

## UTF-8 / Umlaut Handling

Source files use UTF-8 without BOM, compiled with `!% -Cu`. Umlauts (ä ö ü ß Ä Ö Ü) appear directly in source and are declared in the Z-machine character table via `Zcharacter` in `lib/de/globals_de.h`.

To target interpreters without Unicode support, define `USE_ASCII` before including the library. This disables `Zcharacter` declarations and makes `PrintDE(str)` available for runtime umlaut→digraph transliteration (ä→ae, ö→oe, ü→ue, ß→ss, etc.).

## Notes

- The article system (die/der/das) is not fully automatic — use the `article` property on objects and the `female`/`neuter` attributes for correct agreement
- German noun inflection (Akkusativ/Dativ) is partially supported; see `docs/Implementation.md`
