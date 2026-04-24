! Part of PunyInformDE: German localisation of PunyInform.
! This file replaces grammar.h with German verb definitions.
! It first includes the base English grammar.h, then adds German synonyms.
!
! German verb definitions follow the tradition of using the second-person
! imperative singular (du-form) as the command word.
! Special characters: digraphs ae/oe/ue/ss are used for umlauts/Eszett
! for z3 compatibility; they map to ä/ö/ü/ß in z5+.
!
! TODO: Review all German verb translations before release.
!
System_file;

! ---------------------------------------------------------------------------
! German room/container contents listing functions.
! Defined BEFORE Include "grammar.h" so that grammar.h's #IfNDef guards skip
! the English defaults. LISTOBJS_ROOM_SUFFIX = ".^" is set in globals_de.h.
! ---------------------------------------------------------------------------

[ _ListObjsMsg p_parent  _count;
	_count = PrintContents(1, p_parent, 0); ! count without printing
	print "^";
	if(_count == 2) print "Hier befinden sich ";
	else print "Hier ist ";
	if(also_flag) print "auch ";
];

[ _ListObjsInOnMsg p_parent  _count;
	_count = PrintContents(1, p_parent, 0);
	print "^";
	if(p_parent has supporter) print "Auf "; else print "In ";
	print (the) p_parent;
	if(_count == 2) print " befinden sich "; else print " ist ";
	if(also_flag) print "auch ";
];

! Include the base English grammar (actions and action subs)
Include "grammar.h";

! ---------------------------------------------------------------------------
! PrintVerb is intentionally NOT defined here.
! VerbName() in grammar.h will print German verb words naturally by calling
! print (address) p_v, which gives the correct German verb word.
! If you need to override how a specific verb is printed, define PrintVerb
! in your game file before including globals.h.
! ---------------------------------------------------------------------------

! German meta verbs
! TODO: Review German command words
! ---------------------------------------------------------------------------

Extend 'again' first
	*                                           -> Again;
Verb meta 'erneut' 'nochmal'
	*                                           -> Again;

Verb meta 'beende' 'ende'
	*                                           -> Quit;

Verb meta 'lade' 'wiederher'
	*                                           -> Restore;

Verb meta 'neustart'
	*                                           -> Restart;

Verb meta 'speicher'
	*                                           -> Save;

Verb meta 'punkte' 'punktestand'
	*                                           -> Score;

Extend 'version' first
	*                                           -> Version;

Verb meta 'knapp'
	*                                           -> LookModeNormal;

Verb meta 'ausfuehrlich'
	*                                           -> LookModeLong;

Verb meta 'superknapp'
	*                                           -> LookModeShort;

#IfDef OPTIONAL_EXTENDED_METAVERBS;
#Ifndef NO_PLACES;
! TODO: Review German command words for places/objects listing
! 'orte'/'objekte' alias existing English meta verbs (only if OPTIONAL_EXTENDED_METAVERBS)
Verb 'orte' = 'places';
Verb 'objekte' = 'objects';
#EndIf;
#EndIf; ! OPTIONAL_EXTENDED_METAVERBS

#Ifdef OPTIONAL_EXTENDED_METAVERBS;
Verb meta 'skript' 'transkript'
	*                                           -> ScriptOn
	* 'an'/'ein'                                -> ScriptOn
	* 'aus'                                     -> ScriptOff;
#EndIf;

! ---------------------------------------------------------------------------
! German game verbs
! TODO: Review and complete all German command translations
! ---------------------------------------------------------------------------

! --- Take / Pick up ---
! TODO: nimm, hol, nehm = take; greif = grab/take
Verb 'nimm' 'hol' 'nehm'
	* multi                                     -> Take
	* 'auf' multi                               -> Take
	* multi 'auf'                               -> Take
	* multiinside 'aus' noun                    -> Remove
	* multiinside 'von' noun                    -> Remove;

Verb 'greif' 'fass'
	* multi                                     -> Take
	* 'nach' multi                              -> Take
	* multiinside 'aus' noun                    -> Remove
	* noun                                      -> Touch;

! --- Drop ---
! TODO: lass, lege, wirf = drop; schmeis = throw/drop
Verb 'lass' 'schmeis' 'wirf'
	* multiheld                                 -> Drop
	* multiheld 'fallen'/'hin'/'hier'/'ab'/'weg' -> Drop
	* multiheld 'aus' 'der'/'dem'/'den'/'die' noun -> Remove
	* multiheld 'aus' noun                      -> Remove
	* multiexcept 'in'/'hinein' noun            -> Insert
	* multiexcept 'auf' noun                    -> PutOn;

