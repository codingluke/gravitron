#include "headers/Projectile.h"
#include "headers/Spacecraft.h"
#include <sstream>
#include <iostream>
#include <QDebug>


/**
 * Projectile will be the SuperClass of all kinds of weapon projectiles,
 * space Debris and temporary area effects. To avoid a cluttering of the
 * game area, most projectiles should have a limited timeToLive.
 */
 Projectile::Projectile() : GameActor()
 {
    this->timeToLive = -1;
    g = 0;
}

Projectile::Projectile(Vec3f position, double mass, float gravitationRange, float g, int timeToLive, int health, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
GameActor(position, mass, gravitationRange, g, health, field, actors)
{
    this->timeToLive = timeToLive;
    this->friendly.push_back(&friendly);
}

Projectile::Projectile(Vec3f position, double mass, float gravitationRange, float g, int timeToLive, int health, GameField &field, vector<GameActor*> *actors) :
GameActor(position, mass, gravitationRange, g, health, field, actors)
{
    this->timeToLive = timeToLive;
}

Projectile::Projectile(const Projectile &projectile) : GameActor(projectile)
{
    this->timeToLive = projectile.getTimeToLive();
    g = 0;
}

Projectile::~Projectile()
{
}

int Projectile::getTimeToLive() const
{
    return timeToLive;
}

void Projectile::incKillPointsOfFriends()
{
    for(GameActor* ga : friendly) {
        Spacecraft* sc = dynamic_cast<Spacecraft*>(ga);
        if (sc) {
            sc->incKillPoints();
        }
    }
}


/**
 * Loses one unit of timeToLive per frame. If the TTL
 * equals 0, the Projectile will die. Projectiles with a TTL of
 * -1 are considered "immortal".
 */
 void Projectile::update()
 {
    if (!isKilled()) {
      velocity += acceleration;
      if (maxSpeed != -1) {
        if (velocity.magnitude() > maxSpeed) {
            velocity = velocity.normalize() * maxSpeed;
            acceleration = acceleration.normalize() * maxSpeed;
        }
    }

    position += velocity;
    if (position.v[0] > field->getWidth())
        kill();
    if (position.v[0] < 0)
        kill();
    if (position.v[1] > field->getHeight())
        kill();
    if (position.v[1] < 0)
        kill();
    if (!isKilled())
    {
        if (timeToLive == 0)
            kill();
        else if (timeToLive != -1 && !isKilled())
            timeToLive--;
    }
}
}

void Projectile::handleCollision(GameActor &other)
{

}

