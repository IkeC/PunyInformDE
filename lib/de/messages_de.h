! Part of PunyInformDE: German localisation of PunyInform.
! This file replaces messages.h with German translations.
!
! Note: Zcharacter declarations for German special characters are in globals.h.
!
System_file;

!
! Simple string messages
!

#Ifndef MSG_TAKE_YOURSELF;
Constant MSG_TAKE_YOURSELF "Selbstverliebt wie immer.";
#EndIf;
#Ifndef MSG_TAKE_NO_CAPACITY;
Constant MSG_TAKE_NO_CAPACITY "Mehr kannst du nicht tragen.";
#EndIf;
#Ifndef MSG_TAKE_DEFAULT;
Default MSG_TAKE_DEFAULT = 1000;
Constant _MSG_TAKE_DEFAULT_HAS_CASE = 1; ! internal: include the switch case below
#EndIf;
#Ifndef MSG_DRINK_NOTHING_SUITABLE;
Constant MSG_DRINK_NOTHING_SUITABLE "Hier gibt es nichts zu trinken.";
#EndIf;
#Ifndef MSG_DROP_DROPPED;
Constant MSG_DROP_DROPPED "In Ordnung.";
#EndIf;
#Ifndef MSG_THROW_ANIMATE;
Constant MSG_THROW_ANIMATE "Sinnlos.";
#Endif;
#Ifndef MSG_THROW_DEFAULT;
Constant MSG_THROW_DEFAULT "Im entscheidenden Moment versagen dir die Nerven.";
#Endif;
#Ifndef MSG_SMELL_DEFAULT;
Constant MSG_SMELL_DEFAULT "Du riechst nichts Unerwartetes.";
#Endif;
#Ifndef MSG_LISTEN_DEFAULT;
Constant MSG_LISTEN_DEFAULT "Du hörst nichts Unerwartetes.";
#Endif;
#Ifndef MSG_TELL_PLAYER;
Constant MSG_TELL_PLAYER "Du redest ein Weilchen mit dir selbst.";
#Endif;
#Ifndef MSG_TELL_DEFAULT;
Constant MSG_TELL_DEFAULT "Keine Reaktion.";
#Endif;
#Ifndef MSG_ENTER_ALREADY;
Constant MSG_ENTER_ALREADY "Aber du bist schon da!";
#Endif;
#Ifndef MSG_EXIT_ALREADY;
Constant MSG_EXIT_ALREADY "Aber du bist im Moment in nichts drin!";
#Endif;
#Ifndef MSG_EXIT_NOT_ON;
Constant MSG_EXIT_NOT_ON "Du bist da nicht drauf.";
#Endif;
#Ifndef MSG_EXIT_NOT_IN;
Constant MSG_EXIT_NOT_IN "Du bist da nicht drin.";
#Endif;
#Ifndef MSG_INVENTORY_EMPTY;
Constant MSG_INVENTORY_EMPTY "Du hast nichts.";
#Endif;
#Ifndef MSG_GO_CANT_GO;
Constant MSG_GO_CANT_GO "Da kannst du nicht hingehen.";
#Endif;
#Ifndef MSG_SAVE_DEFAULT;
Constant MSG_SAVE_DEFAULT "Ok.";
#Endif;
#Ifndef MSG_INSERT_ITSELF;
Constant MSG_INSERT_ITSELF "Man kann nichts in sich selbst hineinlegen.";
#Endif;
#Ifndef MSG_PUTON_ITSELF;
Constant MSG_PUTON_ITSELF "Man kann nicht etwas auf sich selbst stellen.";
#Endif;
#Ifndef MSG_ATTACK_DEFAULT;
Constant MSG_ATTACK_DEFAULT "Gewalt ist in diesem Fall nicht die Antwort.";
#Endif;
#Ifndef MSG_FILL_NO_WATER;
Constant MSG_FILL_NO_WATER "Aber hier gibt es kein Wasser zum Tragen.";
#EndIf;
#Ifndef MSG_DIG_NO_USE;
Constant MSG_DIG_NO_USE "Graben bringt hier nichts.";
#EndIf;
#Ifndef MSG_WAIT_DEFAULT;
Constant MSG_WAIT_DEFAULT "Nichts passiert.";
#EndIf;
#Ifndef MSG_TOUCH_DEFAULT;
Constant MSG_TOUCH_DEFAULT "Du ertastest nichts Unerwartetes.";
#EndIf;
#Ifndef MSG_PUSHDIR_DEFAULT;
Constant MSG_PUSHDIR_DEFAULT "Ist das das Beste, was dir einfällt?";
#EndIf;
#Ifndef MSG_JUMP;
Constant MSG_JUMP "Du springst auf der Stelle.";
#EndIf;
#Ifndef MSG_REMOVE_DEFAULT;
Constant MSG_REMOVE_DEFAULT "Entfernt.";
#EndIf;
#Ifndef MSG_SEARCH_NOTHING_SPECIAL;
Constant MSG_SEARCH_NOTHING_SPECIAL "Du findest nichts Besonderes.";
#EndIf;
#Ifndef MSG_OOPS_DEFAULT;
Constant MSG_OOPS_DEFAULT "Denk dir nichts dabei.";
#EndIf;
#Ifndef MSG_PARSER_ONLY_TO_ANIMATE;
Constant MSG_PARSER_ONLY_TO_ANIMATE "Das kann man nur mit etwas Lebendigem machen.";
#EndIf;
#Ifndef MSG_PARSER_NOT_MULTIPLE_VERB;
Constant MSG_PARSER_NOT_MULTIPLE_VERB "Man kann mit diesem Verb nicht mehrere Objekte verwenden.";
#EndIf;
#Ifndef MSG_PARSER_NOT_MULTIPLE_DIRS;
Constant MSG_PARSER_NOT_MULTIPLE_DIRS "Du kannst nicht mehrere Richtungen verwenden.";
#EndIf;
#Ifndef MSG_PARSER_BAD_NUMBER;
Constant MSG_PARSER_BAD_NUMBER "Ich habe diese Zahl nicht verstanden.";
#EndIf;
#Ifndef MSG_PARSER_NO_INPUT;
Constant MSG_PARSER_NO_INPUT "Wie bitte?";
#EndIf;
#Ifndef MSG_PARSER_UNKNOWN_SENTENCE;
Constant MSG_PARSER_UNKNOWN_SENTENCE "Ich verstehe diesen Satz nicht.";
#EndIf;
#Ifndef MSG_PARSER_UNKNOWN_VERB;
Constant MSG_PARSER_UNKNOWN_VERB "Dieses Verb kenne ich nicht.";
#EndIf;
#Ifndef MSG_PARSER_CANT_DISAMBIGUATE;
Constant MSG_PARSER_CANT_DISAMBIGUATE "Ich verstehe immer noch nicht, worauf du anspielst.";
#EndIf;
#Ifndef MSG_PARSER_UNKNOWN_PERSON;
Constant MSG_PARSER_UNKNOWN_PERSON "Ich kann nicht erkennen, auf wen du dich beziehst.";
#EndIf;
#Ifndef MSG_PARSER_CANT_OOPS;
Constant MSG_PARSER_CANT_OOPS "Tut mir leid, das kann nicht korrigiert werden.";
#EndIf;
#Ifndef MSG_PARSER_COMPLEX_AGAIN;
Constant MSG_PARSER_COMPLEX_AGAIN "Der Befehl 'erneut' muss in einer neuen Eingabezeile stehen.^";
#EndIf;
#Ifndef MSG_PARSER_NOTHING_TO_AGAIN;
Constant MSG_PARSER_NOTHING_TO_AGAIN "Das kannst du kaum wiederholen.";
#EndIf;
#Ifndef MSG_PARSER_BE_MORE_SPECIFIC;
Constant MSG_PARSER_BE_MORE_SPECIFIC "Du musst genauer sein.";
#EndIf;
#Ifndef MSG_PARSER_NO_MULTIPLES_FOR_NPC;
Constant MSG_PARSER_NO_MULTIPLES_FOR_NPC "Du kannst nur auf einzelne Objekte verweisen, wenn du mit anderen redest.";
#EndIf;
#IfnDef OPTIONAL_NO_DARKNESS;
#IfnDef MSG_NOW_DARK;
Constant MSG_NOW_DARK "^Es ist nun stockdunkel hier.";
#EndIf;
#EndIf;

#IfDef OPTIONAL_FULL_SCORE;
#IfDef OPTIONAL_SCORED;
#Ifndef MSG_FULLSCORE_OBJECTS;
Constant MSG_FULLSCORE_OBJECTS "finde diverse Objekte";
#EndIf;
#Ifndef MSG_FULLSCORE_ROOMS;
Constant MSG_FULLSCORE_ROOMS "besuch verschiedene Orte";
#EndIf;
#EndIf;
#Ifndef MSG_FULLSCORE_ACTIONS;
Constant MSG_FULLSCORE_ACTIONS "mache bemerkenswerte Aktionen";
#EndIf;
#EndIf;

!
! complex messages (enumerated)
!

