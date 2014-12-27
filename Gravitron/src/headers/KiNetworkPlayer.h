#ifndef KINETWORKPLAYER_H
#define KINETWORKPLAYER_H

#include "KiPlayer.h"
#include "Spacecraft.h"

class KiNetworkPlayer : public KiPlayer
{
public:
    KiNetworkPlayer(Spacecraft* spacecraft, int frag, int difficulty);
    virtual ~KiNetworkPlayer();
};

#endif // KINETWORKPLAYER_H
