#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "headers/QmlFileReader.h"
#include "headers/GravitronSettings.h"
#include "headers/Game.h"
#include "headers/MenuListener.h"
#include <string>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qRegisterMetaType<string>("string");
    qmlRegisterType<QMLFileReader, 1>("QMLFileReader", 1, 0, "QMLFileReader");
    qmlRegisterType<GravitronSettings, 1>("GravitronSettings", 1, 0, "GravitronSettings");

    QQmlApplicationEngine engine;
    GravitronSettings settings;
    MenuListener mListener(&settings); // = MenuListener(&settings);
    engine.rootContext()->setContextProperty("Settings", &settings);
    engine.rootContext()->setContextProperty("MListener", &mListener);


    // Add Game
    Game game(&engine);
    //game.setEngine(&engine);
    engine.rootContext()->setContextProperty("Game", &game);

    //engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/qml/main2.qml")));

    return app.exec();
}