! Note, we can only use id 2-999
#Ifndef MSG_CLOSE_YOU_CANT;
Default MSG_CLOSE_YOU_CANT = 2;
Constant _MSG_CLOSE_YOU_CANT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_ENTER_YOU_CANT;
Default MSG_ENTER_YOU_CANT = 3;
Constant _MSG_ENTER_YOU_CANT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_EXAMINE_NOTHING_SPECIAL;
Default MSG_EXAMINE_NOTHING_SPECIAL = 4;
Constant _MSG_EXAMINE_NOTHING_SPECIAL_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TAKE_ANIMATE;
Default MSG_TAKE_ANIMATE = 5;
Constant _MSG_TAKE_ANIMATE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TAKE_PLAYER_PARENT;
Default MSG_TAKE_PLAYER_PARENT = 6;
Constant _MSG_TAKE_PLAYER_PARENT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_EAT_ANIMATE;
Default MSG_EAT_ANIMATE = 7;
Constant _MSG_EAT_ANIMATE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_DROP_NOT_HOLDING;
Default MSG_DROP_NOT_HOLDING = 8;
Constant _MSG_DROP_NOT_HOLDING_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_OPEN_DEFAULT;
Default MSG_OPEN_DEFAULT = 9;
Constant _MSG_OPEN_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_CLOSE_DEFAULT;
Default MSG_CLOSE_DEFAULT = 10;
Constant _MSG_CLOSE_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_LOOK_BEFORE_ROOMNAME;
Default MSG_LOOK_BEFORE_ROOMNAME  = 11;
Constant _MSG_LOOK_BEFORE_ROOMNAME_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SHOW_NOT_HOLDING;
Default MSG_SHOW_NOT_HOLDING = 12;
Constant _MSG_SHOW_NOT_HOLDING_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SHOW_DEFAULT;
Default MSG_SHOW_DEFAULT = 13;
Constant _MSG_SHOW_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_GIVE_NOT_HOLDING;
Default MSG_GIVE_NOT_HOLDING = 14;
Constant _MSG_GIVE_NOT_HOLDING_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_GIVE_DEFAULT;
Default MSG_GIVE_DEFAULT = 15;
Constant _MSG_GIVE_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_ASKFOR_DEFAULT;
Default MSG_ASKFOR_DEFAULT = 16;
Constant _MSG_ASKFOR_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_ASKTO_DEFAULT;
Default MSG_ASKTO_DEFAULT = 17;
Constant _MSG_ASKTO_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_ENTER_DEFAULT;
Default MSG_ENTER_DEFAULT = 18;
Constant _MSG_ENTER_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_EXIT_FIRST_LEAVE;
Default MSG_EXIT_FIRST_LEAVE = 19;
Constant _MSG_EXIT_FIRST_LEAVE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_ENTER_NOT_OPEN;
Default MSG_ENTER_NOT_OPEN = 20;
Constant _MSG_ENTER_NOT_OPEN_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_EXIT_NOT_OPEN;
Default MSG_EXIT_NOT_OPEN = 21;
Constant _MSG_EXIT_NOT_OPEN_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_EXIT_DEFAULT;
Default MSG_EXIT_DEFAULT = 22;
Constant _MSG_EXIT_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_INVENTORY_DEFAULT;
Default MSG_INVENTORY_DEFAULT = 23;
Constant _MSG_INVENTORY_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_GO_FIRST_LEAVE;
Default MSG_GO_FIRST_LEAVE = 24;
Constant _MSG_GO_FIRST_LEAVE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_GIVE_PLAYER;
Default MSG_GIVE_PLAYER 25;
Constant _MSG_GIVE_PLAYER_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SAVE_FAILED;
Default MSG_SAVE_FAILED 26;
Constant _MSG_SAVE_FAILED_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_RESTORE_FAILED;
Default MSG_RESTORE_FAILED 27;
Constant _MSG_RESTORE_FAILED_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_RESTART_FAILED;
Default MSG_RESTART_FAILED 28;
Constant _MSG_RESTART_FAILED_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_INSERT_DEFAULT;
Default MSG_INSERT_DEFAULT 29;
Constant _MSG_INSERT_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_INSERT_NOT_OPEN;
Default MSG_INSERT_NOT_OPEN 30;
Constant _MSG_INSERT_NOT_OPEN_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_ASK_DEFAULT;
Default MSG_ASK_DEFAULT 31;
Constant _MSG_ASK_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_ANSWER_DEFAULT;
Default MSG_ANSWER_DEFAULT 32;
Constant _MSG_ANSWER_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_RESTART_RESTORE_OR_QUIT;
Default MSG_RESTART_RESTORE_OR_QUIT 33;
Constant _MSG_RESTART_RESTORE_OR_QUIT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_AREYOUSUREQUIT;
Default MSG_AREYOUSUREQUIT 34;
Constant _MSG_AREYOUSUREQUIT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_WEAR_ALREADY_WORN;
Default MSG_WEAR_ALREADY_WORN 35;
Constant _MSG_WEAR_ALREADY_WORN_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_WEAR_NOT_CLOTHING;
Default MSG_WEAR_NOT_CLOTHING 36;
Constant _MSG_WEAR_NOT_CLOTHING_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_WEAR_NOT_HOLDING;
Default MSG_WEAR_NOT_HOLDING 37;
Constant _MSG_WEAR_NOT_HOLDING_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_WEAR_DEFAULT;
Default MSG_WEAR_DEFAULT 38;
Constant _MSG_WEAR_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_INSERT_ALREADY;
Default MSG_INSERT_ALREADY 39;
Constant _MSG_INSERT_ALREADY_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_INSERT_NO_ROOM;
Default MSG_INSERT_NO_ROOM 40;
Constant _MSG_INSERT_NO_ROOM_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PUTON_ALREADY;
Default MSG_PUTON_ALREADY 41;
Constant _MSG_PUTON_ALREADY_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PUTON_NO_ROOM;
Default MSG_PUTON_NO_ROOM 42;
Constant _MSG_PUTON_NO_ROOM_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PUTON_DEFAULT;
Default MSG_PUTON_DEFAULT 43;
Constant _MSG_PUTON_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_GO_DOOR_CLOSED;
Default MSG_GO_DOOR_CLOSED 44;
Constant _MSG_GO_DOOR_CLOSED_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SWITCH_ON_NOT_SWITCHABLE;
Default MSG_SWITCH_ON_NOT_SWITCHABLE 45;
Constant _MSG_SWITCH_ON_NOT_SWITCHABLE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SWITCH_OFF_NOT_SWITCHABLE;
Default MSG_SWITCH_OFF_NOT_SWITCHABLE 46;
Constant _MSG_SWITCH_OFF_NOT_SWITCHABLE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SWITCH_ON_ON;
Default MSG_SWITCH_ON_ON 47;
Constant _MSG_SWITCH_ON_ON_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SWITCH_OFF_NOT_ON;
Default MSG_SWITCH_OFF_NOT_ON 48;
Constant _MSG_SWITCH_OFF_NOT_ON_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SWITCH_ON_DEFAULT;
Default MSG_SWITCH_ON_DEFAULT 49;
Constant _MSG_SWITCH_ON_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SWITCH_OFF_DEFAULT;
Default MSG_SWITCH_OFF_DEFAULT 50;
Constant _MSG_SWITCH_OFF_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PUSH_STATIC;
Default MSG_PUSH_STATIC 51;
Constant _MSG_PUSH_STATIC_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PULL_STATIC;
Default MSG_PULL_STATIC 52;
Constant _MSG_PULL_STATIC_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TURN_STATIC;
Default MSG_TURN_STATIC 53;
Constant _MSG_TURN_STATIC_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PUSH_SCENERY;
Default MSG_PUSH_SCENERY 54;
Constant _MSG_PUSH_SCENERY_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PULL_SCENERY;
Default MSG_PULL_SCENERY 55;
Constant _MSG_PULL_SCENERY_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TURN_SCENERY;
Default MSG_TURN_SCENERY 56;
Constant _MSG_TURN_SCENERY_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PUSH_ANIMATE;
Default MSG_PUSH_ANIMATE 57;
Constant _MSG_PUSH_ANIMATE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PULL_ANIMATE;
Default MSG_PULL_ANIMATE 58;
Constant _MSG_PULL_ANIMATE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TURN_ANIMATE;
Default MSG_TURN_ANIMATE 59;
Constant _MSG_TURN_ANIMATE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TURN_DEFAULT;
Default MSG_TURN_DEFAULT 60;
Constant _MSG_TURN_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PUSH_DEFAULT;
Default MSG_PUSH_DEFAULT 61;
Constant _MSG_PUSH_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PULL_DEFAULT;
Default MSG_PULL_DEFAULT 62;
Constant _MSG_PULL_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_YOU_HAVE_WON;
Default MSG_YOU_HAVE_WON 63;
Constant _MSG_YOU_HAVE_WON_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_YOU_HAVE_DIED;
Default MSG_YOU_HAVE_DIED 64;
Constant _MSG_YOU_HAVE_DIED_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_OPEN_YOU_CANT;
Default MSG_OPEN_YOU_CANT = 65;
Constant _MSG_OPEN_YOU_CANT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PARSER_NOTHING_TO_VERB;
Default MSG_PARSER_NOTHING_TO_VERB 66;
Constant _MSG_PARSER_NOTHING_TO_VERB_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TOUCHABLE_FOUND_CLOSED;
Default MSG_TOUCHABLE_FOUND_CLOSED 67;
Constant _MSG_TOUCHABLE_FOUND_CLOSED_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_CONSULT_NOTHING_INTERESTING;
Default MSG_CONSULT_NOTHING_INTERESTING 68;
Constant _MSG_CONSULT_NOTHING_INTERESTING_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_CUT_NO_USE;
Default MSG_CUT_NO_USE 69;
Constant _MSG_CUT_NO_USE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SACK_PUTTING;
Default MSG_SACK_PUTTING 70;
Constant _MSG_SACK_PUTTING_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_LOCK_NOT_A_LOCK;
Default MSG_LOCK_NOT_A_LOCK 71;
Constant _MSG_LOCK_NOT_A_LOCK_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_LOCK_ALREADY_LOCKED;
Default MSG_LOCK_ALREADY_LOCKED 72;
Constant _MSG_LOCK_ALREADY_LOCKED_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_LOCK_CLOSE_FIRST;
Default MSG_LOCK_CLOSE_FIRST 73;
Constant _MSG_LOCK_CLOSE_FIRST_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_LOCK_KEY_DOESNT_FIT;
Default MSG_LOCK_KEY_DOESNT_FIT 74;
Constant _MSG_LOCK_KEY_DOESNT_FIT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_LOCK_DEFAULT;
Default MSG_LOCK_DEFAULT 75;
Constant _MSG_LOCK_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_DISROBE_NOT_WEARING;
Default MSG_DISROBE_NOT_WEARING 76;
Constant _MSG_DISROBE_NOT_WEARING_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_DISROBE_DEFAULT;
Default MSG_DISROBE_DEFAULT 77;
Constant _MSG_DISROBE_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_REMOVE_NOT_HERE;
Default MSG_REMOVE_NOT_HERE 79;
Constant _MSG_REMOVE_NOT_HERE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SEARCH_IN_IT_ISARE;
Default MSG_SEARCH_IN_IT_ISARE 80;
Constant _MSG_SEARCH_IN_IT_ISARE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SEARCH_ON_IT_ISARE;
Default MSG_SEARCH_ON_IT_ISARE 81;
Constant _MSG_SEARCH_ON_IT_ISARE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SEARCH_EMPTY;
Default MSG_SEARCH_EMPTY 82;
Constant _MSG_SEARCH_EMPTY_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SEARCH_NOTHING_ON;
Default MSG_SEARCH_NOTHING_ON 83;
Constant _MSG_SEARCH_NOTHING_ON_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SEARCH_CANT_SEE_CLOSED;
Default MSG_SEARCH_CANT_SEE_CLOSED 84;
Constant _MSG_SEARCH_CANT_SEE_CLOSED_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_EAT_DEFAULT;
Default MSG_EAT_DEFAULT = 85;
Constant _MSG_EAT_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifdef OPTIONAL_FULL_SCORE;
#Ifndef MSG_FULLSCORE_START;
Default MSG_FULLSCORE_START 86;
Constant _MSG_FULLSCORE_START_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_FULLSCORE_END;
Default MSG_FULLSCORE_END 87;
Constant _MSG_FULLSCORE_END_HAS_CASE = 1;
#EndIf;
#Endif;
#Ifndef MSG_SCORE_DEFAULT;
Default MSG_SCORE_DEFAULT 88;
Constant _MSG_SCORE_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_UNLOCK_NOT_A_LOCK;
Default MSG_UNLOCK_NOT_A_LOCK 89;
Constant _MSG_UNLOCK_NOT_A_LOCK_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_UNLOCK_ALREADY_UNLOCKED;
Default MSG_UNLOCK_ALREADY_UNLOCKED 90;
Constant _MSG_UNLOCK_ALREADY_UNLOCKED_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_UNLOCK_KEY_DOESNT_FIT;
Default MSG_UNLOCK_KEY_DOESNT_FIT 91;
Constant _MSG_UNLOCK_KEY_DOESNT_FIT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_UNLOCK_DEFAULT;
Default MSG_UNLOCK_DEFAULT 92;
Constant _MSG_UNLOCK_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_ENTER_BAD_LOCATION;
Default MSG_ENTER_BAD_LOCATION 93;
Constant _MSG_ENTER_BAD_LOCATION_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PROMPT;
Default MSG_PROMPT 94;
Constant _MSG_PROMPT_HAS_CASE = 1;
#EndIf;
#Ifndef OPTIONAL_NO_DARKNESS;
#Ifndef MSG_EXAMINE_DARK;
Default MSG_EXAMINE_DARK 95;
Constant _MSG_EXAMINE_DARK_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SEARCH_DARK;
Default MSG_SEARCH_DARK 96;
Constant _MSG_SEARCH_DARK_HAS_CASE = 1;
#EndIf;
#Endif;
#Ifndef MSG_EXAMINE_ONOFF;
Default MSG_EXAMINE_ONOFF 97;
Constant _MSG_EXAMINE_ONOFF_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_ORDERS_WONT;
Default MSG_ORDERS_WONT 98;
Constant _MSG_ORDERS_WONT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_AUTO_TAKE;
Default MSG_AUTO_TAKE 99;
Constant _MSG_AUTO_TAKE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_AUTO_DISROBE;
Default MSG_AUTO_DISROBE = 100;
Constant _MSG_AUTO_DISROBE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PARSER_PARTIAL_MATCH;
Default MSG_PARSER_PARTIAL_MATCH = 101;
Constant _MSG_PARSER_PARTIAL_MATCH_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TAKE_BELONGS;
Default MSG_TAKE_BELONGS 102;
Constant _MSG_TAKE_BELONGS_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TAKE_PART_OF;
Default MSG_TAKE_PART_OF 103;
Constant _MSG_TAKE_PART_OF_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TAKE_NOT_AVAILABLE;
Default MSG_TAKE_NOT_AVAILABLE 104;
Constant _MSG_TAKE_NOT_AVAILABLE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PARSER_CONTAINER_ISNT_OPEN;
Default MSG_PARSER_CONTAINER_ISNT_OPEN 105;
Constant _MSG_PARSER_CONTAINER_ISNT_OPEN_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PARSER_NOT_HOLDING;
Default MSG_PARSER_NOT_HOLDING 106;
Constant _MSG_PARSER_NOT_HOLDING_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PARSER_CANT_TALK;
Default MSG_PARSER_CANT_TALK 107;
Constant _MSG_PARSER_CANT_TALK_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_WAVE_NOTHOLDING;
Default MSG_WAVE_NOTHOLDING 108;
Constant _MSG_WAVE_NOTHOLDING_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_JUMP_OVER;
Default MSG_JUMP_OVER 109;
Constant _MSG_JUMP_OVER_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TIE_DEFAULT;
Default MSG_TIE_DEFAULT 110;
Constant _MSG_TIE_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_CLOSE_NOT_OPEN;
Default MSG_CLOSE_NOT_OPEN 111;
Constant _MSG_CLOSE_NOT_OPEN_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_RUB_DEFAULT;
Default MSG_RUB_DEFAULT 112;
Constant _MSG_RUB_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SQUEEZE_DEFAULT;
Default MSG_SQUEEZE_DEFAULT 113;
Constant _MSG_SQUEEZE_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_EXAMINE_CLOSED;
Default MSG_EXAMINE_CLOSED 114;
Constant _MSG_EXAMINE_CLOSED_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_EMPTY_IS_CLOSED;
Default MSG_EMPTY_IS_CLOSED 115; ! Only used from extended verbset, but same message also used in basic set.
Constant _MSG_EMPTY_IS_CLOSED_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PARSER_NO_NEED_REFER_TO;
Default MSG_PARSER_NO_NEED_REFER_TO 116;
Constant _MSG_PARSER_NO_NEED_REFER_TO_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PARSER_DONT_UNDERSTAND_WORD;
Default MSG_PARSER_DONT_UNDERSTAND_WORD 117;
Constant _MSG_PARSER_DONT_UNDERSTAND_WORD_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_INSERT_NOT_CONTAINER;
Default MSG_INSERT_NOT_CONTAINER 118;
Constant _MSG_INSERT_NOT_CONTAINER_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TRANSFER_ALREADY;
Default MSG_TRANSFER_ALREADY 119;
Constant _MSG_TRANSFER_ALREADY_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_YES_OR_NO;
Default MSG_YES_OR_NO 120;
Constant _MSG_YES_OR_NO_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_RESTART_CONFIRM;
Default MSG_RESTART_CONFIRM 121;
Constant _MSG_RESTART_CONFIRM_HAS_CASE = 1;
#EndIf;
#Ifndef NO_SCORE;
#Ifndef MSG_PARSER_NEW_SCORE;
Default MSG_PARSER_NEW_SCORE 122;
Constant _MSG_PARSER_NEW_SCORE_HAS_CASE = 1;
#EndIf;
#Endif;
#Ifndef MSG_CLIMB_ANIMATE;
Default MSG_CLIMB_ANIMATE 123;
Constant _MSG_CLIMB_ANIMATE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_CLIMB_DEFAULT;
Default MSG_CLIMB_DEFAULT 124;
Constant _MSG_CLIMB_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PARSER_BAD_PATTERN_PREFIX;
Default MSG_PARSER_BAD_PATTERN_PREFIX 125;
Constant _MSG_PARSER_BAD_PATTERN_PREFIX_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PARSER_BAD_PATTERN_SUFFIX;
Default MSG_PARSER_BAD_PATTERN_SUFFIX 126;
Constant _MSG_PARSER_BAD_PATTERN_SUFFIX_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TAKE_ALREADY_HAVE;
Default MSG_TAKE_ALREADY_HAVE 127;
Constant _MSG_TAKE_ALREADY_HAVE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SHOUT_DEFAULT;
Default MSG_SHOUT_DEFAULT 128;
Constant _MSG_SHOUT_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SHOUTAT_DEFAULT;
Default MSG_SHOUTAT_DEFAULT 129;
Constant _MSG_SHOUTAT_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_INSERT_ANIMATE;
Default MSG_INSERT_ANIMATE 130;
Constant _MSG_INSERT_ANIMATE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PUTON_ANIMATE;
Default MSG_PUTON_ANIMATE 131;
Constant _MSG_PUTON_ANIMATE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_LOOKMODE_NORMAL;
Default MSG_LOOKMODE_NORMAL 132;
Constant _MSG_LOOKMODE_NORMAL_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_LOOKMODE_LONG;
Default MSG_LOOKMODE_LONG 133;
Constant _MSG_LOOKMODE_LONG_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_LOOKMODE_SHORT;
Default MSG_LOOKMODE_SHORT 134;
Constant _MSG_LOOKMODE_SHORT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_AUTO_TAKE_NOT_HELD;
Default MSG_AUTO_TAKE_NOT_HELD = 135;
Constant _MSG_AUTO_TAKE_NOT_HELD_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_AUTO_DISROBE_WORN;
Default MSG_AUTO_DISROBE_WORN = 136;
Constant _MSG_AUTO_DISROBE_WORN_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TAKE_SCENERY;
Default MSG_TAKE_SCENERY = 137;
Constant _MSG_TAKE_SCENERY_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_TAKE_STATIC;
Default MSG_TAKE_STATIC = 138;
Constant _MSG_TAKE_STATIC_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_EAT_INEDIBLE;
Default MSG_EAT_INEDIBLE = 139;
Constant _MSG_EAT_INEDIBLE_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_OPEN_ALREADY;
Default MSG_OPEN_ALREADY = 140;
Constant _MSG_OPEN_ALREADY_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_OPEN_LOCKED;
Default MSG_OPEN_LOCKED = 141;
Constant _MSG_OPEN_LOCKED_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PUTON_NOT_SUPPORTER;
Default MSG_PUTON_NOT_SUPPORTER = 142;
Constant _MSG_PUTON_NOT_SUPPORTER_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PARSER_NO_IT;
Default MSG_PARSER_NO_IT = 143;
Constant _MSG_PARSER_NO_IT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PARSER_CANT_SEE_IT;
Default MSG_PARSER_CANT_SEE_IT = 144;
Constant _MSG_PARSER_CANT_SEE_IT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_NOTIFY_ON;
Default MSG_NOTIFY_ON = 145;
Constant _MSG_NOTIFY_ON_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_NOTIFY_OFF;
Default MSG_NOTIFY_OFF = 146;
Constant _MSG_NOTIFY_OFF_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_ENTER_HELD;
Default MSG_ENTER_HELD 147;
Constant _MSG_ENTER_HELD_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_PARSER_NOSUCHTHING;
Default MSG_PARSER_NOSUCHTHING 148;
Constant _MSG_PARSER_NOSUCHTHING_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SHOUT_NOSUCHTHING;
Default MSG_SHOUT_NOSUCHTHING 149;
Constant _MSG_SHOUT_NOSUCHTHING_HAS_CASE = 1;
#EndIf;

