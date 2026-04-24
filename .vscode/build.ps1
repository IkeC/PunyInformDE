#Requires -Version 3.0
# PunyInformDE build script — invoked by the VS Code "Build" task.
# Working directory must be the project root (set by the task via options.cwd).

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

# Replace all German umlauts with ASCII digraphs in a source file.
# Writes UTF-8 WITHOUT BOM — Inform 6 rejects the UTF-8 BOM that
# PowerShell 5.x's Set-Content -Encoding UTF8 adds automatically.
function Convert-ToAsciiDigraphs {
    param([string]$Source, [string]$Destination)
    $destDir = Split-Path $Destination -Parent
    if ($destDir -and (-not (Test-Path $destDir))) {
        New-Item -ItemType Directory -Force -Path $destDir | Out-Null
    }
    $lines = (Get-Content $Source -Encoding UTF8) `
        -replace [char]0xe4, "ae" `
        -replace [char]0xf6, "oe" `
        -replace [char]0xfc, "ue" `
        -replace [char]0xdf, "ss" `
        -replace [char]0xc4, "Ae" `
        -replace [char]0xd6, "Oe" `
        -replace [char]0xdc, "Ue"
    $utf8NoBom = New-Object System.Text.UTF8Encoding $false
    $absPath = Join-Path $PWD.Path $Destination
    [System.IO.File]::WriteAllLines($absPath, $lines, $utf8NoBom)
}

New-Item -ItemType Directory -Force -Path "build" | Out-Null

# -------------------------------------------------------------------------
# Standard Unicode build
# -------------------------------------------------------------------------
Write-Host "Compiling beispiel.z5..."
& .\tools\inform6.exe +include_path=lib example\beispiel.inf build\beispiel.z5
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

# -------------------------------------------------------------------------
# ASCII build
#
# Inform 6 stores string literals with their Unicode code-points regardless
# of whether Zcharacter is declared. To get truly ASCII output, every source
# file that contains German strings must be preprocessed (umlauts → digraphs)
# before compilation.
#
# Files preprocessed into build\ascii_lib\  (override lib\ on the include path):
#   lib\de\globals_de.h   – status-bar label " Züge: " → " Zuege: "
#   lib\de\messages_de.h  – all parser messages
#   lib\puny.h            – " (enthält" → " (enthaelt"
# File preprocessed into build\ascii_src\   (override example\ on include path):
#   example\beispiel.inf  – all game text (rooms, objects, intro, …)
#
# lib\de\grammar_de.h is deliberately NOT preprocessed: it defines dictionary
# words (e.g. 'öffne') that already have ASCII alternatives ('oeffne') in the
# same Verb statement – preprocessing would create duplicate-word compile errors.
# -------------------------------------------------------------------------
Write-Host "Generating ASCII source tree..."
New-Item -ItemType Directory -Force -Path "build\ascii_lib\de" | Out-Null
New-Item -ItemType Directory -Force -Path "build\ascii_src"     | Out-Null

Convert-ToAsciiDigraphs "lib\de\globals_de.h"  "build\ascii_lib\de\globals_de.h"
Convert-ToAsciiDigraphs "lib\de\messages_de.h" "build\ascii_lib\de\messages_de.h"
Convert-ToAsciiDigraphs "lib\puny.h"           "build\ascii_lib\puny.h"
Convert-ToAsciiDigraphs "example\beispiel.inf" "build\ascii_src\beispiel.inf"

Write-Host "Compiling beispiel_ascii.z5..."
& .\tools\inform6.exe "+include_path=build\ascii_lib,build\ascii_src,lib" example\beispiel_ascii.inf build\beispiel_ascii.z5
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

# -------------------------------------------------------------------------
# ASCII walkthrough (for manual testing / Test Dfrotz (ASCII) task)
# -------------------------------------------------------------------------
Write-Host "Generating ASCII walkthrough..."
(Get-Content "example\beispiel.walkthrough.txt" -Encoding UTF8) `
    -replace [char]0xe4, "ae" `
    -replace [char]0xf6, "oe" `
    -replace [char]0xfc, "ue" `
    -replace [char]0xdf, "ss" `
    -replace [char]0xc4, "Ae" `
    -replace [char]0xd6, "Oe" `
    -replace [char]0xdc, "Ue" `
    | Set-Content "example\beispiel.walkthrough.ascii.txt" -Encoding ASCII

Write-Host "Build complete: build\beispiel.z5, build\beispiel_ascii.z5, example\beispiel.walkthrough.ascii.txt"
