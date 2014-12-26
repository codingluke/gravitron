#ifndef ASTEROID_H
#define ASTEROID_H
#include "GameActor.h"

class Asteroid : public GameActor
{
public:
    Asteroid();
    void handleCollision(GameActor &other);
};

#endif // ASTEROID_H
