"""Compile regressions for PunyInform 6.8/6.9 integration."""

from __future__ import annotations

import subprocess
from pathlib import Path

GAME_ROOT = Path(__file__).resolve().parent.parent
INFORM6 = GAME_ROOT / "tools" / "inform6.exe"
INCLUDE_PATH = f"{GAME_ROOT / 'lib'},{GAME_ROOT / 'lib' / 'de'}"


def _compile(source: Path, output: Path, *flags: str) -> subprocess.CompletedProcess:
    return subprocess.run(
        [str(INFORM6), f"+include_path={INCLUDE_PATH}", *flags, str(source), str(output)],
        capture_output=True,
        text=True,
        timeout=60,
    )


def test_debug_optional_no_add_to_scope_compiles(tmp_path):
    """DEBUG REACTIVE and DEBUG_PARSEPATTERN compile with add_to_scope disabled."""
    result = _compile(
        GAME_ROOT / "tests" / "compile_v69.inf",
        tmp_path / "compile_v69.z5",
    )
    assert result.returncode == 0, f"{result.stdout}\n{result.stderr}"
    assert "Error:" not in result.stdout


def test_z6_packing_and_screen_extensions_compile(tmp_path):
    """Z6 odd/even packing and the updated screen extensions compile."""
    result = _compile(
        GAME_ROOT / "tests" / "compile_v69.inf",
        tmp_path / "compile_v69.z6",
        "-v6",
        "-B",
    )
    assert result.returncode == 0, f"{result.stdout}\n{result.stderr}"
    assert "Error:" not in result.stdout
