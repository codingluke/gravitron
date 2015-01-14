#include "headers/GameGenerator.h"
#include "headers/ActorsAdjustments.h"
#include "headers/Planet.h"
#include "headers/Asteroid.h"
#include "headers/Spacecraft.h"
#include "headers/KiPlayer.h"
#include "headers/KiNetworkPlayer.h"
#include "headers/HumanPlayer.h"
#include "headers/HumanNetworkPlayer.h"
#include "headers/GameField.h"
#include "headers/PowerUp.h"
#include "headers/Scrap.h"
#include "headers/Sun.h"
#include <QDebug>

GameGenerator::GameGenerator(QObject *parent) :
    QObject(parent)
{
}

GameGenerator::GameGenerator(GravitronSettings *settings)
{
    this->settings = settings;
    this->field = new GameField(1000 , 1000);
}

GameGenerator::GameGenerator(const GameGenerator& original)
{
    settings = original.settings;
    field = original.field;
    actors = original.actors;
    bots = original.bots;
    humanPlayer = original.humanPlayer;
}

void GameGenerator::generateGame(GameLoop* g) {
    srand(time(NULL));
    //generateBots();
    generateSun();
    generateRandomPowerUps();
    generateRandomScrap();
    generatePlanets();
    generateAstroids();
    generatePlayer(g);

    g->setBots(bots);
    g->setPlayer(humanPlayer);
    g->setActors(actors);
    g->setRespawTime(settings->respawTime());
}

void GameGenerator::generateBots() {
    Spacecraft* sc = generateNewSpacecraft();
    actors.push_back(sc);
    for(int i = 0; i < settings->botsCount(); i++) {
        if (settings->network()) {
            bots.push_back(new KiNetworkPlayer(sc, settings->frag(), settings->difficulty()));
        } else {
            bots.push_back(new KiPlayer(sc, settings->frag(), settings->difficulty()));
        }
    }
}

void GameGenerator::generatePlayer(GameLoop* g) {
    Spacecraft* sc = generateNewSpacecraft();
    actors.push_back(sc);
    if (settings->network()) {
        humanPlayer.push_back(new HumanNetworkPlayer(sc, settings->frag(), g));
    } else {
        humanPlayer.push_back(new HumanPlayer(sc, settings->frag(), g));
    }
}

Spacecraft* GameGenerator::generateNewSpacecraft() {
    Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
    float mass = fmod(rand(), SPACECRAFT_MAX_MASS - (SPACECRAFT_MIN_MASS - 1)) + SPACECRAFT_MIN_MASS;
    float g = fmod(rand(), PLANET_MAX_G - (PLANET_MIN_G - 1)) + PLANET_MIN_G;
    float gravitationRange = fmod(rand(), PLANET_MAX_GRAVITATION_RANGE - (PLANET_MIN_GRAVITATION_RANGE - 1)) + PLANET_MIN_GRAVITATION_RANGE;
    return new Spacecraft(position, mass, 0, 0, *field, 10);
}



void GameGenerator::generatePlanets() {
    for(int i = 0; i < settings->planetCount(); i++) {
        Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
        float mass = fmod(rand(), PLANET_MAX_MASS - (PLANET_MIN_MASS - 1)) + PLANET_MIN_MASS;
        float g = fmod(rand(), PLANET_MAX_G - (PLANET_MIN_G - 1)) + PLANET_MIN_G;
        float gravitationRange = fmod(rand(), PLANET_MAX_GRAVITATION_RANGE - (PLANET_MIN_GRAVITATION_RANGE - 1)) + PLANET_MIN_GRAVITATION_RANGE;
        actors.push_back(new Planet(position, mass, gravitationRange, g, *field));
    }
}

void GameGenerator::generateAstroids() {
    for(int i = 0; i < settings->astroidCount(); i++) {
        Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
        float mass = fmod(rand(), ASTEROID_MAX_MASS - (ASTEROID_MIN_MASS - 1)) + ASTEROID_MIN_MASS;
        float g = fmod(rand(), ASTEROID_MAX_G - (ASTEROID_MIN_G - 1)) + ASTEROID_MIN_G;
        float gravitationRange = fmod(rand(), ASTEROID_MAX_GRAVITATION_RANGE - (ASTEROID_MIN_GRAVITATION_RANGE - 1)) + ASTEROID_MIN_GRAVITATION_RANGE;
        actors.push_back(new Asteroid(position, mass, gravitationRange, g, *field, 7));
    }
}

void GameGenerator::generateRandomPowerUps() {
    int numberRadomPowerUps = 0;
    if (settings->difficulty() == 1) {
        numberRadomPowerUps = rand() % 10;
    } else if (settings->difficulty() == 2) {
        numberRadomPowerUps = 1;
    }

    for (int i = 0; i < numberRadomPowerUps; i++) {
        Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
        actors.push_back(generateNewPowerUp(position));
    }
}

GameActor* GameGenerator::generateNewPowerUp(Vec3f position) {
    return new PowerUp(position, *field);
}

void GameGenerator::generateRandomScrap() {
    int numberRadomScrap = 0;
    if (settings->difficulty() == 2) {
        numberRadomScrap = rand() % 30;
    } else if (settings->difficulty() == 2) {
        numberRadomScrap = rand() % 10;
    }

    for (int i = 0; i < numberRadomScrap; i++) {
        Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
        actors.push_back(generateNewScrap(position));
    }
}

GameActor* GameGenerator::generateNewScrap(Vec3f position) {
    float mass = fmod(rand(), SCRAP_MAX_MASS - (SCRAP_MIN_MASS - 1)) + SCRAP_MIN_MASS;
    float g = fmod(rand(), SCRAP_MAX_G - (SCRAP_MIN_G - 1)) + SCRAP_MIN_G;
    float gravitationRange = fmod(rand(), SCRAP_MAX_GRAVITATION_RANGE - (SCRAP_MIN_GRAVITATION_RANGE - 1)) +SCRAP_MIN_GRAVITATION_RANGE;
    return new Scrap(position, mass, gravitationRange, g, *field);
}

void GameGenerator::generateSun() {
    Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
    float mass = fmod(rand(), SUN_MAX_MASS - (SUN_MIN_MASS - 1)) + SUN_MIN_MASS;
    float g = fmod(rand(), SUN_MAX_G - (SUN_MIN_G - 1)) + SUN_MIN_G;
    float gravitationRange = fmod(rand(), SUN_MAX_GRAVITATION_RANGE - (SUN_MIN_GRAVITATION_RANGE - 1)) + SUN_MIN_GRAVITATION_RANGE;
    actors.push_back(new Sun(position, mass, gravitationRange, g, *field));
}
