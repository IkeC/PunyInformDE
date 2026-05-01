"""Tests: enterable container messages (issues #9-#12).

Covers four problems with entering containers/vehicles:

  Issue #9: 'steige in X' not recognised (grammar missing '* in noun -> Enter')
  Issue #10: MSG_ENTER_NOT_OPEN double 'ist' — "die Seekiste ist geschlossen ist."
  Issue #11: MSG_OPEN_DEFAULT shows "und siehst nichts" for empty container
  Issue #12: MSG_ENTER_DEFAULT uses "betrittst" instead of "gehst in"

All tests use the 'Seekiste' object in sterne.inf, which has:
  has female openable enterable container (starts closed, contains the Schlüssel)
The Seekiste already exists in the first room — no extra object needed.
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import (
    assert_output_contains,
    assert_output_not_contains,
)

UNKNOWN_VERB   = "kenne ich nicht"
NOT_UNDERSTOOD = "verstehe nicht"

_OPEN_CHEST = ["oeffne kiste"]
# To test an empty container: open → take key → close → reopen.
# Close verb token differs between Unicode and ASCII builds.
_EMPTY_CHEST_UNICODE = ["oeffne kiste", "nimm schluessel", "schlie\u00df kiste"]
_EMPTY_CHEST_ASCII   = ["oeffne kiste", "nimm schluessel", "schliess kiste"]


# ---------------------------------------------------------------------------
# Issue #10: MSG_ENTER_NOT_OPEN — no double "ist"
# ---------------------------------------------------------------------------

@pytest.mark.feature("enterable")
def test_enter_closed_container_no_double_ist(game):
    """Trying to enter a closed container must not produce 'ist geschlossen ist'."""
    out = game.run(["geh in kiste"])
    assert_output_not_contains(out, "ist geschlossen ist",
        msg="Double 'ist' must not appear in the closed-container message")
    assert_output_contains(out, "geschlossen ist",
        msg="Message should still say '... geschlossen ist.'")


@pytest.mark.feature("enterable")
def test_enter_closed_container_no_double_ist_ascii(game_ascii):
    """ASCII build: same double-'ist' check."""
    out = game_ascii.run(["geh in kiste"])
    assert_output_not_contains(out, "ist geschlossen ist")
    assert_output_contains(out, "geschlossen ist")


# ---------------------------------------------------------------------------
# Issue #11: MSG_OPEN_DEFAULT — no "und siehst nichts" for empty container
# ---------------------------------------------------------------------------

@pytest.mark.feature("enterable")
def test_open_empty_container_no_siehst_nichts(game):
    """Opening an empty container must not say 'und siehst nichts'."""
    out = game.run(_EMPTY_CHEST_UNICODE + ["oeffne kiste"])
    assert_output_not_contains(out, "siehst nichts",
        msg="'und siehst nichts' must not appear when container is empty")
    assert_output_contains(out, "ffnest die Seekiste",
        msg="Open confirmation should still appear")


@pytest.mark.feature("enterable")
def test_open_empty_container_no_siehst_nichts_ascii(game_ascii):
    """ASCII build: same check for empty container open."""
    out = game_ascii.run(_EMPTY_CHEST_ASCII + ["oeffne kiste"])
    assert_output_not_contains(out, "siehst nichts")
    assert_output_contains(out, "ffnest die Seekiste")


# ---------------------------------------------------------------------------
# Issue #12: MSG_ENTER_DEFAULT — "gehst in" not "betrittst"
# ---------------------------------------------------------------------------

@pytest.mark.feature("enterable")
def test_enter_container_gehst_in_not_betrittst(game):
    """Entering a container says 'Du gehst in ...' not 'Du betrittst ...'."""
    out = game.run(_OPEN_CHEST + ["gehe in kiste"])
    assert_output_not_contains(out, "betrittst",
        msg="'betrittst' must not appear when entering a container")
    assert_output_contains(out, "gehst in",
        msg="Expected 'Du gehst in ...'")


@pytest.mark.feature("enterable")
def test_enter_container_gehst_in_not_betrittst_ascii(game_ascii):
    """ASCII build: entering container says 'gehst in'."""
    out = game_ascii.run(_OPEN_CHEST + ["gehe in kiste"])
    assert_output_not_contains(out, "betrittst")
    assert_output_contains(out, "gehst in")


# ---------------------------------------------------------------------------
# Issue #9: grammar — 'steige in X' recognised as Enter
# ---------------------------------------------------------------------------

@pytest.mark.feature("enterable")
def test_steige_in_accepted(game):
    """'steige in kiste' must be understood as an Enter command (no parser error)."""
    out = game.run(_OPEN_CHEST + ["steige in kiste"])
    assert_output_not_contains(out, NOT_UNDERSTOOD,
        msg="'steige in kiste' must be parsed, not produce 'verstehe nicht'")
    assert_output_not_contains(out, UNKNOWN_VERB)


@pytest.mark.feature("enterable")
def test_steige_in_accepted_ascii(game_ascii):
    """ASCII build: 'steige in kiste' is accepted."""
    out = game_ascii.run(_OPEN_CHEST + ["steige in kiste"])
    assert_output_not_contains(out, NOT_UNDERSTOOD)
    assert_output_not_contains(out, UNKNOWN_VERB)


# ---------------------------------------------------------------------------
# Issue a: 'x' abbreviation prints German verb name
# ---------------------------------------------------------------------------

@pytest.mark.feature("enterable")
def test_x_abbreviation_prints_german(game):
    """'x' abbreviation: parser error must say 'untersuche etwas', not 'examine etwas'."""
    out = game.run(["x"])
    assert_output_not_contains(out, "examine",
        msg="English 'examine' must not appear in parser message")
    assert_output_contains(out, "untersuche",
        msg="German 'untersuche' must appear in parser message for 'x'")


@pytest.mark.feature("enterable")
def test_x_abbreviation_prints_german_ascii(game_ascii):
    """ASCII build: same check for 'x' abbreviation."""
    out = game_ascii.run(["x"])
    assert_output_not_contains(out, "examine")
    assert_output_contains(out, "untersuche")


# ---------------------------------------------------------------------------
# Issue b: 'raus' as standalone verb exits container
# ---------------------------------------------------------------------------

@pytest.mark.feature("enterable")
def test_raus_exits_container(game):
    """'raus' alone must exit the Seekiste (Exit action)."""
    out = game.run(_OPEN_CHEST + ["gehe in kiste", "raus"])
    assert_output_not_contains(out, NOT_UNDERSTOOD,
        msg="'raus' must be understood")
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_contains(out, "sst die Seekiste",
        msg="Expected exit confirmation 'Du verl\u00e4sst die Seekiste.'")


@pytest.mark.feature("enterable")
def test_raus_exits_container_ascii(game_ascii):
    """ASCII build: 'raus' exits container."""
    out = game_ascii.run(_OPEN_CHEST + ["gehe in kiste", "raus"])
    assert_output_not_contains(out, NOT_UNDERSTOOD)
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_contains(out, "verlaesst die Seekiste")


