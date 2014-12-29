#ifndef POWERUP_H
#define POWERUP_H
#include "GameActor.h"

class PowerUp : public GameActor
{
public:
    PowerUp();
    void handleCollision(GameActor &other);
};

#endif // POWERUP_H
