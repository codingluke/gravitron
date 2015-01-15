#ifndef ASTEROID_H
#define ASTEROID_H
#include "GameActor.h"

class Asteroid : public GameActor
{


public:
    Asteroid();
    Asteroid(Vec3f position, double mass, float gravitationRange, float g, GameField &field, float maxSpeed, vector<GameActor*> *actors);
    void handleCollision(GameActor &other);
    GameActorView* getView() const ;
};

#endif // ASTEROID_H
