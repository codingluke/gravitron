#include "headers/Player.h"
#include "headers/ActorsAdjustments.h"

Player::Player(QObject *parent) : QObject(parent)
{
    respawnCounter = roundsToRespawn;
}


Player::Player(Spacecraft* spacecraft, int frag)
{
    this->spacecraft = spacecraft;
    this->frag = frag;
    respawnCounter = roundsToRespawn;
}

Player::~Player() {

}

void Player::processInput()
{
}

void Player::setRoundsToRespawn(int roundsToRespawn)
{
    this->roundsToRespawn = roundsToRespawn;
}

void Player::pollRespawn()
{
    if (respawnCounter == 0) {
        spacecraft->repair();
        respawnCounter = roundsToRespawn;
    } else if (spacecraft->isKilled()) {
        respawnCounter--;
    }
}

void Player::respawn() {
    spacecraft->repair();
}

int Player::getWeapon() const
{
    return spacecraft->getWeapon();
}

int Player::getRespawnCounter() const
{
    return respawnCounter;
}

int Player::getHealth() const
{
    return spacecraft->getHealth();
}

Spacecraft* Player::getSpacecraft() const
{
    return spacecraft;
}

int Player::getHealthPercentage() const
{
    float percent = 0;
    if (spacecraft->isKilled()) {
        percent = (roundsToRespawn - respawnCounter) * 100 / roundsToRespawn;
    } else {
        percent = spacecraft->getHealth() * 100 / SPACECRAFT_MAX_HEALTH;
    }
    return percent;
}

bool Player::isWinner() const
{
    return (spacecraft->getKillPoints() == frag);
}

int Player::getKillPoints() const
{
    return spacecraft->getKillPoints();
}