#IfDef OPTIONAL_PROVIDE_UNDO_FINAL;
#Ifndef MSG_UNDO_NOTHING_DONE;
Constant MSG_UNDO_NOTHING_DONE "[Man kann nicht ~rückgängig machen~, was nicht getan wurde!]";
#EndIf;
#Ifndef MSG_UNDO_NOT_PROVIDED;
Constant MSG_UNDO_NOT_PROVIDED "[Ihr Interpreter bietet kein ~rückgängig machen~ an.]";
#EndIf;
#Ifndef MSG_UNDO_FAILED;
Constant MSG_UNDO_FAILED "~Rückgängig machen~ fehlgeschlagen.";
#EndIf;
#Ifndef MSG_UNDO_DONE;
Constant MSG_UNDO_DONE "Vorherigen Zug rückgängig gemacht.";
#EndIf;
#EndIf;

#Ifndef MSG_COMMENT_TRANSCRIPT;
Constant MSG_COMMENT_TRANSCRIPT "[Kommentar aufgezeichnet]^";
#EndIf;
#Ifndef MSG_COMMENT_NO_TRANSCRIPT;
#ifdef OPTIONAL_EXTENDED_METAVERBS;
Constant MSG_COMMENT_NO_TRANSCRIPT "[Kommentar nicht aufgezeichnet. Um Kommentare aufzuzeichnen, starte ein Transkript.]^";
#IfNot;
Constant MSG_COMMENT_NO_TRANSCRIPT "[Kommentar nicht aufgezeichnet. Dieses Spiel unterstützt keine Transkripte.]^";
#EndIf;
#EndIf;

