#include "headers/Planet.h"
#include <string>
#include <QDebug>
#include <sstream>
#include <iostream>

Planet::Planet(Vec3f pos, GameField &field) :
    GameActor(pos, 10, 30, 0.5, 100, field)
{
}

void Planet::kill() {
    qDebug() << "Planet: kill";
}

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
