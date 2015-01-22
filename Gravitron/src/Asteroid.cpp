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
    GameActorView* view = new GameActorView("qrc:/qml/asteroid");
    view->setProperty("identifier", "S");
    view->setProperty("x", x.str());
    view->setProperty("y", y.str());
    std::ostringstream rot;
    rot << calculateRotation();
    view->setProperty("angle", rot.str());
    return view;
}

void Asteroid::handleCollision(GameActor &other)
{

}
