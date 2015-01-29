#ifndef SUN_H
#define SUN_H
#include "GameActor.h"

class Sun : public GameActor
{
public:
    Sun(Vec3f position, float mass, float gravitationRange, float g, GameField& field, vector<GameActor*> *actors);
    void handleCollision(GameActor &other);
    GameActorView* getView() const;
    void update();
};

#endif // SUN_H
