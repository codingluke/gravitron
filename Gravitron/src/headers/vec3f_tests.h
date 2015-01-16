#ifndef VEC3F_TESTS_H
#define VEC3F_TESTS_H

#include <QObject>
#include <QtTest/QTest>
#include "Vec3f.h"

class Vec3F_Tests : public QObject
{
    Q_OBJECT
    private:
       Vec3f vector;


    private slots:
        void init();

        void Vec3F_Tests_testPlusOperator();
        void Vec3F_Tests_testMinusOperator();
        void Vec3F_Tests_testSlashOperator();
        void Vec3F_Tests_testStarOperator();

        void Vec3F_Tests_testPlusEqualsOperator();
        void Vec3F_Tests_testMinusEqualsOperator();
        void Vec3F_Tests_testSlashEqualsOperator();
        void Vec3F_Tests_testStarEqualsOperator();

        void Vec3F_Test_EqualsOperator();
        void Vec3F_Test_BoolEqualsOperator();
        void Vec3F_Test_BoolNotEqualsOperator();

        void Vec3F_Test_ArrayOperator();
        void Vec3F_Test_ArrayOperator_Ref();

        void Vec3F_Test_Magnitude();
        void Vec3F_Test_MagnitudeSquared();
        void Vec3F_Test_Normaize();
        void Vec3F_Test_Dot();
        void Vec3F_Test_Cross();
};

#endif // VEC3F_TESTS_H
