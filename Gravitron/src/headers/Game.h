#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <string>
#include <QString>
#include "GameLoop.h"
#include <QtQml>
#include <QQuickItem>
#include "GameActorView.h"
#include "GravitronSettings.h"
#include "GameGenerator.h"
#include "TcpClient.h"
#include "TcpServer.h"

using namespace std;

class Game: public QObject
{
    Q_OBJECT

    private:
        QQmlApplicationEngine *engine;
        QQuickItem *qmlParent;
        GameLoop *gameLoop;
        GravitronSettings *settings;

    public:
        Game(QObject *parent = 0);
        Game(QQmlApplicationEngine *theEngine, GravitronSettings *theSettings);
        ~Game();

        Q_INVOKABLE void setQmlParent(QQuickItem *theQmlParent);
        Q_INVOKABLE void start();
        Q_INVOKABLE void start(TcpClient *client);
        Q_INVOKABLE void start(TcpServer *server);
        Q_INVOKABLE void stop();

    public slots:
        void render(vector<GameActorView*> *views);
        void setActiveWappon(int wapponNumber);

    signals:
        Q_INVOKABLE void inputEvents(int code);

    private:
        void clearScene();
};

#endif
