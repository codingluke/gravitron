#include "headers/Scrap.h"
#include <iostream>
#include <sstream>

//GameActor::GameActor(Vec3f position, double mass, float gravitationRange, float g, int health, GameField &field, float maxSpeed)
Scrap::Scrap(Vec3f position, GameField& field) : GameActor(position, 0.2, 0, 0, 0.5, field, 0.3)
{
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
    //std::cout << "spacecraft" << std::endl;
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView *view = new GameActorView("qrc:/qml/scrap");
    view->setProperty("identifier", "S");
    view->setProperty("x", x.str());
    view->setProperty("y", y.str());
    view->setProperty("scrapImg", img);
    return view;
}