! --- Look / Examine ---
! TODO: schau, seh, sieh, guck = look; untersuche, betrachte = examine
Verb 'schau' 'seh' 'sieh' 'guck' 'blick' 'u//'
	*                                           -> Look
	* 'dich' 'um'                               -> Look
	* 'um'                                      -> Look
	* noun                                      -> Examine
	* 'an' noun                                 -> Examine
	* noun 'an'                                 -> Examine
	* 'in' noun                                 -> Search
	* 'auf' noun                                -> Examine
	* 'unter' noun                              -> Search;

Verb 'untersuche' 'betrachte' 'inspiziere'
	* noun                                      -> Examine;

! --- Open ---
! TODO: oeffne = open; entkorke = uncork
Verb 'oeffne' 'o' 'öffne' 'entkorke'
	* noun                                      -> Open
	* noun 'mit' held                           -> Unlock;

! --- Close / Lock / Unlock via schliess/schließ ---
! schließ X auf [mit Y]  → Unlock X (with Y)
! schließ X zu/ab [mit Y] → Lock X (with Y)
! schließ X              → Close X
Verb 'schliess' 'schließ' 'zumach'
	* noun 'auf' 'mit' held                     -> Unlock
	* noun 'mit' held 'auf'                     -> Unlock
	* noun 'auf'                                -> Unlock
	* noun 'zu'/'ab' 'mit' held                 -> Lock
	* noun 'mit' held 'zu'/'ab'                 -> Lock
	* noun 'zu'/'ab'                            -> Lock
	* noun                                      -> Close;

! --- mach (multi-purpose German verb: mach auf/zu/an/aus) ---
! TODO: mach X auf = open X; mach X zu = close X; mach X an = switch on; mach X aus = switch off
Verb 'mach'
	* noun 'auf'                                -> Open
	* noun 'zu'                                 -> Close
	* noun 'an'                                 -> SwitchOn
	* noun 'aus'                                -> SwitchOff
	* noun 'kaputt'                             -> Attack
	* 'auf' noun                                -> Open
	* 'zu' noun                                 -> Close
	* 'an' noun                                 -> SwitchOn
	* 'aus' noun                                -> SwitchOff;

! --- Inventory ---
! TODO: inventar, besitz, inv = inventory
Verb 'inventar' 'besitz' 'zeig_i'
	*                                           -> Inv;

! --- Wait ---
! TODO: warte = wait
Verb 'warte'
	*                                           -> Wait;

! --- Go ---
! TODO: geh, lauf, renn, wander = go/walk
#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'geh' 'lauf' 'renn' 'wander' 'fluecht'
	* noun=ADirection                           -> Go
	* 'nach' noun=ADirection                    -> Go
	* noun                                      -> Enter
	* 'in' noun                                 -> Enter
	* 'raus'/'hinaus'/'heraus'                  -> Exit
	* 'rein'/'hinein'/'herein'                  -> GoIn;
#IfNot;
Verb 'geh' 'lauf' 'renn' 'wander' 'fluecht'
	* noun=ADirection                           -> Go
	* 'nach' noun=ADirection                    -> Go
	* noun                                      -> Enter
	* 'in' noun                                 -> Enter
	* 'raus'/'hinaus'/'heraus'                  -> Exit;
#EndIf;

Verb 'verlass'
	*                                           -> Exit
	* noun                                      -> Exit;

Verb 'betreten' 'betret'
	* noun                                      -> Enter;

! --- Give / Show ---
! TODO: gib, reich = give; zeig, praesentier = show
Verb 'gib' 'reich' 'uebertrag'
	* held 'an' creature                        -> Give
	* held creature                             -> Give
	* creature held                             -> Give reverse;

Verb 'zeig' 'praesentier'
	* creature held                             -> Show reverse
	* held creature                             -> Show
	* held 'an' creature                        -> Show
	* creature held 'vor'                       -> Show reverse;

! --- Put in / Put on / Drop ---
! TODO: leg, stell, steck = put; stell auf = put on; leg in = put in; leg ab = drop
Verb 'leg' 'lege' 'stell' 'steck' 'tu'
	* multiheld                                 -> Drop
	* multiheld 'ab'/'hin'/'weg'/'nieder'       -> Drop
	* multiexcept 'in'/'hinein' noun            -> Insert
	* multiexcept 'auf' noun                    -> PutOn
	* multiexcept noun                          -> Insert
	* 'an' held                                 -> Wear;

! --- Wear ---
! TODO: anzieh = put on (clothing); zieh an = put on (clothing)
Verb 'anzieh' 'trag'
	* held                                      -> Wear;

