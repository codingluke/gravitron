#include "headers/KiNetworkPlayer.h"

KiNetworkPlayer::KiNetworkPlayer(Spacecraft *spacecraft, int frag, int difficulty, std::vector<GameActor*> *actors) :
KiPlayer(spacecraft, frag, difficulty, actors)
{
}

KiNetworkPlayer::~KiNetworkPlayer() {

}
