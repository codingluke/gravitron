#include "headers/Physics.h"

Physics::Physics()
{
}


Vec3f Physics::calculateGravitationForce(GameActor *from, GameActor *to) {
    Vec3f force = from->getPosition() - to->getPosition();
    float distance = force.magnitude();
    if (distance <= from->getGravitationRange() && distance != 0) { //can have same position
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
    float d = distance(vec1, vec2);
    return d <= (rad1 + rad2);
}

float Physics::distance(Vec3f vec1, Vec3f vec2) {
    Vec3f distance = vec1 - vec2;
    return distance.magnitude();
}
