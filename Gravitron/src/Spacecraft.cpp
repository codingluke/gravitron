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
    GameActor(position, mass, gravitationRange, g, SPACECRAFT_MAX_HEALTH, field, actors)
{
    init();
}

Spacecraft::Spacecraft(Vec3f position, double mass, float gravitationRange, float g, GameField &field, float maxSpeed, vector<GameActor*> *actors) :
    GameActor(position, mass, gravitationRange, g, SPACECRAFT_MAX_HEALTH, field, maxSpeed, actors)
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
    GameActorView *view = new GameActorView("qrc:/qml/spacecraft");
    view->setProperty("identifier", identifier);
    view->setProperty("x", position[0]);
    view->setProperty("y", position[1]);
    view->setProperty("visible", !killed);
    view->setProperty("angle", calculateRotation());
    view->setProperty("controllingPlayerID", controllingPlayerID);
    return view;
}


int Spacecraft::getWeapon() const
{
    return weapon;
}

int Spacecraft::getKillPoints() const
{
    return killPoints;
}

void Spacecraft::incKillPoints()
{
    killPoints++;
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
    Projectile* p = NULL;
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
    position = Vec3f(rand() % field->getWidth(), rand() % field->getHeight(), 0);
    health = SPACECRAFT_MAX_HEALTH;
    killed = false;
}

Projectile &Spacecraft::shootDown()
{
    Projectile* p = NULL;
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
    Projectile* p = NULL;
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
    Projectile* p = NULL;
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
}

void Spacecraft::handleKill()
{
    velocity = Vec3f();
    acceleration = Vec3f();
    weapon = 1;
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


