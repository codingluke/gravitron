#include "headers/GameGenerator.h"
#include "headers/Planet.h"
#include "headers/Asteroid.h"
#include "headers/Spacecraft.h"
#include "headers/KiPlayer.h"
#include "headers/KiNetworkPlayer.h"
#include "headers/HumanPlayer.h"
#include "headers/HumanNetworkPlayer.h"
#include "headers/GameField.h"
#include <QDebug>

GameGenerator::GameGenerator(QObject *parent) :
    QObject(parent)
{
}

GameGenerator::GameGenerator(GravitronSettings *settings) {
    this->settings = settings;
    this->field = new GameField(500 , 500);
}

void GameGenerator::generateGame(GameLoop* g) {
    /*
    bool mFullScreen;
    int mMusicSoundVolume;
    bool mPlayMusic;
    bool mPlaySounds;
    QString mPlayerName;
    */
    //generateBots();
    generatePlanets();
    //generateAstroids();
    generatePlayer();

    qDebug() << "GameCreator: " << actors.size();

    g->setBots(bots);
    g->setPlayer(humanPlayer);
    g->setActors(actors);
    g->setRespawTime(settings->respawTime());

    g->setGameField(field); //settings->playingFieldSize()))
}

void GameGenerator::generateBots() {
    for(int i = 0; i < settings->botsCount(); i++) {
        Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
        float mass = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        Spacecraft* sc = new Spacecraft(position, mass, 0, 0, *field, 10);
        actors.push_back(sc);
        if (settings->network()) {
            bots.push_back(new KiNetworkPlayer(sc, settings->frag(), settings->difficulty()));
        } else {
            bots.push_back(new KiPlayer(sc, settings->frag(), settings->difficulty()));
        }
    }
}

void GameGenerator::generatePlayer() {
    Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
    float mass = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    Spacecraft* sc = new Spacecraft(position, mass, 0, 0, *field, 10);
    actors.push_back(sc);
    if (settings->network()) {
        humanPlayer.push_back(new HumanNetworkPlayer(sc, settings->frag()));
    } else {
        humanPlayer.push_back(new HumanPlayer(sc, settings->frag()));
    }
}

void GameGenerator::generatePlanets() {
    for(int i = 0; i < settings->planetCount(); i++) {
        Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
        //qDebug() << "GameGenerator " <<position[0] << " " << position[1];
        actors.push_back(new Planet(position, *field));
    }
}

void GameGenerator::generateAstroids() {
    for(int i = 0; i < settings->astroidCount(); i++) {
        actors.push_back(new Asteroid());
    }
}
