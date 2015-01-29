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
#include "AIPlayer.h"
#include "NetworkInputHandler.h"

class GameGenerator; // <<== Forward declare the class. Because of circular definitions.

using namespace std;

class GameLoop : public QThread
{
    Q_OBJECT

    private:
        bool running;
        int ms_per_update;
        QObject *game;
        QQmlApplicationEngine *engine;
        vector<AIPlayer*> bots;
        vector<Player*> player;
        int respawnTime;
        GameField *field;

    public:
        std::vector<GameActor*> actors;

        GameLoop(GameGenerator gGenerator);

        virtual ~GameLoop();

        void setBots(vector<AIPlayer*> bots);
        void setPlayer(vector<Player*> player);
        void setActors(vector<GameActor*> actors);
        void setGameField(GameField* newField);
        void setRespawTime(int respawnTime);
        void stop();

    public slots:
        void run();

    private:
        void processInput();
        void update();
        void render();
        void execLocalPlayerAction(int code);
        void deleteBots();
        void deletePlayer();
        void deleteActors();
        void remapActorsReferences();
        float getRelativePositionX(Spacecraft &anchor, GameActor &other) const;
        float getRelativePositionY(Spacecraft &anchor, GameActor &other) const;
        void checkWinner();

    signals:
        void renderObject(vector<GameActorView*> *views);
        void sendViewlist(QString viewlist);
        void activeWeaponGame(int weaponNumber);
        void lifepoints(int lifepoints);
        void backgroundPos(float x, float y, float fieldWidth, float fieldHeight);
        void theWinnerIs(QString winnerName);
        void fragStatus(int must, int have);
};

#endif

