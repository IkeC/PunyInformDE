# PunyInformDE Changelog

## 2026-11-18 - PunyInform 6.9 synchronization

Updated the shared library to PunyInform 6.9 and included the subsequent fix
for Z6 transcript input. German grammar, messages, article declension, and
pronoun handling remain PunyInformDE-specific.

### PunyInform 6.8

- Added Z6-aware status-line handling and support for Z6 colours.
- Fixed `IsAString`, `IsARoutine`, and `RunRoutines` for odd/even packed Z6/Z7
  story files compiled with `-B`.
- Added `lib/ext_z6graphics.h` for Z6 windows, colours, cursor, mouse, and
  picture operations.
- Adjusted menu, quote-box, and talk-menu geometry for Z6 screen units.
- Cleared stale `inp1` and `inp2` values before parsing each action.

### PunyInform 6.9

- Fixed disambiguation when the player enters a new command instead of
  answering the noun question.
- Fixed compilation with `DEBUG_PARSEPATTERN` and with `DEBUG` plus
  `OPTIONAL_NO_ADD_TO_SCOPE`.
- Added a Z6 picture-window example upstream; added the Z6 graphics extension
  to PunyInformDE.
- Added `Z6MoveCursor_Units`, `Z6DrawPicture_Units`, and the
  `HandleFunctionKey` entry point.
- Fixed Z6 status-line width handling and allowed Space to select menu entries.
- Optimized Z3 multiple-object parsing and `MoveFloatingObjects`.
- Improved debug scope output and the `DEBUG REACTIVE` suggestions.
- Refined the upstream compile-all test handling for Z6 programs.

### Post-6.9 upstream fix

- `_ReadPlayerInput` now copies Z6 keyboard input into an active transcript.

### PunyInformDE corrections completed with this sync

- Completed `OPTIONAL_NO_ADD_TO_SCOPE` support. Earlier localisation work had
  dropped three upstream guards, so `add_to_scope` was still declared and
  referenced even when the option was enabled:
  - the `add_to_scope` property in `selfobj` (`lib/puny.h`);
  - the `add_to_scope` check in `_InitObjects` (`lib/puny.h`);
  - the `_ObjectScopedBySomething` routine and its caller in
    `ObjectIsUntouchable` (`lib/scope.h`).
- Removed a leftover `DEBUG_TIMER` timing print that upstream deleted in 6.9.

### PunyInformDE example and validation

- Added an off-room `Flagzeichen` to `sterne.inf`, placed in scope by a
  routine-based `add_to_scope`; Unicode and ASCII tests cover the behavior.
- Added a regression for a new command typed at a disambiguation prompt. The
  compound phrase `untersuche schuhe und plakat` reaches the phase-2 reparse
  path; without the 6.9 fix the following command is silently lost.
- Added compile regressions for `DEBUG` + `DEBUG_PARSEPATTERN` +
  `OPTIONAL_NO_ADD_TO_SCOPE`, and for Z6 odd/even packing (`-v6 -B`) with the
  menu, quote-box, talk-menu and Z6 graphics extensions.
- Added a Z6 build (`build/sterne.z6`) to the build script. Z6 is covered by
  compile checks and a manual interpreter run; the automated transcript tests
  remain Z3/Z5 only.
- Kept the `Abendsonne` `describe=2` regression in the example and test suite.
- Updated the walkthrough and project version notes for the 6.9 base.
