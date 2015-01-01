#ifndef SUN_H
#define SUN_H
#include "GameActor.h"

class Sun : public GameActor
{
public:
    Sun(Vec3f position, float mass, float gravitationRange, float g, GameField& field);
    void handleCollision(GameActor &other);
    GameActorView* getView() const;
    void applyForce(Vec3f force);
    void update();
};

#endif // SUN_H
