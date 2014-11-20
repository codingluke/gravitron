#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <string>
#include "GameLoop.h"
#include <QtQml>
#include <QQuickItem>

using namespace std;

class Game: public QObject
{
    Q_OBJECT
    QThread workerThread;

    private:
        QQmlApplicationEngine *engine;
        QQuickItem *qmlParent;

    public:
        Game(QObject *parent = 0);
        Game(QQmlApplicationEngine *theEngine);
        ~Game();

        Q_INVOKABLE void setQmlParent(QQuickItem *theQmlParent);

    public slots:
        void handleResults(const string &result);

    signals:
        Q_INVOKABLE void start();
        Q_INVOKABLE void stop();

    private:
        void init();
};

#endif
