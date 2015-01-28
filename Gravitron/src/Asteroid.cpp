#include "headers/Asteroid.h"
#include "headers/ActorsAdjustments.h"
#include <sstream>
#include <iostream>

Asteroid::Asteroid(Vec3f position, double mass, float gravitationRange, float g, GameField &field, float maxSpeed, vector<GameActor*> *actors) :
    GameActor(position, mass, gravitationRange, g, 50, field, maxSpeed, actors)
{
    Vec3f startAcceleration(rand() % 5, rand() % 5, 0.0f);
    acceleration = startAcceleration;
}


GameActorView* Asteroid::getView() const {
    GameActorView* view = new GameActorView("qrc:/qml/asteroid");
    view->setProperty("identifier", identifier);
    view->setProperty("x", position[0]);
    view->setProperty("y", position[1]);
    view->setProperty("angle", calculateRotation());
    return view;
}

void Asteroid::handleCollision(GameActor &other)
{
    other.dealDamage(ASTEROID_DAMAGE);
}
