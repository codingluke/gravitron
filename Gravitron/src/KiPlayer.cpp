#include "headers/KiPlayer.h"

KiPlayer::KiPlayer(Spacecraft *spacecraft, int frag, int difficulty) : Player(spacecraft, frag)
{
    this->difficulty = difficulty;
}

KiPlayer::~KiPlayer() {

}
