#ifndef SUN_H
#define SUN_H
#include "GameActor.h"

class Sun : public GameActor
{
public:
    Sun(Vec3f pos, GameField &field);
    void handleCollision(GameActor &other);
    GameActorView* getView() const;
    void applyForce(Vec3f force);
    void update();
};

#endif // SUN_H
