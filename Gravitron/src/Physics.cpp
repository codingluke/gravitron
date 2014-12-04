#include "headers/Physics.h"

Physics::Physics()
{
}


Vec3f Physics::calculateGravitationForce(GameActor from, GameActor to) {
    Vec3f force = from.getPosition() - to.getPosition();
    float distance = force.magnitude();
    if (distance <= from.getGravitationRange()) {
        force.normalize();
        float strength = (from.getG() * from.getMass() * to.getMass()) / (distance * distance);
        force = force * strength;
    } else {
        force = Vec3f();
    }
    return force;
}
