#include "headers/Scrap.h"
#include "headers/ActorsAdjustments.h"
#include <iostream>
#include <sstream>

Scrap::Scrap(Vec3f position, float mass, float gravitationRange, float g, GameField &field, vector<GameActor*> *actors) :
    GameActor(position, mass, gravitationRange, g, 20, field, 0.3, actors)
{
    Vec3f startAcceleration(rand() % 5, rand() % 5, 0);
    acceleration = startAcceleration;

    int imgNumber = rand() % 3;
    img = "scrap3";
    if(imgNumber == 1) {
        img = "scrap1";
    } else if (imgNumber == 2) {
        img = "scrap2";
    }
}

void Scrap::handleCollision(GameActor &other)
{
    other.dealDamage(ActConf::SCRAP_DAMAGE);
}

GameActorView* Scrap::getView() const {
    GameActorView *view = new GameActorView("qrc:/qml/scrap");
    view->setProperty("scrapImg", img);
    view->setProperty("identifier", identifier);
    view->setProperty("x", position[0]);
    view->setProperty("y", position[1]);
    view->setProperty("angle", calculateRotation());
    return view;
}
