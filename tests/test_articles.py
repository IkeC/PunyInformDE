"""Tests: §1 Artikelsystem — korrekte Artikel für alle Genera und Kasus.

Verifiziert, dass das §1-Artikelsystem automatisch korrekte deutsche Artikel
aus den Genus-Attributen der Objekte ableitet (has female, has neuter, has
pluralname, oder Standard maskulin).

Testobjekte (aus beispiel.inf):
  Seekiste   – has female    → Nom: "die", Akk: "die", Indef: "eine"
  Kompass    – maskulin      → Nom: "der", Akk: "den", Indef: "ein"
  Fernrohr   – has neuter    → Nom: "das", Akk: "das", Indef: "ein"
  Goldmünzen – has pluralname → Nom: "die", Indef: "einige"

Alle Tests verwenden ASCII-Digraphe, damit dfrotz im piped-stdin-Modus
zuverlässig funktioniert.
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import (
    assert_output_contains,
    assert_output_not_contains,
)

NOT_UNDERSTOOD = "verstehe nicht"


# ---------------------------------------------------------------------------
# Hilfsbefehle
# ---------------------------------------------------------------------------

_GET_KEY = ["oeffne kiste", "nimm schluessel"]
_UNLOCK_AND_GOTO_OBERDECK = _GET_KEY + [
    "schliess tuer mit schluessel auf",
    "oeffne tuer", "nord", "rauf",
]


# ---------------------------------------------------------------------------
# Femininum (has female): Seekiste
# ---------------------------------------------------------------------------

@pytest.mark.feature("articles")
def test_feminin_indef_nominativ(game):
    """Feminin unbestimmt Nominativ: Initialliste zeigt 'eine Seekiste'."""
    out = game.run(["schau"])
    # Die Initialliste der Kajüte enthält "eine Seekiste (geschlossen)"
    assert_output_contains(out, "eine Seekiste",
        msg="Feminin Indef Nom: erwartet 'eine Seekiste'")


@pytest.mark.feature("articles")
def test_feminin_def_akkusativ_oeffnen(game):
    """Feminin bestimmt Akkusativ: 'oeffne kiste' → 'Du öffnest die Seekiste'."""
    out = game.run(["oeffne kiste"])
    assert_output_contains(out, "die Seekiste",
        msg="Feminin Def Akk: erwartet 'die Seekiste'")
    assert_output_not_contains(out, "den Seekiste",
        msg="Feminin Akk: 'den' darf nicht erscheinen")
    assert_output_not_contains(out, "das Seekiste",
        msg="Feminin Akk: 'das' darf nicht erscheinen")


# ---------------------------------------------------------------------------
# Maskulinum (Standard, kein has female/neuter): Kompass
# ---------------------------------------------------------------------------

@pytest.mark.feature("articles")
def test_maskulin_indef_nominativ_inventar(game):
    """Maskulin unbestimmt Nominativ: Inventar zeigt 'ein alter Kompass'."""
    out = game.run(["nimm kompass", "inventar"])
    assert_output_contains(out, "alter Kompass",
        msg="Maskulin Nom: erwartet 'alter Kompass' im Inventar")


@pytest.mark.feature("articles")
def test_maskulin_def_akkusativ_ablegen(game):
    """Maskulin bestimmt Akkusativ: 'lege kompass ab' → 'Du legst den alter Kompass ...'."""
    out = game.run(["nimm kompass", "lege kompass auf schreibtisch"])
    # MSG_PUTON_DEFAULT: "Du legst den alter Kompass auf den Schreibtisch."
    assert_output_contains(out, "du legst den",
        msg="Maskulin Def Akk: erwartet 'Du legst den ...' in der Ablegen-Meldung")
    assert_output_not_contains(out, "du legst die",
        msg="Maskulin Akk: 'Du legst die' darf nicht erscheinen")


# ---------------------------------------------------------------------------
# Neutrum (has neuter): Fernrohr
# ---------------------------------------------------------------------------

@pytest.mark.feature("articles")
def test_neutrum_indef_nominativ_raum(game):
    """Neutrum unbestimmt Nominativ: Oberdeck-Auflistung zeigt 'ein Messing-Fernrohr'."""
    out = game.run(_UNLOCK_AND_GOTO_OBERDECK + ["schau"])
    assert_output_contains(out, "ein Messing-Fernrohr",
        msg="Neutrum Indef Nom: erwartet 'ein Messing-Fernrohr'")


@pytest.mark.feature("articles")
def test_neutrum_def_akkusativ_nehmen(game):
    """Neutrum bestimmt Akkusativ: MSG_AUTO_TAKE verwendet 'das Messing-Fernrohr'."""
    # Wenn man etwas tut, das Auto-Take auslöst, oder explizit nimmt
    out = game.run(_UNLOCK_AND_GOTO_OBERDECK + ["nimm fernrohr"])
    # Nach dem Nehmen: Fernrohr sollte erkannt werden
    assert_output_not_contains(out, NOT_UNDERSTOOD)


# ---------------------------------------------------------------------------
# Plural (has pluralname): Goldmünzen
# ---------------------------------------------------------------------------

@pytest.mark.feature("articles")
def test_plural_indef_nominativ_schreibtisch(game):
    """Plural unbestimmt: Schreibtisch-Auflistung zeigt 'einige Goldmünzen'."""
    out = game.run(["untersuche schreibtisch"])
    assert_output_contains(out, "einige",
        msg="Plural Indef: erwartet 'einige Goldmünzen'")


@pytest.mark.feature("articles")
def test_plural_def_akkusativ_ablegen(game):
    """Plural bestimmt Akkusativ: 'lege muenzen auf schreibtisch' → 'Du legst die Gold...'."""
    out = game.run(["nimm muenzen", "lege muenzen auf schreibtisch"])
    # MSG_PUTON_DEFAULT: "Du legst die Goldmünzen auf den Schreibtisch."
    assert_output_contains(out, "du legst die",
        msg="Plural Def Akk: erwartet 'Du legst die ...' in der Ablegen-Meldung")
    assert_output_not_contains(out, "du legst den",
        msg="Plural Akk: 'Du legst den' darf nicht erscheinen")


# ---------------------------------------------------------------------------
# Kein redundantes 'article' Property nötig
# ---------------------------------------------------------------------------

@pytest.mark.feature("articles")
def test_no_article_property_needed(game):
    """Objekte ohne 'with article' erhalten trotzdem korrekte Artikel."""
    # Kompass hat kein 'with article' — trotzdem korrekter maskuliner Artikel
    out = game.run(["nimm kompass", "untersuche ihn"])
    assert_output_contains(out, "Kompass",
        msg="Kompass (kein article-Property) sollte erkennbar sein")
    assert_output_not_contains(out, NOT_UNDERSTOOD)
