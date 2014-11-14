#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "headers/QmlFileReader.h"
#include "headers/GravitronSettings.h"
#include "headers/Game.h"
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qRegisterMetaType<string>("string");
    qmlRegisterType<QMLFileReader, 1>("QMLFileReader", 1, 0, "QMLFileReader");
    qmlRegisterType<GravitronSettings, 1>("GravitronSettings", 1, 0, "GravitronSettings");

    QQmlApplicationEngine engine;
    GravitronSettings settings;
    settings.setFullScreen(true);
    settings.setPlayMusic(true);
    settings.setPlaySounds(true);
    settings.setMusicSoundVolume(78);
    settings.setPlayerName("RobNoFlop");
    engine.rootContext()->setContextProperty("Settings", &settings);

    // Add Game
    Game game;
    game.setEngine(&engine);
    engine.rootContext()->setContextProperty("Game", &game);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
