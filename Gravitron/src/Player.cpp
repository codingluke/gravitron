#include "headers/Player.h"
#include "headers/ActorsAdjustments.h"

Player::Player(QObject *parent) : QObject(parent)
{
}


Player::Player(Spacecraft* spacecraft, int frag)
{
    this->spacecraft = spacecraft;
    this->frag = frag;
}

Player::~Player() {

}

void Player::processInput()
{
}

void Player::respawn() {
    this->spacecraft->repair();
}

int Player::getWeapon() const
{
    return spacecraft->getWeapon();
}

int Player::getLifepoints() const {
    float percent = spacecraft->getHealth() * 100 / SPACECRAFT_MAX_HEALTH;
    return percent;
}
