#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "qmlfilereader.h"
#include "point.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<QMLFileReader, 1>("QMLFileReader", 1, 0, "QMLFileReader");

    QQmlApplicationEngine engine;
    Point p;
    engine.rootContext()->setContextProperty("point", &p);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
