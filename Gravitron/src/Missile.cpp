#include "headers/Missile.h"
#include "headers/ActorsAdjustments.h"
#include <sstream>
#include <iostream>
#include <QDebug>

Missile::Missile() : Projectile()
{
}

Missile::Missile(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Projectile(position, 0, 0, 0, 90, 1, field, friendly, actors)
{
    applyForce(velocity);
    this->maxSpeed = velocity.magnitude() + 30;
}

Missile::Missile(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Projectile(actor.getPosition(), 0, 0, 0, 90, 1, field, friendly, actors)
{
    applyForce(velocity);
    this->maxSpeed = velocity.magnitude() + 30;
}


Missile::Missile(GameActor &actor, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Projectile(actor.getPosition(), 0, 0, 0, 90, 1, field, friendly, actors)
{
    applyForce(actor.getVelocity());
    this->maxSpeed = actor.getVelocity().magnitude() + 30;
}

Missile::Missile(const Missile &projectile) :
    Projectile(projectile)
{

}

Missile::~Missile()
{

}

void Missile::handleCollision(GameActor &other)
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
        other.dealDamage(MISSILE_DAMAGE);
        kill();
    }
}

GameActorView* Missile::getView() const {
    std::ostringstream identifiy;
    identifiy << identifier;
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView *view = new GameActorView("qrc:/qml/missile");
    view->setProperty("identifier", identifiy.str());
    view->setProperty("x", x.str());
    view->setProperty("y", y.str());
    if (killed) {
        view->setProperty("color", "red");
    } else {
        view->setProperty("color", "blue");
    }
    std::ostringstream rot;
    rot << calculateRotation();
    view->setProperty("angle", rot.str());
    return view;
}
