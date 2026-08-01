! PunyInformDE: German-specific globals
! This file is included by lib/globals.h at the very start, so these
! definitions take precedence over any English defaults in globals.h.
!
! To update from a new PunyInform release, only globals.h needs updating
! — the German overrides here remain separate.

! ---------------------------------------------------------------------------
! German special characters
! The Zcharacter alphabet table is defined in lib/de/chartable_de.h, which game
! source must include before any string literal (even "Constant Story").
! ASCII and Z3 builds skip the table automatically via #IfV5/#IfNDef USE_ASCII
! guards inside chartable_de.h.
! ---------------------------------------------------------------------------

! ---------------------------------------------------------------------------
! German parser word constants
! These override the English defaults defined in globals.h.
! ---------------------------------------------------------------------------
Constant ALL_WORD     = 'alles';   ! English: 'all'
Constant EXCEPT_WORD1 = 'ausser';  ! English: 'but'   (außer — digraph)
Constant EXCEPT_WORD2 = 'ohne';    ! English: 'except'
Constant AND_WORD     = 'und';     ! English: 'and'
Constant THEN1__WD    = 'dann';    ! English: 'then'

! ---------------------------------------------------------------------------
! German string constants for is/are
! ---------------------------------------------------------------------------
Constant IS_STR  = "ist ";   ! English: "is "
Constant ARE_STR = "sind ";  ! English: "are "

! Status line labels (override English Score/Moves)
Constant SCORE__TX       = " Punkte: ";
Constant SCORE_SHORT__TX = " Pt:";
Constant MOVES__TX       = " Züge: ";
Constant MOVES_SHORT__TX = " Zg:";

! Suffix printed after room contents list (override " here.^" from grammar.h)
! German prefix functions end with "ist "/"befinden sich ", so no suffix needed
Constant LISTOBJS_ROOM_SUFFIX = ".^";

! ---------------------------------------------------------------------------
! §3 groundwork: grammatical case and adjective properties
! ---------------------------------------------------------------------------
#IfNDef Nom;
Constant Nom = 0;
#EndIf;
#IfNDef Akk;
Constant Akk = 1;
#EndIf;
#IfNDef Dat;
Constant Dat = 2;
#EndIf;

! Current case used by _PrintObjName / article_de helpers.
! Default stays Nominativ for generic object rendering.
Global short_name_case = Nom;

! Last preferred target for ambiguous German "sie": 1=herobj, 2=themobj.
Global de_last_sie_target = 0;

! ---------------------------------------------------------------------------
! Mixed-gender synonym attributes
! A single object may be known by synonyms of different grammatical gender,
! e.g. "das Gerät" (neuter, primary) / "die Kamera" (female) / "der Apparat" (male).
! Mark secondary genders with also_female / also_male / also_neuter so that
! PronounNotice sets ALL matching pronoun slots at once.
!   das Gerät / die Kamera / der Apparat → has neuter, also_female, also_male
!   die Lampe / das Licht                → has female, also_neuter
!   der Schlüssel / die Schlüsselkarte   → (male) also_female
! Use also_plural when an object also has a plural name (different word or
! grammatical plural form), so that "sie" / "ihnen" (plural they/them) also
! refer to the object after the player uses the plural synonym.
!   das Tau / die Taue                   → has neuter, also_plural
! ---------------------------------------------------------------------------
Attribute also_female;
Attribute also_male;
Attribute also_neuter;
Attribute also_plural;

! Override the default player-object description used by the base library.
#IfnDef CUSTOM_PLAYER_OBJECT_DESCRIPTION;
Constant CUSTOM_PLAYER_OBJECT_DESCRIPTION "Gutaussehend wie immer.";
#EndIf;
#IfnDef CUSTOM_DARKNESS_DESCRIPTION;
Constant CUSTOM_DARKNESS_DESCRIPTION "Es ist stockdunkel!";
#EndIf;

! Optional adjective stem(s) and noun declension marker for §3.
#IfNDef adj;
Property adj;
#EndIf;

! ---------------------------------------------------------------------------
! German string constants (for parser messages)
! ---------------------------------------------------------------------------
Constant SOMETHING_STR      = "etwas";           ! English: "something"
Constant SOMEONE_STR        = "jemanden";        ! English: "someone"
Constant SOMEDIRECTION_STR  = "(eine Richtung)"; ! English: "(some direction)"

! ---------------------------------------------------------------------------
! German abbreviations
! Defining CUSTOM_ABBREVIATIONS prevents globals.h from adding English ones.
! When GAME_ABBREVS is defined, the game provides all abbreviations itself
! (e.g. via zabbrev). In that case these defaults are skipped so that
! the game can use all 96 abbreviation slots.
! ---------------------------------------------------------------------------
Constant CUSTOM_ABBREVIATIONS;
#IfnDef GAME_ABBREVS;
Abbreviate "Bist du sicher, dass du das ";
Abbreviate " Selbstverliebt wie immer";
Abbreviate "nichts Unerwartetes";
Abbreviate "(zuerst nehme ";
Abbreviate "Entschuldigung,";
Abbreviate "Du kannst ";
Abbreviate "verstehe nicht";
Abbreviate "Du bist ";
Abbreviate " bereits ";
Abbreviate " nichts ";
Abbreviate "Du hast ";
Abbreviate " nicht ";
Abbreviate "etwas ";
Abbreviate "Richtung";
Abbreviate "Punkte";
Abbreviate "Du tr";
Abbreviate " kein";
Abbreviate "[Kommentar";
Abbreviate " dich";
Abbreviate "Inform ";
Abbreviate "estand";
Abbreviate " sein";
Abbreviate " haben";
Abbreviate "halten";
Abbreviate "stehst";
#EndIf; ! GAME_ABBREVS

