#ifndef GAMEACTOR_HEADER
#define GAMEACTOR_HEADER
#include "Vec3f.h"
#include "GameActorView.h"
#include <vector>

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

    float gravitationRange;
    bool killed;

    /**
     * The gravitation acceleration.
     */
    float g;

public:
	GameActor();
    GameActor(Vec3f position, double mass, float gravitationRange, float g);
	GameActor(const GameActor &actor);
    virtual ~GameActor();

	virtual void applyForce(Vec3f force);
	virtual void update();
	virtual void update(vector<GameActor*> actors);
	void update(double radius);

	bool operator== (GameActor& right);
    GameActor &operator= (const GameActor &right);

	Vec3f getPosition() const;
	Vec3f getAcceleration() const;
	Vec3f getVelocity() const;
    float getMass() const;
    float getGravitationRange() const;
    float getG() const;
    virtual GameActorView* getView() const;

    void kill();

    virtual std::string toString() const;

private:
    void initialize(Vec3f position, double mass, float gravitationRange, float g);
	void initialize(const GameActor &actor);
};

#endif
