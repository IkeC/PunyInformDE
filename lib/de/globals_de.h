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
! ---------------------------------------------------------------------------
Constant CUSTOM_ABBREVIATIONS;
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
#Iftrue #version_number > 3;
#IfDef OPTIONAL_FULL_DIRECTIONS;
Array _direction_dict_words static --> 'n//' 's//' 'o//' 'w//' 'no' 'nw' 'so' 'sw' 'hoch' 0 0 0
	'nord' 'sued' 'ost' 'west' 'nordost' 'nordwest' 'suedost' 'suedwest' 'rauf' 'runter' 'rein' 'raus';
#IfNot;
Array _direction_dict_words static --> 'n//' 's//' 'o//' 'w//' 'hoch' 0 0 0
	'nord' 'sued' 'ost' 'west' 'rauf' 'runter' 'rein' 'raus';
#EndIf;
#EndIf;

! German parser extension (enables ja/nein in YesOrNo via Replace directive)
Include "parser_de.h";
