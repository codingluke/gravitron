#include "headers/physics_tests.h"
#include "headers/Physics.h"
#include "headers/Vec3f.h"

void Physics_tests::initTestCase() {
    Vec3f pos(1.0f, 1.0f, 1.0f);
    gf = new GameField(1,1);
    actor1 = GameActor(pos, 1.0, 1.0f, 1.0f, 1, *gf, 1.0f, NULL);
    pos = Vec3f(2.0f, 2.0f, 2.0f);
    actor2 = GameActor(pos, 1.0, 1.0f, 1.0f, 1, *gf, 1.0f, NULL);

}
void Physics_tests::Physics_tests_calculateGravitationForce_gravitation() {
    Vec3f force = Physics::calculateGravitationForce(&actor1, &actor2);
    QVERIFY(force[0] == 0.0f && force[2] == 0.0f && force[2] == 0.0f);
}

void Physics_tests::Physics_tests_calculateGravitationForce_noGravitation() {
    Vec3f pos(1.0f, 1.0f, 1.0f);
    actor1 = GameActor(pos, 1.0, 500.0f, 3.0f, 1, *gf, 1.0f, NULL);
    Vec3f force = Physics::calculateGravitationForce(&actor1, &actor2);
    QVERIFY(force[0] == -1.0f && force[2] == -1.0f && force[2] == -1.0f);
}

void Physics_tests::Physics_tests_collisionDetection_colliton() {
    QVERIFY(Physics::collisionDetection(actor1.getPosition(),20.0f,actor2.getPosition(),20.0f));
}

void Physics_tests::Physics_tests_collisionDetection_noCollition() {
    QVERIFY(!Physics::collisionDetection(actor1.getPosition(),0.0f,actor2.getPosition(),0.0f));
}

void Physics_tests::cleanupTestCase() {
    delete gf;
}
