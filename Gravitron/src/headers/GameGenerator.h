#ifndef GAMEGENERATOR_H
#define GAMEGENERATOR_H

#include <QObject>
#include "GravitronSettings.h"
#include "GameLoop.h"
#include "Player.h"
#include "TcpServer.h"
#include <vector>

class GameLoop; // <<== Forward declare the class. Because of circular definitions.

class GameGenerator : public QObject
{
    Q_OBJECT
    private:
        GravitronSettings *settings;
        GameField* field;
        TcpServer* server;
        std::vector<GameActor*> actors;
        std::vector<Player*> bots;
        std::vector<Player*> humanPlayer;

    public:
        explicit GameGenerator(QObject *parent = 0);
        GameGenerator(GravitronSettings *settings, GameField* field);
        GameGenerator(GravitronSettings *settings, GameField* field, TcpServer *server);
        GameGenerator(const GameGenerator& original); // copy constructor

        ~GameGenerator();
        void generateGame(GameLoop* g);

        GameActor* generateNewPowerUp(Vec3f position);
        GameActor* generateNewScrap(Vec3f position);

    private:
        void generateBots();
        void generatePlanets();
        void generateAstroids();
        void generatePlayer(GameLoop* g);
        void generateRandomPowerUps();
        void generateRandomScrap();
        void generateSun();
        Spacecraft* generateNewSpacecraft();
};

#endif // GAMEGENERATOR_H
