#ifndef MISSILE_H
#define MISSILE_H
#include "Projectile.h"

class Missile : public Projectile
{
public:
    Missile();
    void handleCollision(GameActor &other);
};

#endif // MISSILE_H
