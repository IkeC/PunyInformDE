# German Grammar in PunyInformDE

## Overview

This document describes the three core German grammar problems that had to be
solved, how the reference libraries **deform 6/11** (Martin Oehm) and
**German.i7x** (Team GerX) approached them, and how PunyInformDE solved each
one within PunyInform's lightweight, old-hardware-targeted architecture.

Reference files consulted:
- `German.h`, `GermanG.h` — deform 6/11 (2005–2010)
- `German.i7x` — German.i7x v4 (2023)

**Performance constraint**: PunyInform targets old 8-bit hardware via
Z-machine interpreters (1 MHz effective throughput, ~64 KB story file).
Every extra array entry, property, or per-command function call has real cost.

---

## 1. Article System: Cases (Nominativ, Akkusativ, Dativ)

### The Problem

Base PunyInform prints only Nominative article forms everywhere. German grammar
requires four cases:

| Case        | m (der)  | f (die)   | n (das)  | pl (die)  |
|-------------|----------|-----------|----------|-----------|
| Nominativ   | der/ein  | die/eine  | das/ein  | die/-     |
| Dativ       | **dem/einem**| der/einer | **dem/einem**| den/- |
| Akkusativ   | **den/einen**| die/eine  | das/ein  | die/-     |

IF messages need Akkusativ and Dativ constantly:
- "Du legst **den** Schlüssel in **die** Kiste."  (Akk)
- "Du kannst nicht mit **dem** Schlüssel öffnen."  (Dat)

Without case support, masculine objects in Akkusativ ("den Schlüssel") are
silently printed as "der Schlüssel".

### How Deform / German.i7x Solve It

Both use a `short_name_case` global (0=Nom, 1=Gen, 2=Dat, 3=Akk) and a flat
article table indexed by `case × 4 + gender`:

```inform
Array LanguageArticles -->
    "die " "der " "die " "das "    ! def, Nom: pl m f n
    "den " "dem " "der " "dem "    ! def, Dat
    "die " "den " "die " "das "    ! def, Akk
    ...
```

Messages set `short_name_case` before printing so the table lookup picks the
right form. Shorthand print-rule functions (`der`, `den`, `dem`) wrap this.

Gender is derived from attributes (`male`/`female`/`neuter`/`pluralname`).
German.i7x uses a `grammatical_gender` property instead of attributes, but
that costs one property slot per object — the attribute approach is cheaper.

### PunyInformDE Solution

Implemented in `lib/de/article_de.h`, `lib/puny.h`, `lib/de/messages_de.h`.

- `DE_DefArticles` / `DE_IndefArticles` arrays (Nom/Akk/Dat × 4 genders = 12 entries each)
- `short_name_case` global; case-set helpers `DE_Der`, `DE_Den`, `DE_Dem`, `DE_Ein`, `DE_Einen`, `DE_Einem`
- `_PrintObjName` in `puny.h` uses the tables
- Messages that use Akkusativ or Dativ call the helpers

Genitiv is not implemented — it is not needed by any PunyInform message and
appears rarely in IF command parsing.

---

## 2. Pronoun Input

### The Problem

PunyInform's parser recognises only four English pronouns: `it`, `him`, `her`,
`them`. German input forms (`er`, `ihn`, `ihm`, `sie`, `es`, `ihnen`) are
unknown words:

```
>> oeffne kiste
Du öffnest die Seekiste.
>> schau in sie          ← natural German
Ich verstehe dieses Verb nicht.   ← parser sees "sie" as unknown noun
```

### How Deform Solves It

Deform uses a `LanguagePronouns` table interpreted by the full Inform 6 parser,
with GNA bit-patterns for gender/animateness matching. The full parser maintains
a pronoun→object mapping updated after each successful parse.

PunyInform's four-slot model (`itobj`/`himobj`/`herobj`/`themobj`) has no GNA
table and cannot use that mechanism directly.

### PunyInformDE Solution

Implemented in `lib/de/parser_de.h` (BeforeParsing Pass 3) and `lib/parser.h`
(`PronounNotice`, `#IfDef LANG_DE` block).

**BeforeParsing Pass 3** rewrites German pronoun tokens to their English
equivalents in the raw input buffer before the main parser runs:

