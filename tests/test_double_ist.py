"""Tests: no double 'ist' in CTheyreorThats-based messages (issue a).

CTheyreorThats already prints "Er ist" / "Sie ist" / "Es ist" / "Sie sind".
Before the fix, several messages appended " ist ..." on top of that, producing
output like "Sie ist ist nicht portabel." (feminine scenery) or
"Er ist ist fixiert." (masculine static object).

This file verifies that each affected message produces exactly one 'ist'
(or 'sind' for plurals) and never the substring 'ist ist'.
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import assert_output_contains, assert_output_not_contains

DOUBLE_IST = "ist ist"


# ---------------------------------------------------------------------------
# MSG_TAKE_SCENERY — "(CTheyreorThats) nicht portabel."
# ---------------------------------------------------------------------------

def test_take_scenery_female_no_double_ist(game):
    """Taking a female scenery object must give 'Sie ist nicht portabel.' once."""
    out = game.run(["nimm koje"])
    assert_output_not_contains(out, DOUBLE_IST)
    assert_output_contains(out, "Sie ist nicht portabel.")


def test_take_scenery_female_no_double_ist_ascii(game_ascii):
    out = game_ascii.run(["nimm koje"])
    assert_output_not_contains(out, DOUBLE_IST)
    assert_output_contains(out, "Sie ist nicht portabel.")


def test_take_scenery_male_no_double_ist(game):
    """Taking a male scenery object must give 'Er ist nicht portabel.' once."""
    out = game.run(["nimm schreibtisch"])
    assert_output_not_contains(out, DOUBLE_IST)
    assert_output_contains(out, "Er ist nicht portabel.")


def test_take_scenery_male_no_double_ist_ascii(game_ascii):
    out = game_ascii.run(["nimm schreibtisch"])
    assert_output_not_contains(out, DOUBLE_IST)
    assert_output_contains(out, "Er ist nicht portabel.")


# ---------------------------------------------------------------------------
# MSG_EAT_INEDIBLE — "(CTheyreorThats) ungenießbar."
# ---------------------------------------------------------------------------

def test_eat_inedible_male_no_double_ist(game):
    """Eating an inedible masculine object must give 'Er ist ungenießbar.' once."""
    out = game.run(["iss ring"])
    assert_output_not_contains(out, DOUBLE_IST)
    assert_output_contains(out, "Er ist ungenie")  # covers both Unicode ß and ASCII ss


def test_eat_inedible_male_no_double_ist_ascii(game_ascii):
    out = game_ascii.run(["iss ring"])
    assert_output_not_contains(out, DOUBLE_IST)
    assert_output_contains(out, "Er ist ungenie")


def test_eat_inedible_female_no_double_ist(game):
    """Eating an inedible feminine object must give 'Sie ist ungenießbar.' once."""
    # Seekarte (female) is on the Schreibtisch; parser implicitly takes it before eating.
    out = game.run(["iss karte"])
    assert_output_not_contains(out, DOUBLE_IST)
    assert_output_contains(out, "Sie ist ungenie")  # covers both Unicode ß and ASCII ss


def test_eat_inedible_female_no_double_ist_ascii(game_ascii):
    out = game_ascii.run(["iss karte"])
    assert_output_not_contains(out, DOUBLE_IST)
    assert_output_contains(out, "Sie ist ungenie")
