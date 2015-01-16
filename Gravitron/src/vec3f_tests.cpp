#include "headers/vec3f_tests.h"
#include <math.h>

void Vec3F_Tests::init() {
    vector = Vec3f(2.0f, 2.0f, 2.0f);
}

void Vec3F_Tests::Vec3F_Tests_testPlusOperator() {
    vector = vector + vector;
    QVERIFY(vector.v[0] == 4.0f && vector.v[1] == 4.0f && vector.v[2] == 4.0f);
}

void Vec3F_Tests::Vec3F_Tests_testMinusOperator() {
    vector = vector - vector;
    QVERIFY(vector.v[0] == 0.0f && vector.v[1] == 0.0f && vector.v[2] == 0.0f);
}

void Vec3F_Tests::Vec3F_Tests_testSlashOperator() {
    vector = vector / 4;
    QVERIFY(vector.v[0] == 0.5f && vector.v[1] == 0.5f && vector.v[2] == 0.5f);
}
void Vec3F_Tests::Vec3F_Tests_testStarOperator(){;
    vector = vector * 2;
    QVERIFY(vector.v[0] == 4.0f && vector.v[1] == 4.0f && vector.v[2] == 4.0f);
}

void Vec3F_Tests::Vec3F_Tests_testPlusEqualsOperator() {
    vector += vector;
    QVERIFY(vector.v[0] == 4.0f && vector.v[1] == 4.0f && vector.v[2] == 4.0f);
}
void Vec3F_Tests::Vec3F_Tests_testMinusEqualsOperator() {
    vector -= vector;
    QVERIFY(vector.v[0] == 0.0f && vector.v[1] == 0.0f && vector.v[2] == 0.0f);
}
void Vec3F_Tests::Vec3F_Tests_testSlashEqualsOperator(){
    vector /= 4;
    QVERIFY(vector.v[0] == 0.5f && vector.v[1] == 0.5f && vector.v[2] == 0.5f);
}
void Vec3F_Tests::Vec3F_Tests_testStarEqualsOperator(){
    vector *= 2;
    QVERIFY(vector.v[0] == 4.0f && vector.v[1] == 4.0f && vector.v[2] == 4.0f);
}

void Vec3F_Tests::Vec3F_Test_EqualsOperator() {
    Vec3f help = vector;
    QVERIFY(help == vector);
}
void Vec3F_Tests::Vec3F_Test_BoolEqualsOperator() {
    Vec3f help(2.0f, 2.0f, 2.0f);
    QVERIFY(help == vector);
}
void Vec3F_Tests::Vec3F_Test_BoolNotEqualsOperator() {
    Vec3f help(1.0f, 1.0f, 1.0f);
    QVERIFY(help != vector);
}

void Vec3F_Tests::Vec3F_Test_ArrayOperator() {
    float help = vector[1];
    QVERIFY(help == 2.0f);
}
void Vec3F_Tests::Vec3F_Test_ArrayOperator_Ref() {
    float &help = vector[1];
    QVERIFY(help == 2.0f);
}

void Vec3F_Tests::Vec3F_Test_Magnitude() {
    QVERIFY(round(vector.magnitude()) == round(3.464101615f));
}
void Vec3F_Tests::Vec3F_Test_MagnitudeSquared() {
    QVERIFY(vector.magnitudeSquared() == 12.0f);
}
void Vec3F_Tests::Vec3F_Test_Normaize() {
    vector = vector.normalize();
    QVERIFY(vector.v[0] == 2.0f/3.464101615f && vector.v[1] == 2.0f/3.464101615f && vector.v[2] == 2.0f/3.464101615f);
}
void Vec3F_Tests::Vec3F_Test_Dot() {
    Vec3f help(2.0f,2.0f,2.0f);
    float result = vector.dot(help);
    QVERIFY(result == 12.0f);
}
void Vec3F_Tests::Vec3F_Test_Cross() {
    Vec3f help(2.0f,2.0f,2.0f);
    vector = vector.cross(help);
    QVERIFY(vector.v[0] == 0.0f && vector.v[1] == 0.0f && vector.v[2] == 0.0f);
}
