#ifndef SCRAP_H
#define SCRAP_H
#include "GameActor.h"

class Scrap : public GameActor
{
public:
    Scrap();
    void handleCollision(GameActor &other);
};

#endif // SCRAP_H
