#ifndef SCRAP_H
#define SCRAP_H
#include "GameActor.h"

class Scrap : public GameActor
{
public:
    Scrap(Vec3f position, GameField &field);
    void handleCollision(GameActor &other);
    GameActorView* getView() const;

private:
    string img;
};

#endif // SCRAP_H
