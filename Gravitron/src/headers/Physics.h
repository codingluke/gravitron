#ifndef PHYSICS_H
#define PHYSICS_H
#include "Vec3f.h"
#include "GameActor.h"

class Physics
{
    public:
        Physics();

    public:
        static Vec3f calculateGravitationForce(GameActor *from, GameActor *to);
};

#endif // PHYSICS_H
