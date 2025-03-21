#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QTranslator>
#include <QLocale>
#include "headers/QmlFileReader.h"
#include "headers/GravitronSettings.h"
#include "headers/Game.h"
#include "headers/Locator.h"
#include "headers/TcpClient.h"
#include "headers/TcpServer.h"

#include "headers/vec3f_tests.h"
#include "headers/physics_tests.h"

using namespace std;

int main(int argc, char *argv[])
{
#ifdef TEST
    Vec3F_Tests test1;
    QTest::qExec(&test1);

    Physics_tests test2;
    QTest::qExec(&test2);

#endif

    QGuiApplication app(argc, argv);
    qmlRegisterType<QMLFileReader, 1>("QMLFileReader", 1, 0, "QMLFileReader");

    QQmlApplicationEngine engine;
    GravitronSettings settings;
    engine.rootContext()->setContextProperty("Settings", &settings);
    engine.rootContext()->setContextProperty("applicationDirPath", QGuiApplication::applicationDirPath());

    // Add TCP
    TcpServer server;
    TcpClient client;
    engine.rootContext()->setContextProperty("TcpServer", &server);
    engine.rootContext()->setContextProperty("TcpClient", &client);

    // Add Game
    Game game(&engine, &settings, &client, &server);
    engine.rootContext()->setContextProperty("Game", &game);

    Locator l(settings, app);
    l.loadLanguage(settings.language());

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
