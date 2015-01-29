#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"
#include "Spacecraft.h"


class AIPlayer : public Player
{
    private:
        void followTarget(GameActor *toFollow);
        void shoot();
        void findTarget();

    public:
        AIPlayer(Spacecraft* spacecraft, int frag, int difficulty,
                 std::vector<GameActor*> *actors, QString name);
        virtual ~AIPlayer();

        void update();
        void setActors(vector<GameActor*> *actors);

    protected:
       int difficulty;
       GameActor* target;
       vector<GameActor*> *actors;
};

#endif // AIPLAYER_H
