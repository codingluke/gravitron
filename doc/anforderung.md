# Anforderung

## Infos
Name: Gravitron
Team: Robert Kasseck (543583), Richard Remus(542820), Lukas Hodel(545881)

## Ziel
Implementierung eines Mehrspieler-Weltraum-Shooters (Gravitron) in C++.

## Basic Features
- Objekte verfügend über eine Gravitation bezüglich ihrer Masse.
- Das spiel soll über das Netzwerk im Multiplayer spielbar sein, wobei ein spieler der Host
- Es soll eine KI mit 3 schwierigkeitsstufen beinhalten.
- Bei jedem spieler lokale Spielstatistik

## Gameplay
__spielfeld__
Es gibt ein Spiefled (Sonnensystem), welches sich logisch um eine Kugel handelt. Der Spieler steuert sein eigenes schiff und bewegt sich __auf__ der Kugel. Das Spielfeld ist somit eine Fläche.

__Spielmodus__
Es handelt sich um ein klassisches Deadmatch. Jeder Spieler kämpft gegen alle anderen Spieler (sowie KI-Spieler).
Ziel und somit das Ende des Spiels, ist es eine vorher gesetzte Punktzahl zu erreichen. Die Punktzahl repräsentiert die Abschüsse anderer Spieler.

__Gravitationssystem__
Alle im Spielfeld befindlichen Objekte (Raumschiffe, Planeten, Schwarze-Löcher...) besitzen eine Gravitation relativ zu ihrer Masse. Diese beeinflussen die Flugbahn von Geschossen und Schiffen. 
Die Nicht-Spieler-Objekte sollen sich zunächst nicht gegenseitig beeinflussen.

__Nicht-Spieler-Objekte__
- Planeten
- Schwarze Löcher
- Schrott
- Asteoriden

__Kollisionen__
Es wird für alle möglichen Kollisionen eine eine spezifische Behandlung
definiert.

__PowerUps__
Das Raumschiff eines abgeschossenen Spielers wird zu einem PowerUp, welches von allen Spielern aufgesammelt werden kann. Je nach Stärke des abgeschossenen
Spielers wird die Effizienz des PowerUps bestimmt. Die Art wird zufällig bestimmt.

Mögliche Arten von PowerUps:
- Waffen
- Rüstung
- Effekte (Unsichbarkeit, Masse eines Schiffes erhöhen, Steuerung invertieren)

## Plattformen
- Windows
- Linux
- OSX
- Android

