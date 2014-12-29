#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QTranslator>
#include <QLocale>
#include "headers/QmlFileReader.h"
#include "headers/GravitronSettings.h"
#include "headers/Game.h"
#include "headers/MenuListener.h"
#include "headers/Locater.h"
#include "headers/TcpClient.h"
#include "headers/TcpServer.h"
#include "headers/GameGenerator.h"
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

    GameGenerator gGenerator(&settings);
    // Add Game
    Game game(&engine, &gGenerator);
    engine.rootContext()->setContextProperty("Game", &game);

    // Add TCP
    TcpServer server;
    TcpClient client;
    engine.rootContext()->setContextProperty("Server", &server);
    engine.rootContext()->setContextProperty("Client", &client);

    Locater l(settings, app);
    l.loadLanguare(settings.languare());

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
