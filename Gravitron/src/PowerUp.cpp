#include "headers/PowerUp.h"
#include "headers/Spacecraft.h"
#include <iostream>
#include <sstream>

PowerUp::PowerUp(Vec3f position, GameField &field, vector<GameActor*> *actors) : GameActor(position, 0.0, 0.0, 0.0, 0, field, actors)
{
}

void PowerUp::handleCollision(GameActor &other)
{
    Spacecraft* isSpacecraft = dynamic_cast<Spacecraft*>(&other);
    if (isSpacecraft != 0) {
        isSpacecraft->upgradeWeapon();
        kill();
    }
}

GameActorView* PowerUp::getView() const
{
    std::ostringstream identifiy;
    identifiy << identifier;
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView *view = new GameActorView("qrc:/qml/powerUp");
    view->setProperty("identifier", identifiy.str());
    view->setProperty("x", x.str());
    view->setProperty("y", y.str());

    return view;
}

void PowerUp::applyForce(Vec3f force) {}
void PowerUp::update() {}
void PowerUp::update(vector<GameActor*> actors) {}