#IfDef OPTIONAL_EXTENDED_VERBSET;
#Ifndef MSG_BURN_DEFAULT;
Constant MSG_BURN_DEFAULT "Dieser gewagte Akt wird wenig bringen.";
#EndIf;
#Ifndef MSG_BUY_DEFAULT;
Constant MSG_BUY_DEFAULT "Es wird nichts verkauft.";
#EndIf;
#Ifndef MSG_EMPTY_WOULDNT_ACHIEVE;
Constant MSG_EMPTY_WOULDNT_ACHIEVE "Das wird kaum etwas leeren.";
#EndIf;
#Ifndef MSG_RHETORICAL_QUESTION;
Constant MSG_RHETORICAL_QUESTION "Das war eine rhetorische Frage.";
#EndIf;
#Ifndef MSG_PRAY_DEFAULT;
Constant MSG_PRAY_DEFAULT "Dein Gebet hat keine praktischen Auswirkungen.";
#EndIf;
#Ifndef MSG_SING_DEFAULT;
Constant MSG_SING_DEFAULT "Dein Gesang ist schrecklich.";
#EndIf;
#Ifndef MSG_SLEEP_DEFAULT;
Constant MSG_SLEEP_DEFAULT "Du fühlst dich nicht besonders müde.";
#EndIf;
#Ifndef MSG_SORRY_DEFAULT;
Constant MSG_SORRY_DEFAULT "Oh, du musst dich nicht entschuldigen.";
#EndIf;
#Ifndef MSG_SQUEEZE_YOURSELF;
Constant MSG_SQUEEZE_YOURSELF "Behalte deine Hände bei dir.";
#EndIf;
#Ifndef MSG_SWIM_DEFAULT;
Constant MSG_SWIM_DEFAULT "Es gibt nicht genug Wasser, um darin zu schwimmen.";
#EndIf;
#Ifndef MSG_SWING_DEFAULT;
Constant MSG_SWING_DEFAULT "Hier gibt es nichts Sinnvolles zum Schaukeln.";
#EndIf;
#Ifndef MSG_TASTE_DEFAULT;
Constant MSG_TASTE_DEFAULT "Du schmeckst nichts Unerwartetes.";
#EndIf;
#Ifndef MSG_THINK_DEFAULT;
Constant MSG_THINK_DEFAULT "Das ist eine gute Idee.";
#EndIf;
#Ifndef MSG_WAVEHANDS_DEFAULT;
Constant MSG_WAVEHANDS_DEFAULT "Du winkst und kommst dir etwas blöd vor.";
#EndIf;
#Ifndef MSG_WAKE_DEFAULT;
Constant MSG_WAKE_DEFAULT "Die schreckliche Wahrheit ist, dass dies kein Traum ist.";
#Endif;
#Ifndef MSG_WAKEOTHER_DEFAULT;
Constant MSG_WAKEOTHER_DEFAULT "Das erscheint unsinnig.";
#Endif;
#Ifndef MSG_KISS_PLAYER;
Constant MSG_KISS_PLAYER "Wenn du glaubst, dass das hilft.";
#Endif;
#Ifndef MSG_KISS_DEFAULT;
Constant MSG_KISS_DEFAULT "Konzentriere dich auf das Spiel.";
#Endif;
#Ifndef MSG_MILD_DEFAULT;
Constant MSG_MILD_DEFAULT "Durchaus.";
#EndIf;
#Ifndef MSG_STRONG_DEFAULT;
Constant MSG_STRONG_DEFAULT "Echte Abenteurer verwenden solche Begriffe nicht.";
#EndIf;

#Ifndef MSG_BLOW_DEFAULT;
Default MSG_BLOW_DEFAULT 200;
Constant _MSG_BLOW_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_WAVE_DEFAULT;
Default MSG_WAVE_DEFAULT 201;
Constant _MSG_WAVE_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_EMPTY_ALREADY_EMPTY;
Default MSG_EMPTY_ALREADY_EMPTY 202;
Constant _MSG_EMPTY_ALREADY_EMPTY_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SET_DEFAULT;
Default MSG_SET_DEFAULT 203;
Constant _MSG_SET_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_SET_TO_DEFAULT;
Default MSG_SET_TO_DEFAULT 204;
Constant _MSG_SET_TO_DEFAULT_HAS_CASE = 1;
#EndIf;
#Ifndef MSG_EMPTY_NOT_CONTAINER;
Default MSG_EMPTY_NOT_CONTAINER 205;
Constant _MSG_EMPTY_NOT_CONTAINER_HAS_CASE = 1;
#EndIf;
#EndIf;


#Ifndef _MSG_PUSH_DEFAULT_HAS_CASE;
#Ifndef _MSG_PULL_DEFAULT_HAS_CASE;
#Ifndef _MSG_TURN_DEFAULT_HAS_CASE;
Constant SKIP_MSG_PUSH_DEFAULT;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_PUSH_STATIC_HAS_CASE;
#Ifndef _MSG_PULL_STATIC_HAS_CASE;
#Ifndef _MSG_TURN_STATIC_HAS_CASE;
#Ifndef _MSG_TAKE_STATIC_HAS_CASE;
Constant SKIP_MSG_PUSH_STATIC;
#Endif;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_PUSH_SCENERY_HAS_CASE;
#Ifndef _MSG_PULL_SCENERY_HAS_CASE;
#Ifndef _MSG_TURN_SCENERY_HAS_CASE;
Constant SKIP_MSG_PUSH_SCENERY;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_PUSH_ANIMATE_HAS_CASE;
#Ifndef _MSG_PULL_ANIMATE_HAS_CASE;
#Ifndef _MSG_TURN_ANIMATE_HAS_CASE;
#Ifndef _MSG_CLIMB_ANIMATE_HAS_CASE;
Constant SKIP_MSG_PUSH_ANIMATE;
#Endif;
#Endif;
#Endif;
#Endif;


#Ifndef _MSG_DROP_NOT_HOLDING_HAS_CASE;
#Ifndef _MSG_SHOW_NOT_HOLDING_HAS_CASE;
#Ifndef _MSG_GIVE_NOT_HOLDING_HAS_CASE;
#Ifndef _MSG_WEAR_NOT_HOLDING_HAS_CASE;
Constant SKIP_MSG_DROP_NOT_HOLDING;
#Endif;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_OPEN_YOU_CANT_HAS_CASE;
#Ifndef _MSG_CLOSE_YOU_CANT_HAS_CASE;
#Ifndef _MSG_ENTER_YOU_CANT_HAS_CASE;
#Ifndef _MSG_LOCK_NOT_A_LOCK_HAS_CASE;
#Ifndef _MSG_UNLOCK_NOT_A_LOCK_HAS_CASE;
#Ifndef _MSG_WEAR_NOT_CLOTHING_HAS_CASE;
Constant SKIP_MSG_OPEN_YOU_CANT;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_TAKE_ANIMATE_HAS_CASE;
#Ifndef _MSG_EAT_ANIMATE_HAS_CASE;
Constant SKIP_MSG_TAKE_ANIMATE;
#Endif;
#Endif;

#Ifndef _MSG_TAKE_PLAYER_PARENT_HAS_CASE;
#Ifndef _MSG_GO_FIRST_LEAVE_HAS_CASE;
#Ifndef _MSG_EXIT_FIRST_LEAVE_HAS_CASE;
Constant SKIP_MSG_TAKE_PLAYER_PARENT;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_CLOSE_DEFAULT_HAS_CASE;
#Ifndef _MSG_ENTER_DEFAULT_HAS_CASE;
#Ifndef _MSG_LOCK_DEFAULT_HAS_CASE;
#Ifndef _MSG_UNLOCK_DEFAULT_HAS_CASE;
#Ifndef _MSG_EXIT_DEFAULT_HAS_CASE;
Constant SKIP_MSG_CLOSE_DEFAULT;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_GIVE_DEFAULT_HAS_CASE;
#Ifndef _MSG_SHOW_DEFAULT_HAS_CASE;
Constant SKIP_MSG_GIVE_DEFAULT;
#Endif;
#Endif;

#Ifndef _MSG_ASKFOR_DEFAULT_HAS_CASE;
#Ifndef _MSG_ASKTO_DEFAULT_HAS_CASE;
#Ifndef _MSG_ORDERS_WONT_HAS_CASE;
Constant SKIP_MSG_ASKFOR_DEFAULT;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_ENTER_NOT_OPEN_HAS_CASE;
#Ifndef _MSG_EXIT_NOT_OPEN_HAS_CASE;
#Ifndef _MSG_INSERT_NOT_OPEN_HAS_CASE;
#Ifndef _MSG_GO_DOOR_CLOSED_HAS_CASE;
#Ifndef _MSG_EMPTY_IS_CLOSED_HAS_CASE;
Constant SKIP_MSG_ENTER_NOT_OPEN;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_GIVE_PLAYER_HAS_CASE;
#Ifndef _MSG_TAKE_ALREADY_HAVE_HAS_CASE;
Constant SKIP_MSG_GIVE_PLAYER;
#Endif;
#Endif;

#Ifndef _MSG_SAVE_FAILED_HAS_CASE;
#Ifndef _MSG_RESTORE_FAILED_HAS_CASE;
#Ifndef _MSG_RESTART_FAILED_HAS_CASE;
Constant SKIP_MSG_SAVE_FAILED;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_INSERT_ALREADY_HAS_CASE;
#Ifndef _MSG_PUTON_ALREADY_HAS_CASE;
#Ifndef _MSG_TRANSFER_ALREADY_HAS_CASE;
Constant SKIP_MSG_INSERT_ALREADY;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_INSERT_ANIMATE_HAS_CASE;
#Ifndef _MSG_PUTON_ANIMATE_HAS_CASE;
Constant SKIP_MSG_INSERT_ANIMATE;
#Endif;
#Endif;

#Ifndef _MSG_INSERT_NO_ROOM_HAS_CASE;
#Ifndef _MSG_PUTON_NO_ROOM_HAS_CASE;
Constant SKIP_MSG_INSERT_NO_ROOM;
#Endif;
#Endif;

#Ifndef _MSG_ASK_DEFAULT_HAS_CASE;
#Ifndef _MSG_ANSWER_DEFAULT_HAS_CASE;
#Ifndef _MSG_SHOUT_DEFAULT_HAS_CASE;
#Ifndef _MSG_SHOUTAT_DEFAULT_HAS_CASE;
Constant SKIP_MSG_ASK_DEFAULT;
#Endif;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_SWITCH_ON_NOT_SWITCHABLE_HAS_CASE;
#Ifndef _MSG_SWITCH_OFF_NOT_SWITCHABLE_HAS_CASE;
Constant SKIP_MSG_SWITCH_ON_NOT_SWITCHABL;
#Endif;
#Endif;

#Ifndef _MSG_SWITCH_ON_ON_HAS_CASE;
#Ifndef _MSG_SWITCH_OFF_NOT_ON_HAS_CASE;
Constant SKIP_MSG_SWITCH_ON_ON;
#Endif;
#Endif;

