#ifndef PHYSICS_TESTS_H
#define PHYSICS_TESTS_H

#include <QObject>
#include <QtTest/QTest>
#include "GameActor.h"

class Physics_tests : public QObject
{
    Q_OBJECT
private:
    GameActor actor1;
    GameActor actor2;
    GameField *gf;

private slots:
    void initTestCase();
    void Physics_tests_calculateGravitationForce_gravitation();
    void Physics_tests_calculateGravitationForce_noGravitation();
    void Physics_tests_collisionDetection_colliton();
    void Physics_tests_collisionDetection_noCollition();
    void cleanupTestCase();
};

#endif // PHYSICS_TESTS_H
