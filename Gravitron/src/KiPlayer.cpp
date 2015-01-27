#include "headers/KiPlayer.h"
#include "headers/PowerUp.h"
#include <iostream>
#include <QDebug>

KiPlayer::KiPlayer(Spacecraft *spacecraft, int frag, int difficulty) : Player(spacecraft, frag)
{
    this->difficulty = difficulty;
    target = NULL;
    findTarget();
}

KiPlayer::~KiPlayer() {

}

void KiPlayer::update() {
    Spacecraft* isSpacecraft = dynamic_cast<Spacecraft*>(target);
    PowerUp* isPowerUp = dynamic_cast<PowerUp*>(target);
    if((isSpacecraft != 0) || (isPowerUp != 0)) {
        followTarget();
        shoot();
    } else {
        findTarget();
    }
}

void KiPlayer::findTarget() {
    if (actors.size() > 1)
    {
        GameActor* candidate = NULL;
        float minDistance = -1;
        for (GameActor* act : actors)
        {
            Spacecraft* isSpacecraft = dynamic_cast<Spacecraft*>(act);
            PowerUp* isPowerUp = dynamic_cast<PowerUp*>(act);
            if (((isSpacecraft != 0) || (isPowerUp != 0)) && (act != this->spacecraft))
            {
                if (minDistance > 0)
                {
                    if (this->spacecraft->getDistance(*act) < minDistance)
                    {
                        candidate = act;
                        minDistance = this->spacecraft->getDistance(*act);
                    }
                }
                else
                {
                    minDistance = this->spacecraft->getDistance(*act);
                }
            }
        }
        Spacecraft* isSpacecraft = dynamic_cast<Spacecraft*>(candidate);
        PowerUp* isPowerUp = dynamic_cast<PowerUp*>(candidate);
        if ((isSpacecraft != 0) || (isPowerUp != 0))
            target = candidate;
        if (isPowerUp != 0)
            cerr << "target: PowerUp\n";
        if (isSpacecraft)
            cerr << "target: Spacecraft\n";
    }
}

bool KiPlayer::leftEnemys() {
    bool leftEnemeys = false;
    for (int i = 0; i < actors.size(); i++){
        if (Spacecraft* isSpacecraft = dynamic_cast<Spacecraft*>(actors[i])) {
            leftEnemeys = true;
            i = actors.size();
        }
    }
    return leftEnemeys;
}

void KiPlayer::setActors(vector<GameActor*> actors) {
    this->actors = actors;
}

void KiPlayer::followTarget() {
    GameActor* test = dynamic_cast<GameActor*>(target);
    if (target != 0)
    {
        Vec3f d = target->getPosition() - spacecraft->getPosition();
        d = d.normalize();
        spacecraft->applyForce(d);
    }
}

void KiPlayer::shoot() {
    if(rand() % 10 == 0.1f) {
        spacecraft->shootDown();
    } else if(rand() % 10 == 0.1f) {
        spacecraft->shootLeft();
    } else if(rand() % 10 == 0.1f) {
        spacecraft->shootRight();
    } else if(rand() % 10 == 0.1f) {
        spacecraft->shootUp();
    }
}
