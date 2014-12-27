#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include "GameActor.h"
#include "GameField.h"


class Spacecraft : public GameActor
{
    public:
        Spacecraft();
        Spacecraft(Vec3f position, double mass,
                   float gravitationRange, float g, GameField &field);
        Spacecraft(Vec3f position, double mass,
                   float gravitationRange, float g, GameField &field,
                   float maxSpeed);
        Spacecraft(const Spacecraft &spacecraft);
        virtual ~Spacecraft();

        GameActorView* getView() const override;

        void forceAhead();
        void forceBack();
        void forceLeft();
        void forceRight();
        void repair();
};

#endif // SPACECRAFT_H
