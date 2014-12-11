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
        static bool collisionDetection(Vec3f vec1, float rad1,
                                       Vec3f vec2, float rad2);
};

#endif // PHYSICS_H
