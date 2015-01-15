#ifndef PLANET_H
#define PLANET_H
#include "GameActor.h"

class Planet : public GameActor
{
public:
    Planet();
    Planet(Vec3f pos, float mass, float gravitationRange, float g, GameField &field, vector<GameActor*> *actors);
    void handleCollision(GameActor &other);
    void kill();
    GameActorView* getView() const;
    void update();
};

#endif // PLANET_H
