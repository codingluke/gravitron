#ifndef PLANET_H
#define PLANET_H
#include "GameActor.h"

class Planet : public GameActor
{
public:
    Planet(Vec3f pos, GameField &field);
    void kill();
    GameActorView* getView() const;
    void update();
};

#endif // PLANET_H
