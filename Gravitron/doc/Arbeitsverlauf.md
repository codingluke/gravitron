#Einarbeitung
- GameDesignPatters
- Qt/Qml 
- Projektstrukturen

#Projekt Architektur
- .pro
- Translations
|- src 
	- .cpp
	|- headers
		- .h
|- qml 
	- .qml
	|- menu
		- .qml
	|- actors
		- .qml
|- asserts
	|- img
	|- text
	|- audio

Qml, Bilder und Text sind in .qrc Dateien organisiert.


#Klassen Architektur
- GameActor
	- Projekttile
		-Laser
		-Missile
			-AimMissile
	- Sun
	- Spacecraft
	- Planet
	- PowerUp
	- Scrap
	- Asteroid

-Player
	- HumanPlayer
		- HumanNetworkPlayer
	- KiPlayer
		- KiNetworkPlayer

Game <-> GameLoop
Game: 
	- c++ Qml Mapping
	- Scene Management
GameLoop: 	
	- Updates
	- InputHandling	

#Tests / Speichertests
- Physiks
- Vec3f

- sanitize


#Hürden
- Qt verstehen
	- mekrwürdiges / ungewohntes verhalten
	-  



- Settings persistent
- 
	

