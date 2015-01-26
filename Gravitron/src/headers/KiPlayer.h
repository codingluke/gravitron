#ifndef KIPLAYER_H
#define KIPLAYER_H

#include "Player.h"
#include "Spacecraft.h"


class KiPlayer : public Player
{
private:
    bool leftEnemys();
    void followTarget();
    void shot();
    void findTarget();

public:
    KiPlayer(Spacecraft* spacecraft, int frag, int difficulty);
    virtual ~KiPlayer();
    void update();
    void setActors(vector<GameActor*> actors);

protected:
   int difficulty;
   int target;
   vector<GameActor*> actors;
};

#endif // KIPLAYER_H
