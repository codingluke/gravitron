#ifndef POWERUP_H
#define POWERUP_H
#include "GameActor.h"

class PowerUp : public GameActor
{
public:
    PowerUp(Vec3f position, GameField &field, vector<GameActor*> *actors);
    void handleCollision(GameActor &other);
    GameActorView* getView() const;
    virtual void applyForce(Vec3f force);
    virtual void update();
    virtual void update(vector<GameActor*> actors);
};

#endif // POWERUP_H
