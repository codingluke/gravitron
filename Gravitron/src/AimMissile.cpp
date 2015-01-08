#include "headers/AimMissile.h"

AimMissile::AimMissile() : Missile()
{
}

AimMissile::AimMissile(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly) :
    Missile(position, velocity, field, friendly)
{
}

AimMissile::AimMissile(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly) :
    Missile(actor.getPosition(), velocity, field, friendly)
{
}


AimMissile::AimMissile(GameActor &actor, GameField &field, GameActor &friendly) :
    Missile(actor, field, friendly)
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
    
}


