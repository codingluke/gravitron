#include "headers/Sun.h"
#include "headers/ActorsAdjustments.h"
#include <iostream>
#include <sstream>

Sun::Sun(Vec3f position, float mass, float gravitationRange, float g, GameField& field, vector<GameActor*> *actors)
    : GameActor(position, mass, gravitationRange, g, -1, field, actors)
{
}

void Sun::handleCollision(GameActor &other)
{
    other.dealDamage(SUN_DAMAGE);
}

GameActorView* Sun::getView() const {
    GameActorView *view = new GameActorView("qrc:/qml/sun");
    view->setProperty("identifier", identifier);
    view->setProperty("x", position[0]);
    view->setProperty("y", position[1]);
    view->setProperty("angle", calculateRotation());
    return view;
}

void Sun::applyForce(Vec3f force) {}
void Sun::update() {}
