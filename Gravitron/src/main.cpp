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
    MenuListener mListener(&settings); // = MenuListener(&settings);
    engine.rootContext()->setContextProperty("Settings", &settings);
    engine.rootContext()->setContextProperty("MListener", &mListener);

    // Add Game
    Game game(&engine);
    engine.rootContext()->setContextProperty("Game", &game);

    // Add TCP
    TcpServer server;
    TcpClient client;
    //engine.rootContext()->setContextProperty("Server", &server);
    //engine.rootContext()->setContextProperty("Client", &client);

    //server.startListen(8000);
    //QThread::msleep(200);
    //client.start("127.0.0.1", 8000);

    Locater l(settings, app);
    l.loadLanguare(settings.languare());


    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