! --- Disrobe ---
! TODO: auszieh = take off (clothing)
Verb 'auszieh'
	* held                                      -> Disrobe;

! --- zieh (ambiguous: zieh X an = wear; zieh X aus = disrobe; zieh = pull) ---
! TODO: zieh X an/aus/weg = wear/disrobe/pull
Verb 'zieh' 'zupf'
	* worn 'aus'                                -> Disrobe
	* held 'an'                                 -> Wear
	* noun 'an'                                 -> Pull
	* noun                                      -> Pull;

! --- Ask / Tell ---
! TODO: frag = ask; erzaehl, sag = tell/say
Verb 'frag'
	* creature 'nach' topic                     -> Ask
	* creature 'fuer'/'um' noun                 -> AskFor
	* creature 'zu' topic                       -> AskTo;

Verb 'erzaehl' 'erz' 'berichtige'
	* creature 'ueber' topic                    -> Tell
	* creature 'von' topic                      -> Tell;

Verb 'sag' 'sprech' 'antworte'
	* topic 'zu' creature                       -> Answer
	* topic 'an' creature                       -> Answer
	* creature topic                            -> Tell;

! --- Drink ---
! TODO: trink = drink; sauf = drink (colloquial)
Verb 'trink' 'sauf'
	* noun                                      -> Drink;

! --- Eat ---
! TODO: iss = eat; fris = eat (animal/rude)
Verb 'iss' 'fris'
	* held                                      -> Eat;

! --- Listen ---
! TODO: hoer, lausch = listen
Verb 'hoer' 'lausch'
	*                                           -> Listen
	* 'auf' noun                                -> Listen
	* noun                                      -> Listen;

! --- Smell ---
! TODO: rieche, schnupfer = smell
Verb 'rieche' 'schnupfer'
	*                                           -> Smell
	* noun                                      -> Smell;

! --- Touch / Feel ---
! TODO: beruehr, fuehle, tast = touch/feel
Verb 'beruehr' 'fuehle' 'tast'
	* noun                                      -> Touch;

! --- Search ---
! TODO: durchsuche, such = search
Verb 'durchsuche' 'such'
	* noun                                      -> Search
	* 'in' noun                                 -> Search;

! --- Read ---
! TODO: lies, les = read
Verb 'lies' 'les'
	* noun                                      -> Examine;

! --- Lock / Unlock ---
! TODO: schliess ab, abschliess = lock; oeffne ab, aufschliess = unlock
Verb 'abschliess' 'verriegel'
	* noun 'mit' held                           -> Lock
	* noun                                      -> Lock;

Verb 'aufschliess' 'entriegele' 'entsperr'
	* noun 'mit' held                           -> Unlock
	* noun                                      -> Unlock;

! --- Switch on/off ---
! TODO: schalte X an = switch on; schalte X aus = switch off
Verb 'schalte' 'druck'
	* noun 'an'                                 -> SwitchOn
	* noun 'aus'                                -> SwitchOff
	* 'an' noun                                 -> SwitchOn
	* 'aus' noun                                -> SwitchOff;

! --- Attack ---
! TODO: hau, schlag, tritt, greif an = attack
Verb 'hau' 'schlag' 'tritt' 'toete' 'zerstoer' 'kaputt' 'erschlag'
	* noun                                      -> Attack
	* noun 'mit' held                           -> Attack;

! --- Climb ---
! TODO: kletter, steig = climb
Verb 'kletter' 'steig'
	* noun                                      -> Climb
	* 'hoch' noun                               -> Climb
	* noun 'hoch'                               -> Climb
	* 'auf' noun                                -> Enter;

! --- Jump ---
! TODO: spring = jump
Verb 'spring'
	*                                           -> Jump
	* 'ueber' noun                              -> JumpOver
	* 'in'/'auf' noun                           -> Enter;

! --- Push / Pull / Turn ---
! TODO: schieb, drueck, stoss = push; zieh_an, zupf = pull; dreh = turn
Verb 'schieb' 'drueck' 'stoss'
	* noun                                      -> Push
	* noun noun=ADirection                      -> PushDir;

Verb 'dreh' 'kurbel'
	* noun                                      -> Turn
	* noun 'an'                                 -> SwitchOn
	* noun 'aus'                                -> SwitchOff;

! --- Dig ---
! TODO: graeb, schaufle = dig
Verb 'graeb' 'schaufle'
	* noun                                      -> Dig
	* noun 'mit' held                           -> Dig;

