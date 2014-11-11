#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "qmlfilereader.h"
<<<<<<< HEAD
#include "gravitronsettings.h"
#include "game.h"
#include <string>
=======
#include "point.h"
>>>>>>> 5f98fd7e01a353fa4497525e2f9606037cbae50d

using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qRegisterMetaType<string>("string");
    qmlRegisterType<QMLFileReader, 1>("QMLFileReader", 1, 0, "QMLFileReader");
    qmlRegisterType<GravitronSettings, 1>("GravitronSettings", 1, 0, "GravitronSettings");
    qmlRegisterType<Game, 1>("Game", 1, 0, "Game");

    QQmlApplicationEngine engine;
    Point p;
    engine.rootContext()->setContextProperty("point", &p);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
