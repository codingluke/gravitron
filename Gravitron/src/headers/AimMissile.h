#ifndef AIMMISSILE_H
#define AIMMISSILE_H
#include "Missile.h"

class AimMissile : public Missile
{
public:
    AimMissile();
    AimMissile(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly);
    AimMissile(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly);
    AimMissile(GameActor &actor, GameField &field, GameActor &friendly);
    AimMissile(const Missile &projectile);
    ~AimMissile();
    void handleCollision(GameActor &other);
};

#endif // AIMMISSILE_H
