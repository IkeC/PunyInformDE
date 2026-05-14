"""Tests: describe=2 Eigenschaft (neues PunyInform-Feature post-v6.5).

describe=2 bedeutet: Das Objekt ist im Raum vorhanden und kann untersucht
werden, erscheint aber NICHT in der "Hier befinden sich..."-Liste und setzt
auch_flag nicht.

Testfall: Abendsonne im Oberdeck.
  - has neuter, kein has scenery
  - describe-Routine gibt 2 zurück
  - Muss NICHT in der Raumliste auftauchen
  - Muss mit "untersuche sonne" erreichbar sein
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import assert_output_contains, assert_output_not_contains

# ---------------------------------------------------------------------------
# Navigation zum Oberdeck (ASCII-sichere Befehle)
# ---------------------------------------------------------------------------
_GO_DECK = [
    "oeffne kiste",
    "nimm schluessel",
    "schliess tuer mit schluessel auf",
    "oeffne tuer",
    "nord",
    "rauf",
]


# ---------------------------------------------------------------------------
# describe=2: Objekt erscheint NICHT in der Raumliste
# ---------------------------------------------------------------------------

def test_describe2_not_in_room_listing(game):
    """Abendsonne (describe=2) darf nicht in der Hier-befinden-sich-Liste auftauchen."""
    out = game.run(_GO_DECK + ["schau"])
    assert_output_not_contains(
        out,
        "Abendsonne",
        msg="Abendsonne darf bei describe=2 nicht in der Raumliste erscheinen.",
    )


def test_describe2_not_in_room_listing_ascii(game_ascii):
    """ASCII: Abendsonne (describe=2) darf nicht in der Hier-befinden-sich-Liste auftauchen."""
    out = game_ascii.run(_GO_DECK + ["schau"])
    assert_output_not_contains(
        out,
        "Abendsonne",
        msg="Abendsonne darf bei describe=2 nicht in der Raumliste erscheinen.",
    )


# ---------------------------------------------------------------------------
# describe=2: Objekt kann trotzdem untersucht werden
# ---------------------------------------------------------------------------

def test_describe2_examinable(game):
    """Abendsonne (describe=2) muss direkt untersuchbar sein."""
    out = game.run(_GO_DECK + ["untersuche sonne"])
    assert_output_contains(
        out,
        "Sonnenuntergang",
        msg="Abendsonne muss trotz describe=2 eine Beschreibung haben.",
    )


def test_describe2_examinable_ascii(game_ascii):
    """ASCII: Abendsonne (describe=2) muss direkt untersuchbar sein."""
    out = game_ascii.run(_GO_DECK + ["untersuche sonne"])
    assert_output_contains(
        out,
        "Sonnenuntergang",
        msg="Abendsonne muss trotz describe=2 eine Beschreibung haben.",
    )
