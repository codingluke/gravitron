#ifndef PLAYER_H
#define PLAYER_H

#include "Spacecraft.h"

class Player
{
public:
    Player(Spacecraft* spacecraft, int frag);
    virtual ~Player();
    void respawn();


public:
    Spacecraft* spacecraft;
    int frag;


};

#endif // PLAYER_H
