#include "headers/Planet.h"
#include <string>
#include <QDebug>
#include <sstream>
#include <iostream>

//GameActor(Vec3f position, double mass, float gravitationRange, float g, int health, GameField &field)
Planet::Planet(Vec3f pos, float mass, float gravitationRange, float g, GameField &field, vector<GameActor*> *actors) :
    GameActor(pos, mass, gravitationRange, g, 100, field, actors)
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
