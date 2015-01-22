#include "headers/Laser.h"
#include "headers/ActorsAdjustments.h"
#include <sstream>
#include <iostream>
#include <QDebug>

Laser::Laser() : Projectile()
{
}

Laser::Laser(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Projectile(position, 0, 0, 0, 90, 1, field, friendly, actors)
{
    applyForce(velocity);
    this->maxSpeed = velocity.magnitude();
}

Laser::Laser(Vec3f position, Vec3f velocity, GameField &field, vector<GameActor*> *actors) :
    Projectile(position, 0, 0, 0, 90, 1, field, actors)
{
    applyForce(velocity);
    this->maxSpeed = velocity.magnitude();
}

Laser::Laser(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Projectile(actor.getPosition(), 0, 0, 0, 90, 1, field, friendly, actors)
{
    applyForce(velocity);
    this->maxSpeed = velocity.magnitude();
}

Laser::Laser(GameActor &actor, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Projectile(actor.getPosition(), 0, 0, 0, 90, 1, field, friendly, actors)
{
    applyForce(actor.getVelocity());
    this->maxSpeed = actor.getVelocity().magnitude();
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
    vector<GameActor*>::iterator it;
    bool otherIsFriendly = false;
    for (it = friendly.begin(); it != friendly.end(); it++)
    {
        if (*it == &other)
            otherIsFriendly = true;
    }
    if (!otherIsFriendly)
    {
        other.dealDamage(LASER_DAMAGE);
        kill();
    }
}

GameActorView* Laser::getView() const {
    //std::cout << "spacecraft" << std::endl;
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView *view = new GameActorView("qrc:/qml/laser");
    view->setProperty("identifier", "L");
    view->setProperty("x", x.str());
    view->setProperty("y", y.str());
    std::ostringstream rot;
    rot << calculateRotation();
    view->setProperty("angle", rot.str());
    return view;
}
