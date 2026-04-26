! Part of PunyInformDE: Deutsche Artikeltabellen und Druckfunktionen.
!
! Dieses Modul implementiert §1 der Grammatikanalyse: korrekte Artikel
! für alle drei Kasus (Nominativ, Akkusativ, Dativ) und alle vier
! grammatischen Geschlechter (maskulin, feminin, Neutrum, Plural).
!
! === Für Spieleautoren ===
!
! Nach diesem Modul braucht kein Objekt mehr "with article ..." zu
! deklarieren, solange es has female, has neuter oder den Standard
! (maskulin) verwendet. Die Tabelle liefert automatisch den richtigen
! Artikel für alle Kasus:
!
!   Object -> Kiste "Seekiste"          ! hat female → Artikel "eine/einer/die/der..."
!       ...
!       has female, container, openable;   ! kein article: Eigenschaft nötig
!
!   Object -> Schlüssel "kleiner Schlüssel"   ! kein female/neuter → maskulin
!       ...                                   ! kein article: Eigenschaft nötig
!
! Nur bei Ausnahmen wird article gesetzt:
!
!   Object Sonne "Sonne"
!       with article 0,   ! Kein unbestimmter Artikel ("die Sonne", nie "eine Sonne")
!       has female;
!
!   Object Hotel "Hotel"
!       with article "so ein",   ! Ungewöhnliche Form
!       has neuter;
!
! === Für Nachrichten in messages_de.h ===
!
! Verwende folgende Druckfunktionen für grammatisch korrekte Kasus:
!
!   (DE_Der) obj    Nominativ bestimmt   : "der/die/das/die Schlüssel"
!   (DE_Den) obj    Akkusativ bestimmt   : "den/die/das/die Schlüssel"
!   (DE_Dem) obj    Dativ bestimmt       : "dem/der/dem/den Schlüssel"
!   (DE_Ein) obj    Nominativ unbestimmt : "ein/eine/ein/einige Schlüssel"
!   (DE_Einen) obj  Akkusativ unbestimmt : "einen/eine/ein/einige Schlüssel"
!   (DE_Einem) obj  Dativ unbestimmt     : "einem/einer/einem/einigen Schlüssel"
!
! Die (the)/(The) und (a)/(A) Formatzeiger bleiben für Nominativ erhalten.
!
! === Speicherbedarf ===
! DE_DefArticles:   12 Einträge × 2 Bytes = 24 Bytes (Zeiger auf Strings)
! DE_IndefArticles: 12 Einträge × 2 Bytes = 24 Bytes
! Stringliterale: ca. 60 Bytes (geteilt, da Inform kurze Strings optimiert)
!
System_file;

! ---------------------------------------------------------------------------
! DE_Gender -- grammatisches Geschlecht eines Objekts ermitteln.
!
! Gibt zurück:
!   0 = maskulin  (Standard, wenn weder has female noch has neuter)
!   1 = feminin   (has female)
!   2 = Neutrum   (has neuter)
!   3 = Plural    (has pluralname)
! ---------------------------------------------------------------------------
[ DE_Gender p_obj;
    if (p_obj has pluralname) return 3;
    if (p_obj has female)     return 1;
    if (p_obj has neuter)     return 2;
    return 0;  ! maskulin (Standard)
];

! ---------------------------------------------------------------------------
! Bestimmte Artikel: der/die/das/die  (Nominativ/Akkusativ/Dativ × 4 Geschlechter)
!
! Index: case * 4 + gender
!   case:   0 = Nominativ   1 = Akkusativ   2 = Dativ
!   gender: 0 = mask.       1 = fem.        2 = Neut.   3 = Plural
!
!           mask.   fem.    Neut.   Plural
! ---------------------------------------------------------------------------
Array DE_DefArticles -->
    "der"  "die"  "das"  "die"    ! Nominativ (Index 0..3)
    "den"  "die"  "das"  "die"    ! Akkusativ (Index 4..7)
    "dem"  "der"  "dem"  "den"    ! Dativ     (Index 8..11)
;

! ---------------------------------------------------------------------------
! Unbestimmte Artikel: ein/eine/ein/- (Nominativ/Akkusativ/Dativ × 4 Geschlechter)
!
! Plural: 0 = kein unbestimmter Artikel (wird separat behandelt).
!
!           mask.     fem.      Neut.     Plural
! ---------------------------------------------------------------------------
Array DE_IndefArticles -->
    "ein"    "eine"   "ein"    0        ! Nominativ (Index 0..3)
    "einen"  "eine"   "ein"    0        ! Akkusativ (Index 4..7)
    "einem"  "einer"  "einem"  0        ! Dativ     (Index 8..11)
;

