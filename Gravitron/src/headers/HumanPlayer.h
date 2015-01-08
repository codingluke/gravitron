#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "Spacecraft.h"
#include "GameLoop.h"

class HumanPlayer : public Player
{
    Q_OBJECT
public:
    HumanPlayer(Spacecraft* spacecraft, int frag, GameLoop *loop);
    virtual ~HumanPlayer();

private slots:
    void setActiveWappon(int wapponNumber);
};

#endif // HUMANPLAYER_H
