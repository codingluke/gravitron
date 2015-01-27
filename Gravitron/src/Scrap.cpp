#include "headers/Scrap.h"
#include <iostream>
#include <sstream>

//GameActor::GameActor(Vec3f position, double mass, float gravitationRange, float g, int health, GameField &field, float maxSpeed)
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

}

GameActorView* Scrap::getView() const {
    std::ostringstream identifiy;
    identifiy << identifier;
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView *view = new GameActorView("qrc:/qml/scrap");
    view->setProperty("identifier", identifiy.str());
    view->setProperty("x", x.str());
    view->setProperty("y", y.str());
    view->setProperty("scrapImg", img);
    std::ostringstream rot;
    rot << calculateRotation();
    view->setProperty("angle", rot.str());
    return view;
}
