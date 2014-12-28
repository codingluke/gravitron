#ifndef ASTEROID_H
#define ASTEROID_H
#include "GameActor.h"

class Asteroid : public GameActor
{
public:
    Asteroid(Vec3f position, double mass, float gravitationRange, float g, GameField &field, float maxSpeed);
    GameActorView* getView() const ;
};

#endif // ASTEROID_H
