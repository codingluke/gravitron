#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include "GameActor.h"
#include "GameField.h"
#include "Projectile.h"


class Spacecraft : public GameActor
{
    public:
        Spacecraft();
        Spacecraft(Vec3f position, double mass,
                   float gravitationRange, float g, int health, GameField &field);
        Spacecraft(Vec3f position, double mass,
                   float gravitationRange, float g, int health, GameField &field,
                   float maxSpeed);
        Spacecraft(const Spacecraft &spacecraft);
        void handleCollision(GameActor &other);
        virtual ~Spacecraft();

        GameActorView* getView() const override;

        void forceAhead();
        void forceBack();
        void forceLeft();
        void forceRight();

        Projectile &shootUp();
        Projectile &shootDown();
        Projectile &shootLeft();
        Projectile &shootRight();
};

#endif // SPACECRAFT_H
