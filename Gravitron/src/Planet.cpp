#include "headers/Planet.h"
#include "headers/ActorsAdjustments.h"
#include "headers/Asteroid.h"
#include <string>
#include <QDebug>
#include <sstream>
#include <iostream>

Planet::Planet(Vec3f pos, float mass, float gravitationRange, float g, GameField &field, vector<GameActor*> *actors) :
    GameActor(pos, mass, gravitationRange, g, 100, field, actors)
{
}

GameActorView* Planet::getView() const {
    GameActorView* view = new GameActorView("qrc:/qml/planet");
    view->setProperty("identifier", identifier);
    view->setProperty("x", position[0]);
    view->setProperty("y", position[1]);
    view->setProperty("angle", calculateRotation());
    return view;
}

void Planet::update() {
}

void Planet::handleCollision(GameActor &other)
{
    other.dealDamage(PLANET_DAMAGE);
}

void Planet::handleKill()
{
    for(int i = 0; i < 3; i++) {
         Vec3f pos(position);
         float mass = fmod(rand(), ASTEROID_MAX_MASS - (ASTEROID_MIN_MASS - 1)) + ASTEROID_MIN_MASS;
         float g = fmod(rand(), ASTEROID_MAX_G - (ASTEROID_MIN_G - 1)) + ASTEROID_MIN_G;
         float gravitationRange = fmod(rand(), ASTEROID_MAX_GRAVITATION_RANGE - (ASTEROID_MIN_GRAVITATION_RANGE - 1)) + ASTEROID_MIN_GRAVITATION_RANGE;
         actors->push_back(new Asteroid(pos, mass, gravitationRange, g, *field, 7, actors));
    }
}
