# GameLoop
Am Anfang des Projektes war es zu erst mal wichtig herauszufinden wie ein Echtzeit spiel überhaupt aufgebaut ist. Um einwehnig das Gefühl dafür zu erhalten haben wir das Buch www.gameprogrammingpatterns.com "duchgelesen".
Dabei sind wir auf den GameLoop gestossen. http://gameprogrammingpatterns.com/game-loop.html.

Dabei haben wir uns vorallem auf folgende implementierung geeinigt:

    while (true)
    {
      double start = getCurrentTime();
      processInput();
      update();
      render();
      sleep(start + MS_PER_FRAME - getCurrentTime());
    }

Es wird sequenziell zuerst den Benutzerinput verarbeitet (processInput), dabei handelt es sich um Keyborad input über das lokale keyboard oder übers netzwerk.
Dann wird der spielstatus neu berechnet indem alle Aktoren sich aktuallisieren (update). Wenn der neue Spielstand berechnet wurde, wird dann alles gerendert.
Wenn dann noch zeit überig blieb, wird diese geschlaffen. So garantieren wir eine konstante spielgeschwindigkeit, egal ob ein rechner schneller ist oder nicht.

## Rendern in einem anderen thread.
Der GameLoop ist ein eigener Thread, das effektive rendern wird nicht im GameLoop gemacht. Im GameLoop werden nur die Daten vorbereitet, damit sie universell gerendert werden können. Dabei werden die vorbereiteten Views über QT eigene Signale weitergereicht.

# GameActorView
Um den Spielstand universell rendern zu können und somit die Logik vom Design zu trennen, mussten wir ein Datenobjekt erstellen, welches die Eigenschaften eines Spielobjektes einfach darstellen kann. Dabei haben wir den GameActorView entwickelt. Der GameActorView ist streng genommen nur eine Key-Value liste. Er beinhaltet die Eigenschaften als Keys, und deren Values.
Jeder GameActor, kann nun einen GameActorView von sich und seinem aktuellen status erstellen. Dieser view kann dann serialisiert werden und an einer beliebigen anderen stelle wieder gelesen werden. Ob dann aus dem View ein QML objekt generiert wird oder mit OpenGL ein objekt gerendert wird ist egal.

In unserem Fall werden diese GameActorViews im Game.cpp von der methode Game::render gelesen. Dann werden für jeden View ein QQuickItem generiert. Welche QML Datei verwendet werden soll, wird ebenfalls im GameActorView definiert. So kann einfach pro GameActor eine GameActor.qml erstellt werden.

Der Schwierige Punkt in diesem Scenario war, wie man aus C++ heraus QML Objekte generieren kann:

    // Zuerst muss der QML Pfad vom GameActorView gelesen werden. Dieser
    // definiert welche .qml Datei für den View verwendet werden soll.
    QString path = QString::fromStdString((*view)->getQmlPath());

    // Dann wird eine neue Komponente davo erstellte davo erstellt
    QQmlComponent component(engine, QUrl(path));
    QQuickItem *childItem = qobject_cast<QQuickItem*>(component.create());

    // Dieser muss dann einen Parent gegeben werden. In unserem Fall ist 
    // der qmlParent dem Game.cpp objekt bekannt.
    childItem->setParent(qmlParent);
    childItem->setParentItem(qmlParent);

    ...
    
    // Dann können die einzelnen Eigenschaften dem QQuickItem übergeben werden.
    for(pit = props.begin(); pit != props.end(); pit++) {
        childItem->setProperty(pit->first.c_str(), pit->second.c_str());
    }

# Netzwerk

