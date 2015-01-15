#include "headers/Sun.h"
#include <iostream>
#include <sstream>

//GameActor(Vec3f position, double mass, float gravitationRange, float g, int health, GameField &field);
Sun::Sun(Vec3f position, float mass, float gravitationRange, float g, GameField& field, vector<GameActor*> *actors) 
    : GameActor(position, mass, gravitationRange, g, -1, field, actors)
{
}

void Sun::handleCollision(GameActor &other)
{
    
}

GameActorView* Sun::getView() const {
    //std::cout << "spacecraft" << std::endl;
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView *view = new GameActorView("qrc:/qml/sun");
    view->setProperty("identifier", "S");
    view->setProperty("x", x.str());
    view->setProperty("y", y.str());
    return view;
}

void Sun::applyForce(Vec3f force) {}
void Sun::update() {}
