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
    other.dealDamage(SUN_DEALDAMAGE);
}

GameActorView* Sun::getView() const {
    std::ostringstream identifiy;
    identifiy << identifier;
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView *view = new GameActorView("qrc:/qml/sun");
    view->setProperty("identifier", identifiy.str());
    view->setProperty("x", x.str());
    view->setProperty("y", y.str());
    return view;
}

void Sun::applyForce(Vec3f force) {}
void Sun::update() {}
