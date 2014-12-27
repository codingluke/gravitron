#include "headers/Spacecraft.h"
#include "headers/Laser.h"
#include <sstream>
#include <iostream>

Spacecraft::Spacecraft() : GameActor()
{
    g = 0;
}

Spacecraft::Spacecraft(Vec3f position, double mass, float gravitationRange, float g, int health, GameField &field) :
    GameActor(position, mass, gravitationRange, g, health, field)
{
    g = 0;
}

Spacecraft::Spacecraft(Vec3f position, double mass, float gravitationRange, float g, int health, GameField &field, float maxSpeed) :
    GameActor(position, mass, gravitationRange, g, health, field, maxSpeed)
{
    g = 0;
}

Spacecraft::Spacecraft(const Spacecraft &spacecraft) : GameActor(spacecraft)
{
    g = 0;
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
    view->setProperty("color", "green");
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
    Projectile *shot = new Laser(this->getPosition() + Vec3f(0,-2.,0.), Vec3f(0., -1., 0.), *field, *this);
    return *shot;
}

Projectile &Spacecraft::shootDown()
{
    Projectile *shot = new Laser(this->getPosition() + Vec3f(0., 2., 0.), Vec3f(0., 1., 0.), *field, *this);
    return *shot;
}

Projectile &Spacecraft::shootLeft()
{
    Projectile *shot = new Laser(this->getPosition() + Vec3f(-2., 0., 0.), Vec3f(-1., 0., 0.), *field, *this);
    return *shot;
}

Projectile &Spacecraft::shootRight()
{
    Projectile *shot = new Laser(this->getPosition() + Vec3f(2., 0., 0.), Vec3f(1., 0., 0.), *field, *this);
    return *shot;
}

void Spacecraft::handleCollision(GameActor &other)
{
    //other.dealDamage(10);
    //dealDamage(5);
}

