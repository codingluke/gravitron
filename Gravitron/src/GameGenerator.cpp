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

/**
 * Constructor needed for QT.
 * @param parent The parent QObject.
 */
GameGenerator::GameGenerator(QObject *parent) :
    QObject(parent)
{
}

/**
 * The constructor for an singlepalyer game.
 * @param settings The @see GravitronSettings.
 * @param field The @see GameField.
 */
GameGenerator::GameGenerator(GravitronSettings *settings, GameField* field)
{
    this->settings = settings;
    this->field = field;
}

/**
 * The constructor for an multipalyer game.
 * @param settings The @see GravitronSettings.
 * @param field The @see GameField.
 * @param server The @see TcpServer.
 */
GameGenerator::GameGenerator(GravitronSettings *settings, GameField* field, TcpServer *server)
{
    this->settings = settings;
    this->field = field;
    this->server = server;
}

/**
 * The copy constructor.
 * @param original The original object.
 */
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

/**
 * The destructor.
 */
GameGenerator::~GameGenerator()
{
}

/**
 * Generate the \see GameActor, \see AIPlayer and \see HumanPlayer for the given
 * \see GameLoop.
 * @param g The \see GameLoop.
 */
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

/**
 * Generate the \see AIPlayer s (aka bots) depending on the count of bots in
 * the \see GravitronSettings.
 */
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

/**
 * Generate \see HumanPlayer or/and \see HumanNetworkPlayer. If the game is a
 * singelplayer game one \see HumanPlayer is generated else the game is a multiplayer
 * game and a \see HumanPlayer and a \see HumanNetworkPlayer is generated.
 */
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

/**
 * Generate a \see Spacecraft with a random position and rondom mass, g and gravitationRange in the
 * borders that deffined in the \see ActConf class. The \see Spacecraft is added to the actors list.
 * @return The \see Spacecraft.
 */
Spacecraft* GameGenerator::generateNewSpacecraft() {
    Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
    float mass = fmod(rand(), ActConf::SPACECRAFT_MAX_MASS - (ActConf::SPACECRAFT_MIN_MASS - 1)) + ActConf::SPACECRAFT_MIN_MASS;
    return new Spacecraft(position, mass, 0, 0, *field, ActConf::SPACECRAFT_MAX_MAXSPEED, actors);
}

/**
 * Generate the \see Planet s with a random position and rondom mass, g and gravitationRange in the
 * borders that deffined in the \see ActConf class. The number of \see Planet s is defind in the
 * \see GravitronSettings. All \see Planet s are added to the list of actros.
 */
void GameGenerator::generatePlanets() {
    for(int i = 0; i < settings->planetCount(); i++) {
        Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
        float mass = fmod(rand(), ActConf::PLANET_MAX_MASS - (ActConf::PLANET_MIN_MASS - 1)) + ActConf::PLANET_MIN_MASS;
        float g = fmod(rand(), ActConf::PLANET_MAX_G - (ActConf::PLANET_MIN_G - 1)) + ActConf::PLANET_MIN_G;
        float gravitationRange = fmod(rand(), ActConf::PLANET_MAX_GRAVITATION_RANGE - (ActConf::PLANET_MIN_GRAVITATION_RANGE - 1)) + ActConf::PLANET_MIN_GRAVITATION_RANGE;
        actors->push_back(new Planet(position, mass, gravitationRange, g, *field, actors));
    }
}

/**
 * Generate the \see Asteroid s with a random position and rondom mass, g and gravitationRange in the
 * borders that deffined in the \see ActConf class. The number of \see Asteroid s is defind in the
 * \see GravitronSettings. All \see Asteroid s are added to the list of actros.
 */
void GameGenerator::generateAstroids() {
    for(int i = 0; i < settings->astroidCount(); i++) {
        Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
        float mass = fmod(rand(), ActConf::ASTEROID_MAX_MASS - (ActConf::ASTEROID_MIN_MASS - 1)) + ActConf::ASTEROID_MIN_MASS;
        float g = fmod(rand(), ActConf::ASTEROID_MAX_G - (ActConf::ASTEROID_MIN_G - 1)) + ActConf::ASTEROID_MIN_G;
        float gravitationRange = fmod(rand(), ActConf::ASTEROID_MAX_GRAVITATION_RANGE - (ActConf::ASTEROID_MIN_GRAVITATION_RANGE - 1)) + ActConf::ASTEROID_MIN_GRAVITATION_RANGE;
        actors->push_back(new Asteroid(position, mass, gravitationRange, g, *field, 7, actors));
    }
}

/**
 * Generate the \see PowerUp s. The number of \see PowerUp s is random depaning on the
 * difficulty. On easy 0 betwenn 10, on middle 0 between 10 and on hard no are generated.
 * All genreated \see PowerUp s are add to list of actors.
 */
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

/**
 * Generate a new \see PowerUp at the given position.
 * @param position The position.
 * @return The \see PowerUp.
 */
GameActor* GameGenerator::generateNewPowerUp(Vec3f position) {
    return new PowerUp(position, *field, actors);
}

/**
 * Generate the \see Scrap. The number of \see Scrap is random depaning on the
 * difficulty. On easy there is nothing generate, on middle 0 between 10, on hard
 * 0 between 30.
 * All genreated \see Scrap are add to list of actors.
 */
void GameGenerator::generateRandomScrap() {
    int numberRadomScrap = 0;
    if (settings->difficulty() == 3) {
        numberRadomScrap = rand() % 30;
    } else if (settings->difficulty() == 2) {
        numberRadomScrap = rand() % 10;
    }

    for (int i = 0; i < numberRadomScrap; i++) {
        Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
        actors->push_back(generateNewScrap(position));
    }
}

/**
 * Generate a \see Scrap with the given position and rondom mass, g and gravitationRange in the
 * borders that deffined in the \see ActConf class.
 * @param position The position.
 * @return The generated scrap.
 */
GameActor* GameGenerator::generateNewScrap(Vec3f position) {
    float mass = fmod(rand(), ActConf::SCRAP_MAX_MASS - (ActConf::SCRAP_MIN_MASS - 1)) + ActConf::SCRAP_MIN_MASS;
    float g = fmod(rand(), ActConf::SCRAP_MAX_G - (ActConf::SCRAP_MIN_G - 1)) + ActConf::SCRAP_MIN_G;
    float gravitationRange = fmod(rand(), ActConf::SCRAP_MAX_GRAVITATION_RANGE - (ActConf::SCRAP_MIN_GRAVITATION_RANGE - 1)) + ActConf::SCRAP_MIN_GRAVITATION_RANGE;
    return new Scrap(position, mass, gravitationRange, g, *field, actors);
}

/**
 * Generate the \see Sun with a random position and rondom mass, g and gravitationRange in the
 * borders that deffined in the \see ActConf class. The \see Sun is added to the actors list.
 */
void GameGenerator::generateSun() {
    Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
    float mass = fmod(rand(), ActConf::SUN_MAX_MASS - (ActConf::SUN_MIN_MASS - 1)) + ActConf::SUN_MIN_MASS;
    float g = fmod(rand(), ActConf::SUN_MAX_G - (ActConf::SUN_MIN_G - 1)) + ActConf::SUN_MIN_G;
    float gravitationRange = fmod(rand(), ActConf::SUN_MAX_GRAVITATION_RANGE - (ActConf::SUN_MIN_GRAVITATION_RANGE - 1)) + ActConf::SUN_MIN_GRAVITATION_RANGE;
    actors->push_back(new Sun(position, mass, gravitationRange, g, *field, actors));
}
