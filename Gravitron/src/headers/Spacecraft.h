#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include "GameActor.h"
#include "GameField.h"
#include "Projectile.h"
#include <string>

/**
 * The spacecraft is a player controlled entity. It may be controlled by either a human 
 * player or by the AI.
 */
class Spacecraft : public GameActor
{
    private:
        /**
         * This represents the currently equipped weapon.
         */
        int weapon;
        /**
         * The id of the controlling player.
         */
        int controllingPlayerID;
        float accelerationFactor;
        int killPoints = 0;
        string name;

    private:
        void init();

    public:
        Spacecraft();
        Spacecraft(Vec3f position, double mass,
                   float gravitationRange, float g, GameField &field,
                   vector<GameActor*> *actors);
        Spacecraft(Vec3f position, double mass,
                   float gravitationRange, float g, GameField &field,
                   float maxSpeed, vector<GameActor*> *actors);
        Spacecraft(const Spacecraft &spacecraft);

        virtual ~Spacecraft();

        void handleCollision(GameActor &other);
        int getControllingPlayer() const;
        string getName() const;
        GameActorView* getView() const override;
        int getWeapon() const;
        int getKillPoints() const;

        void incKillPoints();
        void handleKill();
        void setName(string name);
        void setControllingPlayer(int controllingPlayerID);

        void forceAhead();
        void forceBack();
        void forceLeft();
        void forceRight();

        Projectile &shootUp();
        Projectile &shootDown();
        Projectile &shootLeft();
        Projectile &shootRight();
        void repair();
        void upgradeWeapon();
};

#endif // SPACECRAFT_H
