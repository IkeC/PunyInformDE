#!/usr/bin/env bash
# PunyInformDE build script for Linux/macOS — equivalent of build/build.ps1.
# Can be called from any directory; the script navigates to the project root.
#   cd build && bash build.sh    # from build/ directory
#   bash build/build.sh          # from project root
#
# Requirements:
#   inform6  >= 6.44 (e.g. from https://github.com/DavidKinder/Inform6 releases)
#   dfrotz (optional, for transcript generation; e.g. apt install frotz)

set -euo pipefail

# Navigate to project root regardless of the calling directory.
cd "$(dirname "$0")/.."

# -------------------------------------------------------------------------
# Configuration: tool paths (customize here or via environment variables)
# -------------------------------------------------------------------------
# INFORM6: Path to Inform 6 compiler (https://github.com/DavidKinder/Inform6)
# Default: searches in PATH. Set to override:
# INFORM6=/path/to/inform6
INFORM6="${INFORM6:-inform6}"

# DFROTZ: Path to dfrotz interpreter (https://gitlab.com/DavidGriffith/frotz)
# Default: searches in PATH. Set to override:
# DFROTZ=/path/to/dfrotz
DFROTZ="${DFROTZ:-dfrotz}"

# -------------------------------------------------------------------------
# Helper: replace German umlauts with ASCII digraphs and write to destination
# -------------------------------------------------------------------------
ascii_digraphs() {
    local src="$1" dst="$2"
    mkdir -p "$(dirname "$dst")"
    sed \
        -e 's/ä/ae/g' -e 's/ö/oe/g' -e 's/ü/ue/g' -e 's/ß/ss/g' \
        -e 's/Ä/Ae/g' -e 's/Ö/Oe/g' -e 's/Ü/Ue/g' \
        "$src" > "$dst"
}

mkdir -p build

# -------------------------------------------------------------------------
# Standard Unicode build
# -------------------------------------------------------------------------
echo "Compiling sterne.z5..."
"$INFORM6" "+include_path=lib,lib/de" example/sterne.inf build/sterne.z5

# -------------------------------------------------------------------------
# ASCII build
#
# Inform 6 stores string literals with their Unicode code-points regardless
# of whether Zcharacter is declared. To get truly ASCII output, every source
# file that contains German strings must be preprocessed (umlauts → digraphs)
# before compilation.
# -------------------------------------------------------------------------
echo "Generating ASCII source tree..."
mkdir -p build/ascii_lib/de
mkdir -p build/ascii_src

ascii_digraphs lib/de/globals_de.h                  build/ascii_lib/de/globals_de.h
ascii_digraphs lib/de/chartable_de.h                build/ascii_lib/de/chartable_de.h
ascii_digraphs lib/de/messages_de.h                 build/ascii_lib/de/messages_de.h
ascii_digraphs lib/de/grammar_de.h                  build/ascii_lib/de/grammar_de.h
ascii_digraphs lib/de/parser_de.h                   build/ascii_lib/de/parser_de.h
ascii_digraphs lib/de/article_de.h                  build/ascii_lib/de/article_de.h
ascii_digraphs lib/de/ext_talk_menu_inline_de.h     build/ascii_lib/de/ext_talk_menu_inline_de.h
ascii_digraphs lib/puny.h                           build/ascii_lib/puny.h
ascii_digraphs example/sterne.inf                   build/ascii_src/sterne.inf

echo "Compiling sterne.ascii.z5..."
"$INFORM6" "+include_path=build/ascii_lib,build/ascii_lib/de,build/ascii_src,lib,lib/de" \
    example/sterne_ascii.inf build/sterne.ascii.z5

# -------------------------------------------------------------------------
# Z3 build  (reuses the ASCII source tree)
# -------------------------------------------------------------------------
echo "Compiling sterne.z3..."
"$INFORM6" "+include_path=build/ascii_lib,build/ascii_lib/de,build/ascii_src,lib,lib/de" \
    example/sterne_z3.inf build/sterne.z3

# -------------------------------------------------------------------------
# ASCII walkthrough (generated on demand for transcript runs)
# -------------------------------------------------------------------------
ASCII_WALKTHROUGH="$(mktemp)"
trap 'rm -f "$ASCII_WALKTHROUGH"' EXIT

# -------------------------------------------------------------------------
# Transcript generation (requires dfrotz)
# -------------------------------------------------------------------------
if command -v "$DFROTZ" &>/dev/null; then
    echo "Generating transcripts..."
    rm -f build/sterne.transcript.txt \
          build/sterne.transcript.ascii.txt \
          build/sterne.transcript.z3.txt

    echo "Generating temporary ASCII walkthrough..."
    ascii_digraphs example/sterne.walkthrough.txt "$ASCII_WALKTHROUGH"

    "$DFROTZ" -m -q -Z 0 -T -w 999 -S 999 \
        -n build/sterne.transcript.txt \
        build/sterne.z5 \
        < example/sterne.walkthrough.txt

    "$DFROTZ" -m -q -Z 0 -T -w 999 -S 999 \
        -n build/sterne.transcript.ascii.txt \
        build/sterne.ascii.z5 \
        < "$ASCII_WALKTHROUGH"

    "$DFROTZ" -m -q -Z 0 -T -w 999 -S 999 \
        -n build/sterne.transcript.z3.txt \
        build/sterne.z3 \
        < "$ASCII_WALKTHROUGH"
else
    echo "dfrotz not found (checked: $DFROTZ) — skipping transcript generation."
    echo "Install with: sudo apt install frotz  (or set DFROTZ=/path/to/dfrotz)"
fi

echo "Build complete: build/sterne.z5, build/sterne.ascii.z5, build/sterne.z3"