! German string constants for list printing
! Override the English " and " separator used in PrintContents (puny.h).
Constant AND_LIST_STR = " und ";

! ---------------------------------------------------------------------------
! German direction word constants
! Setting DIRECTION_WORDS_DEFINED skips the English defaults block and the
! English _direction_dict_words array in globals.h. This file supplies both.
! ---------------------------------------------------------------------------
Constant DIRECTION_WORDS_DEFINED;
Constant DIR_ABBREV_N   = 'n//';    ! Norden  (abbreviation stays 'n')
Constant DIR_ABBREV_S   = 's//';    ! Süden   (abbreviation stays 's')
Constant DIR_ABBREV_E   = 'o//';    ! Osten   ('o', not 'e')
Constant DIR_ABBREV_W   = 'w//';    ! Westen  (abbreviation stays 'w')
Constant DIR_ABBREV_U   = 'hoch';   ! hinauf  ('hoch'; no single-char abbrev)
Constant DIR_ABBREV_D   = 0;        ! hinunter (no abbreviation)
Constant DIR_ABBREV_IN  = 0;        ! rein    (no abbreviation)
Constant DIR_ABBREV_OUT = 0;        ! raus    (no abbreviation)
Constant DIR_WORD_N     = 'nord';
Constant DIR_WORD_S     = 'sued';
Constant DIR_WORD_E     = 'ost';
Constant DIR_WORD_W     = 'west';
Constant DIR_WORD_U     = 'rauf';
Constant DIR_WORD_D     = 'runter';
Constant DIR_WORD_IN    = 'rein';
Constant DIR_WORD_OUT   = 'raus';
#IfDef OPTIONAL_FULL_DIRECTIONS;
Constant DIR_ABBREV_NE  = 'no';       ! Nordost
Constant DIR_ABBREV_NW  = 'nw';       ! Nordwest  (same as English)
Constant DIR_ABBREV_SE  = 'so';       ! Südost
Constant DIR_ABBREV_SW  = 'sw';       ! Südwest   (same as English)
Constant DIR_WORD_NE    = 'nordost';
Constant DIR_WORD_NW    = 'nordwest';
Constant DIR_WORD_SE    = 'suedost';
Constant DIR_WORD_SW    = 'suedwest';
#EndIf;

! V5+ direction word array — replaces the English one in globals.h.
! Using DIR_* constants (not literals) silences I6 "declared but not used" warnings:
! the compiler tracks constant use in array initialisers but not in @je operands.
#Iftrue #version_number > 3;
#IfDef OPTIONAL_FULL_DIRECTIONS;
Array _direction_dict_words static -->
	DIR_ABBREV_N DIR_ABBREV_S DIR_ABBREV_E DIR_ABBREV_W
	DIR_ABBREV_NE DIR_ABBREV_NW DIR_ABBREV_SE DIR_ABBREV_SW
	DIR_ABBREV_U DIR_ABBREV_D DIR_ABBREV_IN DIR_ABBREV_OUT
	DIR_WORD_N DIR_WORD_S DIR_WORD_E DIR_WORD_W
	DIR_WORD_NE DIR_WORD_NW DIR_WORD_SE DIR_WORD_SW
	DIR_WORD_U DIR_WORD_D DIR_WORD_IN DIR_WORD_OUT;
#IfNot;
Array _direction_dict_words static -->
	DIR_ABBREV_N DIR_ABBREV_S DIR_ABBREV_E DIR_ABBREV_W
	DIR_ABBREV_U DIR_ABBREV_D DIR_ABBREV_IN DIR_ABBREV_OUT
	DIR_WORD_N DIR_WORD_S DIR_WORD_E DIR_WORD_W
	DIR_WORD_U DIR_WORD_D DIR_WORD_IN DIR_WORD_OUT;
#EndIf;
#IfNot;
! V3: I6 does not count constants used in @je assembly operands as "used".
! This dummy static array references all DIR_* constants in a non-assembly context
! to silence those warnings. (static --> arrays occupy read-only story-file space.)
Array _dir_words_anchor static -->
	DIR_ABBREV_N DIR_ABBREV_S DIR_ABBREV_E DIR_ABBREV_W
	DIR_ABBREV_U DIR_ABBREV_D DIR_ABBREV_IN DIR_ABBREV_OUT
	DIR_WORD_N DIR_WORD_S DIR_WORD_E DIR_WORD_W
	DIR_WORD_U DIR_WORD_D DIR_WORD_IN DIR_WORD_OUT;
#IfDef OPTIONAL_FULL_DIRECTIONS;
Array _dir_fullwords_anchor static -->
	DIR_ABBREV_NE DIR_ABBREV_NW DIR_ABBREV_SE DIR_ABBREV_SW
	DIR_WORD_NE DIR_WORD_NW DIR_WORD_SE DIR_WORD_SW;
#EndIf;
#EndIf;

! German parser extension (enables ja/nein in YesOrNo via Replace directive)
Include "parser_de.h";

[ DirectionsDescription; "Du siehst nichts Besonderes in dieser Richtung."; ];
