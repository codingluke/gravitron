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
        GameField *field;
        float window_width = 1000;
        float window_height = 1000;

    public:
        Game(QObject *parent = 0);
        Game(QQmlApplicationEngine *theEngine, GravitronSettings *theSettings);
        ~Game();

        Q_INVOKABLE void setQmlParent(QQuickItem *theQmlParent);
        Q_INVOKABLE void start();
        Q_INVOKABLE void startClient(TcpClient *client);
        Q_INVOKABLE void startServer(TcpServer *server);
        Q_INVOKABLE void stop();

    public slots:
        void render(vector<GameActorView*> *views);
        void renderRemote(QString views);
        void setActiveWeapon(int weaponNumber);
        void setLifepoints(int lifepoints);
        void setBackgroundPosition(float x, float y, float fieldWidth, float fieldHeight);
        void setInfoboxMessage(QString message);

    private:
        void clearScene(vector<GameActorView*> *views);
        void setRelativePosition(float anchor_x, float anchor_y, GameActorView *view);
};

#endif
