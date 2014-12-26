#ifndef PLANET_H
#define PLANET_H
#include "GameActor.h"

class Planet : public GameActor
{
public:
    Planet();
    void handleCollision(GameActor &other);
};

#endif // PLANET_H
