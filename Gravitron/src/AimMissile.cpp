#include "headers/AimMissile.h"
#include "headers/ActorsAdjustments.h"

AimMissile::AimMissile() : Missile()
{
}

AimMissile::AimMissile(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Missile(position, velocity, field, friendly, actors)
{
}

AimMissile::AimMissile(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Missile(actor.getPosition(), velocity, field, friendly, actors)
{
}


AimMissile::AimMissile(GameActor &actor, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Missile(actor, field, friendly, actors)
{
}

AimMissile::AimMissile(const Missile &projectile) :
    Missile(projectile)
{

}

AimMissile::~AimMissile()
{

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
        other.dealDamage(AIM_MISSILE_DAMAGE);
        kill();
    }
}