| German | → English | Condition |
|--------|-----------|-----------|
| `er`, `ihn`, `ihm` | `him` | `himobj ≠ 0` |
| `sie` | `her` | `herobj ≠ 0` (feminine priority) |
| `sie` | `them` | `themobj ≠ 0` (plural fallback) |
| `es` | `it` | `itobj ≠ 0` |
| `ihnen` | `them` | `themobj ≠ 0` |

`PronounNotice` in `parser.h` is extended (`#IfDef LANG_DE`) so that inanimate
feminine objects update `herobj` (not just animate), enabling "die Kiste → sie".

**Known limitation**: `ihr` is excluded — it is ambiguous between the
possessive article ("ihr Haus"), the Dativ pronoun, and the 2nd-person-plural
address. Players can use `sie` in Dativ contexts instead.

### Mixed-Gender Synonyms

**The Problem**

An object might be known by multiple names in different genders:
- "das Gerät" (neuter primary) — `nimm es`
- "die Kamera" (feminine synonym) — `nimm sie`
- "der Apparat" (masculine synonym) — `nimm ihn`

In a normal object, each gender pronoun can reference at most one object. After
`untersuche kamera` (feminine), PronounNotice sees the neuter object and sets
only `itobj`, leaving `herobj` stale. Then `nimm sie` fails.

**Deform's Approach**

Deform uses a circular buffer (8 slots) to store one runtime gender override per
object. After `untersuche kamera`, code would call `GenderNotice(Gerät, female)`
to set an override. But this can only hold *one* override at a time — for three
genders simultaneously, you get the static primary + one CG override = 2 active
genders. The CG system is designed for runtime gender *change* (e.g. revealed
character identity), not persistent multi-synonym support.

**PunyInformDE Solution**

Implemented in `lib/de/globals_de.h` and `lib/parser.h` (`PronounNotice` LANG_DE).

Four attributes allow an object to activate multiple pronoun slots at once:

```inform
Attribute also_female;
Attribute also_male;
Attribute also_neuter;
Attribute also_plural;
```

**Gender synonyms** (`also_female`, `also_male`, `also_neuter`): for objects
known by names in more than one grammatical gender. Example:

```inform
Object -> Geraet "Gerät"
    with
        name 'gerät' 'fotokamera' 'kamera'
             'fotoapparat' 'apparat',
        description "...",
    has neuter also_female also_male;
```

After ANY interaction with this object (via any of its three name forms),
`PronounNotice` runs and sets:
- `itobj = Gerät` (primary neuter)
- `herobj = Gerät` (also_female)
- `himobj = Gerät` (also_male)

All three pronouns now point to the same object. Subsequent commands `nimm es`,
`nimm sie`, and `nimm ihn` all work.

**Plural synonym** (`also_plural`): for objects that have a primary singular name
but are also known by a plural form. Example: "das Tau" (neuter) / "die Taue" (plural):

```inform
Object -> Tau "Tau"
    with
        name 'tau' 'hanftau' 'taue',
        description "...",
    has neuter also_plural;
```

After any interaction, `PronounNotice` sets both `itobj` (neuter) and `themobj`
(plural), and `de_last_sie_target = 2` (plural). This means `nimm es` and
`nimm sie` / `nimm ihnen` all work for the same object. The `also_plural`
check runs last in the attribute chain, so if `also_plural` and `also_female`
are both present, `sie` resolves to the plural reading.

**Known limitation**: All activated pronouns become over-inclusive. After `untersuche
apparat` (male), the feminine pronoun `sie` also points to Gerät, potentially
overwriting a genuine feminine antecedent from earlier in the conversation.
This is acceptable for the rare case of multi-gender synonyms; more sophisticated
tracking would require per-word gender metadata (which deform lacks too).

**Comparison with deform**

| | deform CG | PunyInformDE `also_*` |
|---|---|---|
| Capacity | Static gender + 1 CG override = 2 | Static + 4 attributes = 5 |
| Three-gender case | Partial (CG is single-override) | Full support |
| Plural synonym | Not supported | `also_plural` sets `themobj` |
| Memory | 16-word global buffer + pointer | 4 attribute bits |
| Author API | `GenderNotice(obj, g)` per gender | `has neuter also_female also_male` |
| Primary use case | Runtime gender revelation | Persistent multi-synonym support |

---

## 3. Adjective Inflection

### The Problem

German adjectives decline by case, gender, and definiteness. A stem-only
`name` entry like `'klein'` matches "kleiner Schlüssel" (Nom indef m) but
not "kleinen Schlüssel" (Akk def m) since the player types the inflected form.

