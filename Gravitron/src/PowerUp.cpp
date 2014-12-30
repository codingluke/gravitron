#include "headers/PowerUp.h"
#include <iostream>
#include <sstream>

PowerUp::PowerUp(Vec3f position, GameField &field) : GameActor(position, 0.0, 0.0, 0.0, 0, field)
{
}

void PowerUp::handleCollision(GameActor &other)
{
    
}

GameActorView* PowerUp::getView() const
{
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView *view = new GameActorView("qrc:/qml/powerUp");
    view->setProperty("identifier", "10");
    view->setProperty("x", x.str());
    view->setProperty("y", y.str());

    return view;
}

void PowerUp::applyForce(Vec3f force) {}
void PowerUp::update() {}
void PowerUp::update(vector<GameActor*> actors) {}
