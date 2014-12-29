#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "Spacecraft.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer(Spacecraft* spacecraft, int frag);
    virtual ~HumanPlayer();
};

#endif // HUMANPLAYER_H
