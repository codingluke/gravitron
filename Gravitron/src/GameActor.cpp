#include "./GameActor.h"
#include <sstream>
#include "./Vec3f.h"

void GameActor::initialize(Vec3f position, double mass)
{
	position = Vec3f();
	velocity = Vec3f();
	acceleration = Vec3f();
	this->position += position;
	this->mass = mass;
}

void GameActor::initialize(const GameActor &actor)
{
	position = actor.getPosition();
	acceleration = actor.getAcceleration();
	velocity = actor.getVelocity();
	mass = actor.getMass();
}

GameActor::GameActor()
{
	Vec3f in = Vec3f();
	initialize(in, 1.);
}

GameActor::GameActor(Vec3f position, double mass)
{
	initialize(position, mass);
}

GameActor::GameActor(GameActor &actor)
{
	initialize(actor);
}

GameActor::~GameActor()
{
}

void GameActor::applyForce(Vec3f force)
{
	velocity += force;
}

void GameActor::update()
{
	position += velocity;
}

/**
 * Updates the GameActor and adjusts its distance from
 * the origin (0,0,0) to place it on the surface of a sphere
 * of the given radius.
 * @param radius the radius of the sphere
 */
void GameActor::update(double radius)
{
	update();
	position = position.normalize() * radius;
}

bool GameActor::operator== (GameActor& right)
{
	bool equals = true;
	if (position != right.getPosition())
		equals = false;
	else if (velocity != right.getVelocity())
		equals = false;
	else if (acceleration != right.getAcceleration())
		equals = false;
	else if (mass != right.getMass())
		equals = false;
	return equals;
}

GameActor &GameActor::operator= (const GameActor &right)
{
	initialize(right);
	return *this;
}

Vec3f GameActor::getVelocity() const
{
	return velocity;
}

Vec3f GameActor::getAcceleration() const
{
	return acceleration;
}

Vec3f GameActor::getPosition() const
{
	return position;
}

double GameActor::getMass() const
{
	return mass;
}

std::string GameActor::toString() const
{
	std::ostringstream os;
    os << "pos:(" << (double) position[0] << ", " << (double) position[1] << ", " << (double) position[2] << ")";
    os << std::endl;
    os << "vel:(" << (double) velocity[0] << ", " << (double) velocity[1] << ", " << (double) velocity[2] << ")";
    return os.str();
}
