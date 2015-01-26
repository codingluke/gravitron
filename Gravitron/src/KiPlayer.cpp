#include "headers/KiPlayer.h"
#include "headers/PowerUp.h"
#include <iostream>
#include <QDebug>

KiPlayer::KiPlayer(Spacecraft *spacecraft, int frag, int difficulty) : Player(spacecraft, frag)
{
    this->difficulty = difficulty;
    findTarget();
}

KiPlayer::~KiPlayer() {

}

void KiPlayer::update() {
    Spacecraft* isSpacecraft = dynamic_cast<Spacecraft*>(actors[target]);
    PowerUp* isPowerUp = dynamic_cast<PowerUp*>(actors[target]);
    if(target < actors.size() &&
       (isSpacecraft != NULL ||
        isPowerUp != NULL)) {
        followTarget();
        shot();
    } else {
        findTarget();
    }
}

void KiPlayer::findTarget() {
    Spacecraft* isSpacecraft = NULL;
    PowerUp* isPowerUp = NULL;
    bool findEnemy = leftEnemys();
    while ((isSpacecraft == NULL ||
            isPowerUp == NULL) &&
            findEnemy)
    {
        target = rand() % actors.size();
        isSpacecraft = dynamic_cast<Spacecraft*>(actors[target]);
        if(isSpacecraft == spacecraft) {
            isSpacecraft = NULL;
        }
        isPowerUp = dynamic_cast<PowerUp*>(actors[target]);
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
    Vec3f d = spacecraft->getPosition() - actors.at(target)->getPosition();
    d = d.normalize();
    spacecraft->applyForce(d);
}

void KiPlayer::shot() {
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
