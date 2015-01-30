% Projekt im Kurs "Entwicklung von Multimediasystemen"
% Lukas Hodel; Robert Kasseck; Richard Remus
% 29. Januar 2015

#Idee

#Anforderungen

#Einarbeitung

##GameDesignPatters

##Qt/Qml 

##Projektstrukturen

#Spiellogik

##GameActor

##Projectile

#Programmlogik 	

##Game

###c++ Qml Mapping

###Scene Management

##Gameloop

##Updates

##InputHandling	

##Player

###HumanPlayer
Der __HumanPlayer__ besitzt eine Imputhandler dessen hilfe er die Aktuellen eingaben lesenkann und so das __Spacecraft__ gesetuert wird.

###HumanNetworkPlayer

###AIPlayer

###AINetworkPlayer

#Tests
Hier wurde einige Klasse des Projektes mit hilfe des QT-Testframeworks getestet. Die beiden Klassen Physics und Vec3f bilden die Grundlage jeder Bewegung im Spiel.
Also ist es von hoher Bedeutung das die beiden Kassen auch immer wie erwartet arbeiten.

##Physics
Für alle Test wurde zuerste einaml ein einheitlicher Ausgangszustand geschaffen in dem zwei GameActors auf eine feste Postion gesetzt wurden. Ausgehend von diesen Positionen und Gravitaions eigenschaften wurden ein erwarteter Wert errechnet und dann in dem Test für alle Methoden der Physiks Klasse geprüft ob auch diese Werte ausgerechnet werden.

##Vec3f
Auch hier wurde ein einheitlicher Ausgangvektor geschafften. Auch das weitere vorgehen war wie bei der Phydics Klasse.

#Speichertests
Das Projket wurde in C++ geschrieben und so ist es wichtig Speicherzugriffsfehler und Memoryleaks zu finden und zu behenen. Es wurde zuerst versucht das Tool valgrid zu verwenden. Allerdings gab es einige Probleme, die die Analyse der Fehler unmöglichmachten. Ein vermudliche unsache ist die Speicheroptimierung von QT. Das Testen mit sanitize war deutlich erfolgreicher.

##Sanitize
Der Speichertest mit sanitize ist mit ein paar einfachen Kompiler und Linker Komandos zu nutzen. Die Komandos wurden über die QT Projektdatei dem Kompilter und Linker übergeben.

Kommandos:
QMAKE_CXXFLAGS_DEBUG += -fsanitize=address -O1 -fno-omit-frame-pointer
QMAKE_LFLAGS_DEBUG += -fsanitize=address

Der Vorteil von sanitize der im vergelich zu valgrind festgestellt werden konnte war, dass sanitize die Programmausführung bei einem Fehler abbricht. Dies hatte zur folge, dass das Programm immer ohne Speicherfehler ist. Auch lief die Programmausführung mit sanitize wesentlich schneller als mit valgind.


#Übersetzungen
Um das Programm in mehreren Sprachen zu Verfügung zu stellen wurden die QT Translations Tools benutzt. Der Text der in meherern Sprachen angezeigt werden soll musste in die Funktion qsTr() gesetzt werden. In der Projektdatei musste angegeben werden für welche Sprachen es eine Übersetzungen geben soll.

TRANSLATIONS = gravitron_de.ts \
               gravitron_en.ts

Der name der Übersetzungsdateien kann beliebig sein da eine Zuordnung manuell vorgenommen werden muss. 
Um nun die Übersetzungen zu erzeugen sind die drei folgende Schritte notwendig.
1. lupdate Gravitron.pro Es werden alle Dateien nach der qsTr() Funktion durchsucht und als "offene" Übersetzung registriert.
2. Die Übersetzungsdateien können nun mit QT Linguist geöffnet und übersetzt werden.
3. lrelease Erzeugt die feritgen Übersetzungsdateien mit der Endung .qm


Bei Programmausführung werden die Übersetzungen mit der Klasse __Locator__ geladen.

#Probleme beim Entwicklungsprozesses
##Qt verstehen

##Settings persistent speichern

#Ergebnisse und Einschätzung

#Fazit
