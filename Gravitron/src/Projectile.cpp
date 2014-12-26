#include "headers/Projectile.h"
#include <sstream>
#include <iostream>


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

Projectile::Projectile(Vec3f position, double mass, float gravitationRange, float g, int timeToLive, int health, GameField &field, GameActor &friendly) : 
    GameActor(position, mass, gravitationRange, g, health, field)
    {
        this->timeToLive = timeToLive;
        g = 0;
        this->friendly.push_back(&friendly);
    }

Projectile::Projectile(const Projectile &projectile) : GameActor(projectile)
{
    this->timeToLive = projectile.getTimeToLive();
    g = 0;
}

Projectile::~Projectile() {

} 

int Projectile::getTimeToLive() const 
{
    return timeToLive;
}


/**
 * Loses one unit of timeToLive per frame. If the TTL
 * equals 0, the Projectile will die. Projectiles with a TTL of 
 * -1 are considered "immortal".
 */
void Projectile::update()
{
    GameActor::update();
    if (timeToLive == 0)
        kill();
    else if (timeToLive != -1)
        timeToLive--;
}

void handleCollision(GameActor &other)
{
    
}

