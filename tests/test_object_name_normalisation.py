"""Tests: digraph input for object names works after removing explicit digraph entries.

Before this fix, sterne.inf listed both digraph and umlaut forms in name properties:
  name 'tuer' 'tür' 'kajuetentuer' 'kajütentür' ...

The digraph entries were redundant because:
  - Unicode build: _DE_NormaliseDigraphsOnly converts 'tuer'→'tür' etc. before lookup
  - ASCII build: the preprocessing pass converts source umlauts to digraphs at compile
    time, so 'tür' in source becomes 'tuer' in the compiled dict

After the fix only umlaut entries remain in name lists. These tests verify that digraph
player input still resolves correctly to the right objects in both builds.
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import assert_output_contains, assert_output_not_contains

CANNOT_SEE = "kannst du nicht sehen"


# ---------------------------------------------------------------------------
# Kajütentür (Kajuentuer): 'tür' 'kajütentür' 'eichentür' — no 'tuer'/'kajuetentuer'
# ---------------------------------------------------------------------------

@pytest.mark.feature("name_normalisation")
def test_untersuche_tuer_digraph_unicode(game):
    """Digraph 'tuer' must still refer to the Kajütentür in the Unicode build."""
    out = game.run(["untersuche tuer"])
    assert_output_not_contains(out, CANNOT_SEE)
    assert_output_contains(out, "solide")  # door description: "Das alte Schloss sieht sehr solide aus."


@pytest.mark.feature("name_normalisation")
def test_untersuche_tuer_digraph_ascii(game_ascii):
    """Digraph 'tuer' must still refer to the Kajütentür in the ASCII build."""
    out = game_ascii.run(["untersuche tuer"])
    assert_output_not_contains(out, CANNOT_SEE)
    assert_output_contains(out, "solide")


@pytest.mark.feature("name_normalisation")
def test_untersuche_kajuetentuer_digraph_unicode(game):
    """Compound digraph 'kajuetentuer' must normalise to 'kajütentür' in Unicode build."""
    out = game.run(["untersuche kajuetentuer"])
    assert_output_not_contains(out, CANNOT_SEE)
    assert_output_contains(out, "solide")


@pytest.mark.feature("name_normalisation")
def test_untersuche_kajuetentuer_digraph_ascii(game_ascii):
    """Compound digraph 'kajuetentuer' must work in the ASCII build."""
    out = game_ascii.run(["untersuche kajuetentuer"])
    assert_output_not_contains(out, CANNOT_SEE)
    assert_output_contains(out, "solide")


# ---------------------------------------------------------------------------
# Kajüte scenery (KajueteScenery): 'kajüte' 'kajüten' 'kapitän' — no 'kajuete'/'kapitaen'
# ---------------------------------------------------------------------------

@pytest.mark.feature("name_normalisation")
def test_untersuche_kajuete_digraph_unicode(game):
    """Digraph 'kajuete' must normalise to 'kajüte' and match the scenery in Unicode build."""
    out = game.run(["untersuche kajuete"])
    assert_output_not_contains(out, CANNOT_SEE)


@pytest.mark.feature("name_normalisation")
def test_untersuche_kajuete_digraph_ascii(game_ascii):
    """Digraph 'kajuete' must match the scenery in the ASCII build."""
    out = game_ascii.run(["untersuche kajuete"])
    assert_output_not_contains(out, CANNOT_SEE)


# ---------------------------------------------------------------------------
# Goldmünzen (Muenzen): 'geld' 'münzen' 'goldmünzen' — no 'muenzen'/'goldmuenzen'
# ---------------------------------------------------------------------------

@pytest.mark.feature("name_normalisation")
def test_untersuche_muenzen_digraph_unicode(game):
    """Digraph 'muenzen' must normalise to 'münzen' in the Unicode build."""
    out = game.run(["untersuche muenzen"])
    assert_output_not_contains(out, CANNOT_SEE)
    assert_output_contains(out, "Seeadler")  # description of the coins


@pytest.mark.feature("name_normalisation")
def test_untersuche_muenzen_digraph_ascii(game_ascii):
    """Digraph 'muenzen' must match Goldmünzen in the ASCII build."""
    out = game_ascii.run(["untersuche muenzen"])
    assert_output_not_contains(out, CANNOT_SEE)
    assert_output_contains(out, "Seeadler")


# ---------------------------------------------------------------------------
# Schlüssel (Schluessel): 'klein' 'schlüssel' 'messingschlüssel' — no 'schluessel'
# Test is additional coverage; the existing test_nimm_schluessel_ascii in
# test_umlauts.py already covers the pick-up scenario.
# ---------------------------------------------------------------------------

@pytest.mark.feature("name_normalisation")
def test_untersuche_schluessel_digraph_unicode(game):
    """Digraph 'schluessel' must normalise to 'schlüssel' in the Unicode build."""
    out = game.run(["oeffne kiste", "untersuche schluessel"])
    assert_output_not_contains(out, CANNOT_SEE)
    assert_output_contains(out, "Messing")


@pytest.mark.feature("name_normalisation")
def test_untersuche_messingschluessel_digraph_unicode(game):
    """Compound digraph 'messingschluessel' normalises to 'messingschlüssel' in Unicode."""
    out = game.run(["oeffne kiste", "untersuche messingschluessel"])
    assert_output_not_contains(out, CANNOT_SEE)
    assert_output_contains(out, "Messing")
