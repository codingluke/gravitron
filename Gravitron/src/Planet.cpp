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

// void Planet::kill() {
//     qDebug() << "Planet: kill";

// }

GameActorView* Planet::getView() const {
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView* v = new GameActorView("qrc:/qml/planet");
    v->setProperty("identifier", "S");
    v->setProperty("x", x.str());
    v->setProperty("y", y.str());
    return v;
}

void Planet::update() {
}

void Planet::handleCollision(GameActor &other)
{

}

void Planet::handleKill()
{
    // for(int i = 0; i < 3; i++) {
    //     Vec3f position(this->position);
    //     float mass = fmod(rand(), ASTEROID_MAX_MASS - (ASTEROID_MIN_MASS - 1)) + ASTEROID_MIN_MASS;
    //     float g = fmod(rand(), ASTEROID_MAX_G - (ASTEROID_MIN_G - 1)) + ASTEROID_MIN_G;
    //     float gravitationRange = fmod(rand(), ASTEROID_MAX_GRAVITATION_RANGE - (ASTEROID_MIN_GRAVITATION_RANGE - 1)) + ASTEROID_MIN_GRAVITATION_RANGE;
    //     // Asteroid *asteroid = ;
    //     actors->push_back(new Asteroid(position, mass, gravitationRange, g, *field, 7, actors));
    //     Vec3f direction(rand(), rand(), 0);
    //     actors->back()->applyForce(direction);
    // } 
}