! --- Fill ---
! TODO: fuell = fill
Verb 'fuell'
	* noun                                      -> Fill;

! --- Cut ---
! TODO: schneide, hack = cut
Verb 'schneide' 'hack'
	* noun                                      -> Cut
	* noun 'mit' held                           -> Attack;

! --- Tie ---
! TODO: binde, befestige = tie/attach
Verb 'binde' 'befestige' 'befestig'
	* noun                                      -> Tie
	* noun 'an' noun                            -> Tie;

! --- Shout ---
! TODO: schreie, ruf, bruell = shout
Verb 'schreie' 'ruf' 'bruell' 'schrei'
	* topic 'zu'/'an' creature                  -> Answer
	* 'zu'/'an' noun                            -> ShoutAt
	* topic                                     -> Shout
	*                                           -> Shout;

! --- Rub / Clean ---
! TODO: reib, putz, wisch = rub/clean
Verb 'reib' 'putz' 'wisch' 'polier'
	* noun                                      -> Rub;

! --- Squeeze (only in extended verbset) ---
! TODO: drueck_an, quetsch = squeeze
#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'quetsch' 'presse'
	* noun                                      -> Squeeze;
#EndIf;

! --- Sit / Stand / Lie ---
! TODO: setz, sitz = sit; steh = stand; lieg = lie down
Verb 'setz' 'sitz'
	* 'auf' noun                                -> Enter
	* 'in' noun                                 -> Enter;

Verb 'steh'
	*                                           -> Exit
	* 'auf'                                     -> Exit
	* 'auf' 'von' noun                          -> GetOff;

Verb 'lieg'
	* 'auf' noun                                -> Enter;

! --- Yes / No ---
! TODO: ja = yes; nein = no
! Note: 'ja', 'j//' and 'nein' are added to the dictionary via parser.h (YesOrNo function),
! so they work as answers to yes/no prompts even without OPTIONAL_EXTENDED_VERBSET.
#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'ja' 'j//'
	*                                           -> Yes;
Verb 'nein'
	*                                           -> No;
#EndIf;

! --- Transfer (push to location) ---
! TODO: bring, trag = bring/carry to
Verb 'bring' 'trag_zu'
	* noun noun=ADirection                      -> PushDir;

#Ifdef OPTIONAL_EXTENDED_VERBSET;
! --- Extended verbset German synonyms ---
! TODO: Review these optional verb translations

! Burn
Verb 'verbrenn' 'zuend' 'entzuend'
	* noun                                      -> Burn
	* noun 'mit' held                           -> Burn;

! Buy
Verb 'kauf' 'erwirb'
	* noun                                      -> Buy;

! Consult
Verb 'schlage_nach' 'konsultier' 'such_in'
	* noun 'nach' topic                         -> Consult
	* 'in' noun 'nach' topic                    -> Consult reverse;

! Empty
Verb 'leer' 'schuette' 'leere'
	* noun                                      -> Empty
	* noun 'aus'                                -> Empty;

! Kiss
Verb 'kuss' 'umarm' 'kuess'
	* noun                                      -> Kiss;

! Pray
Verb 'bet'
	*                                           -> Pray;

! Set / Adjust
Verb 'stell_ein' 'einstell' 'regelein'
	* noun                                      -> Set
	* noun 'auf' topic                          -> SetTo;

! Sing
Verb 'sing'
	*                                           -> Sing;

! Sleep
Verb 'schlaf'
	*                                           -> Sleep;

! Sorry
Verb 'entschuldige' 'verzeih'
	*                                           -> Sorry;

! Swim
Verb 'schwimm' 'tauch'
	*                                           -> Swim;

! Swing
Verb 'schaukel' 'schaukelauf'
	* noun                                      -> Swing;

! Taste
Verb 'probiere' 'koste' 'schmeck'
	* noun                                      -> Taste;

! Think
Verb 'denk' 'nachdenk' 'ueberlege'
	*                                           -> Think;

! Transfer
Verb 'transportier' 'bring_zu' 'zuweise'
	* noun 'zu'/'an' noun                       -> Transfer;

! Wake
Verb 'weck' 'wach'
	*                                           -> Wake
	* noun                                      -> WakeOther;

! Wave
Verb 'wink' 'schwenk'
	*                                           -> WaveHands
	* noun                                      -> Wave;

! Blow
Verb 'blase' 'blow'
	* noun                                      -> Blow;

! Strong/Mild language - German expletives
Verb 'mist' 'scheiße' 'verflucht' 'merde'
	*                                           -> Mild;
#EndIf; ! OPTIONAL_EXTENDED_VERBSET
