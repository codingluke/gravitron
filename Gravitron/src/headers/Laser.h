#ifndef LASER_H
#define LASER_H
#include "Projectile.h"
#include "GameActorView.h"


class Laser : public Projectile
{

public:
    Laser();
    Laser(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors);
    Laser(Vec3f position, Vec3f velocity, GameField &field, vector<GameActor*> *actors);
    Laser(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors);
    Laser(GameActor &actor, GameField &field, GameActor &friendly, vector<GameActor*> *actors);
    Laser(const Laser &laser);
    ~Laser();
    int getTimeToLive() const;
    void handleCollision(GameActor &other) override;

    GameActorView* getView() const override;
};

#endif // LASER_H
