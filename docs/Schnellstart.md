# Spiele schreiben mit PunyInformDE

Dies ist eine kleine Anleitung, wie du dein erstes eigenes Spiel schreiben kannst. Wenn du Probleme hast, bitte [erstelle ein Issue](https://github.com/IkeC/PunyInformDE/issues)!

Wir gehen in dieser Anleitung von folgenden Basisverzeichnissen aus, du kannst sie aber frei wählen.

Windows:
`C:\Source\`

Linux/Mac:
`/home/ike/source`

# PunyInformDE herunterladen

Benutze [git](https://git-scm.com/), um den aktuellsten PunyInformDE-Stand in dein Basisverzeichnis zu klonen:

`git clone https://github.com/IkeC/PunyInformDE`

Jetzt solltest du ein Verzeichnis `PunyInformDE` in deinem Basisverzeichnis haben.

# Inform6-Compiler bereitstellen

Um ein geschriebenes Spiel in Programmcode zu übersetzen, muss es kompiliert werden. Dazu brauchen wir den [Inform6](https://github.com/DavidKinder/Inform6)-Compiler.

Wenn du Windows benutzt, hast du den Compile bereits im `tools`-Verzeichnis:

`C:\Source\PunyInformDE\tools\Inform6.exe`

Unter Linux/Mac-Version kompilierst du den Compiler am besten selbst. Aus deinem Basisverzeichnis:

```
# gcc-Compiler installieren
sudo apt install gcc
# Inform6-Repo klonen
git clone https://github.com/DavidKinder/Inform6
# In Verzeichnis wechseln
cd Inform6
# Kompilieren
gcc -o inform6 *.c
# Link im Tools-Verzeichnis erstellen
cd ../PunyInformDE/tools
ln -s ../../Inform6/inform6 .
```

Alternativ kannst du den Compiler über einen Paketmanager installieren, z.B. unter Linux Ubuntu mit:

```
sudo apt install inform6-compiler
ln -s /usr/bin/inform6 ../PunyInformDE/tools/inform6
```

# Beispiel kompilieren

Aus dem Basisverzeichnis, unter Windows:

```
cd PunyInformDE
.\tools\inform6.exe +include_path=lib,lib/de .\example\minimal.inf minimal.z5
```

Linux/Mac:
```
cd PunyInformDE
tools/inform6 +include_path=lib,lib/de example/minimal.inf minimal.z5
```

Wenn alles funktioniert hat, solltest du jetzt das kompilierte Spiel `minimal.z5` im Verzeichnis `PunyInformDE` haben. Glückwunsch!

# Beispiel spielen

Es gibt viele Programme, die Spiele im Z-machine-Format (.z3, .z5, .z8 etc.) ausführen können. Eine kleine Liste findest du [hier](https://ikeserver.de/Staub/download.html). Zum schnellen Testen bietet sich z.B. `dfrotz` an, welches du direkt über die Kommandozeile ausführen kannst. Das kann später sehr hilfreich sein, wenn du dein Spiel z.B. automatisch testen lassen willst, oder ein Transkript eines kompletten Spieldurchlaufs erzeugen willst.

Unter Windows kannst du dfrotz direkt aus dem Tools-Verzeichnis starten:

```
cd PunyInformDE
tools\dfrotz.exe sterne-test.z5
```

Für Linux/Mac kannst du `dfrotz` auch wieder selbst kompilieren:

```
git clone https://gitlab.com/DavidGriffith/frotz
cd frotz
make dfrotz
# Link im Tools-Verzeichnis erstellen
cd ../PunyInformDE/tools
ln -s ../../frotz/dfrotz .

```

Starten mit:
```
cd PunyInformDE
tools/dfrotz minimal.z5
```

# Schreibe dein eigenes Spiel!

Oben haben wir ja ´minimal.inf´ kompiliert. Das ist eine einfache Textdatei mit folgendem Inhalt:

```
!% -Cu
Constant Story      "Minimal";
Constant Headline   "^Ein Beispielspiel für PunyInfomDE.^";
Constant OPTIONAL_NO_DARKNESS;
Constant INITIAL_LOCATION_VALUE = Buecherei;

Include "globals.h";
Include "puny.h";

Object Buecherei "Die Bücherei"
	with
		description "Du bist in einer Bücherei.";

Object -> Kiste "Kiste"
	with
		name 'kiste',
		inside_description "Ich steh' gerne in der Kiste!",
	has container open openable enterable;

[Initialise;
	print "Oha, wie bin ich denn in der Bücherei gelandet?^";
];
```

Am besten legst du für dein eigenes Spiel einen eigenen Order (z.B. `MeinSpiel` in deinem Basisverzeichnis an. Schreibe dein Spiel in `mein-spiel.inf`, dann kompiliere und teste es! Unter Windows:

```
mkdir MeinSpiel
cd MeinSpiel
# Wir kopieren mal das Beispiel und benennen es um
cp ..\PunyInformDE\example\minimal.inf MeinSpiel.inf
# Geänderte Include-Pfade beachten!
..\PunyInformDE\tools\inform6.exe +include_path=..\PunyInformDE\lib,..\PunyInformDE\lib\de MeinSpiel.inf MeinSpiel.z5
# Testen
..\PunyInformDE\tools\dfrotz.exe MeinSpiel.z5
```

# Hilfe, Links und Ressourcen

Wenn du Hilfe brauchst, schau am besten im [PunyInformDE thread](https://if-forum.org/topic.php?id=1385) vorbei. Dieses Forum ist der zentrale Treffpunkt für die deutsche Interactive Fiction-Community.

Alternativ oder zusätzlich kannst du gerne [ein Issue](https://github.com/IkeC/PunyInformDE/issues) hier in GitHub erstellen.