#ifndef KINETWORKPLAYER_H
#define KINETWORKPLAYER_H

#include "KiPlayer.h"
#include "Spacecraft.h"

class KiNetworkPlayer : public KiPlayer
{
public:
    KiNetworkPlayer(Spacecraft* spacecraft, int frag, int difficulty, std::vector<GameActor*> *actors);
    virtual ~KiNetworkPlayer();
};

#endif // KINETWORKPLAYER_H
