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
    void generateGame(GameLoop* g);

private:
    void generateBots();
    void generatePlanets();
    void generateAstroids();
    void generatePlayer();


signals:

public slots:

};

#endif // GAMEGENERATOR_H
