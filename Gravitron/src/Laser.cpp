#include "headers/Laser.h"

Laser::Laser() : Projectile()
{
}

Laser::Laser(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly) : 
    Projectile(position, 0, 0, 0, 180, field, friendly) 
{
    applyForce(velocity);
}

Laser::Laser(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly) :
    Projectile(actor.getPosition(), 0, 0, 0, 180, field, friendly) 
{
    applyForce(velocity);
}

Laser::Laser(GameActor &actor, GameField &field, GameActor &friendly) :
    Projectile(actor.getPosition(), 0, 0, 0, 180, field, friendly)
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
