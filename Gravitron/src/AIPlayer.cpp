#include "headers/AIPlayer.h"
#include "headers/PowerUp.h"
#include <iostream>
#include <QDebug>

AIPlayer::AIPlayer(Spacecraft *spacecraft, int frag, int difficulty,
                   std::vector<GameActor*> *actors, QString name)
         : Player(spacecraft, frag, name)
{
    this->difficulty = difficulty;
    this->actors = actors;
    target = NULL;
    findTarget();
}

AIPlayer::~AIPlayer() {

}

void AIPlayer::update() {
    if (!spacecraft->isKilled()) {
        bool targetExists = false;
        for (GameActor* act : *actors) {
            if (target == act)
                targetExists = true;
        }
        if (targetExists && !target->isKilled()) {
                followTarget(target);
                shoot();
        }
        else {
            findTarget();
        }
    } else {
        pollRespawn();
    }
}

void AIPlayer::findTarget() {
    if (actors->size() > 1)
    {
        GameActor* candidate = NULL;
        float minDistance = -1;
        for (GameActor* act : *actors)
        {
            if (act != this->spacecraft)
            {
                Spacecraft* isSpacecraft = dynamic_cast<Spacecraft*>(act);
                PowerUp* isPowerUp = dynamic_cast<PowerUp*>(act);
                if ((isSpacecraft) || (isPowerUp != 0))
                {
                    if (minDistance != -1)
                    {
                        if (this->spacecraft->getDistance(*act) < minDistance)
                        {
                            candidate = act;
                            minDistance = this->spacecraft->getDistance(*candidate);
                        }
                    }
                    else
                    {
                        candidate = act;
                        minDistance = this->spacecraft->getDistance(*act);
                    }
                }
            }
        }
        Spacecraft* isSpacecraft = dynamic_cast<Spacecraft*>(candidate);
        PowerUp* isPowerUp = dynamic_cast<PowerUp*>(candidate);
        if ((isSpacecraft != 0) || (isPowerUp != 0))
            target = candidate;
    }
}

void AIPlayer::followTarget(GameActor *toFollow) {
    GameActor* test = dynamic_cast<GameActor*>(toFollow);
    if (test != 0)
    {
        Vec3f d = test->getPosition() - spacecraft->getPosition();
        d = d.normalize();
        spacecraft->applyForce(d);
    }
}

void AIPlayer::shoot() {
    if(rand() % 100 <= 1) {
        spacecraft->shootDown();
    } else if(rand() % 100 <= 1) {
        spacecraft->shootLeft();
    } else if(rand() % 100 <= 1) {
        spacecraft->shootRight();
    } else if(rand() % 100 <= 1) {
        spacecraft->shootUp();
    }
}
