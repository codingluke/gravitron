#include "headers/PowerUp.h"
#include "headers/Spacecraft.h"
#include "headers/ActorsAdjustments.h"
#include <iostream>
#include <sstream>


PowerUp::PowerUp(Vec3f position, GameField &field, vector<GameActor*> *actors) : GameActor(position, ActConf::POWERUP_MAX_MASS, ActConf::POWERUP_MAX_GRAVITATION_RANGE, ActConf::POWERUP_MIN_G, ActConf::POWERUP_MAX_HEALTH, field, actors)
{
}

void PowerUp::handleCollision(GameActor &other)
{
    Spacecraft* isSpacecraft = dynamic_cast<Spacecraft*>(&other);

    if (isSpacecraft != 0 && !(isSpacecraft->isKilled())) {
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
