#ifndef LASER_H
#define LASER_H
#include "Projectile.h"

class Laser : public Projectile
{

public:
    Laser();
    Laser(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly); 
    Laser(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly);
    Laser(GameActor &actor, GameField &field, GameActor &friendly);
    Laser(const Laser &projectile);
    virtual ~Laser();
    int getTimeToLive() const;
    void handleCollision(GameActor &other);
};

#endif // LASER_H
