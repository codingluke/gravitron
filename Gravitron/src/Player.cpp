#include "headers/Player.h"

Player::Player(Spacecraft* spacecraft, int frag)
{
    this->spacecraft = spacecraft;
    this->frag = frag;
}

Player::~Player() {

}

void Player::respawn() {
    this->spacecraft->repair();
}
