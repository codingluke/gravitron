#include "headers/Spacecraft.h"
#include <sstream>
#include <iostream>

Spacecraft::Spacecraft() : GameActor()
{
    g = 0;
}

Spacecraft::Spacecraft(Vec3f position, double mass, float gravitationRange, float g) :
    GameActor(position, mass, gravitationRange, g)
{
    g = 0;
}

Spacecraft::Spacecraft(const Spacecraft &spacecraft) : GameActor(spacecraft)
{
    g = 0;
}

Spacecraft::~Spacecraft() {

}


/*void Spacecraft::applyForce(Vec3f force) {

}

void Spacecraft::update() {

}

void Spacecraft::update(double radius) {

}*/

GameActorView* Spacecraft::getView() const {
    std::cout << "spacecraft" << std::endl;
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView *view = new GameActorView("qrc:/qml/spacecraft");
    view->setProperty("identifier", "S");
    view->setProperty("x", x.str());
    view->setProperty("y", y.str());
    view->setProperty("color", "green");
    return view;
}

/*std::string Spacecraft::toString() const {

}*/
