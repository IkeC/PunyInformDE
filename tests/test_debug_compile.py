"""Tests: DEBUG build compilation (issue #13).

Verifies that the game compiles without errors when the Inform DEBUG flag
is used (-D).  Before the fix, the compiler would fail with:

    lib/parser.h, line 2171: Error: No such constant as "ERR_UNSAFE_GRAMMAR_PROP"

because messages_de.h defined ERR constants 1-10 but omitted constant 11
(ERR_UNSAFE_GRAMMAR_PROP), which was only added to the base messages.h in a
later PunyInform update and not ported to the German override file.

The constant is only referenced inside an #Ifdef DEBUG / #IfTrue RUNTIME_ERRORS
guard in parser.h, so non-debug builds succeed even without the constant.
"""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path

import pytest

GAME_ROOT = Path(__file__).resolve().parent.parent

# Locate tools
INFORM6   = GAME_ROOT / "tools" / "inform6.exe"
LIB_PATH  = f"{GAME_ROOT / 'lib'},{GAME_ROOT / 'lib' / 'de'}"
STORY_SRC = GAME_ROOT / "example" / "sterne.inf"


def _compile_debug(extra_flags: list[str], output: Path) -> subprocess.CompletedProcess:
    """Invoke inform6 with DEBUG (-D) and return the CompletedProcess."""
    cmd = [
        str(INFORM6),
        f"+include_path={GAME_ROOT / 'lib'},{GAME_ROOT / 'lib' / 'de'}",
        *extra_flags,
        str(STORY_SRC),
        str(output),
    ]
    return subprocess.run(cmd, capture_output=True, text=True, timeout=60)


# ---------------------------------------------------------------------------
# Unicode Z5 DEBUG build
# ---------------------------------------------------------------------------

def test_debug_build_unicode_compiles(tmp_path):
    """A Debug build of the Unicode (Z5) story file must compile without errors.

    This would fail before the fix with:
        Error: No such constant as "ERR_UNSAFE_GRAMMAR_PROP"
    """
    result = _compile_debug(["-D"], tmp_path / "sterne_debug.z5")
    assert result.returncode == 0, (
        "DEBUG (Unicode) build failed.\n"
        f"stdout:\n{result.stdout}\n"
        f"stderr:\n{result.stderr}"
    )
    # Extra guard: no "Error:" lines in output
    error_lines = [l for l in result.stdout.splitlines() if "Error:" in l]
    assert error_lines == [], f"Unexpected error lines:\n{chr(10).join(error_lines)}"


# ---------------------------------------------------------------------------
# ASCII Z5 DEBUG build
# ---------------------------------------------------------------------------

STORY_ASCII_SRC = GAME_ROOT / "example" / "sterne_ascii.inf"


def test_debug_build_ascii_compiles(tmp_path):
    """A Debug build of the ASCII (USE_ASCII) story file must compile without errors."""
    result = _compile_debug(["-D"], tmp_path / "sterne_ascii_debug.z5")
    assert result.returncode == 0, (
        "DEBUG (ASCII) build failed.\n"
        f"stdout:\n{result.stdout}\n"
        f"stderr:\n{result.stderr}"
    )
    error_lines = [l for l in result.stdout.splitlines() if "Error:" in l]
    assert error_lines == [], f"Unexpected error lines:\n{chr(10).join(error_lines)}"
