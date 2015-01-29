#include "headers/GameGenerator.h"
#include "headers/ActorsAdjustments.h"
#include "headers/Planet.h"
#include "headers/Asteroid.h"
#include "headers/Spacecraft.h"
#include "headers/AIPlayer.h"
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

GameGenerator::GameGenerator(GravitronSettings *settings, GameField* field)
{
    this->settings = settings;
    this->field = field;
}

GameGenerator::GameGenerator(GravitronSettings *settings, GameField* field, TcpServer *server)
{
    this->settings = settings;
    this->field = field;
    this->server = server;
}

GameGenerator::GameGenerator(const GameGenerator& original) :
    QObject(original.parent())
{
    settings = original.settings;
    field = original.field;
    server = original.server;
    actors = original.actors;
    bots = original.bots;
    humanPlayer = original.humanPlayer;
}

GameGenerator::~GameGenerator()
{
}

void GameGenerator::generateGame(GameLoop* g) {
    this->actors = &(g->actors);
    srand(time(NULL));
    generateBots();
    generateSun();
    generateRandomPowerUps();
    generateRandomScrap();
    generatePlanets();
    generateAstroids();
    generatePlayer();

    g->setBots(bots);
    g->setPlayer(humanPlayer);
    g->setRespawTime(settings->respawTime());
    g->setGameField(field);
}

void GameGenerator::generateBots()
{
    for(int i = 0; i < settings->botsCount(); i++) {
        Spacecraft* sc = generateNewSpacecraft();
        actors->push_back(sc);
        bots.push_back(new AIPlayer(
            sc, settings->frag(), settings->difficulty(), actors, "Bot"
        ));
    }
}

void GameGenerator::generatePlayer() {
    if (settings->network()) {
        Spacecraft* sc = generateNewSpacecraft();
        Spacecraft* sc2 = generateNewSpacecraft();
        actors->push_back(sc);
        actors->push_back(sc2);
        humanPlayer.push_back(new HumanPlayer(
            sc, settings->frag(), settings->playerName()
        ));
        humanPlayer.push_back( new HumanNetworkPlayer(
            sc2, settings->frag(), server, "Network"
        ));
    } else {
        Spacecraft* sc = generateNewSpacecraft();
        actors->push_back(sc);
        humanPlayer.push_back(new HumanPlayer(
            sc, settings->frag(), settings->playerName()
        ));
    }
}

Spacecraft* GameGenerator::generateNewSpacecraft() {
    Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
    float mass = fmod(rand(), ActConf::SPACECRAFT_MAX_MASS - (ActConf::SPACECRAFT_MIN_MASS - 1)) + ActConf::SPACECRAFT_MIN_MASS;
    return new Spacecraft(position, mass, 0, 0, *field, ActConf::SPACECRAFT_MAX_MAXSPEED, actors);
}



void GameGenerator::generatePlanets() {
    for(int i = 0; i < settings->planetCount(); i++) {
        Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
        float mass = fmod(rand(), ActConf::PLANET_MAX_MASS - (ActConf::PLANET_MIN_MASS - 1)) + ActConf::PLANET_MIN_MASS;
        float g = fmod(rand(), ActConf::PLANET_MAX_G - (ActConf::PLANET_MIN_G - 1)) + ActConf::PLANET_MIN_G;
        float gravitationRange = fmod(rand(), ActConf::PLANET_MAX_GRAVITATION_RANGE - (ActConf::PLANET_MIN_GRAVITATION_RANGE - 1)) + ActConf::PLANET_MIN_GRAVITATION_RANGE;
        actors->push_back(new Planet(position, mass, gravitationRange, g, *field, actors));
    }
}

void GameGenerator::generateAstroids() {
    for(int i = 0; i < settings->astroidCount(); i++) {
        Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
        float mass = fmod(rand(), ActConf::ASTEROID_MAX_MASS - (ActConf::ASTEROID_MIN_MASS - 1)) + ActConf::ASTEROID_MIN_MASS;
        float g = fmod(rand(), ActConf::ASTEROID_MAX_G - (ActConf::ASTEROID_MIN_G - 1)) + ActConf::ASTEROID_MIN_G;
        float gravitationRange = fmod(rand(), ActConf::ASTEROID_MAX_GRAVITATION_RANGE - (ActConf::ASTEROID_MIN_GRAVITATION_RANGE - 1)) + ActConf::ASTEROID_MIN_GRAVITATION_RANGE;
        actors->push_back(new Asteroid(position, mass, gravitationRange, g, *field, 7, actors));
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
        actors->push_back(generateNewPowerUp(position));
    }
}

GameActor* GameGenerator::generateNewPowerUp(Vec3f position) {
    return new PowerUp(position, *field, actors);
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
        actors->push_back(generateNewScrap(position));
    }
}

GameActor* GameGenerator::generateNewScrap(Vec3f position) {
    float mass = fmod(rand(), ActConf::SCRAP_MAX_MASS - (ActConf::SCRAP_MIN_MASS - 1)) + ActConf::SCRAP_MIN_MASS;
    float g = fmod(rand(), ActConf::SCRAP_MAX_G - (ActConf::SCRAP_MIN_G - 1)) + ActConf::SCRAP_MIN_G;
    float gravitationRange = fmod(rand(), ActConf::SCRAP_MAX_GRAVITATION_RANGE - (ActConf::SCRAP_MIN_GRAVITATION_RANGE - 1)) + ActConf::SCRAP_MIN_GRAVITATION_RANGE;
    return new Scrap(position, mass, gravitationRange, g, *field, actors);
}

void GameGenerator::generateSun() {
    Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
    float mass = fmod(rand(), ActConf::SUN_MAX_MASS - (ActConf::SUN_MIN_MASS - 1)) + ActConf::SUN_MIN_MASS;
    float g = fmod(rand(), ActConf::SUN_MAX_G - (ActConf::SUN_MIN_G - 1)) + ActConf::SUN_MIN_G;
    float gravitationRange = fmod(rand(), ActConf::SUN_MAX_GRAVITATION_RANGE - (ActConf::SUN_MIN_GRAVITATION_RANGE - 1)) + ActConf::SUN_MIN_GRAVITATION_RANGE;
    actors->push_back(new Sun(position, mass, gravitationRange, g, *field, actors));
}
