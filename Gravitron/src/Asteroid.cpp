#include "headers/Asteroid.h"
#include <sstream>
#include <iostream>

Asteroid::Asteroid(Vec3f position, double mass, float gravitationRange, float g, GameField &field, float maxSpeed, vector<GameActor*> *actors) :
    GameActor(position, mass, gravitationRange, g, 50, field, maxSpeed, actors)
{}


GameActorView* Asteroid::getView() const {
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView* v = new GameActorView("qrc:/qml/asteroid");
    v->setProperty("identifier", "S");
    v->setProperty("x", x.str());
    v->setProperty("y", y.str());
    return v;
}

void Asteroid::handleCollision(GameActor &other)
{

}
