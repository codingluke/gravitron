#include "headers/HumanPlayer.h"
#include "headers/GameLoop.h"
#include <QDebug>

HumanPlayer::HumanPlayer(Spacecraft *spacecraft, int frag, GameLoop* loop) : Player(spacecraft, frag)
{
    this->spacecraft->setWeapon(1);
    connect(loop, SIGNAL(activeWeaponPlayer(int)), this, SLOT(setActiveWeapon(int)));
}

HumanPlayer::~HumanPlayer() {

}

void HumanPlayer::setActiveWeapon(int weaponNumber) {
    this->spacecraft->setWeapon(weaponNumber);
}
