#ifndef HUMANNETWORKPLAYER_H
#define HUMANNETWORKPLAYER_H

#include "HumanPlayer.h"
#include "Spacecraft.h"

class HumanNetworkPlayer : public HumanPlayer
{
public:
    HumanNetworkPlayer(Spacecraft* spacecraft, int frag);
    virtual ~HumanNetworkPlayer();
};

#endif // HUMANNETWORKPLAYER_H
