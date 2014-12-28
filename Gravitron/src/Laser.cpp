#include "headers/Laser.h"
#include <sstream>
#include <iostream>
#include <QDebug>

Laser::Laser() : Projectile()
{
}

Laser::Laser(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly) :
    Projectile(position, 0, 0, 0, 90, 1, field, friendly)
{
    applyForce(velocity);
}

Laser::Laser(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly) :
    Projectile(actor.getPosition(), 0, 0, 0, 90, 1, field, friendly)
{
    applyForce(velocity);
}

Laser::Laser(GameActor &actor, GameField &field, GameActor &friendly) :
    Projectile(actor.getPosition(), 0, 0, 0, 90, 1, field, friendly)
{
    applyForce(actor.getVelocity());
}

Laser::Laser(const Laser &projectile) :
    Projectile(projectile)
{

}

Laser::~Laser()
{

}

void Laser::handleCollision(GameActor &other)
{
    qDebug() << "Collision";

    vector<GameActor*>::iterator it;
    bool otherIsFriendly = false;
    for (it = friendly.begin(); it != friendly.end(); it++)
    {
        if (*it == &other)
            otherIsFriendly = true;
    }
    if (!otherIsFriendly)
    {
        other.dealDamage(20);
        kill();
    }
}

GameActorView* Laser::getView() const {
    //std::cout << "spacecraft" << std::endl;
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView *view = new GameActorView("qrc:/qml/actor");
    view->setProperty("identifier", "L");
    view->setProperty("x", x.str());
    view->setProperty("y", y.str());
    view->setProperty("color", "blue");
    return view;
}
