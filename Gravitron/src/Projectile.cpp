#include "headers/Projectile.h"
#include "headers/Spacecraft.h"
#include <sstream>
#include <iostream>
#include <QDebug>


/**
 * Default constructor.
 */
Projectile::Projectile() : GameActor()
{
    this->timeToLive = -1;
    g = 0;
}

/**
 * Creates a new Projectile with a given postion, mass, gravitational range, gravitational pull, time to live
 * health and a given set of friendly GameActors whithin a given game field. 
 * @param   position the position
 * @param   mass the mass   
 * @param   gravitationRange the gravitational range
 * @param   g the gravitational force
 * @param   timeToLive the time to live
 * @param   health the total health points
 * @param   field the game field
 * @param   friendly a set of friendly actors
 * @param   actors a set of all actors
 */
Projectile::Projectile(Vec3f position, double mass, float gravitationRange, float g, int timeToLive, int health, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
GameActor(position, mass, gravitationRange, g, health, field, actors)
{
    this->timeToLive = timeToLive;
    this->friendly.push_back(&friendly);
}

/**
 * Creates a new Projectile with a given postion, mass, gravitational range, gravitational pull, time to live
 * health  whithin a given game field. 
 * @param   position the position
 * @param   mass the mass   
 * @param   gravitationRange the gravitational range
 * @param   g the gravitational force
 * @param   timeToLive the time to live
 * @param   health the total health points
 * @param   field the game field
 * @param   actors a set of all actors
 */
Projectile::Projectile(Vec3f position, double mass, float gravitationRange, float g, int timeToLive, int health, GameField &field, vector<GameActor*> *actors) :
GameActor(position, mass, gravitationRange, g, health, field, actors)
{
    this->timeToLive = timeToLive;
}

/**
 * The copy constructor.
 * @param projectile the original
 */
Projectile::Projectile(const Projectile &projectile) : GameActor(projectile)
{
    this->timeToLive = projectile.getTimeToLive();
    g = 0;
}

/**
 * The destructor.
 */
Projectile::~Projectile() {}

/**
 * Determines the current time to live (in update cycles).
 * @return current time to live
 */
int Projectile::getTimeToLive() const
{
    return timeToLive;
}

/**
 * This increases the score (kill points, frags) of all Spacecrafts that are 
 * included in the set of friendly GameActors of this Projectile.
 */
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
 * This will calculate the condition of this Projectile for the 
 * next cycle, meaning the position and acceleration will be updated 
 * and the time to live will be decreased by 1. Additionally the 
 * Projectile will be killed, if it touches the borders of the
 * game area.
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



