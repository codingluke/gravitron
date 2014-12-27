#ifndef KIPLAYER_H
#define KIPLAYER_H

#include "Player.h"
#include "Spacecraft.h"

class KiPlayer : public Player
{
public:
    KiPlayer(Spacecraft* spacecraft, int frag, int difficulty);
    virtual ~KiPlayer();

protected:
   int difficulty;
};

#endif // KIPLAYER_H
