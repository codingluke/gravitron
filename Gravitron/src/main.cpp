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
    qmlRegisterType<Game, 1>("Game", 1, 0, "Game");

    QQmlApplicationEngine engine;
    GravitronSettings settings;
    settings.setFullScreen(true);
    settings.setPlayMusic(true);
    settings.setPlaySounds(true);
    settings.setMusicSoundVolume(78);
    settings.setPlayerName("RobNoFlop");
    engine.rootContext()->setContextProperty("Settings", &settings);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
