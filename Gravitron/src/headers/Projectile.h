#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "GameActor.h"
#include <vector>

class Projectile : public GameActor
{
private:
    int timeToLive;
protected:
    vector<GameActor*> friendly;

public:
    Projectile();
    Projectile(Vec3f position, double mass, float gravitationRange, float g, int timeToLive, int health, GameField &field, GameActor &friendly);
    Projectile(Vec3f position, double mass, float gravitationRange, float g, int timeToLive, int health, GameField &field);
    Projectile(const Projectile &projectile);
    ~Projectile();
    int getTimeToLive() const;
    void handleCollision(GameActor &other);
    void update() override;

};

#endif // PROJECTILE_H