#Ifndef _MSG_SWITCH_ON_DEFAULT_HAS_CASE;
#Ifndef _MSG_SWITCH_OFF_DEFAULT_HAS_CASE;
Constant SKIP_MSG_SWITCH_ON_DEFAULT;
#Endif;
#Endif;

#Ifndef _MSG_PARSER_NOT_HOLDING_HAS_CASE;
#Ifndef _MSG_AUTO_TAKE_NOT_HELD_HAS_CASE;
#Ifndef _MSG_WAVE_NOTHOLDING_HAS_CASE;
Constant SKIP_MSG_PARSER_NOT_HOLDING;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_CLOSE_NOT_OPEN_HAS_CASE;
#Ifndef _MSG_TOUCHABLE_FOUND_CLOSED_HAS_CASE;
#Ifndef _MSG_PARSER_CONTAINER_ISNT_OPEN_HAS_CASE;
Constant SKIP_MSG_CLOSE_NOT_OPEN;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_CUT_NO_USE_HAS_CASE;
#Ifndef _MSG_JUMP_OVER_HAS_CASE;
#Ifndef _MSG_TIE_DEFAULT_HAS_CASE;
#Ifndef _MSG_CLIMB_DEFAULT_HAS_CASE;
Constant SKIP_MSG_CUT_NO_USE;
#Endif;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_LOCK_ALREADY_LOCKED_HAS_CASE;
#Ifndef _MSG_UNLOCK_ALREADY_UNLOCKED_HAS_CASE;
Constant SKIP_MSG_LOCK_ALREADY_LOCKED;
#Endif;
#Endif;

#Ifndef _MSG_LOCK_KEY_DOESNT_FIT_HAS_CASE;
#Ifndef _MSG_UNLOCK_KEY_DOESNT_FIT_HAS_CASE;
Constant SKIP_MSG_LOCK_KEY_DOESNT_FIT;
#Endif;
#Endif;

#Ifndef _MSG_RUB_DEFAULT_HAS_CASE;
#Ifndef _MSG_SQUEEZE_DEFAULT_HAS_CASE;
Constant SKIP_MSG_RUB_DEFAULT;
#Endif;
#Endif;

#Ifndef _MSG_LOOKMODE_NORMAL_HAS_CASE;
#Ifndef _MSG_LOOKMODE_LONG_HAS_CASE;
#Ifndef _MSG_LOOKMODE_SHORT_HAS_CASE;
Constant SKIP_MSG_LOOKMODE;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_INSERT_NOT_CONTAINER_HAS_CASE;
#Ifndef MSG_EMPTY_NOT_CONTAINER;
Constant SKIP_MSG_INSERT_NOT_CONTAINER;
#Ifnot;
#Ifndef _MSG_EMPTY_NOT_CONTAINER_HAS_CASE;
Constant SKIP_MSG_INSERT_NOT_CONTAINER;
#Endif;
#Endif;
#Endif;

#Ifndef OPTIONAL_NO_SCORE;
#Ifndef _MSG_NOTIFY_ON_HAS_CASE;
#Ifndef _MSG_NOTIFY_OFF_HAS_CASE;
Constant SKIP_MSG_NOTIFY_ON;
#Endif;
#Endif;
#Endif;

#Ifndef OPTIONAL_NO_DARKNESS;
#Ifndef _MSG_EXAMINE_DARK_HAS_CASE;
#Ifndef _MSG_SEARCH_DARK_HAS_CASE;
Constant SKIP_MSG_EXAMINE_DARK;
#Endif;
#Endif;
#Endif;

#Ifndef _MSG_PARSER_NOSUCHTHING_HAS_CASE;
#Ifndef _MSG_SHOUT_NOSUCHTHING_HAS_CASE;
Constant SKIP_MSG_PARSER_NOSUCHTHING;
#Endif;
#Endif;

