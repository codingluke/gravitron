#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <string>
#include <QString>
#include "GameLoop.h"
#include <QtQml>
#include <QQuickItem>
#include "GameActorView.h"

using namespace std;

class Game: public QObject
{
    Q_OBJECT

    private:
        QQmlApplicationEngine *engine;
        QQuickItem *qmlParent;
        GameLoop *gameLoop;

    public:
        Game(QObject *parent = 0);
        Game(QQmlApplicationEngine *theEngine);
        ~Game();

        Q_INVOKABLE void setQmlParent(QQuickItem *theQmlParent);
        Q_INVOKABLE void start();

    public slots:
        void handleResults(const string &result);
        void render(vector<GameActorView*> *views);

    signals:
        Q_INVOKABLE void stop();
        Q_INVOKABLE void inputEvents(const QString &key);

    private:
        void init();
        void clearScene();
};

#endif
