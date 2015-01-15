#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include "GameActor.h"
#include "GameField.h"
#include "Projectile.h"


class Spacecraft : public GameActor
{
    private:
        int weapon;

    public:
        Spacecraft();
        Spacecraft(Vec3f position, double mass,
                   float gravitationRange, float g, GameField &field, vector<GameActor*> *actors);
        Spacecraft(Vec3f position, double mass,
                   float gravitationRange, float g, GameField &field,
                   float maxSpeed, vector<GameActor*> *actors);
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
        void repair();

        void setWeapon(int weaponNumber);
};

#endif // SPACECRAFT_H
