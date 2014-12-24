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
        //int inputs;
        GameField *field;
        InputHandler *inputHandler;

    //protected:
        //bool eventFilter(QObject *obj, QEvent *event);

    public:
        GameLoop(InputHandler *inputHandler);
        virtual ~GameLoop();

    public slots:
        void run();
        void stop();
        //void inputEvents(int code);

    private:
        void processInput();
        void update();
        void render();
        void applyGravitationToAllActor();
        void updateAllActors();
        void execLocalPlayerAction(int code);

    signals:
        void ping(const string &result);
        void renderObject(vector<GameActorView*> *views);
};

#endif
