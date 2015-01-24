#include "headers/AimMissile.h"
#include "headers/ActorsAdjustments.h"
#include "headers/Physics.h"

AimMissile::AimMissile() : Missile()
{
    target = -1;
}

AimMissile::AimMissile(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Missile(position, velocity, field, friendly, actors)
{
    target = -1;
}

AimMissile::AimMissile(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Missile(actor.getPosition(), velocity, field, friendly, actors)
{
    target = -1;
}


AimMissile::AimMissile(GameActor &actor, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Missile(actor, field, friendly, actors)
{
    target = -1;
}

AimMissile::AimMissile(const Missile &projectile) :
    Missile(projectile)
{
    target = -1;
}

AimMissile::~AimMissile()
{
    target = -1;
}

void AimMissile::handleCollision(GameActor &other)
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

void AimMissile::update() {
    if(target == -1 || target >= actors->size()) {
        setRandomTarget();
    }
    Vec3f d = position - actors->at(target)->getPosition();
    applyForce(d.normalize());

    Projectile::update();
}

void AimMissile::setRandomTarget() {
    bool otherIsFriendly = false;
    do {
        target = rand() % actors->size();
        vector<GameActor*>::iterator it;
        for (it = friendly.begin(); it != friendly.end(); it++)
        {
            if (*it == actors->at(target)) {
                otherIsFriendly = true;
            }
        }
    } while (otherIsFriendly || target == -1);
}


