#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <QThread>
#include <string>
#include <QString>
#include <QQmlApplicationEngine>
#include "GameActor.h"
#include "GameActorView.h"
#include <QKeyEvent>
#include "GameField.h"
#include "InputHandler.h"

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
        vector<GameActor*> actors;
        GameActor *localPlayer;
        GameField *field;
        InputHandler *inputHandler;

    public:
        GameLoop(InputHandler *inputHandler);
        virtual ~GameLoop();

    public slots:
        void run();
        void stop();

    private:
        void processInput();
        void update();
        void render();
        void execLocalPlayerAction(int code);

    signals:
        void ping(const string &result);
        void renderObject(vector<GameActorView*> *views);
};

#endif