[ _PrintMsg p_msg p_arg_1 p_arg_2;
	if(IsAString(p_msg))
		print_ret (string) p_msg;

#Ifdef LibraryMessages;
	if(p_msg > 999) {
		return LibraryMessages(p_msg, p_arg_1, p_arg_2);
	}
#Endif;

	! Not a string, there should be code for the message here
	switch(p_msg) {
#Ifdef _MSG_PROMPT_HAS_CASE;
	MSG_PROMPT:
		print "> ";
		rtrue;
#EndIf;
#Ifdef _MSG_LOOK_BEFORE_ROOMNAME_HAS_CASE;
	MSG_LOOK_BEFORE_ROOMNAME:
		! what to write at first when describing a room. Can be used to
		! add a newline, but default is to write nothing.
		!@new_line;
#Endif;
#Ifdef _MSG_TAKE_SCENERY_HAS_CASE;
	MSG_TAKE_SCENERY:
		print_ret (CTheyreorThats) noun, " nicht portabel.";
#EndIf;
#Ifndef SKIP_MSG_PUSH_DEFAULT;
	MSG_PUSH_DEFAULT, MSG_PULL_DEFAULT, MSG_TURN_DEFAULT:
		"Du siehst keinen Grund dazu.";
#Endif;
#Ifndef SKIP_MSG_PUSH_STATIC;
	MSG_PUSH_STATIC, MSG_PULL_STATIC, MSG_TURN_STATIC:
		print_ret (CObjIs) noun, " nicht beweglich.";
#Endif;
#Ifndef SKIP_MSG_TAKE_STATIC;
	MSG_TAKE_STATIC:
		print_ret "Du kannst ", (DE_Den) noun, " nicht mitnehmen.";
#Endif;
#Ifndef SKIP_MSG_PUSH_SCENERY;
	MSG_PUSH_SCENERY, MSG_PULL_SCENERY, MSG_TURN_SCENERY:
		print_ret (CObjIs) noun, " nicht beweglich.";
#Endif;
#IfDef SACK_OBJECT;
#Ifdef _MSG_SACK_PUTTING_HAS_CASE;
	MSG_SACK_PUTTING:
	! p_arg_1 = the object being put into SACK_OBJECT.
		! "legen" = Akkusativ; "in" + Akkusativ (Richtung) → (DE_Den)
		"(lege ", (DE_Den) p_arg_1, " in ", (DE_Den) SACK_OBJECT, " um Platz zu schaffen)";
#EndIf;
#EndIf;
#Ifdef _MSG_INVENTORY_DEFAULT_HAS_CASE;
	MSG_INVENTORY_DEFAULT:
		! return true if something listed to run afterroutines
		! or false if MSG_INVENTORY_EMPTY should be displayed
		p_arg_1 = "Du hast ";
		if(inventory_style == 0) {
			p_arg_1 = "Du hast bei dir:";
			p_arg_2 = NEWLINE_BIT;
		}
		! Inventory items are direct objects of "Du hast" → Akkusativ
		short_name_case = Akk;
		if(PrintContents(p_arg_1, player, p_arg_2)) {
			short_name_case = Nom;
			if(inventory_style) print ".^";
			rtrue;
		}
		short_name_case = Nom;
		rfalse;
#EndIf;
#Ifdef _MSG_EXAMINE_NOTHING_SPECIAL_HAS_CASE;
	MSG_EXAMINE_NOTHING_SPECIAL:
		! "an" + Dativ → (DE_Dem)
		"Du erkennst nichts Besonderes an ", (DE_Dem) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_PUSH_ANIMATE;
	MSG_PUSH_ANIMATE, MSG_PULL_ANIMATE, MSG_TURN_ANIMATE, MSG_CLIMB_ANIMATE:
		"Das wäre nicht gerade höflich.";
#Endif;
#Ifndef SKIP_MSG_DROP_NOT_HOLDING;
	MSG_DROP_NOT_HOLDING, MSG_SHOW_NOT_HOLDING, MSG_GIVE_NOT_HOLDING,
	MSG_WEAR_NOT_HOLDING:
		! "halten" = Akkusativ → (DE_Den)
		"Du hast ", (DE_Den) noun, " gar nicht.";
#Endif;
#Ifndef SKIP_MSG_OPEN_YOU_CANT;
	MSG_OPEN_YOU_CANT, MSG_CLOSE_YOU_CANT, MSG_ENTER_YOU_CANT,
	MSG_LOCK_NOT_A_LOCK, MSG_UNLOCK_NOT_A_LOCK, MSG_WEAR_NOT_CLOTHING:
	! p_arg_1 = the base verb for this action.
		"Du kannst ", (ThatorThose) noun, " nicht ", (verbname) p_arg_1, ".";
#Endif;
#Ifdef _MSG_OPEN_ALREADY_HAS_CASE;
	MSG_OPEN_ALREADY:
		print_ret (CTheyreorIts) noun, " bereits offen.";
#EndIf;
#Ifdef _MSG_OPEN_LOCKED_HAS_CASE;
	MSG_OPEN_LOCKED:
		print_ret (CTheyreorIts) noun, " verschlossen.";
#EndIf;
#Ifdef _MSG_PUTON_NOT_SUPPORTER_HAS_CASE;
	MSG_PUTON_NOT_SUPPORTER:
		"Du kannst nichts auf ", (ThatorThose) second, " stellen.";
#EndIf;
#Ifndef SKIP_MSG_TAKE_ANIMATE;
	MSG_TAKE_ANIMATE, MSG_EAT_ANIMATE:
		! Nominativ: noun ist Subjekt von "interessiert" → (DE_Der)
		"Ich glaube nicht, dass ", (DE_Der) noun, " das interessiert.";
#Endif;
#Ifndef SKIP_MSG_TAKE_PLAYER_PARENT;
	MSG_TAKE_PLAYER_PARENT, MSG_GO_FIRST_LEAVE, MSG_EXIT_FIRST_LEAVE:
	! p_arg_1 = the object the player has to leave to perform the action.
	! "verlassen" = Akkusativ → (DE_Den)
		"Zuerst musst du ", (DE_Den) p_arg_1, " verlassen.";
#Endif;
#Ifdef _MSG_OPEN_DEFAULT_HAS_CASE;
	MSG_OPEN_DEFAULT:
		! "öffnen" = Akkusativ → (DE_Den)
		print "Du öffnest ", (DE_Den) noun;
		if (noun has container && noun hasnt transparent &&
				~~IndirectlyContains(noun, player)) {
			if (PrintContents(1, noun, 0) ~= 0) {
				print " und siehst ";
				p_arg_2 = short_name_case;
				short_name_case = Akk;
				PrintContents(0, noun);
				short_name_case = p_arg_2;
			}
		}
		".";
#Endif;
#Ifndef SKIP_MSG_CLOSE_DEFAULT;
	MSG_CLOSE_DEFAULT:
		! "schließen" = Akkusativ → (DE_Den)
		"Du schließt ", (DE_Den) noun, ".";
	MSG_ENTER_DEFAULT:
		! Akkusativ: "in X" (container) oder "auf X" (supporter)
		if (noun has supporter) { "Du steigst auf ", (DE_Den) noun, "."; }
		"Du gehst in ", (DE_Den) noun, ".";
	MSG_EXIT_DEFAULT:
		! "verlassen" = Akkusativ → (DE_Den)
		if (noun has supporter) { "Du steigst von ", (DE_Dem) noun, "."; }
		"Du verlässt ", (DE_Den) noun, ".";
	MSG_LOCK_DEFAULT:
		! "verriegeln" = Akkusativ → (DE_Den)
		"Du verriegelst ", (DE_Den) noun, ".";
	MSG_UNLOCK_DEFAULT:
		! "aufschließen" = Akkusativ → (DE_Den)
		"Du schließt ", (DE_Den) noun, " auf.";
#Endif;
#Ifndef SKIP_MSG_GIVE_DEFAULT;
	MSG_GIVE_DEFAULT, MSG_SHOW_DEFAULT:
		! Nominativ: second ist Subjekt → (DE_Der_Cap) am Satzanfang
		print_ret (DE_Der_Cap) second, " scheint nicht interessiert zu sein.";
#Endif;
#Ifndef SKIP_MSG_ASKFOR_DEFAULT;
	MSG_ASKFOR_DEFAULT, MSG_ASKTO_DEFAULT, MSG_ORDERS_WONT:
	! p_arg_1 = the actor which the player has asked to do something.
		! Nominativ: p_arg_1 ist Subjekt → (DE_Der_Cap) am Satzanfang
		print_ret (DE_Der_Cap) p_arg_1, " hat Besseres zu tun.";
#Endif;
#Ifndef SKIP_MSG_ENTER_NOT_OPEN;
	MSG_ENTER_NOT_OPEN, MSG_EXIT_NOT_OPEN, MSG_INSERT_NOT_OPEN,
	MSG_GO_DOOR_CLOSED, MSG_EMPTY_IS_CLOSED:
	! p_arg_1 = the object which is closed, thus blocking the players action
		! Nominativ: p_arg_1 ist Subjekt im Nebensatz → (DE_Der)
		"Das geht nicht, da ", (DE_Der) p_arg_1, " geschlossen ist.";
#Endif;
#Ifndef SKIP_MSG_GIVE_PLAYER;
	MSG_GIVE_PLAYER, MSG_TAKE_ALREADY_HAVE:
		"Du hast ", (ItorThem) noun, " bereits.";
#Endif;
#Ifndef SKIP_MSG_SAVE_FAILED;
	MSG_SAVE_FAILED, MSG_RESTORE_FAILED, MSG_RESTART_FAILED:
		"Fehlgeschlagen: ", (verbname) verb_word, ".";
#Endif;
#Ifndef SKIP_MSG_INSERT_ALREADY;
	MSG_INSERT_ALREADY, MSG_PUTON_ALREADY, MSG_TRANSFER_ALREADY:
		"Schon da.";
#Endif;
#Ifndef SKIP_MSG_INSERT_ANIMATE;
	MSG_INSERT_ANIMATE, MSG_PUTON_ANIMATE:
		"Versuch stattdessen ", (ItorThem) noun, " zu geben.";
#Endif;
#Ifndef SKIP_MSG_INSERT_NO_ROOM;
	MSG_INSERT_NO_ROOM, MSG_PUTON_NO_ROOM:
		"Es ist kein Platz mehr.";
#Endif;
#Ifdef _MSG_INSERT_DEFAULT_HAS_CASE;
	MSG_INSERT_DEFAULT:
		! "legen in" (wohin?) = Akkusativ für noun + second → (DE_Den)
		"Du legst ", (DE_Den) noun, " in ", (DE_Den) second, ".";
#EndIf;
#Ifdef _MSG_PUTON_DEFAULT_HAS_CASE;
	MSG_PUTON_DEFAULT:
		! "legen auf" (wohin?) = Akkusativ für noun + second → (DE_Den)
		"Du legst ", (DE_Den) noun, " auf ", (DE_Den) second, ".";
#EndIf;
#Ifndef SKIP_MSG_ASK_DEFAULT;
	MSG_ASK_DEFAULT, MSG_ANSWER_DEFAULT, MSG_SHOUT_DEFAULT, MSG_SHOUTAT_DEFAULT:
		"Keine Antwort.";
#Endif;
#Ifdef _MSG_WEAR_ALREADY_WORN_HAS_CASE;
	MSG_WEAR_ALREADY_WORN:
		! "mit" + Dativ → (DE_Dem)
		"Du bist bereits mit ", (DE_Dem) noun, " bekleidet.";
#EndIf;
#Ifdef _MSG_WEAR_DEFAULT_HAS_CASE;
	MSG_WEAR_DEFAULT:
		! "mit" + Dativ → (DE_Dem)
		"Du bist nun mit ", (DE_Dem) noun, " bekleidet.";
#EndIf;
#Ifdef _MSG_DISROBE_NOT_WEARING_HAS_CASE;
	MSG_DISROBE_NOT_WEARING:
		! "mit" + Dativ → (DE_Dem)
		"Du bist nicht mit ", (DE_Dem) noun, " bekleidet.";
#EndIf;
#Ifdef _MSG_DISROBE_DEFAULT_HAS_CASE;
	MSG_DISROBE_DEFAULT:
		! "ausziehen" = Akkusativ → (DE_Den)
		"Du ziehst ", (DE_Den) noun, " aus.";
#EndIf;
#Ifndef SKIP_MSG_SWITCH_ON_NOT_SWITCHABL;
	MSG_SWITCH_ON_NOT_SWITCHABLE, MSG_SWITCH_OFF_NOT_SWITCHABLE:
		print_ret (CTheyreorThats) noun, " nicht umschaltbar.";
#Endif;
#Ifndef SKIP_MSG_SWITCH_ON_ON;
	MSG_SWITCH_ON_ON, MSG_SWITCH_OFF_NOT_ON:
		print_ret (CTheyreorThats) noun, " schon ", (OnOff) noun, ".";
#Endif;
#Ifndef SKIP_MSG_SWITCH_ON_DEFAULT;
	MSG_SWITCH_ON_DEFAULT, MSG_SWITCH_OFF_DEFAULT:
		! "schalten" = Akkusativ → (DE_Den)
		"Du schaltest ", (DE_Den) noun, " ", (OnOff) noun, ".";
#Endif;
#Ifdef _MSG_AUTO_TAKE_HAS_CASE;
	MSG_AUTO_TAKE:
	! p_arg_1 = the object the player automatically picks up
	! "nehmen" = Akkusativ → (DE_Den)
		"(du nimmst zuerst ", (DE_Den) p_arg_1, ")";
#Endif;
#Ifdef _MSG_AUTO_DISROBE_HAS_CASE;
	MSG_AUTO_DISROBE:
	! p_arg_1 = the object the player automatically takes off.
	! "ausziehen" = Akkusativ → (DE_Den)
		"(du ziehst zuerst ", (DE_Den) p_arg_1, " aus)";
#Endif;
#Ifdef _MSG_AUTO_DISROBE_WORN_HAS_CASE;
	MSG_AUTO_DISROBE_WORN:
	! p_arg_1 = the object the player would need to take off.
	! "ausziehen" = Akkusativ → (DE_Den)
		"Du müsstest zuerst ", (DE_Den) p_arg_1, " ausziehen.";
#Endif;
#Ifdef _MSG_PARSER_NOTHING_TO_VERB_HAS_CASE;
	MSG_PARSER_NOTHING_TO_VERB:
	! p_arg_1 = the last word in player input + 1.
		if(action == ##Drop or ##Insert) {
			if((parse + 2 + (p_arg_1 - 2) *4) --> 0 == ALL_WORD)
				"Du trägst nichts.";
			if(TryNumber(verb_wordnum + 1) > 0) "Du hast nichts davon.";
		}
		print "Es gibt keine Dinge, die ~";
		_PrintPartialMatch(verb_wordnum, p_arg_1 - 1);
		"~ entsprechen.";
#EndIf;
#Ifndef SKIP_MSG_PARSER_NOT_HOLDING;
	MSG_PARSER_NOT_HOLDING, MSG_AUTO_TAKE_NOT_HELD, MSG_WAVE_NOTHOLDING:
	! p_arg_1 = the object which the player must be holding to perform the
	! action but isnt.
	! "halten" = Akkusativ → (DE_Den)
		"Aber du hast ", (DE_Den) p_arg_1, " gar nicht.";
#Endif;
#Ifdef _MSG_PARSER_PARTIAL_MATCH_HAS_CASE;
	MSG_PARSER_PARTIAL_MATCH:
	! p_arg_1 = the word number of the last word understood + 1.
		print "Ich habe dich nur bis ~";
		_PrintPartialMatch(verb_wordnum, p_arg_1);
		"~ verstanden.";
#EndIf;
#Ifdef _MSG_PARSER_CANT_TALK_HAS_CASE;
	MSG_PARSER_CANT_TALK:
	! p_arg_1 = the object which cant be talked to.
	! "mit" + Dativ → (DE_Dem)
		"Du kannst nicht mit ", (DE_Dem) p_arg_1, " reden.";
#EndIf;
#Ifdef _MSG_PARSER_NO_NEED_REFER_TO_HAS_CASE;
	MSG_PARSER_NO_NEED_REFER_TO:
		! TODO: "Du musst dich in diesem Spiel nicht auf ~ beziehen."
		print "Du musst dich in diesem Spiel nicht auf ~";
		_PrintUnknownWord();
		"~ beziehen.";
#EndIf;
#Ifdef _MSG_PARSER_DONT_UNDERSTAND_WORD_HAS_CASE;
	MSG_PARSER_DONT_UNDERSTAND_WORD:
		! TODO: "Entschuldigung, ich verstehe nicht was ~ bedeutet."
		print "Entschuldigung, ich verstehe nicht ";
		if(oops_unfixed) {
			"dieses Wort auch nicht.";
		}
		print "was ~";
		_PrintUnknownWord();
		"~ bedeutet.";
#EndIf;
#Ifdef _MSG_PARSER_BAD_PATTERN_PREFIX_HAS_CASE;
	MSG_PARSER_BAD_PATTERN_PREFIX:
		print "Ich glaube, du wolltest ~";
		rtrue;
#EndIf;
#Ifdef _MSG_PARSER_BAD_PATTERN_SUFFIX_HAS_CASE;
	MSG_PARSER_BAD_PATTERN_SUFFIX:
		"~ sagen. Bitte versuche es erneut.";
#EndIf;
#Ifdef _MSG_PARSER_NO_IT_HAS_CASE;
	MSG_PARSER_NO_IT:
		print "Ich weiß nicht, was ~";
		if (p_arg_1 == 'it') print "es";
		else if (p_arg_1 == 'him') print "er";
		else if (p_arg_1 == 'her' or 'them') print "sie";
		else print (address) p_arg_1;
		print_ret "~ bedeutet.";
#EndIf;
#Ifndef SKIP_MSG_PARSER_NOSUCHTHING;
	MSG_PARSER_NOSUCHTHING, MSG_SHOUT_NOSUCHTHING:
		"So etwas kannst du nicht sehen.";
#EndIf;
#Ifdef _MSG_PARSER_CANT_SEE_IT_HAS_CASE;
	MSG_PARSER_CANT_SEE_IT:
		"Du kannst ~", (address) p_arg_1, "~ (", (name) p_arg_2, ") momentan nicht sehen.";
#EndIf;
#Ifndef SKIP_MSG_CLOSE_NOT_OPEN;
	MSG_CLOSE_NOT_OPEN, MSG_TOUCHABLE_FOUND_CLOSED,
	MSG_PARSER_CONTAINER_ISNT_OPEN:
	! p_arg_1 = the object which isnt open.
		print_ret (CObjIs) p_arg_1, " nicht offen.";
#Endif;
#Ifdef _MSG_CONSULT_NOTHING_INTERESTING_HAS_CASE;
	MSG_CONSULT_NOTHING_INTERESTING:
		! "in" + Dativ (wo?) → (DE_Dem)
		"Du findest nichts von Belang in ", (DE_Dem) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_CUT_NO_USE;
	MSG_CUT_NO_USE, MSG_JUMP_OVER, MSG_TIE_DEFAULT, MSG_CLIMB_DEFAULT:
		"Damit erreichst du nichts.";
#Endif;
#Ifndef SKIP_MSG_LOCK_ALREADY_LOCKED;
	MSG_LOCK_ALREADY_LOCKED:
		! Nominativ: noun ist Subjekt → (DE_Der_Cap) am Satzanfang
		print_ret (DE_Der_Cap) noun, " ist bereits verschlossen.";
	MSG_UNLOCK_ALREADY_UNLOCKED:
		! Nominativ: noun ist Subjekt → (DE_Der_Cap) am Satzanfang
		print_ret (DE_Der_Cap) noun, " ist bereits aufgeschlossen.";
#Endif;
#Ifdef _MSG_LOCK_CLOSE_FIRST_HAS_CASE;
	MSG_LOCK_CLOSE_FIRST:
		! "schließen" = Akkusativ → (DE_Den)
		"Zuerst musst du ", (DE_Den) noun, " schließen.";
#EndIf;
#Ifndef SKIP_MSG_LOCK_KEY_DOESNT_FIT;
	MSG_LOCK_KEY_DOESNT_FIT, MSG_UNLOCK_KEY_DOESNT_FIT:
		if (second == nothing) "Gib an, womit du das Schloss öffnen oder schließen willst.";
		! Nominativ: second ist Subjekt → (DE_Der_Cap) am Satzanfang
		print_ret (DE_Der_Cap) second, " scheint nicht in das Schloss zu passen.";
#Endif;
#Ifdef _MSG_EXAMINE_CLOSED_HAS_CASE;
	MSG_EXAMINE_CLOSED:
	! p_arg_1 = the examined object (which is closed).
		print_ret (CObjIs) p_arg_1, " geschlossen.";
#Endif;
#Ifdef _MSG_REMOVE_NOT_HERE_HAS_CASE;
	MSG_REMOVE_NOT_HERE:
		"Aber ", (ObjIs) noun, " momentan nicht da.";
#EndIf;
#Ifdef _MSG_SEARCH_IN_IT_ISARE_HAS_CASE;
	MSG_SEARCH_IN_IT_ISARE:
		print (DE_Der_Cap) noun, " enthält ";
		p_arg_2 = short_name_case;
		short_name_case = Akk;
		PrintContents(0, noun);
		short_name_case = p_arg_2;
		".";
#EndIf;
#Ifdef _MSG_SEARCH_ON_IT_ISARE_HAS_CASE;
	MSG_SEARCH_ON_IT_ISARE:
		! "auf" + Dativ (Lage, wo?) → (DE_Dem)
		print "Auf ", (DE_Dem) noun;
		PrintContents(" ", noun, ISARE_BIT);
		".";
#EndIf;
#Ifdef _MSG_SEARCH_EMPTY_HAS_CASE;
	MSG_SEARCH_EMPTY:
		print_ret (CObjIs) noun, " leer.";
#EndIf;
#Ifdef _MSG_SEARCH_NOTHING_ON_HAS_CASE;
	MSG_SEARCH_NOTHING_ON:
		! "auf" + Dativ (Lage) → (DE_Dem)
		"Es ist nichts auf ", (DE_Dem) noun, ".";
#EndIf;
#Ifdef _MSG_SEARCH_CANT_SEE_CLOSED_HAS_CASE;
	MSG_SEARCH_CANT_SEE_CLOSED:
		"Du kannst nicht reinschauen, ", (ObjIs) noun, " geschlossen.";
#EndIf;
#Ifdef _MSG_EXAMINE_ONOFF_HAS_CASE;
	MSG_EXAMINE_ONOFF:
		print_ret (CObjIs) noun, " aktuell ", (OnOff) noun, "geschaltet.";
#EndIf;
#Ifdef _MSG_EAT_DEFAULT_HAS_CASE;
	MSG_EAT_DEFAULT:
		! "essen" = Akkusativ → (DE_Den)
		"Du isst ", (DE_Den) noun, ". Nicht schlecht.";
#EndIf;
#Ifndef SKIP_MSG_RUB_DEFAULT;
MSG_RUB_DEFAULT, MSG_SQUEEZE_DEFAULT:
	"Damit erreichst du nichts.";
#Endif;
#Ifdef _MSG_TAKE_NOT_AVAILABLE_HAS_CASE;
	MSG_TAKE_NOT_AVAILABLE:
		print_ret (CObjIs) noun, " nicht vorhanden.";
#EndIf;
#Ifdef _MSG_TAKE_BELONGS_HAS_CASE;
	MSG_TAKE_BELONGS:
		! p_arg_1 = the object that is held by p_arg_2
		! p_arg_1 Nominativ (Subjekt), p_arg_2 Dativ ("gehören" + Dativ) → (DE_Dem)
		print_ret (DE_Der_Cap) p_arg_1, " gehört ", (DE_Dem) p_arg_2, ".";
#EndIf;
#Ifdef _MSG_TAKE_PART_OF_HAS_CASE;
	MSG_TAKE_PART_OF:
		! p_arg_1 = the object that is part of p_arg_2
		! p_arg_1 Nominativ (Subjekt), p_arg_2 Dativ ("von" + Dativ) → (DE_Dem)
		print_ret (DE_Der_Cap) p_arg_1, " ist ein Teil von ", (DE_Dem) p_arg_2, ".";
#EndIf;
#Ifndef OPTIONAL_NO_DARKNESS;
#Ifndef SKIP_MSG_EXAMINE_DARK;
	MSG_EXAMINE_DARK, MSG_SEARCH_DARK:
		"Aber es ist dunkel.";
#Endif;
#Endif;
#Ifdef _MSG_EAT_INEDIBLE_HAS_CASE;
	MSG_EAT_INEDIBLE:
		print_ret (CTheyreorThats) noun, " ungenießbar.";
#EndIf;
#Ifdef _MSG_ENTER_BAD_LOCATION_HAS_CASE;
	MSG_ENTER_BAD_LOCATION:
		print "Du musst zuerst ";
		if(player notin location && ~~IndirectlyContains(parent(player), noun))
			! "verlassen" = Akkusativ → (DE_Den)
			print (DE_Den) parent(player), " verlassen";
		else
			! "betreten" = Akkusativ → (DE_Den)
			print (DE_Den) parent(noun), " betreten";
		".";
#EndIf;
#Ifdef _MSG_ENTER_HELD_HAS_CASE;
	MSG_ENTER_HELD:
		! "betreten" = Akkusativ → (DE_Den); (ItorThem) = Akkusativ-Pronomen
		"Du kannst ", (DE_Den) noun, " nicht betreten, während du ", (ItorThem) noun, " trägst.";
#EndIf;
#Ifndef SKIP_MSG_INSERT_NOT_CONTAINER;
#ifdef MSG_EMPTY_NOT_CONTAINER;
	MSG_INSERT_NOT_CONTAINER, MSG_EMPTY_NOT_CONTAINER:
#Ifnot;
	MSG_INSERT_NOT_CONTAINER:
#Endif;
		! p_arg_1 = the object that cant contain things
		! Nominativ: p_arg_1 ist Subjekt → (DE_Der_Cap) am Satzanfang
		print_ret (DE_Der_Cap) p_arg_1, " kann keine Dinge enthalten.";
#Endif;

#IfDef OPTIONAL_EXTENDED_VERBSET;
#Ifdef _MSG_BLOW_DEFAULT_HAS_CASE;
	MSG_BLOW_DEFAULT:
		! "pusten" = Akkusativ → (DE_Den)
		"Du kannst ", (DE_Den) noun, " nicht sinnvoll pusten.";
#EndIf;
#Ifdef _MSG_EMPTY_ALREADY_EMPTY_HAS_CASE;
	MSG_EMPTY_ALREADY_EMPTY:
		! p_arg_1 = the object that is already empty
		print_ret (CObjIs) p_arg_1, " bereits leer.";
#EndIf;
#Ifdef _MSG_SET_DEFAULT_HAS_CASE;
	MSG_SET_DEFAULT:
		"Nein, du kannst ", (thatorthose) noun, " nicht einstellen.";
#EndIf;
#Ifdef _MSG_SET_TO_DEFAULT_HAS_CASE;
	MSG_SET_TO_DEFAULT:
		"Nein, du kannst ", (thatorthose) noun, " nicht auf etwas einstellen.";
#EndIf;
#Ifdef _MSG_WAVE_DEFAULT_HAS_CASE;
	MSG_WAVE_DEFAULT:
		! "mit" + Dativ → (DE_Dem)
		"Du siehst dämlich aus, wenn du mit ", (DE_Dem) noun, " winkst.";
#EndIf;
#EndIf; ! Extended verbset

#Ifndef NO_SCORE;
#Ifdef _MSG_PARSER_NEW_SCORE_HAS_CASE;
	MSG_PARSER_NEW_SCORE:
		! p_arg_1 = the old score
		if(p_arg_1 < score) {
			p_arg_2 = score - p_arg_1;
			print "^[Du hast ", p_arg_2, " Punkt";
			if(p_arg_2 ~= 1) print "e";
			" erhalten.]";
		} else {
			p_arg_2 = p_arg_1 - score;
			print "^[Du hast ", p_arg_2, " Punkt";
			if(p_arg_2 ~= 1) print "e";
			" verloren.]";
		}
#Endif;
#Endif;
#Ifdef _MSG_SCORE_DEFAULT_HAS_CASE;
	MSG_SCORE_DEFAULT:
#Ifdef NO_SCORE;
		"Es gibt keine Punkte in diesem Spiel.";
#Ifnot;
		if (deadflag) print "In diesem Spiel hast du"; else print "Bisher hast du";
		print " ", score, " von ", MAX_SCORE, " möglichen Punkten erreicht, in ", turns, " ";
		if(turns == 1) print "Zug"; else print "Zügen";
		rtrue;
#Endif;
#Endif;
#IfDef OPTIONAL_FULL_SCORE;
#Ifdef _MSG_FULLSCORE_START_HAS_CASE;
	MSG_FULLSCORE_START:
		print "Die Punktzahl setzt sich wie folgt zusammen:";
#EndIf;
#Ifdef _MSG_FULLSCORE_END_HAS_CASE;
	MSG_FULLSCORE_END:
		"insgesamt (von ", MAX_SCORE, ")";
#EndIf;
#EndIf;

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Infrequently used messages
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#Ifndef SKIP_MSG_LOOKMODE;
	MSG_LOOKMODE_NORMAL, MSG_LOOKMODE_LONG, MSG_LOOKMODE_SHORT:
		print "Dieses Spiel ist jetzt im ";
		if(lookmode==1) print "normalen ~";
		if(lookmode==2) print "~ausführlichen";
		else {
			if(lookmode==3) print "~sehr ";
			print "kurzen";
		}
		print "~ Modus, welcher ";
		if(lookmode ~= 1) print "immer ";
		print "gibt ";
		if(lookmode == 3) print "kurze";
		else print "lange";
		print " Beschreibungen von Orten ";
		if(lookmode == 1)
			"die noch nie besucht wurden, und ansonsten kurze.";
		print "(auch wenn du";
		if(lookmode == 2) print " dort schon warst";
		else print " dort noch nicht warst";
		").";
#Endif;
#Ifdef _MSG_RESTART_RESTORE_OR_QUIT_HAS_CASE;
	MSG_RESTART_RESTORE_OR_QUIT:
		print "^Möchtest du NEUSTART, WIEDERHERSTELLEN";
#Ifdef OPTIONAL_PROVIDE_UNDO_FINAL;
	#Ifdef DEATH_MENTION_UNDO;
			if(((HDR_GAMEFLAGS->1) & 16) ~= 0)
				print ", die letzte Runde RÜCKGÄNGIG machen";
	#Ifnot;
			if(((HDR_GAMEFLAGS->1) & 16) ~= 0 && deadflag ~= GS_WIN)
				print ", die letzte Runde RÜCKGÄNGIG machen";
	#Endif;
#Endif;
#IfDef OPTIONAL_FULL_SCORE;
		print ", die VOLLSTÄNDIGE Punktzahl dieses Spiels angeben";
#EndIf;
		if(AMUSING_PROVIDED == 0 && deadflag == 2) print ", einige Vorschläge für UNTERHALTSAME Aktivitäten sehen";
		print " oder BEENDEN? ";
		rtrue;
#EndIf;
#Ifdef _MSG_AREYOUSUREQUIT_HAS_CASE;
	MSG_AREYOUSUREQUIT: ! print and rtrue to avoid newline
		print "Bist du sicher, dass du das Spiel beenden willst? ";
		rtrue;
#EndIf;
#Ifdef _MSG_YOU_HAVE_WON_HAS_CASE;
	MSG_YOU_HAVE_WON: ! print and rtrue to avoid newline
 		print "Du hast gewonnen!";
 		rtrue;
#EndIf;
#Ifdef _MSG_YOU_HAVE_DIED_HAS_CASE;
	MSG_YOU_HAVE_DIED: ! print and rtrue to avoid newline
		print "Du bist gestorben!";
		rtrue;
#EndIf;
#Ifdef _MSG_YES_OR_NO_HAS_CASE;
	MSG_YES_OR_NO:
		print "Bitte antworte mit Ja oder Nein: ";
		rtrue;
#EndIf;
#Ifdef _MSG_RESTART_CONFIRM_HAS_CASE;
	MSG_RESTART_CONFIRM:
		print "Bist du sicher, dass du neu starten willst? ";
		rtrue;
#Endif;

#Ifdef _MSG_TAKE_DEFAULT_HAS_CASE;
	MSG_TAKE_DEFAULT:
		! "nehmen" = Akkusativ → (DE_Den)
		print_ret "Du nimmst ", (DE_Den) noun, " an dich.";
#EndIf;

#Ifndef NO_SCORE;
#Ifndef SKIP_MSG_NOTIFY_ON;
	MSG_NOTIFY_ON, MSG_NOTIFY_OFF:
		print "Spielstandsmeldung ";
		if(p_msg == MSG_NOTIFY_ON) "ein.";
		"aus.";
#Endif;
#Endif;

default:
		! No code found. Print an error message.
		_RunTimeError(ERR_UNKNOWN_MSGNO);
	}
];

