#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "headers/QmlFileReader.h"
#include "headers/GravitronSettings.h"
#include "headers/Game.h"
#include "headers/MenuListener.h"
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
    MenuListener mListener(&settings); // = MenuListener(&settings);
    engine.rootContext()->setContextProperty("Settings", &settings);
    engine.rootContext()->setContextProperty("MListener", &mListener);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
