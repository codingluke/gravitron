#ifndef PLAYER_H
#define PLAYER_H

#include "Spacecraft.h"
#include <QObject>

class Player : public QObject
{
public:
    Player(QObject *parent = 0);
    Player(Spacecraft* spacecraft, int frag);
    virtual ~Player();
    void respawn();


public:
    Spacecraft* spacecraft;
    int frag;


};

#endif // PLAYER_H
