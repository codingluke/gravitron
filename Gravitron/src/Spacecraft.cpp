#include "headers/Spacecraft.h"
#include "headers/Laser.h"
#include "headers/AimMissile.h"
#include "headers/Missile.h"
#include <sstream>
#include <iostream>

Spacecraft::Spacecraft() : GameActor()
{
    g = 0;
    weapon = 1;
}

Spacecraft::Spacecraft(Vec3f position, double mass, float gravitationRange, float g, GameField &field) :
    GameActor(position, mass, gravitationRange, g, 100, field)
{
    g = 0;
    weapon = 1;
}

Spacecraft::Spacecraft(Vec3f position, double mass, float gravitationRange, float g, GameField &field, float maxSpeed) :
    GameActor(position, mass, gravitationRange, g, 100, field, maxSpeed)
{
    g = 0;
    weapon = 1;
}

Spacecraft::Spacecraft(const Spacecraft &spacecraft) : GameActor(spacecraft)
{
    g = 0;
    weapon = 1;
}

Spacecraft::~Spacecraft() {

}

GameActorView* Spacecraft::getView() const {
    //std::cout << "spacecraft" << std::endl;
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView *view = new GameActorView("qrc:/qml/spacecraft");
    view->setProperty("identifier", "S");
    view->setProperty("x", x.str());
    view->setProperty("y", y.str());
    return view;
}

void Spacecraft::forceAhead()
{
    applyForce(Vec3f(0.,-0.01,0.));
}

void Spacecraft::forceBack()
{
    applyForce(Vec3f(0.,0.01,0.));
}

void Spacecraft::forceLeft()
{
    applyForce(Vec3f(-0.01,0.,0.));
}

void Spacecraft::forceRight()
{
    applyForce(Vec3f(0.01,0.,0.));
}

Projectile &Spacecraft::shootUp()
{
    Projectile* p;
    if (weapon == 1) {
        p = new Laser(this->getPosition() + Vec3f(0,-2.,0.), Vec3f(0., -50., 0.), *field, *this);
    } else if (weapon == 2) {
        p = new Missile(this->getPosition() + Vec3f(0,-2.,0.), Vec3f(0., -12., 0.), *field, *this);
    } else if (weapon == 3) {
        p = new AimMissile(this->getPosition() + Vec3f(0,-2.,0.), Vec3f(0., -12., 0.), *field, *this);
    }
    return *p;
}
void Spacecraft::repair()
{

}
Projectile &Spacecraft::shootDown()
{
    Projectile* p;
    if (weapon == 1) {
        p = new Laser(this->getPosition() + Vec3f(0., 2., 0.), Vec3f(0., 50., 0.), *field, *this);
    } else if (weapon == 2) {
        p = new Missile(this->getPosition() + Vec3f(0., 2., 0.), Vec3f(0., 12., 0.), *field, *this);
    } else if (weapon == 3) {
        p = new AimMissile(this->getPosition() + Vec3f(0., 2., 0.), Vec3f(0., 12., 0.), *field, *this);
    }
    return *p;
}

Projectile &Spacecraft::shootLeft()
{
    Projectile* p;
    if (weapon == 1) {
        p = new Laser(this->getPosition() + Vec3f(-2., 0., 0.), Vec3f(-50., 0., 0.), *field, *this);
    } else if (weapon == 2) {
        p = new Missile(this->getPosition() + Vec3f(-2., 0., 0.), Vec3f(-12., 0., 0.), *field, *this);
    } else if (weapon == 3) {
        p = new AimMissile(this->getPosition() + Vec3f(-2., 0., 0.), Vec3f(-12., 0., 0.), *field, *this);
    }
    return *p;
}

Projectile &Spacecraft::shootRight()
{
    Projectile* p;
    if (weapon == 1) {
        p = new Laser(this->getPosition() + Vec3f(2., 0., 0.), Vec3f(50., 0., 0.), *field, *this);
    } else if (weapon == 2) {
        p = new Missile(this->getPosition() + Vec3f(2., 0., 0.), Vec3f(12., 0., 0.), *field, *this);
    } else if (weapon == 3) {
        p = new AimMissile(this->getPosition() + Vec3f(2., 0., 0.), Vec3f(12., 0., 0.), *field, *this);
    }
    return *p;
}

void Spacecraft::handleCollision(GameActor &other)
{
    //other.dealDamage(10);
    //dealDamage(5);
}

void Spacecraft::setWeapon(int weaponNumber) {
    this->weapon = weaponNumber;
}


