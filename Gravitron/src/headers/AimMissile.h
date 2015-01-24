#ifndef AIMMISSILE_H
#define AIMMISSILE_H
#include "Missile.h"

class AimMissile : public Missile
{
public:
    AimMissile();
    AimMissile(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors);
    AimMissile(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors);
    AimMissile(GameActor &actor, GameField &field, GameActor &friendly, vector<GameActor*> *actors);
    AimMissile(const Missile &projectile);
    ~AimMissile();
    void update();
    void handleCollision(GameActor &other);

private:
    int target;
    void setRandomTarget();
};

#endif // AIMMISSILE_H
