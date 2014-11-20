#ifndef GAMEACTORVIEW_H
#define GAMEACTORVIEW_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <string>

using namespace std;

class GameActorView: public QObject
{
    Q_OBJECT

    private:
      string qml_resource;

    public:
        GameActorView(QObject *parent = 0);

        QQuickItem* render(QQmlApplicationEngine *engine, QQuickItem *qmlParent);
};

#endif
