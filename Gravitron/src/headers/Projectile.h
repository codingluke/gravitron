#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "GameActor.h"
#include <vector>

class Projectile : public GameActor
{
private:
    int timeToLive;
    vector<GameActor*> friendly;

public:
    Projectile();
    Projectile(Vec3f position, double mass, float gravitationRange, float g, int timeTo, GameField &field, GameActor &friendly);
    Projectile(const Projectile &projectile);
    virtual ~Projectile();
    int getTimeToLive() const; 

    void update() override;
};

#endif // PROJECTILE_H