! German gender/article helpers
! TODO: These need to be extended for full German grammatical gender support

[ ThatorThose p_obj;
	! Akkusativ Demonstrativpronomen nach Genus:
	! maskulin="den", feminin="die", Neutrum="das", Plural="die"
	if (p_obj has pluralname) { print "die";  return; }
	if (p_obj has female)     { print "die";  return; }
	if (p_obj has neuter)     { print "das";  return; }
	print "den";  ! maskulin Akkusativ
];

[ ItorThem p_obj;
	! Akkusativ-Pronomen nach Genus (für alle Objekte, belebt oder unbelebt):
	! maskulin="ihn", feminin="sie", Neutrum="es", Plural="sie"
	! Hinweis: Im Deutschen haben auch unbelebte Objekte Genus-abhängige Pronomina.
	if (p_obj == player)       { print "du selbst"; rtrue; }
	if (p_obj has pluralname)  { print "sie"; rtrue; }  ! Plural Akk = "sie"
	if (p_obj has female)      { print "sie"; rtrue; }  ! Feminin Akk = "sie"
	if (p_obj has neuter)      { print "es";  rtrue; }  ! Neutrum Akk = "es"
	print "ihn";  ! Maskulin Akk = "ihn" (Standard)
];

! Note: ItOrThem() is an alias for ItorThem() - Inform 6 is case-insensitive

