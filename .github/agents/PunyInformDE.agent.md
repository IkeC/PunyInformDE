---
name: PunyInformDE
description: Continues the PunyInform plan with... (see docs/project-plan.md)

Understands and executes tasks closely following the project plan at `docs/project-plan.md`. Update the `docs/project-plan.md`, `docs/Implementation.md` and `README.md` with the current state and progress. `example\beispiel.inf` is a definition for an example adventure - extend and/or rewwrite it to cover the changes we made. "example\beispiel.walkthrough.txt" shall contain a full walkthrough of the game that shall also be covered by tests. Test using PunyTest and put them in `tests/`. Always run a builds and all tests in a loop until the task is complete.

## Base File Policy (CRITICAL)

The files `lib/globals.h`, `lib/puny.h`, `lib/grammar.h`, `lib/parser.h`, `lib/scope.h`, and `lib/messages.h` are **base PunyInform files**. They MUST NOT be modified with language-specific content (German words, German strings, German grammar).

**The only allowed changes to base files** are minimal, language-agnostic **extension points** — i.e., adding `#IfNDef SOME_CONSTANT; Constant SOME_CONSTANT = "english default"; #EndIf;` defaults or `#IfDef SOME_FLAG;` conditional blocks that are activated by constants defined in `lib/de/` files. The German content always lives in `lib/de/`.

**All German translations belong exclusively in `lib/de/` files:**
- `lib/de/globals_de.h` — German constants (words, strings, flags like `EXTRA_DIRECTION_ROW`, `AND_LIST_STR`)
- `lib/de/grammar_de.h` — German verb definitions
- `lib/de/messages_de.h` — German message text
- `lib/de/puny_de.h` — German helpers (if needed)

**Rationale:** Functions cannot be redefined in Inform 6 after compilation. Where German override functions (`_PrintObjName`, `_PrintAfterEntry`) exist in `puny.h`, they are marked `! PunyInformDE:` and are a known, documented exception. No new such exceptions should be introduced without explicit justification.

Before modifying any base file, ask: "Can this be achieved by defining a constant in `globals_de.h` that the base file already checks (or can check via `#IfNDef`/`#IfDef`)?" If yes, do that instead.
