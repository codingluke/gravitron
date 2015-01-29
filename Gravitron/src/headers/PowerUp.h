#ifndef POWERUP_H
#define POWERUP_H
#include "GameActor.h"

class PowerUp : public GameActor
{
public:
    PowerUp(Vec3f position, GameField &field, vector<GameActor*> *actors);
    void handleCollision(GameActor &other);
    GameActorView* getView() const;
};

#endif // POWERUP_H
