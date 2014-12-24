#include "headers/Physics.h"

Physics::Physics()
{
}


Vec3f Physics::calculateGravitationForce(GameActor *from, GameActor *to) {
    Vec3f force = from->getPosition() - to->getPosition();
    float distance = force.magnitude();
    if (distance <= from->getGravitationRange()) {
        force.normalize();
        float strength = (from->getG() * from->getMass() * to->getMass()) / (distance * distance);
        force = force * strength;
    } else {
        force = Vec3f();
    }
    return force;
}

bool Physics::collisionDetection(Vec3f vec1, float rad1,
                                 Vec3f vec2, float rad2)
{
    Vec3f force = vec1 - vec2;
    float distance = force.magnitude();
    //cerr << distance << "\n";
    return distance <= (rad1 + rad2);
}
