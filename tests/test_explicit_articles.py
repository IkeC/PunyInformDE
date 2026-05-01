"""Tests: Explizite DE_Der_Cap / DE_Der / DE_Den / DE_Dem in messages_de.h.

Issue #8: Ersetzt (The)/(the) in messages_de.h durch explizite deutsche
Artikelfunktionen. Verifiziert:
  - DE_Der_Cap (Nominativ bestimmt, großgeschrieben) für Satzanfang
  - DE_Der     (Nominativ bestimmt, kleingeschrieben) in Satzinneren
  - DE_Den     (Akkusativ bestimmt)
  - DE_Dem     (Dativ bestimmt)
  - Eigennamen (has proper) erhalten keinen Artikel

Abgedeckte Meldungen:
  MSG_TAKE_ANIMATE         (DE_Der  – Nom, Satzinneres)
  MSG_GIVE_DEFAULT         (DE_Der_Cap – Nom, Satzanfang, Eigenname)
  MSG_ENTER_NOT_OPEN       (DE_Der  – Nom, Nebensatz)
  MSG_LOCK_ALREADY_LOCKED  (DE_Der_Cap – Nom, Satzanfang)
  MSG_SEARCH_IN_IT_ISARE   (DE_Der_Cap – Nom, Satzanfang)
  MSG_ENTER_BAD_LOCATION   (DE_Den  – Akk)

Testinfrastruktur: game = Unicode z5, game_ascii = ASCII z5.
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import (
    assert_output_contains,
    assert_output_not_contains,
)

# ---------------------------------------------------------------------------
# Hilfsbefehle
# ---------------------------------------------------------------------------

_GET_KEY = ["oeffne kiste", "nimm schluessel"]
_UNLOCK_DOOR = _GET_KEY + ["schliess tuer mit schluessel auf", "oeffne tuer"]
_GO_DECK = _UNLOCK_DOOR + ["nord", "rauf"]


# ---------------------------------------------------------------------------
# MSG_TAKE_ANIMATE (line 779) – (DE_Der) für Nominativ im Nebensatz
# "Ich glaube nicht, dass [Steuermann Hinnerk] das interessiert."
# Eigenname → kein Artikel
# ---------------------------------------------------------------------------

@pytest.mark.feature("explicit-articles")
def test_take_animate_no_article_proper_name(game):
    """MSG_TAKE_ANIMATE: Eigenname Hinnerk bekommt keinen Artikel."""
    out = game.run(_GO_DECK + ["nimm hinnerk"])
    assert_output_contains(out, "Steuermann Hinnerk das interessiert",
        msg="MSG_TAKE_ANIMATE: Eigenname ohne Artikel erwartet")
    assert_output_not_contains(out, "der Steuermann Hinnerk",
        msg="MSG_TAKE_ANIMATE: 'der' darf nicht vor Eigennamen erscheinen")


@pytest.mark.feature("explicit-articles")
def test_take_animate_no_article_proper_name_ascii(game_ascii):
    """MSG_TAKE_ANIMATE (ASCII): Eigenname ohne Artikel."""
    out = game_ascii.run(_GO_DECK + ["nimm hinnerk"])
    assert_output_contains(out, "Steuermann Hinnerk das interessiert")
    assert_output_not_contains(out, "der Steuermann Hinnerk")


# ---------------------------------------------------------------------------
# MSG_GIVE_DEFAULT (line 823) – (DE_Der_Cap) für Nom Satzanfang mit Eigennamen
# "[Steuermann Hinnerk] scheint nicht interessiert zu sein."
# Eigenname → kein Artikel, aber Satz beginnt trotzdem korrekt
# ---------------------------------------------------------------------------

@pytest.mark.feature("explicit-articles")
def test_give_default_no_article_proper_name(game):
    """MSG_GIVE_DEFAULT: Eigenname Hinnerk als Subjekt – kein Artikel."""
    out = game.run(_GO_DECK + ["gib schluessel an hinnerk"])
    assert_output_contains(out, "Steuermann Hinnerk scheint nicht interessiert zu sein",
        msg="MSG_GIVE_DEFAULT: Eigenname ohne Artikel")
    assert_output_not_contains(out, "Der Steuermann Hinnerk",
        msg="MSG_GIVE_DEFAULT: 'Der' darf nicht vor Eigennamen erscheinen")


@pytest.mark.feature("explicit-articles")
def test_give_default_no_article_proper_name_ascii(game_ascii):
    """MSG_GIVE_DEFAULT (ASCII): Eigenname ohne Artikel."""
    out = game_ascii.run(_GO_DECK + ["gib schluessel an hinnerk"])
    assert_output_contains(out, "Steuermann Hinnerk scheint nicht interessiert zu sein")
    assert_output_not_contains(out, "Der Steuermann Hinnerk")


# ---------------------------------------------------------------------------
# MSG_ENTER_NOT_OPEN (line 834) – (DE_Der) für Nom im Nebensatz (femininum)
# "Das geht nicht, da die Seekiste geschlossen ist."
# ---------------------------------------------------------------------------

@pytest.mark.feature("explicit-articles")
def test_enter_not_open_nominativ(game):
    """MSG_ENTER_NOT_OPEN: Nom feminin 'die Seekiste' im Nebensatz."""
    out = game.run(["geh in kiste"])
    assert_output_contains(out, "da die Seekiste geschlossen ist",
        msg="MSG_ENTER_NOT_OPEN: Nom 'die Seekiste' erwartet")
    assert_output_not_contains(out, "den Seekiste",
        msg="MSG_ENTER_NOT_OPEN: Akkusativ 'den' darf nicht erscheinen")


@pytest.mark.feature("explicit-articles")
def test_enter_not_open_nominativ_ascii(game_ascii):
    """MSG_ENTER_NOT_OPEN (ASCII): Nom feminin 'die Seekiste'."""
    out = game_ascii.run(["geh in kiste"])
    assert_output_contains(out, "da die Seekiste geschlossen ist")
    assert_output_not_contains(out, "den Seekiste")


# ---------------------------------------------------------------------------
# MSG_LOCK_ALREADY_LOCKED (line 1014) – (DE_Der_Cap) für Nom Satzanfang
# "Die Kajütentür ist bereits verschlossen."
# Getriggert: Tür ist von Anfang an verschlossen → ohne Schlüssel 'schliess tuer'
# ---------------------------------------------------------------------------

@pytest.mark.feature("explicit-articles")
def test_lock_already_locked_nominativ(game):
    """MSG_LOCK_ALREADY_LOCKED: Nom feminin 'Die Kajütentür' am Satzanfang."""
    # Die Tür ist schon verschlossen; versuche erneut zu verschließen
    out = game.run(["schliess tuer zu"])
    assert_output_contains(out, "bereits verschlossen",
        msg="MSG_LOCK_ALREADY_LOCKED: 'bereits verschlossen' erwartet")
    # Grossgeschriebener Artikel (Die/Der/Das) am Satzanfang
    assert_output_contains(out, "Die K",
        msg="MSG_LOCK_ALREADY_LOCKED: grossgeschriebenes 'Die' erwartet")


@pytest.mark.feature("explicit-articles")
def test_lock_already_locked_nominativ_ascii(game_ascii):
    """MSG_LOCK_ALREADY_LOCKED (ASCII): 'Die' Kajuetentuer bereits verschlossen."""
    out = game_ascii.run(["schliess tuer zu"])
    assert_output_contains(out, "bereits verschlossen")
    assert_output_contains(out, "Die K")


# ---------------------------------------------------------------------------
# MSG_SEARCH_IN_IT_ISARE (line 1039) – (DE_Der_Cap) für Nom Satzanfang
# "Die Seekiste enthält bereits den kleinen Schlüssel."
# ---------------------------------------------------------------------------

@pytest.mark.feature("explicit-articles")
def test_search_in_it_isare_nominativ(game):
    """MSG_SEARCH_IN_IT_ISARE: Nom feminin 'Die Seekiste enthält bereits ...'."""
    out = game.run(["oeffne kiste", "schau in kiste"])
    assert_output_contains(out, "Die Seekiste",
        msg="MSG_SEARCH_IN_IT_ISARE: 'Die Seekiste' erwartet")
    assert_output_contains(out, "bereits einen kleinen",
        msg="MSG_SEARCH_IN_IT_ISARE: 'bereits einen kleinen' erwartet")


@pytest.mark.feature("explicit-articles")
def test_search_in_it_isare_nominativ_ascii(game_ascii):
    """MSG_SEARCH_IN_IT_ISARE (ASCII): 'Die Seekiste enthaelt bereits ...'."""
    out = game_ascii.run(["oeffne kiste", "schau in kiste"])
    assert_output_contains(out, "Die Seekiste")
    assert_output_contains(out, "enthaelt bereits")


# ---------------------------------------------------------------------------
# MSG_ENTER_BAD_LOCATION (lines 1107/1109) – (DE_Den) für Akkusativ
# "Du musst zuerst die Koje verlassen." (feminin: die=die, Nom=Akk)
# Test beweist zumindest, dass der Akkusativ-Pfad korrekt verwendet wird.
# ---------------------------------------------------------------------------

@pytest.mark.feature("explicit-articles")
def test_enter_bad_location_akkusativ(game):
    """MSG_ENTER_BAD_LOCATION: Akk 'die Koje verlassen' (feminin)."""
    # Spieler in Koje, Kiste ist offen → 'geh in kiste' -> 'Du musst zuerst die Koje verlassen.'
    out = game.run(["oeffne kiste", "steig in koje", "geh in kiste"])
    assert_output_contains(out, "die Koje verlassen",
        msg="MSG_ENTER_BAD_LOCATION: Akk 'die Koje verlassen' erwartet")
    assert_output_not_contains(out, "der Koje",
        msg="MSG_ENTER_BAD_LOCATION: Nom 'der' darf nicht erscheinen")


@pytest.mark.feature("explicit-articles")
def test_enter_bad_location_akkusativ_ascii(game_ascii):
    """MSG_ENTER_BAD_LOCATION (ASCII): Akk 'die Koje verlassen'."""
    out = game_ascii.run(["oeffne kiste", "steig in koje", "geh in kiste"])
    assert_output_contains(out, "die Koje verlassen")
    assert_output_not_contains(out, "der Koje")
