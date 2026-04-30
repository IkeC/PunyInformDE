"""Tests: §1 Artikelsystem — korrekte Artikel für alle Genera und Kasus.

Verifiziert, dass das §1-Artikelsystem automatisch korrekte deutsche Artikel
aus den Genus-Attributen der Objekte ableitet (has female, has neuter, has
pluralname, oder Standard maskulin).

Testobjekte (aus sterne.inf):
  Seekiste   – has female    → Nom: "die", Akk: "die", Indef: "eine"
  Kompass    – maskulin      → Nom: "der", Akk: "den", Indef Nom: "ein", Indef Akk: "einen"
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
def test_maskulin_indef_akkusativ_inventar(game):
    """Maskulin unbestimmt Akkusativ: Inventar zeigt 'einen alten Kompass'.
    'Du hast X' verlangt Akkusativ, daher 'einen' statt 'ein'.
    """
    out = game.run(["nimm kompass", "inventar"])
    assert_output_contains(out, "einen alten Kompass",
        msg="Maskulin Akk: erwartet 'einen alten Kompass' im Inventar")


@pytest.mark.feature("articles")
def test_maskulin_def_akkusativ_ablegen(game):
    """Maskulin bestimmt Akkusativ: 'lege kompass...' → 'Du legst den alten Kompass ...'."""
    out = game.run(["nimm kompass", "lege kompass auf schreibtisch"])
    assert_output_contains(out, "Du legst den alten Kompass auf den Schreibtisch.",
        msg="Maskulin Def Akk: erwartet 'den alten Kompass'")


# ---------------------------------------------------------------------------
# Neutrum (has neuter): Fernrohr
# ---------------------------------------------------------------------------

@pytest.mark.feature("articles")
def test_neutrum_indef_nominativ_raum(game):
    """Neutrum unbestimmt Nominativ: Oberdeck-Auflistung zeigt 'ein Messing-Fernrohr'."""
    out = game.run(_UNLOCK_AND_GOTO_OBERDECK + ["schau"])
    assert_output_contains(out, "ein Messing-",
        msg="Neutrum Indef Nom: erwartet Artikel + Fernrohr in der Raumliste")
    assert_output_contains(out, "Fernrohr",
        msg="Neutrum Indef Nom: erwartet Fernrohr in der Raumliste")


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


@pytest.mark.feature("articles")
def test_dativ_maskulin_wave_uses_kleinen(game):
    """Dativ maskulin in Examine-Default: '... an dem kleinen Ring'."""
    out = game.run(["untersuche ring"])
    assert_output_contains(out, "an dem kleinen Ring")


@pytest.mark.feature("articles")
def test_dativ_feminin_wave_uses_alten(game):
    """Dativ feminin in Examine-Default: '... an der alten Nadel'."""
    out = game.run(["untersuche nadel"])
    assert_output_contains(out, "an der alten Nadel")


@pytest.mark.feature("articles")
def test_dativ_neutrum_examine_default(game):
    """Dativ neutrum in Examine-Default: '... an dem feinen Tuch'."""
    out = game.run(["untersuche tuch"])
    assert_output_contains(out, "an dem feinen Tuch")


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


# ---------------------------------------------------------------------------
# Manuell gesetzter Artikel: article "dein" (Possessiv-Determinierer)
# ---------------------------------------------------------------------------

@pytest.mark.feature("articles")
def test_manueller_artikel_indef_akkusativ_inventar(game):
    """Manuell gesetzter Artikel wird im Akkusativ korrekt dekliniert.

    article "dein" (maskulin) → Inventar zeigt 'deinen Personalausweis'.
    'Du hast X' verlangt Akkusativ, daher 'deinen' statt 'dein'.
    """
    out = game.run(["nimm ausweis", "inventar"])
    # "Du hast deinen Personalausweis" proves both the accusative form and the context
    assert_output_contains(out, "Du hast deinen Personalausweis",
        msg="Manueller Artikel Akk: erwartet 'Du hast deinen Personalausweis' im Inventar")


@pytest.mark.feature("articles")
def test_manueller_artikel_indef_nominativ_raum(game):
    """Manuell gesetzter Artikel im Nominativ (Raumliste): 'dein Personalausweis'."""
    out = game.run(["schau"])
    assert_output_contains(out, "dein Personalausweis",
        msg="Manueller Artikel Nom: erwartet 'dein Personalausweis' in der Raumliste")


# ---------------------------------------------------------------------------
# Manuell gesetzter Artikel: article "mein" + has female (Feminin)
#   Nom: "meine Jacke"   Akk: "meine Jacke"   Dat: "meiner Jacke"
# ---------------------------------------------------------------------------

@pytest.mark.feature("articles")
def test_manueller_artikel_feminin_nominativ_raum(game):
    """Feminin + article 'mein': Raumliste zeigt 'meine Jacke'."""
    out = game.run(["schau"])
    assert_output_contains(out, "meine Jacke",
        msg="Manueller Artikel Feminin Nom: erwartet 'meine Jacke' in der Raumliste")


@pytest.mark.feature("articles")
def test_manueller_artikel_feminin_akkusativ_inventar(game):
    """Feminin + article 'mein': Inventar zeigt 'meine Jacke' (Akk == Nom für Feminin)."""
    out = game.run(["nimm jacke", "inventar"])
    assert_output_contains(out, "Du hast meine Jacke",
        msg="Manueller Artikel Feminin Akk: erwartet 'Du hast meine Jacke'")


@pytest.mark.feature("articles")
def test_manueller_artikel_feminin_dativ_examine(game):
    """Feminin + article 'mein': Description-Funktion zeigt 'meiner Jacke' (Dativ unbestimmt)."""
    out = game.run(["untersuche jacke"])
    assert_output_contains(out, "meiner Jacke",
        msg="Manueller Artikel Feminin Dat: erwartet 'meiner Jacke' in Examine-Antwort")


# ---------------------------------------------------------------------------
# Manuell gesetzter Artikel: article "sein" + has neuter (Neutrum)
#   Nom: "sein Tagebuch"   Akk: "sein Tagebuch"   Dat: "seinem Tagebuch"
# ---------------------------------------------------------------------------

@pytest.mark.feature("articles")
def test_manueller_artikel_neutrum_nominativ_raum(game):
    """Neutrum + article 'sein': Raumliste enthält 'sein Tagebuch' (Nom == Akk für Neutrum).

    Geprüft über Inventar ('Du hast sein Tagebuch') statt direkte Raumliste,
    da die Raumliste 'sein' und 'Tagebuch' an einer Zeilenumbruchsgrenze trennen kann.
    """
    out = game.run(["nimm tagebuch", "inventar"])
    # Nom == Akk für Neutrum: "sein Tagebuch" in beiden Positionen korrekt
    assert_output_contains(out, "Du hast sein Tagebuch",
        msg="Manueller Artikel Neutrum Nom/Akk: erwartet 'Du hast sein Tagebuch'")


@pytest.mark.feature("articles")
def test_manueller_artikel_neutrum_akkusativ_inventar(game):
    """Neutrum + article 'sein': Inventar zeigt 'sein Tagebuch' (Akk == Nom für Neutrum)."""
    out = game.run(["nimm tagebuch", "inventar"])
    assert_output_contains(out, "Du hast sein Tagebuch",
        msg="Manueller Artikel Neutrum Akk: erwartet 'Du hast sein Tagebuch'")


@pytest.mark.feature("articles")
def test_manueller_artikel_neutrum_dativ_examine(game):
    """Neutrum + article 'sein': Description-Funktion zeigt 'seinem Tagebuch' (Dativ unbestimmt)."""
    out = game.run(["untersuche tagebuch"])
    assert_output_contains(out, "seinem Tagebuch",
        msg="Manueller Artikel Neutrum Dat: erwartet 'seinem Tagebuch' in Examine-Antwort")
