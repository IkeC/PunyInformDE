System_file;

! ext_talk_menu_alternative_de.h
! German, inline-dialog port of PunyDust/ext_talk_menu-dust.h
!
! ============================================================
! DIFFERENCES vs. ext_talk_menu.h  (see ext_talk_menu-dust.h in PunyDust)
! ============================================================
!
! PRESENTATION (Z5+):
!   Topics are listed INLINE in the main text window, not in a split upper
!   window.  The player types a number and presses Enter.
!
!     Standard ext_talk_menu.h (Z5):
!       Upper window menu — single keypress to select a topic.
!
!     This file (Z5+):
!       Gesprächsthemen:
!       [1] Wetter
!       [2] Schiff
!       [0] Gespräch beenden
!       > 1
!       [~Was siehst du dort draußen?~]
!       Steuermann Hinnerk kneift die Augen zusammen...
!
!   On Z3 builds the presentation is also inline (numbered topics in main
!   text, @sread input) with pagination for > 8 topics.
!
! PLAYER SPEECH FORMAT:
!   Player line:  [~text~]     (instead of "Du: ~text~")
!   NPC line:     text         (printed directly, no "Actor: ~text~" wrapper)
!
! ARRAY FORMAT — two breaking changes:
!   TM_END = -1  (was 26 in standard ext_talk_menu.h)
!   No TM_ACTIVATE (27), TM_INACTIVATE (28), TM_MAYBE_ADD_LIST (29)
!   Effects in talk arrays: relative refs (1–29), absolute IDs, flags,
!   or routines/strings — same as before.  Activated topics are always
!   re-activated (ReActivateTopic), so topics stay repeatable.
!
! USAGE:
!   Include "ext_talk_menu_alternative_de.h";   ! replaces ext_talk_menu.h
!
! To override a string or TMPrintLine, define it before the include:
!   Constant TM_MSG_EXIT "Tschüß!";
!   Include "ext_talk_menu_alternative_de.h";
! ============================================================

! ---------------------------------------------------------------------------
! Infrastructure
! ---------------------------------------------------------------------------

#Ifndef RUNTIME_ERRORS;
Constant RUNTIME_ERRORS = 2;
#Endif;
#Ifndef RTE_MINIMUM;
Constant RTE_MINIMUM = 0;
Constant RTE_NORMAL = 1;
Constant RTE_VERBOSE = 2;
#Endif;
#Iftrue RUNTIME_ERRORS > RTE_MINIMUM;
Constant TM_ERR = "^[Talk_menu error #";
#Endif;
#Ifdef DEBUG;
	#Ifndef TM_ERR;
	Constant TM_ERR = "^[Talk_menu error #";
	#Endif;
#Endif;

#Ifndef talk_array;
Property individual talk_array;
#Endif;

Global current_talker;

! ---------------------------------------------------------------------------
! German UI strings
! ---------------------------------------------------------------------------

#Ifndef TM_MSG_YOU;
Constant TM_MSG_YOU "Du";
#Endif;

#Ifndef TM_MSG_TALK_ABOUT_WHAT;
[ TM_MSG_TALK_ABOUT_WHAT;
	print "Worüber möchtest du mit ", (the) current_talker, " sprechen?^";
];
#Endif;

! Shown when all topics have been used up (auto-close).
! Leading ^ separates this from the last NPC response.
#Ifndef TM_MSG_TOPICS_DEPLETED;
Constant TM_MSG_TOPICS_DEPLETED "^Damit endet das Gespräch.";
#Endif;

! Shown when the player selects 0 / presses Enter without input.
#Ifndef TM_MSG_EXIT;
Constant TM_MSG_EXIT "Damit beendest du das Gespräch.";
#Endif;

! Shown when an NPC has no active topics at all.
#Ifndef TM_MSG_NO_TOPICS;
Constant TM_MSG_NO_TOPICS "Im Moment fällt dir kein passendes Thema ein.";
#Endif;

! Exit option label for the inline display.
! The trailing ^ prints the newline; the blank line before the prompt
! comes from RunTalk's new_line; statement that follows.
#Ifndef TM_MSG_EXIT_OPTION;
Constant TM_MSG_EXIT_OPTION "[0] Gespräch beenden^";
#Endif;