On the output side, printing "kleiner Schlüssel" statically in the object's
`short_name` is wrong in Akkusativ contexts ("den kleinen Schlüssel").

### How Deform / German.i7x Solve It

#### Input: `PruneWord`

When a word is not found in the dictionary, try stripping common endings:
1. `-em`, `-en`, `-er`, `-es` (two-char)
2. `-e`, `-n`, `-s` (one-char)

and re-check the dictionary. Game authors declare only the stem in `name`.

Both deform and German.i7x use an identical `PruneWord` algorithm with a
`DictionaryLookup` safety check to avoid false stripping.

#### Output: `adj` property + suffix table

Objects declare an adjective stem via `adj "klein"`. The print function
appends the correct case/gender/definiteness suffix from a lookup table
(deform: 80 entries; German.i7x: same layout).

### PunyInformDE Solution

**Stage 1 — Input** (`lib/de/parser_de.h`, Pass 4): Unknown words have
`-em/-en/-er/-es/-e/-n/-s` stripped via `_DE_PruneWordSuffixLen`. Only applied
when the stripped stem is found in the dictionary (dict-safe check).

**Stage 2 — Output** (`lib/de/article_de.h`, `lib/puny.h`): The `adj` property
stores the adjective stem. `_PrintObjName` calls `_DE_GetAdjSuffix(mode, case, gender)`
which returns the correct suffix string. The 36 logical combinations
(3 modes × 3 cases × 4 genders) map to:

| Mode | Case | pl | m | f | n |
|---|---|---|---|---|---|
| Definite | Nom | -en | -e | -e | -e |
| Definite | Akk | -en | -en | -e | -e |
| Definite | Dat | -en | -en | -en | -en |
| Indefinite | Nom | -e | -er | -e | -es |
| Indefinite | Akk | -e | -en | -e | -es |
| Indefinite | Dat | -en | -en | -en | -en |
| Bare | Nom | -e | -er | -e | -es |
| Bare | Akk | -e | -en | -e | -es |
| Bare | Dat | -en | -em | -er | -em |

Vs. deform's 80-entry flat array — Genitiv and demonstrative forms are omitted.

#### The `adj` property vs. inflected forms in `name`

The two mechanisms are orthogonal:
- `adj "alt"` → **output only**: provides the stem that gets a declined suffix appended when printing
- `name 'alt'` → **input only**: the stem must be in the dictionary so Pass 4 can reduce "alten"/"alter"/"altem" to "alt" and match it

Inflected forms in `name` (e.g. `'alter' 'alten'`) are redundant when Pass 4
is working — they are stripped to `'alt'` automatically. Only the stem needs
to be in `name`.

---

## Design Comparison

| Feature | deform | German.i7x | PunyInformDE |
|---------|--------|------------|--------------|
| Definite articles Nom | ✅ | ✅ | ✅ |
| Definite articles Akk/Dat | ✅ | ✅ | ✅ |
| Definite articles Gen | ✅ | ✅ | ❌ not needed |
| Indefinite articles Nom | ✅ | ✅ | ✅ |
| Indefinite articles Akk/Dat | ✅ | ✅ | ✅ |
| Gender via attributes | ✅ | ⚠️ property | ✅ |
| German pronoun INPUT (er/ihn/ihm/sie/es/ihnen) | ✅ | ❌ | ✅ |
| `ihr` pronoun input | ✅ | ❌ | ❌ ambiguous |
| Gender-aware inanimate pronouns | ✅ GNA table | ✅ | ✅ LANG_DE hook |
| Multi-gender synonyms (also_*) | ❌ single CG override | ❌ | ✅ 3 attributes |
| Adjective input stripping | ✅ PruneWord | ✅ | ✅ Pass 4 |
| Adjective output (declined) | ✅ 80-entry table | ✅ | ✅ 36-entry tables |
| Noun declension (Genitiv-s) | ✅ `dekl` | ✅ | ❌ not planned |
| Synonym contractions (ins/vom) | ✅ | ✅ | ❌ not planned |
| Compound word splitting | ❌ | ✅ | ❌ not planned |
| Pronominal adverbs (damit/daraus) | ✅ | ✅ | ❌ not planned |
| Changing gender at runtime | ✅ CG buffer | ✅ | ❌ not planned |

