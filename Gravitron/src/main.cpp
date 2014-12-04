#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QTranslator>
#include <QLocale>
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

    QQmlApplicationEngine engine;
    GravitronSettings settings;
    MenuListener mListener(&settings); // = MenuListener(&settings);
    engine.rootContext()->setContextProperty("Settings", &settings);
    engine.rootContext()->setContextProperty("MListener", &mListener);


    // Add Game
    Game game(&engine);
    //QCoreApplication::instance()->installEventFilter(&game);

    engine.rootContext()->setContextProperty("Game", &game);

    QString locale = QLocale::system().name();
    QTranslator translator;
    if(translator.load("gravitron_" + locale, ":/translations")) {
        app.installTranslator(&translator);
    } else {
        qWarning() << "No languare for your loaction.";
        translator.load("gravitron_en_GB", ":/translations");
        app.installTranslator(&translator);
    }

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