! Z3 only: short labels and next-page option for narrow status bar.
#Iftrue #version_number == 3;
#Ifndef TM_MSG_PAGE_OPTION;
Constant TM_MSG_PAGE_OPTION "[N] Nächste Seite";
#Endif;
#Ifndef TM_MSG_EXIT_OPTION_SHORT;
Constant TM_MSG_EXIT_OPTION_SHORT "[ENTER] Ende";
#Endif;
#Ifndef TM_MSG_PAGE_OPTION_SHORT;
Constant TM_MSG_PAGE_OPTION_SHORT "[N]ächste";
#Endif;
#Endif;

! ---------------------------------------------------------------------------
! Screenplay-style TMPrintLine
!   Player line:  [~text~]   — visually distinct, screenplay / book style
!   NPC line:     text        — printed directly; NPC identity comes from
!                               the text content itself (author's job)
! ---------------------------------------------------------------------------
#Ifndef TMPrintLine;
[TMPrintLine p_actor p_talk_actor p_line;
	if((p_talk_actor.talk_array)-->p_line == TM_NO_LINE) rfalse;
	if(p_actor == player) {
		print "[~";
		_TMCallOrPrint(p_talk_actor, p_line, true);
		print "~]^";
		rfalse;
	}
	_TMCallOrPrint(p_talk_actor, p_line, true);
];
#Endif;


Default TM_FIRST_ID = 300;
Default TM_LAST_ID = 600;

#Iftrue TM_FIRST_ID < 32;
Message fatalerror "*** ERROR: ext_talk_menu: TM_FIRST_ID must be in the range 32 to TM_LAST_ID ***";
#Endif;
#Iftrue TM_FIRST_ID > TM_LAST_ID;
Message fatalerror "*** ERROR: ext_talk_menu: TM_FIRST_ID must be in the range 32 to TM_LAST_ID ***";
#Endif;

! German strings define both TM_MSG_TOPICS_DEPLETED and TM_MSG_EXIT above,
! so the English fallback constant TM_REUSABLE_MSG_EXIT is never needed.
#Ifdef TM_MSG_TOPICS_DEPLETED;
#Ifdef TM_MSG_EXIT;
Constant TM_SKIP_MSG_EXIT;
#Endif;
#Endif;

#Ifndef TM_SKIP_MSG_EXIT;
Constant TM_REUSABLE_MSG_EXIT "With that, you politely end the conversation.";
#Endif;

! Topic-status constants (same as standard ext_talk_menu.h)
Constant TM_INACTIVE 0;
Constant TM_ACTIVE 30;
Constant TM_STALE 31;

! Array terminator: -1 (PunyDust convention; was 26 in standard ext_talk_menu.h)
Constant TM_END -1;

Constant TM_NO_LINE 1;
Constant TM_ADD_BEFORE 2;
Constant TM_ADD_AFTER 3;
Constant TM_ADD_BEFORE_AND_AFTER 4;
Constant TM_KEEP 5;

Global talk_menu_talking = false;
Global talk_menu_multi_mode = true;

! ---------------------------------------------------------------------------
! Internal helpers
! ---------------------------------------------------------------------------

[ _TMPrintMsg p_msg p_no_newline;
	if(metaclass(p_msg) == Routine) {
		p_msg();
		rtrue;
	}
	print (string) p_msg;
	if(p_no_newline == false) new_line;
];

! Actor-based: accesses p_actor.talk_array-->p_index
[ _TMCallOrPrint p_actor p_index p_no_newline;
	_TMPrintMsg((p_actor.talk_array)-->p_index, p_no_newline);
];

[ _SetTopic p_topic p_start p_value _index _val _find_topic _base _curr_id _success;
	_find_topic = p_topic;
	if(_find_topic < 0) _find_topic = -_find_topic;
	_index--;
	while(true) {
		_index++;
		_val = p_start-->_index;
		if(_val == TM_END) return _success;
		if(_val == TM_INACTIVE or TM_ACTIVE or TM_STALE) {
			if(_find_topic < 30) {
				if(_find_topic-- == 1) jump _tm_found_topic;
				continue;
			}
			_base = _index;
			while(true) {
				_index++;
				_curr_id = p_start-->_index;
				if(_curr_id < TM_FIRST_ID || _curr_id > TM_LAST_ID) {
					_index = _index + 2;
					break;
				}
				if(_curr_id == _find_topic) {
					_success = true;
					_index = _base;
._tm_found_topic;
					if(p_value == 1) return p_start-->_index;
					if(_val ~= TM_STALE || p_topic < 0) {
						p_start-->_index = p_value;
					}
					if(_find_topic < 30 || talk_menu_multi_mode == false) rtrue;
					_index = _index + 3;
					break;
				}
			}
		}
	}
];

[ ActivateTopic p_npc p_topic p_start;
	if(p_start == 0) p_start = p_npc.talk_array;
	p_start = _SetTopic(p_topic, p_start, TM_ACTIVE);
	#Ifdef DEBUG;
	#Iftrue RUNTIME_ERRORS > RTE_MINIMUM;
		if(p_start == 0) {
	#Iftrue RUNTIME_ERRORS == RTE_VERBOSE;
			print (string) TM_ERR,"3: Could not activate topic ", p_topic, " for NPC ", (name) p_npc, "]^";
	#Ifnot;
			print (string) TM_ERR,"3]^";
	#Endif;
			rfalse;
		}
	#Endif;
	#Endif;
	return p_start;
];

[ ReActivateTopic p_npc p_topic;
	return ActivateTopic(p_npc, -p_topic);
];

[ InactivateTopic p_npc p_topic p_start;
	if(p_start == 0) p_start = p_npc.talk_array;
	p_start = _SetTopic(p_topic, p_start, TM_INACTIVE);
	#Ifdef DEBUG;
	#Iftrue RUNTIME_ERRORS > RTE_MINIMUM;
		if(p_start == 0) {
	#Iftrue RUNTIME_ERRORS == RTE_VERBOSE;
			print (string) TM_ERR,"3: Could not inactivate topic ", p_topic, " for NPC ", (name) p_npc, "]^";
	#Ifnot;
			print (string) TM_ERR,"3]^";
	#Endif;
			rfalse;
		}
	#Endif;
	#Endif;
	return p_start;
];

[ ReInactivateTopic p_npc p_topic;
	return InactivateTopic(p_npc, -p_topic);
];

[ GetTopicStatus p_npc p_topic p_start;
	if(p_start == 0) p_start = p_npc.talk_array;
	return _SetTopic(p_topic, p_start, 1);
];

! ---------------------------------------------------------------------------
! RunTalk — two variants:
!   Z5+  Inline numbered list; player types a digit and presses Enter.
!   Z3   Inline numbered list with pagination; player types a digit + Enter
!        or N for next page.  (Z3 lacks @set_cursor / @erase_window so a
!        split upper-window is not used.)
! ---------------------------------------------------------------------------

#Iftrue #version_number > 3;

[ RunTalk p_npc _array _i _j _n _val _add_msg _count _shown_header;
	talk_menu_talking = true;
	current_talker = p_npc;
	_array = p_npc.talk_array;
#Iftrue RUNTIME_ERRORS > RTE_MINIMUM;
	if(~~(p_npc provides talk_array)) {
#Iftrue RUNTIME_ERRORS == RTE_VERBOSE;
		print_ret (string) TM_ERR,"1: Object ", p_npc, " (", (name) p_npc, ") doesn't provide talk_array]";
#Ifnot;
		print_ret (string) TM_ERR,"1]";
#Endif;
	}
#Endif;

._tm_restart_talk_after_line;
._tm_restart_talk;

	_i = -1;
	_n = 0;
	while(true) {
		_i++;
		_val = _array-->_i;
		if(_val == TM_END) break;
		if(_val == TM_INACTIVE or TM_STALE) { _i = _i + 3; continue; }
		if(_val == TM_ACTIVE) {
			_n++;
			if(_n == 1 && _shown_header == 0) {
				_TMPrintMsg(TM_MSG_TALK_ABOUT_WHAT);
				_shown_header = 1;
			}
			if(_n == 1) print "^";
			print "[", _n, "] ";
			_i++;
			_val = _array-->_i;
			while(_val >= TM_FIRST_ID && _val <= TM_LAST_ID) { _i++; _val = _array-->_i; }
			_TMCallOrPrint(p_npc, _i);
		}
	}

	if(_n == 0) {
		if(_j == 0) { _TMPrintMsg(TM_MSG_NO_TOPICS); rtrue; }
		! All topics exhausted after at least one exchange — auto-exit
		_TMPrintMsg(TM_MSG_TOPICS_DEPLETED);
		talk_menu_talking = false;
		rtrue;
	}

	_TMPrintMsg(TM_MSG_EXIT_OPTION, true);
	new_line;

	! Read player's choice
	_j = 0;
	while(_j == 0) {
		PrintMsg(MSG_PROMPT);
		buffer->1 = 0;
		@aread buffer parse -> _val;
		_val = parse->1;
		if(_val == 0) { _TMPrintMsg(TM_MSG_EXIT); rtrue; }
		_j = TryNumber(1);
		if(_j < 0 || _j > _n) _j = 0;
		if(_j == 0) { _TMPrintMsg(TM_MSG_EXIT); rtrue; }
	}

	! Find the _j-th active topic and print the exchange
	_i = -1;
	_n = 0;
	while(true) {
		_i++;
		_val = _array-->_i;
		if(_val == TM_ACTIVE) {
			_n++;
			if(_n < _j) continue;
			! This is the chosen topic
			_array-->_i = TM_STALE;
			_i++;
			_val = _array-->_i;
			while(_val >= TM_FIRST_ID && _val <= TM_LAST_ID) { _i++; _val = _array-->_i; }
			_count = _i;		! index of topic-name string (for TM_NO_LINE fallback)
			_i++;
			_add_msg = _array-->_i;
			if(_add_msg == TM_ADD_BEFORE or TM_ADD_AFTER or TM_ADD_BEFORE_AND_AFTER)
				_i++;
			if(_add_msg == TM_ADD_BEFORE or TM_ADD_BEFORE_AND_AFTER) {
				_TMCallOrPrint(p_npc, _i);
				_i++;
			}
			! Player speech
			if(_array-->_i == TM_NO_LINE) {
				_val = _array-->_count;
				if(metaclass(_val) == String)
					print "[~", (string) _val, "~]^";
				else if(metaclass(_val) == Routine) {
					print "[~"; _val(); print "~]^";
				}
			} else
				TMPrintLine(player, p_npc, _i);
			_i++;
			if(_add_msg == TM_ADD_AFTER or TM_ADD_BEFORE_AND_AFTER) {
				_TMCallOrPrint(p_npc, _i);
				_i++;
			}
			! NPC speech
			TMPrintLine(p_npc, p_npc, _i);
			break;
		}
	}

	! Apply effects
	_j = _i;
	while(true) {
		_j++;
		_val = _array-->_j;
		if(_val == TM_INACTIVE or TM_ACTIVE or TM_STALE or TM_END) break;
		if(_val > 0) {
			if(_val < 30) {
				ActivateTopic(p_npc, _val, _array + _j + _j);
				continue;
			}
			#Ifdef EXT_FLAGS;
			if(_val < TM_FIRST_ID) { SetFlag(_val); continue; }
			#Endif;
			if(_val <= TM_LAST_ID) {
				ReActivateTopic(p_npc, _val);
				continue;
			}
		}
		_TMCallOrPrint(p_npc, _j);
	}

	if(talk_menu_talking) {
		new_line;
		jump _tm_restart_talk_after_line;
	}
	talk_menu_talking = false;
	rtrue;
];

#Ifnot;

! Z3 variant: same inline style but with pagination (up to 8 topics per page)
! and @sread for input.
[ RunTalk p_npc _array _i _j _n _val _add_msg _count _offset _more;
	talk_menu_talking = true;
	current_talker = p_npc;
	_array = p_npc.talk_array;
#Iftrue RUNTIME_ERRORS > RTE_MINIMUM;
	if(~~(p_npc provides talk_array)) {
#Iftrue RUNTIME_ERRORS == RTE_VERBOSE;
		print_ret (string) TM_ERR,"1: Object ", p_npc, " (", (name) p_npc, ") doesn't provide talk_array]";
#Ifnot;
		print_ret (string) TM_ERR,"1]";
#Endif;
	}
#Endif;

._tm_restart_talk_after_line;
	_offset = 0;
._tm_restart_talk;
	_count = 0;
	_more = 0;
	_i = -1;
	_n = 0;
	while(true) {
		_i++;
		_val = _array-->_i;
		if(_val == TM_END) break;
		if(_val == TM_INACTIVE or TM_STALE) { _i = _i + 3; continue; }
		if(_val == TM_ACTIVE) {
			if(_count >= 8) { _more = 1; break; }
			_n++;
			if(_n <= _offset) continue;
			_count++;
			if(_count == 1) _TMPrintMsg(TM_MSG_TALK_ABOUT_WHAT);
			print "  ", _count, ": ";
			_i++;
			_val = _array-->_i;
			while(_val >= TM_FIRST_ID && _val <= TM_LAST_ID) { _i++; _val = _array-->_i; }
			_TMCallOrPrint(p_npc, _i);
		}
	}

	if(_n == 0) {
		if(_j == 0) { _TMPrintMsg(TM_MSG_NO_TOPICS); rtrue; }
		! All topics exhausted after at least one exchange — auto-exit
		_TMPrintMsg(TM_MSG_TOPICS_DEPLETED);
		talk_menu_talking = false;
		rtrue;
	}

	_i = TM_MSG_EXIT_OPTION;
	_j = TM_MSG_PAGE_OPTION;
	_TMPrintMsg(_i, true);
	if(_more || _offset) { print "  "; _TMPrintMsg(_j, true); }
	new_line;

	_j = 0;
	while(_j == 0) {
		PrintMsg(MSG_PROMPT);
		@sread buffer parse;
		_n = parse->1;
		if(_n == 0) { _TMPrintMsg(TM_MSG_EXIT); rtrue; }
		_val = buffer->1;
		if(_val == 'n') {
			if(_more) { _offset = _offset + 8; jump _tm_restart_talk; }
			else if(_offset) { _offset = 0; jump _tm_restart_talk; }
		}
		_j = TryNumber(1);
		if(_j < 0 || _j > _count) _j = 0;
		if(_j == 0) { _TMPrintMsg(TM_MSG_EXIT); rtrue; }
	}

	_j = _j + _offset;
	_i = -1;
	_n = 0;
	while(true) {
		_i++;
		_val = _array-->_i;
		if(_val == TM_ACTIVE) {
			_n++;
			if(_n < _j) continue;
			_array-->_i = TM_STALE;
			_i++;
			_val = _array-->_i;
			while(_val >= TM_FIRST_ID && _val <= TM_LAST_ID) { _i++; _val = _array-->_i; }
			_count = _i;
			_i++;
			_add_msg = _array-->_i;
			if(_add_msg == TM_ADD_BEFORE or TM_ADD_AFTER or TM_ADD_BEFORE_AND_AFTER)
				_i++;
			if(_add_msg == TM_ADD_BEFORE or TM_ADD_BEFORE_AND_AFTER) {
				_TMCallOrPrint(p_npc, _i);
				_i++;
			}
			if(_array-->_i == TM_NO_LINE) {
				_val = _array-->_count;
				if(metaclass(_val) == String)
					print "[~", (string) _val, "~]^";
				else if(metaclass(_val) == Routine) {
					print "[~"; _val(); print "~]^";
				}
			} else
				TMPrintLine(player, p_npc, _i);
			_i++;
			if(_add_msg == TM_ADD_AFTER or TM_ADD_BEFORE_AND_AFTER) {
				_TMCallOrPrint(p_npc, _i);
				_i++;
			}
			TMPrintLine(p_npc, p_npc, _i);
			break;
		}
	}

	_j = _i;
	while(true) {
		_j++;
		_val = _array-->_j;
		if(_val == TM_INACTIVE or TM_ACTIVE or TM_STALE or TM_END) break;
		if(_val > 0) {
			if(_val < 30) { ActivateTopic(p_npc, _val, _array + _j + _j); continue; }
			#Ifdef EXT_FLAGS;
			if(_val < TM_FIRST_ID) { SetFlag(_val); continue; }
			#Endif;
			if(_val <= TM_LAST_ID) { ReActivateTopic(p_npc, _val); continue; }
		}
		_TMCallOrPrint(p_npc, _j);
	}

	if(talk_menu_talking) {
		new_line;
		jump _tm_restart_talk_after_line;
	}
	talk_menu_talking = false;
	rtrue;
];

#Endif;

! ---------------------------------------------------------------------------
[ TalkSub;
#Ifdef PUNYINFORM_MAJOR_VERSION;
   if (noun==player) { PrintMsg(MSG_TELL_PLAYER); rtrue; }
   if (~~(noun provides talk_array)) { second = noun; PrintMsg(MSG_SHOW_DEFAULT); rtrue; }
#Ifnot;
   if (noun==player) { L__M(##Tell, 1, noun); rtrue; }
   if (~~(noun provides talk_array)) { L__M(##Show, 2, second); rtrue; }
#Endif;
   RunTalk(noun);
   AfterRoutines();
];

Verb 'talk' 'converse' 'interview' 'interrogate'
	* 'to'/'with' creature                      ->Talk
	* creature                                  ->Talk;

#IfDef LANG_DE;
Verb 'rede' 'unterhalte' 'plaudere' 'diskutier'
	* 'mit' creature                            ->Talk
	* creature                                  ->Talk;
#EndIf;
