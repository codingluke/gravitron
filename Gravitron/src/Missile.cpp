#include "headers/Missile.h"
#include "headers/ActorsAdjustments.h"
#include "headers/Spacecraft.h"
#include <sstream>
#include <iostream>
#include <QDebug>

Missile::Missile() : Projectile()
{
}

Missile::Missile(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
Projectile(position, 0, 0, 0, 300, 1, field, friendly, actors)
{
    applyForce(velocity);
    this->maxSpeed = ActConf::MISSILE_MAX_MAXSPEED;
}

Missile::Missile(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
Projectile(actor.getPosition(), 0, 0, 0, 300, 1, field, friendly, actors)
{
    applyForce(velocity);
    this->maxSpeed = ActConf::MISSILE_MAX_MAXSPEED;
}


Missile::Missile(GameActor &actor, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
Projectile(actor.getPosition(), 0, 0, 0, 300, 1, field, friendly, actors)
{
    applyForce(actor.getVelocity());
    this->maxSpeed = ActConf::MISSILE_MAX_MAXSPEED;
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
    for (it = friendly.begin(); it != friendly.end(); it++) {
        if (*it == &other)
            otherIsFriendly = true;
    }
    if (!otherIsFriendly) {
        other.dealDamage(ActConf::MISSILE_DAMAGE);
        if (other.isKilled() && dynamic_cast<Spacecraft*>(&other)) {
            incKillPointsOfFriends();
        }
        kill();
    }
}

GameActorView* Missile::getView() const {
    GameActorView *view = new GameActorView("qrc:/qml/missile");
    view->setProperty("identifier", identifier);
    view->setProperty("x", position[0]);
    view->setProperty("y", position[1]);
    view->setProperty("angle", calculateRotation());
    if (killed) {
        view->setProperty("color", "red");
    } else {
        view->setProperty("color", "blue");
    }
    return view;
}
