#include "headers/Player.h"

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
