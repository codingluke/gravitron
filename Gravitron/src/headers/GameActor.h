#ifndef GAMEACTOR_H
#define GAMEACTOR_H
#include "Vec3f.h"
#include "GameActorView.h"
#include <vector>
#include "GameField.h"

/**
 * This (abstract) class represents all objects within the game area. An ArrayList of
 * all GameActors will be handled by the main loop; adding, deleting
 * and updating all actors individually. Each GameActor has a pointer
 * to that list, enabling it, to add new GameActors on its own.
 */
class GameActor
{
    protected:

        /**
         *  A global counter representing the number of all GameActors. It will
         *  be increased, whenever a new GameActor is instantiated.
         */
        static int id;

        /**
         *  The identifier of this GameActor. Equals the id field at the time
         *  of instantiation of this very GameActor.
         */
        int identifier;

        /**
         * Velocity is the actual direction and speed for this GameActor.
         */
        Vec3f velocity;

        /**
         * Acceleration is the force, that will be applied to the GameActors
         * velocity per frame.
         */

        Vec3f acceleration;
        /**
         * The current position of the GameActor in a 3-dimensional Cartesian
         * space.
         */

        Vec3f position;
        /**
         * The mass of the GameActor, but actually a factor in relation to
         * a preset normal mass.
         */

        float mass;
        /**
         * The health points of this GameActor, 0 indicating a dead GameActor
         * and -1 indicating an immortal GameActor.
         */
        int health;

        /**
         * The range over which this GameActor can apply its own gravitational
         * pull to other GameActors.
         */
        float gravitationRange;

        /**
         * Defines whether this GameActor counts as killed or not. This will 
         * have implications on both the effects of other GameActors and the 
         * updating process.
         */
        bool killed;

        /**
         * The gravitational force or pull of this GameActor.
         */
        float g;

        /**
         * The maximum speed this GameActor can acquire.
         */
        float maxSpeed;

        /**
         * The game area.
         */
        GameField *field;

        /**
         * A list (vector) of all other GameActors
         */
        vector<GameActor*> *actors;

    public:
        GameActor();
        GameActor(Vec3f position, double mass, float gravitationRange,
                  float g, int health, GameField &field, vector<GameActor*> *actors);
        GameActor(Vec3f position, double mass, float gravitationRange, float g,
                  int health, GameField &field, float maxSpeed,
                  vector<GameActor*> *actors);
        GameActor(const GameActor &actor);

        bool operator== (GameActor& right);
        GameActor &operator= (const GameActor &right);
        Vec3f getPosition() const;
        Vec3f getAcceleration() const;
        Vec3f getVelocity() const;
        float getMass() const;
        float getGravitationRange() const;
        float getG() const;
        void setG(float g);
        float getMaxSpeed() const;
        void setMaxSpeed(float maxSpeed);
        int getHealth() const;
        void setHealth(int health);
        void dealDamage(int damage);
        void addHealth(int health);
        GameField* getField() const;
        vector<GameActor*> *getActors() const;
        void setActors(vector<GameActor*> *actors);
        int getIdentifier() const;
        float getDistance(GameActor &to) const;
        void kill();
        bool isKilled();

        virtual ~GameActor();
        virtual void applyForce(Vec3f force);
        virtual void update();
        virtual void updateAll();
        virtual void handleCollision(GameActor &other);
        virtual void handleKill();
        virtual GameActorView* getView() const;
        virtual std::string toString() const;

    private:
        void initialize(Vec3f position, double mass, float gravitationRange,
                        float g, int health, GameField &field, float maxSpeed,
                        vector<GameActor*> *actors);
        void initialize(const GameActor &actor);

    protected:
        float calculateRotation() const;
        float radToDeg(float radians) const;
};

#endif
