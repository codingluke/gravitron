#ifndef SUN_H
#define SUN_H
#include "GameActor.h"

class Sun : public GameActor
{
public:
    Sun();
    void handleCollision(GameActor &other);
};

#endif // SUN_H
