#ifndef GAMEGENERATOR_H
#define GAMEGENERATOR_H

#include <QObject>
#include "GravitronSettings.h"
#include "GameLoop.h"
#include "Player.h"
#include "AIPlayer.h"
#include "TcpServer.h"
#include <vector>

class GameLoop; // <<== Forward declare the class. Because of circular definitions.

/**
 * This is to generate all GameActor for the Game. Depending on the current
 * GravitronSettings a differen number of Actors of all kinds are generate.
 * All actors will generated with random values with the help of the ActConf
 * class and placed randomly on the GameField.
 * The GameGenerator just works for the GameLoop.
 *
 * Important: All created heab objects not will be delete by the GameGenerator.
 */
class GameGenerator : public QObject
{
    Q_OBJECT
    private:
        /**
         * The GravitronSettings .
         */
        GravitronSettings *settings;

        /**
         * The GameField
         */
        GameField* field;

        /**
         * The TcpServer.
         */
        TcpServer* server;

        /**
         * The list of actors filled doing game generation.
         */
        std::vector<GameActor*> *actors;

        /**
         * The list of generated AIPlayer.
         */
        std::vector<AIPlayer*> bots;

        /**
         * The list of Player.
         */
        std::vector<Player*> humanPlayer;


    public:
        explicit GameGenerator(QObject *parent = 0);
        GameGenerator(GravitronSettings *settings, GameField* field);
        GameGenerator(GravitronSettings *settings, GameField* field, TcpServer *server);
        GameGenerator(const GameGenerator& original); 

        ~GameGenerator();
        void generateGame(GameLoop* g);

        GameActor* generateNewPowerUp(Vec3f position);
        GameActor* generateNewScrap(Vec3f position);

    private:
        void generateBots();
        void generatePlanets();
        void generateAstroids();
        void generatePlayer();
        void generateRandomPowerUps();
        void generateRandomScrap();
        void generateSun();
        Spacecraft* generateNewSpacecraft();
};

#endif // GAMEGENERATOR_H
