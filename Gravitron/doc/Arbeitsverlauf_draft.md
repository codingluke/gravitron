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

Ein sehr kritischer Teil des Projektes besteht in der inneren Spiellogik. Sie bestimmt die Regeln, den Ablauf und auch jeden möglichen Zustand des Spiels. Ihre Aufgabe ist es auch, den Zustand der einzelnen Akteure des Spiels konsistent zu halten. Um die Umsetzung der Logik unabhängig von Qt zu halten, haben wir uns entschieden die Spiellogik völlig von den anderen Bestandteilen des Spiels zu entkoppeln. 

##GameActor
Die Klasse GameActor repräsentiert jedes denkbare Objekt, das Teil des Spielgeschehens ist. Dazu zählen die Raumschiffe der Spieler, Planeten, Sonnen, Weltraumschrott, Asteroiden aber auch jegliche Geschosse der Waffen über die die Schiffe verfügen. Die wichtigsten Eigenschaften eines GameActors sind seine Position, Geschwindigkeit, Beschleunigung, Masse, Lebenspunkte, Gravitationskraft sowie die Reichweite, über welche seine Gravitation andere GameActors beeinflussen kann. Seine Positionierung und Bewegung werden mit elementarer Vektorrechnung realisiert. Wann immer eine Kraft auf einen GamActor wirken soll, wird die Methode __applyForce()__ mit einem  entsprechenden Kraftvektor verwendet. Die angewendete Kraft wirkt sich zunächst nur auf seinen Beschleunigungsvektor addiert, erst beim Aktualisieren des GameActors über __update()__ wird der Beschleunigungsvektor mit dem Geschwindigkeitsvektor verrechnet und mit diesem dann schließlich die neue Position bestimmt.
Falls GameActors miteinander Kollidieren wird dies mithilfe der __collisionDetection()__ aus der __Physics__-Bibliothek ermittelt. Durch Implementation der virtuellen Methode __handleCollision()__ kann festgelegt werden, wie der jeweilige GameActor mit einem Zusammenstoß umgehen soll. Sollte er schaden nehmen, kann dies mit __dealDamage()__ realisiert werden, diese Methode bestimmt dabei auch, ob der zugewiesene Schaden die maximale Zahl von Lebenspunkten überschreitet und aktualisiert das Feld __killed__ dementsprechend. __addHealth()__ agiert in analog entgegengesetzter Weise zu __dealDamage()__ wobei wir jedoch davon ausgehen, dass ein getöteter oder zerstörter GameActor nicht "wiederbelebt" werden sollte. Dies sollte, falls nötig über einen anderen Weg geregelt werden. Falls ein GameActor durch seinen Tod einen Effekt auf das Spielgeschehen haben, zum Beispiel eine Explosion oder das setzen eines PowerUps, kann dies in der virtuellen Methode __handleKill()__ definiert werden. 

##Projectile
Mit Projectile sollen alle möglichen Arten von Geschossen realisiert werden. Das könnten Laser und Raketen, aber auch Bomben, Minen oder andere Dinge sein, welche durch eine Waffe im Spielfeld platziert werden können. Projectile erbt von GameActor, bringt aber ein paar Erweiterungen. Zum einen kann es den Punktestand von befreundeten Raumschiffen beeinflussen, wobei "befreundet" bedeutet, dass dieses Projectile sie nicht in negativer weise beeinflussen kann. Zum anderen kann für jedes Projectile eine maximale Lebensdauer (time to live), gemessen in update-Zyklen. 

#Programmlogik 	

##Game

###c++ Qml Mapping

###Scene Management

##Gameloop

##Updates

##InputHandling	

##Player

###HumanPlayer

###HumanNetworkPlayer

###AIPlayer

###AINetworkPlayer

#Tests

##Physics

##Vec3f

#Speichertests

##Sanitize

#Probleme beim Entwicklungsprozesses
##Qt verstehen

##Settings persistent speichern

#Ergebnisse und Einschätzung

#Fazit
