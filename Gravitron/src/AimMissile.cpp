#include "headers/AimMissile.h"
#include "headers/ActorsAdjustments.h"
#include "headers/Physics.h"

AimMissile::AimMissile() : Missile()
{
    target = NULL;
}

AimMissile::AimMissile(Vec3f position, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Missile(position, velocity, field, friendly, actors)
{
    target = NULL;
}

AimMissile::AimMissile(GameActor &actor, Vec3f velocity, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Missile(actor.getPosition(), velocity, field, friendly, actors)
{
    target = NULL;
}


AimMissile::AimMissile(GameActor &actor, GameField &field, GameActor &friendly, vector<GameActor*> *actors) :
    Missile(actor, field, friendly, actors)
{
    target = NULL;
}

AimMissile::AimMissile(const Missile &projectile) :
    Missile(projectile)
{
    target = NULL;
}

AimMissile::~AimMissile()
{
    target = NULL;
}

void AimMissile::handleCollision(GameActor &other)
{
    vector<GameActor*>::iterator it;
    bool otherIsFriendly = false;
    for (it = friendly.begin(); it != friendly.end(); it++)
    {
        if (*it == &other)
            otherIsFriendly = true;
    }
    if (!otherIsFriendly)
    {
        other.dealDamage(LASER_DAMAGE);
        kill();
    }
}

void AimMissile::update() {
    GameActor* test = dynamic_cast<GameActor*>(target);
    if (test == 0)
    {
        setNearestTarget();
    }
    test = dynamic_cast<GameActor*>(target);
    if (test != 0)
    {
        Vec3f d = target->getPosition() - position;
        applyForce(d.normalize() * 2);
    }
    Projectile::update();
}

void AimMissile::setRandomTarget() {
    if (actors->size() > 1)
    {
        bool otherIsFriendly = false;
        do {
            target = actors->at(rand() % actors->size());
            vector<GameActor*>::iterator it;
            for (it = friendly.begin(); it != friendly.end(); it++)
            {
                bool e = (*it) == target;
                std::cout << e << std::endl;
                if (e == true) {
                    otherIsFriendly = true;
                } else {
                    otherIsFriendly = false;
                }
            }
        } while (otherIsFriendly);
    }
}

void AimMissile::setNearestTarget() 
{
    if (actors->size() > 1)
    {
        GameActor* candidate;
        float minDistance = -1;
        for (GameActor* act : *actors)
        {
            bool otherIsFriendly = false;
            for (GameActor* fr : friendly)
            {
                if (fr == act)
                    otherIsFriendly = true;
            }
            if (!otherIsFriendly && (act != this))
            {
                if (minDistance > 0)
                {
                    if (this->getDistance(*act) < minDistance)
                    {
                        candidate = act;
                        minDistance = this->getDistance(*act);
                    }
                }
                else
                {
                    minDistance = this->getDistance(*act);
                }
            }
        }
        GameActor* finalTarget = dynamic_cast<GameActor*>(candidate);
        if (finalTarget != 0)
            target = finalTarget;
    }   
}


