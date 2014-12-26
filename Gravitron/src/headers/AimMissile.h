#ifndef AIMMISSILE_H
#define AIMMISSILE_H
#include "Missile.h"

class AimMissile : public Missile
{
public:
    AimMissile();
    void handleCollision(GameActor &other);
};

#endif // AIMMISSILE_H
