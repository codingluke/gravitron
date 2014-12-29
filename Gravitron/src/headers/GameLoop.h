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
#include "GameGenerator.h"
#include "Player.h"

class GameGenerator; // <<== Forward declare the class. Because of circular definitions.

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
        Spacecraft *localPlayer;
        vector<Player*> bots;
        vector<Player*> player;
        int respawnTime;
        GameField *field;
        InputHandler *inputHandler;
        GameGenerator *gGenerator;

    public:
        GameLoop(InputHandler *inputHandler, GameGenerator* gGenerator);
        virtual ~GameLoop();
        void setBots(vector<Player*> bots);
        void setPlayer(vector<Player*> player);
        void setActors(vector<GameActor*> actors);
        void setGameField(GameField* newField);
        void setRespawTime(int respawnTime);

    public slots:
        void run();
        void stop();

    private:
        void processInput();
        void update();
        void render();
        void execLocalPlayerAction(int code);
        void deleteBots();
        void deletePlayer();
        void deleteActors();

    signals:
        void ping(const string &result);
        void renderObject(vector<GameActorView*> *views);
};

#endif

