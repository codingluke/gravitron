#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "qmlfilereader.h"
#include "gravitronsettings.h"
#include "game.h"
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
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
