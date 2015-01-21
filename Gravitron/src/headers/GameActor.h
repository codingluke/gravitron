#ifndef GAMEACTOR_HEADER
#define GAMEACTOR_HEADER
#include "Vec3f.h"
#include "GameActorView.h"
#include <vector>
#include "GameField.h"

/**
 * This represents all objects within the game area. An ArrayList of
 * all GameActors will be handled by the main loop; adding, deleting
 * and updating all actors individually.
 */
class GameActor
{
    protected:
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
         * The current position of the GameActor in a 3-dimensional kartesian
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
         * and -1 indicating an invincible GameActor.
         */
        int health;

        float gravitationRange;

        bool killed;

        /**
         * The gravitation acceleration.
         */
        float g;

        /**
         * The maximum speed.
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
        virtual ~GameActor();

        virtual void applyForce(Vec3f force);
        virtual void update();
        virtual void updateAll();
        //virtual void update(vector<GameActor*> actors);
        void update(double radius);

        virtual void handleCollision(GameActor &other);

        virtual void handleKill();

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
        virtual GameActorView* getView() const;
        GameField* getField() const;
        vector<GameActor*> *getActors() const;
        void setActors(vector<GameActor*> *actors);

        void kill();
        bool isKilled();

        virtual std::string toString() const;

    private:
        void initialize(Vec3f position, double mass, float gravitationRange,
                        float g, int health, GameField &field, float maxSpeed,
                        vector<GameActor*> *actors);
        void initialize(const GameActor &actor);
};

#endif
