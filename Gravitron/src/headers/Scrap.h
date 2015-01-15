#ifndef SCRAP_H
#define SCRAP_H
#include "GameActor.h"

class Scrap : public GameActor
{
public:
    Scrap(Vec3f position, float mass, float gravitationRange, float g, GameField &field, vector<GameActor*> *actors);
    void handleCollision(GameActor &other);
    GameActorView* getView() const;

private:
    string img;
};

#endif // SCRAP_H
