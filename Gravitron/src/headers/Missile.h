#ifndef MISSILE_H
#define MISSILE_H
#include "Projectile.h"

class Missile : public Projectile
{
public:
    Missile();
    Missile(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors);
    Missile(Vec3f position, Vec3f velocity, GameField &field, vector<GameActor*> *actors);
    Missile(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors);
    Missile(GameActor &actor, GameField &field, GameActor &friendly, vector<GameActor*> *actors);
    Missile(const Missile &missile);
    ~Missile();
    int getTimeToLive() const;
    void handleCollision(GameActor &other);
    GameActorView* getView() const override;
};

#endif // MISSILE_H
