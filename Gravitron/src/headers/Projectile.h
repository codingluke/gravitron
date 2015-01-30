#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "GameActor.h"
#include <vector>

/**
 * This (abstract) class represents any kind of projectile, laser beam, bomb or mine
 * that can be produced by a weapon. Since projectiles generally damage  things on
 * impact, any effects that are triggered by such, should be implemented by implementing
 * GameActors virtual methods handleCollision() and handleKill() in any inheriting objects.
 * Also a rocket or a laser might not travel for eternity, so its time to live (in update cycles)
 * may be defined and would be decreased with every call of update(). This also prevents a cluttering 
 * of the game area.
 */
class Projectile : public GameActor
{
private:
    /**
     * The time (update cycles) until this projectile vanishes. Once the 
     * time to live equals 0, the Projectile will be destroyed. Projectiles 
     * with a time to live of -1 are considered "immortal".
     */
    int timeToLive;

protected:
    /**
     * All GameActors which shall not be affected by this projectile.
     */
    vector<GameActor*> friendly;

public:
    Projectile();
    Projectile(Vec3f position, double mass, float gravitationRange,
    float g, int timeToLive, int health, GameField &field,
    GameActor &friendly, vector<GameActor*> *actors);
    Projectile(Vec3f position, double mass, float gravitationRange, float g,
    int timeToLive, int health, GameField &field,
    vector<GameActor*> *actors);
    Projectile(const Projectile &projectile);
    ~Projectile();

    int getTimeToLive() const;
    void incKillPointsOfFriends();
    void update() override;
};

#endif // PROJECTILE_H