! ---------------------------------------------------------------------------
! _DE_IndefArtStr -- gibt den richtigen unbestimmten Artikel als String zurück,
!   unter Berücksichtigung einer optionalen article-Override-Eigenschaft.
!
!   Gibt 0 zurück wenn kein Artikel gedruckt werden soll.
!   Gibt -1 zurück wenn der Plural-Fallback "einige"/"einigen" verwendet wird.
!   Sonst: Zeiger auf Artikelstring.
!
! p_case: 0=Nom, 1=Akk, 2=Dat
! p_plural_dative: true → Plural-Fallback ist "einigen" (Dativ)
! ---------------------------------------------------------------------------
[ _DE_IndefArtStr p_obj p_case p_plural_dative   g s;
    ! Override: article 0 → kein Artikel
    if (p_obj.&article && p_obj.article == 0) return 0;
    ! Override: article "string" → Legacy-Eigenschaft, nur für Nominativ
    if (p_obj.&article && p_obj.article ofclass String) return p_obj.article;
    g = DE_Gender(p_obj);
    ! Plural: kein unbestimmter Artikel → "einige"/"einigen"
    if (g == 3) {
        if (p_plural_dative) return -2;  ! signal: print "einigen"
        return -1;                        ! signal: print "einige"
    }
    s = DE_IndefArticles-->(p_case * 4 + g);
    return s;
];

! ---------------------------------------------------------------------------
! _DE_PrintIndefWithName -- Hilfsfunktion: unbestimmten Artikel + Name drucken.
! p_case: 0=Nom, 1=Akk, 2=Dat
! ---------------------------------------------------------------------------
[ _DE_PrintIndefWithName p_obj p_case   s;
    s = _DE_IndefArtStr(p_obj, p_case, (p_case == 2));
    if (s == 0) {
        ! Kein Artikel
        PrintShortName(p_obj);
        return;
    }
    if (s == -1) { print "einige ";   PrintShortName(p_obj); return; }
    if (s == -2) { print "einigen ";  PrintShortName(p_obj); return; }
    print (string) s; print " ";
    PrintShortName(p_obj);
];

! ---------------------------------------------------------------------------
! Bestimmte Artikel + Name (Druckfunktionen für Spielnachrichten)
! ---------------------------------------------------------------------------

! Nominativ bestimmt: "der Schlüssel / die Kiste / das Fernrohr / die Münzen"
! (entspricht (the) in Nominativ-Position)
[ DE_Der p_obj;
    print (string) DE_DefArticles-->(DE_Gender(p_obj)); print " ";
    PrintShortName(p_obj);
];

! Akkusativ bestimmt: "den Schlüssel / die Kiste / das Fernrohr / die Münzen"
[ DE_Den p_obj;
    print (string) DE_DefArticles-->(4 + DE_Gender(p_obj)); print " ";
    PrintShortName(p_obj);
];

! Dativ bestimmt: "dem Schlüssel / der Kiste / dem Fernrohr / den Münzen"
[ DE_Dem p_obj;
    print (string) DE_DefArticles-->(8 + DE_Gender(p_obj)); print " ";
    PrintShortName(p_obj);
];

! ---------------------------------------------------------------------------
! Unbestimmte Artikel + Name (Druckfunktionen für Spielnachrichten)
! ---------------------------------------------------------------------------

! Nominativ unbestimmt: "ein Schlüssel / eine Kiste / ein Fernrohr / einige Münzen"
[ DE_Ein p_obj;
    _DE_PrintIndefWithName(p_obj, 0);
];

! Akkusativ unbestimmt: "einen Schlüssel / eine Kiste / ein Fernrohr / einige Münzen"
[ DE_Einen p_obj;
    _DE_PrintIndefWithName(p_obj, 1);
];

! Dativ unbestimmt: "einem Schlüssel / einer Kiste / einem Fernrohr / einigen Münzen"
[ DE_Einem p_obj;
    _DE_PrintIndefWithName(p_obj, 2);
];

