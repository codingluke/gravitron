#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <QThread>
#include <QString>
#include <vector>
#include "GameActor.h"
#include "GameActorView.h"
#include "GameField.h"
#include "GameGenerator.h"
#include "Player.h"
#include "AIPlayer.h"

class GameGenerator; // <<== Forward declare the class. Because of circular definitions.

using namespace std;

/**
 * Definition of the Gameloop. The GameLoop is the Heartbeat of the game.
 * It orchestrates the Processes to handle the game.
 */
class GameLoop : public QThread
{
    Q_OBJECT

    private:
        /**
         * Shows if the GameLoop is running.
         */
        bool running;

        /**
         * List of all the AI bots.
         */
        vector<AIPlayer*> bots;

        /**
         * List of the Human Players.
         */
        vector<Player*> players;

        /**
         * Pointer to the GameField.
         */
        GameField *field = NULL;

    public:
        vector<GameActor*> actors;

        GameLoop(GameGenerator gGenerator);
        virtual ~GameLoop();

        void setBots(vector<AIPlayer*> bots);
        void setPlayers(vector<Player*> players);
        void setActors(vector<GameActor*> actors);
        void setGameField(GameField* newField);
        void stop();

    public slots:
        void run();

    private:
        void processInput();
        void update();
        void render();
        void deleteBots();
        void deletePlayers();
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

