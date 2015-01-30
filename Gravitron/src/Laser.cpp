#include "headers/Laser.h"
#include "headers/ActorsAdjustments.h"
#include "headers/Spacecraft.h"
#include <sstream>
#include <iostream>
#include <QDebug>

Laser::Laser() : Projectile()
{
}

Laser::Laser(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
Projectile(position, ActConf::LASER_MASS, ActConf::LASER_GRAVITATION_RANGE, ActConf::LASER_G, ActConf::LASER_TIME_TO_LIVE, ActConf::LASER_HEALTH, field, friendly, actors)
{
    applyForce(velocity);
    this->maxSpeed = ActConf::LASER_MAXSPEED;
}

Laser::Laser(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
Projectile(actor.getPosition(), ActConf::LASER_MASS, ActConf::LASER_GRAVITATION_RANGE, ActConf::LASER_G, ActConf::LASER_TIME_TO_LIVE, ActConf::LASER_HEALTH, field, friendly, actors)
{
    applyForce(velocity);
    this->maxSpeed = ActConf::LASER_MAXSPEED;
}

Laser::Laser(GameActor &actor, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
Projectile(actor.getPosition(), ActConf::LASER_MASS, ActConf::LASER_GRAVITATION_RANGE, ActConf::LASER_G, ActConf::LASER_TIME_TO_LIVE, ActConf::LASER_HEALTH, field, friendly, actors)
{
    applyForce(actor.getVelocity());
    this->maxSpeed = ActConf::LASER_MAXSPEED;
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
        other.dealDamage(ActConf::LASER_DAMAGE);
        if (other.isKilled() && dynamic_cast<Spacecraft*>(&other)) {
            incKillPointsOfFriends();
        }
        kill();
    }
}

GameActorView* Laser::getView() const {
    GameActorView *view = new GameActorView("qrc:/qml/laser");
    view->setProperty("identifier", identifier);
    view->setProperty("x", position[0]);
    view->setProperty("y", position[1]);
    view->setProperty("angle", calculateRotation());
    return view;
}
