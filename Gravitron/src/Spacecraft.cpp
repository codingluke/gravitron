#include "headers/Spacecraft.h"
#include "headers/Laser.h"
#include "headers/AimMissile.h"
#include "headers/Missile.h"
#include "headers/PowerUp.h"
#include "headers/ActorsAdjustments.h"
#include <sstream>
#include <iostream>

Spacecraft::Spacecraft() : GameActor()
{
    init();
}

Spacecraft::Spacecraft(Vec3f position, double mass, float gravitationRange, float g, GameField &field, vector<GameActor*> *actors) :
    GameActor(position, mass, gravitationRange, g, 100, field, actors)
{
    init();
}

Spacecraft::Spacecraft(Vec3f position, double mass, float gravitationRange, float g, GameField &field, float maxSpeed, vector<GameActor*> *actors) :
    GameActor(position, mass, gravitationRange, g, 100, field, maxSpeed, actors)
{
    init();
}

Spacecraft::Spacecraft(const Spacecraft &spacecraft) : GameActor(spacecraft)
{
    init();
}

void Spacecraft::init() {
    g = 0;
    weapon = 1;
    accelerationFactor = 0.5;
}

Spacecraft::~Spacecraft() {

}

GameActorView* Spacecraft::getView() const {
    std::ostringstream identifiy;
    identifiy << identifier;
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView *view = new GameActorView("qrc:/qml/spacecraft");
    view->setProperty("identifier", identifiy.str());
    view->setProperty("x", x.str());
    view->setProperty("y", y.str());
    std::ostringstream rot;
    rot << calculateRotation();
    view->setProperty("angle", rot.str());
    std::ostringstream playerID;
    playerID << controllingPlayerID;
    view->setProperty("controllingPlayerID", playerID.str());
    return view;
}

void Spacecraft::forceAhead()
{
    applyForce(Vec3f(0.,-1 * accelerationFactor ,0.));
}

void Spacecraft::forceBack()
{
    applyForce(Vec3f(0.,accelerationFactor,0.));
}

void Spacecraft::forceLeft()
{
    applyForce(Vec3f(-1 * accelerationFactor,0.,0.));
}

void Spacecraft::forceRight()
{
    applyForce(Vec3f(accelerationFactor,0.,0.));
}

Projectile &Spacecraft::shootUp()
{
    Projectile* p;
    if (weapon == 1) {
        p = new Laser(this->getPosition() + Vec3f(0,-2.,0.), Vec3f(0., -50., 0.), *field, *this, actors);
    } else if (weapon == 2) {
        p = new Missile(this->getPosition() + Vec3f(0,-2.,0.), Vec3f(0., -12., 0.), *field, *this, actors);
    } else if (weapon == 3) {
        p = new AimMissile(this->getPosition() + Vec3f(0,-2.,0.), Vec3f(0., -12., 0.), *field, *this, actors);
    }
    actors->push_back(p);
    return *p;
}

void Spacecraft::repair()
{

}

Projectile &Spacecraft::shootDown()
{
    Projectile* p;
    if (weapon == 1) {
        p = new Laser(this->getPosition() + Vec3f(0., 2., 0.), Vec3f(0., 50., 0.), *field, *this, actors);
    } else if (weapon == 2) {
        p = new Missile(this->getPosition() + Vec3f(0., 2., 0.), Vec3f(0., 12., 0.), *field, *this, actors);
    } else if (weapon == 3) {
        p = new AimMissile(this->getPosition() + Vec3f(0., 2., 0.), Vec3f(0., 12., 0.), *field, *this, actors);
    }
    actors->push_back(p);
    return *p;
}

Projectile &Spacecraft::shootLeft()
{
    Projectile* p;
    if (weapon == 1) {
        p = new Laser(this->getPosition() + Vec3f(-2., 0., 0.), Vec3f(-50., 0., 0.), *field, *this, actors);
    } else if (weapon == 2) {
        p = new Missile(this->getPosition() + Vec3f(-2., 0., 0.), Vec3f(-12., 0., 0.), *field, *this, actors);
    } else if (weapon == 3) {
        p = new AimMissile(this->getPosition() + Vec3f(-2., 0., 0.), Vec3f(-12., 0., 0.), *field, *this, actors);
    }
    actors->push_back(p);
    return *p;
}

Projectile &Spacecraft::shootRight()
{
    Projectile* p;
    if (weapon == 1) {
        p = new Laser(this->getPosition() + Vec3f(2., 0., 0.), Vec3f(50., 0., 0.), *field, *this, actors);
    } else if (weapon == 2) {
        p = new Missile(this->getPosition() + Vec3f(2., 0., 0.), Vec3f(12., 0., 0.), *field, *this, actors);
    } else if (weapon == 3) {
        p = new AimMissile(this->getPosition() + Vec3f(2., 0., 0.), Vec3f(12., 0., 0.), *field, *this, actors);
    }
    actors->push_back(p);
    return *p;
}

void Spacecraft::handleCollision(GameActor &other)
{
    //other.dealDamage(10);
    //dealDamage(5);
}

void Spacecraft::upgradeWeapon() {
    if (weapon < 3) {
        this->weapon++;
    }
}

void Spacecraft::setControllingPlayer(int controllingPlayerID)
{
    this->controllingPlayerID = controllingPlayerID;
}

int Spacecraft::getControllingPlayer() const
{
    return this->controllingPlayerID;
}


