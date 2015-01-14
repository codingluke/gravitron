#ifndef GAMEGENERATOR_H
#define GAMEGENERATOR_H

#include <QObject>
#include "GravitronSettings.h"
#include "GameLoop.h"
#include "Player.h"
#include <vector>

class GameLoop; // <<== Forward declare the class. Because of circular definitions.

class GameGenerator : public QObject
{
    Q_OBJECT
    private:
        GravitronSettings *settings;
        std::vector<GameActor*> actors;
        std::vector<Player*> bots;
        std::vector<Player*> humanPlayer;
        GameField* field;

    public:
        explicit GameGenerator(QObject *parent = 0);
        GameGenerator(GravitronSettings *settings);
        GameGenerator(const GameGenerator& original); // copy constructor

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


signals:

public slots:

};

#endif // GAMEGENERATOR_H