[ CObjIs p_obj;
	! Nominativ: p_obj ist Subjekt, großgeschrieben → (DE_Der_Cap)
	print (DE_Der_Cap) p_obj, " ", (isorare) p_obj;
];

[ ObjIs p_obj;
	! Nominativ: p_obj ist Subjekt, kleingeschrieben → (DE_Der)
	print (DE_Der) p_obj, " ", (isorare) p_obj;
];

[ DoOrDoes p_obj;
	! TODO: German doesn't use "do/does" in the same way - returns generic form
	p_obj = p_obj; ! suppress warning
	print "tut";
];

[ HaveOrHas p_obj;
	! TODO: German "haben/hat"
	if (p_obj has pluralname) print "haben"; else print "hat";
];

[ IsorAre p_obj;
	! TODO: German "ist/sind"
	if (p_obj has pluralname || p_obj == player) print "sind"; else print "ist";
];

[ CTheyreorThats p_obj;
	! Nominativ "ist"-Ausdruck nach Genus (für belebte und unbelebte Objekte)
	if (p_obj == player)       { print "Du bist"; return; }
	if (p_obj has pluralname)  { print "Sie sind"; return; }
	if (p_obj has female)      { print "Sie ist"; return; }  ! feminin
	if (p_obj has neuter)      { print "Es ist";  return; }  ! Neutrum
	print "Er ist";  ! maskulin (Standard)
];

[ CTheyreorIts p_obj;
	! Für unbelebte Objekte: Genus-abhängig
	if (p_obj ~= player && p_obj hasnt pluralname) {
		if (p_obj has female)  { print "Sie ist"; return; }  ! feminin
		if (p_obj has neuter)  { print "Es ist";  return; }  ! Neutrum
		if (p_obj hasnt animate) { print "Er ist"; return; } ! maskulin (unbelebt)
	}
	CTheyreorThats(p_obj);
];

[ OnOff p_obj;
	! TODO: German "ein/aus"
	if(p_obj has on) print "ein";
	else print "aus";
	return;
];

[ SingularS p_obj;
	! German doesn't use -s for verb conjugation in the same way
	! but this is kept for compatibility
	p_obj = p_obj; ! suppress warning
];

! Note: thatorthose() is an alias for ThatorThose() - Inform 6 is case-insensitive

!
! Error messages
!
Constant ERR_TOO_MANY_TIMERS_DAEMONS 1;
Constant ERR_OBJECT_HASNT_PROPERTY 2;
Constant ERR_SCOPE_FULL 3;
Constant ERR_UNKNOWN_MSGNO 4;
Constant ERR_INVALID_DIR_PROP 5;
Constant ERR_TOO_MANY_FLOATING 6;
Constant ERR_NOT_DIR_PROP 7;
Constant ERR_NOT_FAKE_OBJ 8;
Constant ERR_ILLEGAL_CHOOSEOBJNO 9;
Constant ERR_BUFFER_OVERRUN 10;
Constant ERR_UNSAFE_GRAMMAR_PROP 11;

[_RunTimeError p_err p_obj _parent;
	print "^[PunyInformDE Fehler: ";
	if(p_err ofclass string)
		print (string) p_err;
	else {
		print p_err;
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
		print " - ";
		switch(p_err) {
		ERR_TOO_MANY_TIMERS_DAEMONS:
			print "Zu viele Timer/Daemons";
		ERR_OBJECT_HASNT_PROPERTY:
			print "Objekt fehlt erforderliche Eigenschaft";
		ERR_SCOPE_FULL:
			print "Umfang voll";
		ERR_UNKNOWN_MSGNO:
			print "Unbekannte Nachrichten-Nr.";
		ERR_INVALID_DIR_PROP:
			print "GoSub mit ungültiger Richtungseigenschaft aufgerufen";
		ERR_TOO_MANY_FLOATING:
			print "Zu viele schwebende Objekte";
		ERR_NOT_DIR_PROP:
			print "DirPropToFakeObj mit nicht-Dirprop aufgerufen";
		ERR_NOT_FAKE_OBJ:
			print "FakeObjToDirProp mit nicht-fakeobj aufgerufen";
		ERR_ILLEGAL_CHOOSEOBJNO:
			print "ChooseObjectsFinal_(Pick oder Discard) mit nicht vorhandenem Array-Index aufgerufen";
#Ifdef DEBUG;
		ERR_BUFFER_OVERRUN:
			print "Pufferüberlauf: Zu viele Zeichen in einen Puffer gedruckt";
		ERR_UNSAFE_GRAMMAR_PROP:
			print "Unsichere Verwendung der grammar-Eigenschaft";
#Endif;
		default:
			print "Unbekannter Fehler";
		}
#EndIf;
	}
	print "]^";
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
	if(p_obj ofclass object) {
		_parent = parent(p_obj);
		! Nominativ: p_obj ist Subjekt der Fehlermeldung → (DE_Der)
		print "Fehlerverursachendes Objekt: ", (DE_Der) p_obj, " (", p_obj, ") in ", (name) _parent, " (", _parent, ")^";
	}
#Ifnot;
	_parent = p_obj; ! Avoid compiler warning
#EndIf;
	rtrue;
];
