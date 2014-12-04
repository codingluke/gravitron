#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <QThread>
#include <string>
#include <QQmlApplicationEngine>
#include "GameActor.h"
#include "GameActorView.h"

using namespace std;

//class GameLoop : public QObject
class GameLoop : public QThread
{
    Q_OBJECT

    private:
        bool running;
        int ms_per_update;
        QObject *game;
        QQmlApplicationEngine *engine;
        vector<GameActor> actors;

    public:
        GameLoop();

    public slots:
        void run();
        void stop();
        //void keypress(const string &key);

    private:
        void processInput();
        void update();
        void render();

    signals:
        void ping(const string &result);
        void renderObject(vector<GameActorView*> *views);
};

#endif
