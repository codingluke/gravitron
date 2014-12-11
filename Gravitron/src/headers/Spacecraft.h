#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include "GameActor.h"


class Spacecraft : public GameActor
{
    public:
        Spacecraft();
        Spacecraft(Vec3f position, double mass, float gravitationRange, float g);
        Spacecraft(const Spacecraft &spacecraft);
        virtual ~Spacecraft();

        /*virtual void applyForce(Vec3f force);
        virtual void update();
        virtual void update(double radius);*/

        GameActorView* getView() const override;
        //virtual std::string toString() const;
};

#endif // SPACECRAFT_H