! ---------------------------------------------------------------------------
! _DE_SubstitutePronouns — §2 Pronomenersetzung (Pass 3 von BeforeParsing).
!
! Hinweis: Diese Funktion ist hier (article_de.h) definiert, nicht in
! parser_de.h, weil sie auf die globalen Variablen herobj/himobj/itobj/themobj
! zugreift. Diese werden erst am Ende von globals.h deklariert, also NACHDEM
! parser_de.h eingebunden wurde. article_de.h wird hingegen von puny.h
! eingebunden, das nach globals.h eingebunden wird — die Variablen sind
! daher hier bereits bekannt.
!
! BeforeParsing (in parser_de.h) ruft _DE_SubstitutePronouns() auf;
! Inform 6 löst Vorwärts-Funktionsreferenzen auf.
!
! Unterstützte Ersetzungen:
!   "er"    (2 Bytes) → "him"   (3 Bytes)  Maskulin Nominativ/Subjekt
!   "ihn"   (3 Bytes) → "him"   (3 Bytes)  Maskulin Akkusativ (in-place)
!   "ihm"   (3 Bytes) → "him"   (3 Bytes)  Maskulin Dativ     (in-place)
!   "sie"   (3 Bytes) → "her"   (3 Bytes)  Feminin  (wenn herobj gesetzt)
!   "sie"   (3 Bytes) → "them"  (4 Bytes)  Plural   (wenn nur themobj gesetzt)
!   "es"    (2 Bytes) → "it"    (2 Bytes)  Neutrum  (in-place)
!   "ihnen" (5 Bytes) → "them"  (4 Bytes)  Dativ Plural (schrumpft um 1)
!
! Nicht ersetzt: "ihr" (Possessivpronomen, mehrdeutig)
!
! Rückgabe: true wenn Ersetzungen vorgenommen wurden, sonst false.
! ---------------------------------------------------------------------------
[ _DE_SubstitutePronouns   _nwords _i _waddr _woff _wlen _blen _j _changed;
    _nwords  = parse->1;
    _changed = false;
    ! Von rechts nach links: Pufferverschiebungen bei früheren Wörtern bleiben gültig
    for (_i = _nwords : _i >= 1 : _i--) {
        if (parse-->(_i + _i - 1) ~= 0) continue;  ! Wort im Wörterbuch → überspringen
        _waddr = WordAddress(_i);
        _wlen  = WordLength(_i);
        _blen  = buffer->1;
        _woff  = _waddr - buffer;  ! Byte-Offset ab Pufferanfang (inkl. 2-Byte-Header)

        ! --- "es" (2 Bytes) → "it" (2 Bytes): in-place ---
        if (_wlen == 2 && _waddr->0 == 'e' && _waddr->1 == 's') {
            buffer->_woff       = 'i';
            buffer->(_woff + 1) = 't';
            _changed = true;
            continue;
        }

        ! --- "er" (2 Bytes) → "him" (3 Bytes): Puffer 1 Byte nach rechts verschieben ---
        if (_wlen == 2 && _waddr->0 == 'e' && _waddr->1 == 'r') {
            if (_blen >= buffer->0) continue;  ! Pufferüberlauf verhindern
            for (_j = _blen + 1 : _j >= _woff + 2 : _j--)
                buffer->(_j + 1) = buffer->_j;
            buffer->_woff       = 'h';
            buffer->(_woff + 1) = 'i';
            buffer->(_woff + 2) = 'm';
            buffer->1 = _blen + 1;
            _changed = true;
            continue;
        }

        ! --- "ihn" (3 Bytes) → "him" (3 Bytes): in-place ---
        if (_wlen == 3 && _waddr->0 == 'i' && _waddr->1 == 'h' && _waddr->2 == 'n') {
            buffer->_woff       = 'h';
            buffer->(_woff + 1) = 'i';
            buffer->(_woff + 2) = 'm';
            _changed = true;
            continue;
        }

        ! --- "ihm" (3 Bytes) → "him" (3 Bytes): in-place (i↔h tauschen) ---
        if (_wlen == 3 && _waddr->0 == 'i' && _waddr->1 == 'h' && _waddr->2 == 'm') {
            buffer->_woff       = 'h';
            buffer->(_woff + 1) = 'i';
            buffer->(_woff + 2) = 'm';
            _changed = true;
            continue;
        }

        ! --- "sie" (3 Bytes) → "her" (3 Bytes) oder "them" (4 Bytes) ---
        if (_wlen == 3 && _waddr->0 == 's' && _waddr->1 == 'i' && _waddr->2 == 'e') {
            if (herobj ~= 0) {
                ! Feminin: "sie" → "her" (in-place, beide 3 Bytes)
                buffer->_woff       = 'h';
                buffer->(_woff + 1) = 'e';
                buffer->(_woff + 2) = 'r';
                _changed = true;
            } else if (themobj ~= 0) {
                ! Plural: "sie" → "them" (3→4 Bytes, 1 Byte rechts verschieben)
                if (_blen >= buffer->0) continue;
                for (_j = _blen + 1 : _j >= _woff + 3 : _j--)
                    buffer->(_j + 1) = buffer->_j;
                buffer->_woff       = 't';
                buffer->(_woff + 1) = 'h';
                buffer->(_woff + 2) = 'e';
                buffer->(_woff + 3) = 'm';
                buffer->1 = _blen + 1;
                _changed = true;
            }
            ! Weder herobj noch themobj gesetzt: "sie" unverändert lassen
            continue;
        }

        ! --- "ihnen" (5 Bytes) → "them" (4 Bytes): überschreiben + 1 Byte links ---
        if (_wlen == 5 && _waddr->0 == 'i' && _waddr->1 == 'h' &&
                          _waddr->2 == 'n' && _waddr->3 == 'e' && _waddr->4 == 'n') {
            buffer->_woff       = 't';
            buffer->(_woff + 1) = 'h';
            buffer->(_woff + 2) = 'e';
            buffer->(_woff + 3) = 'm';
            ! Bytes nach "ihnen" um 1 nach links schieben
            for (_j = _woff + 4 : _j <= _blen : _j++)
                buffer->_j = buffer->(_j + 1);
            buffer->1 = _blen - 1;
            _changed = true;
            continue;
        }
    }
    return _changed;
];
