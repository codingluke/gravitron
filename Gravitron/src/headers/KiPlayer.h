#ifndef KIPLAYER_H
#define KIPLAYER_H

#include "Player.h"
#include "Spacecraft.h"


class KiPlayer : public Player
{
private:
    bool leftEnemys();
    void followTarget(GameActor *toFollow);
    void shoot();
    void findTarget();

public:
    KiPlayer(Spacecraft* spacecraft, int frag, int difficulty, std::vector<GameActor*> *actors);
    virtual ~KiPlayer();
    void update();
    void setActors(vector<GameActor*> *actors);

protected:
   int difficulty;
   GameActor* target;
   vector<GameActor*> *actors;
};

#endif // KIPLAYER_H
