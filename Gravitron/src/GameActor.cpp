#include "headers/GameActor.h"
#include <sstream>
#include <QDebug>
#include <iostream>
#include "headers/Physics.h"
#include <math.h>

int GameActor::id = 0;

/**
 * Initializer method for the constructor.
 * @param position         the position
 * @param mass             the mass
 * @param gravitationRange the gravitational pull range
 * @param g                the gravitational force
 * @param health           the health
 * @param field            the game area
 * @param maxSpeed         the the maximum speed 
 * @param actors           the the other actors
 */

void GameActor::initialize(Vec3f position, double mass, float gravitationRange, float g, int health, GameField &field, float maxSpeed, vector<GameActor*> *actors)
{
    identifier = GameActor::id++;
    killed = false;
    velocity = Vec3f();
    acceleration = Vec3f();
    this->position = position;
    this->mass = mass;
    this->gravitationRange = gravitationRange;
    this->g = g;
    this->field = &field;
    this->maxSpeed = maxSpeed;
    this->health = health;
    this->actors = actors;
}

/**
 * The initializer for the copy constructor.    
 * @param actor the original GameActor
 */
void GameActor::initialize(const GameActor &actor)
{
    identifier = GameActor::id++;
    killed = false;
    position = actor.getPosition();
    acceleration = actor.getAcceleration();
    velocity = actor.getVelocity();
    mass = actor.getMass();
    gravitationRange = actor.gravitationRange;
    g = actor.g;
    field = actor.getField();
    maxSpeed = actor.getMaxSpeed();
    health = actor.getHealth();
    actors = actor.getActors();
}

/**
 * The default constructor.
 */
GameActor::GameActor() {}

/**
 * The constructor for a GameActor without speed limitation.
 * @param position         the position
 * @param mass             the mass
 * @param gravitationRange the gravitational pull range
 * @param g                the gravitational force
 * @param health           the health
 * @param field            the game area
 * @param actors           the the other actors
 */
GameActor::GameActor(Vec3f position, double mass, float gravitationRange, float g, int health, GameField &field, vector<GameActor*> *actors)
{
    initialize(position, mass, gravitationRange, g, health, field, -1, actors);
}

/**
 * The constructor.
 * @param position         the position
 * @param mass             the mass
 * @param gravitationRange the gravitational pull range
 * @param g                the gravitational force
 * @param health           the health
 * @param field            the game area
 * @param maxSpeed         the the maximum speed 
 * @param actors           the the other actors
 */
GameActor::GameActor(Vec3f position, double mass, float gravitationRange, float g, int health, GameField &field, float maxSpeed, vector<GameActor*> *actors)
{
    initialize(position, mass, gravitationRange, g, health, field, maxSpeed, actors);
}

GameActor::GameActor(const GameActor &actor)
{
	initialize(actor);
}

/**
 * The destructor.
 */
GameActor::~GameActor() {}

/**
 * This method will be used, to apply any kind of force to the GameActor.
 * Such would be gravitation, the trajectory analog to the user input, etc.
 * After applying all forces for the current frame, update(radius) should
 * be called.
 * @param force the force to apply to this GameActor
 */
void GameActor::applyForce(Vec3f force)
{
   acceleration += force;
}

/**
 * Updates the position and velocity of this GameActor. With this implementation
 * GameActors will be bounced off the game field borders.
 */
void GameActor::update()
{
    if (!isKilled()) {
        velocity += acceleration;
        if (maxSpeed != -1) {
            if (velocity.magnitude() > maxSpeed) {
                velocity = velocity.normalize() * maxSpeed;
                acceleration = acceleration.normalize() * maxSpeed;
            }
        }
        position += velocity;
        if (position.v[0] > field->getWidth())
        {
            position.v[0] = field->getWidth() - 1;
            velocity.v[0] = velocity.v[0] * (-1);
            acceleration.v[0] = acceleration.v[0] * (-1);
        }
        if (position.v[0] < 0)
        {
            position.v[0] = 1;
            velocity.v[0] = velocity.v[0] * (-1);
            acceleration.v[0] = acceleration.v[0] * (-1);
        }
        if (position.v[1] > field->getHeight())
        {
            position.v[1] = field->getHeight() - 1;
            velocity.v[1] = velocity.v[1] * (-1);
            acceleration.v[1] = acceleration.v[1] * (-1);
        }
        if (position.v[1] < 0)
        {
            position.v[1] = 1;
            velocity.v[1] = velocity.v[1] * (-1);
            acceleration.v[1] = acceleration.v[1] * (-1);
        }
    }
}

/**
 * Checks for collisions with other GameActors, triggers collision handling
 * as well as the calculation and application of the gravitational force
 * towards all other GameActors.
 */
void GameActor::updateAll()
{
 GameActor *other;
    for (unsigned int i = 0; i < actors->size(); i++) {
        other = actors->at(i);
        if (other != this && !other->isKilled()) {
            // Collision Detection
            bool collision = Physics::collisionDetection(position, 20.0f,
                  other->getPosition(), 20.0f);
            if (collision && !killed && !other->isKilled()) // no double kill; if kill generate new actors at the same position a killing loop starts
            {
                other->handleCollision(*this);
                //handleCollision(*other);
            }
            // Update Gravitation
            Vec3f f = Physics::calculateGravitationForce(this, actors->at(i));
            other->applyForce(f);
        }
    }
    update();
}

/**
 * Marks this GameActor as killed and triggers kill handling.
 */
void GameActor::kill()
{
    handleKill();
    killed = true;
}

/**
 * Determines whether this GameActor is killed or not.
 * @return true if this GameActor is killed, false otherwise
 */
bool GameActor::isKilled()
{
    return killed;
}

/**
 * Determines whether to GameActors are the same, in other words,
 * whether they point to the same memory address. Other comparisons
 * would be illogical since all vector based attributes of GameActors
 * could only be compared to a predestined degree of accuracy.
 * @return true if both GameActors are the same, false otherwise
 */
bool GameActor::operator== (GameActor& right) {
    return (*this == right);
}

/**
 * Assigns a given GameActor this one.
 * @return this GameActor after assignment
 */
GameActor &GameActor::operator= (const GameActor &right)
{
	initialize(right);
	return *this;
}

/**
 * Determines the current velocity.
 * @return the current velocity
 */
Vec3f GameActor::getVelocity() const
{
	return velocity;
}

/**
 * Determines the current acceleration.
 * @return the current acceleration
 */
Vec3f GameActor::getAcceleration() const
{
	return acceleration;
}

/**
 * Determines the current position
 * @return the current position
 */
Vec3f GameActor::getPosition() const
{
	return position;
}

/**
 * Determines the current mass
 * @return the current mass
 */
float GameActor::getMass() const
{
	return mass;
}

/**
 * Determines the current gravitational range
 * @return the current gravitational range
 */
float GameActor::getGravitationRange() const
{
    return gravitationRange;
}

/**
 * Determines the current gravitational force
 * @return the current gravitational force
 */
float GameActor::getG() const
{
    return g;
}

/**
 * Determines the current identifier
 * @return the current identifier
 */
int GameActor::getIdentifier() const
{
    return identifier;
}

/**
 * Determines the maximum speed.
 * @return the maximum speed
 */
float GameActor::getMaxSpeed() const
{
    return maxSpeed;
}

/**
 * Sets the gravitational force to a given value.
 * @param g the value to set
 */
void GameActor::setG(float g)
{
    this->g = g;
}

/**
 * Sets the maximum speed to a given value.
 * @param g the value to set
 */
void GameActor::setMaxSpeed(float maxSpeed)
{
    this->maxSpeed = maxSpeed;
}

/**
 * Determines the current amount of health.
 * @return the current health
 */
int GameActor::getHealth() const
{
    return health;
}

/**
 * Sets the  to a given value.
 * @param g the value to set
 */
void GameActor::setHealth(int health)
{
    this->health = health;
}

/**
 * Adds the given value to the health of this GameActor.
 * @param health the health to add
 */
void GameActor::addHealth(int health)
{
    this->health += health;
}

/**
 * Deals a given amount of damage to this GameActor and
 * determines whether this kills it.
 * @param damage the amount of damage to deal
 */
void GameActor::dealDamage(int damage)
{
    if (health != -1)
    {
        if (health <= damage) {
            health = 0;
            kill();
        }
        else
            health -= damage;
    }
}

/**
 * Creates and returns a GameActorView of this instance of
 * GameActor.
 * @return the GameActorView for this GameActor
 */
GameActorView* GameActor::getView() const
{
    std::ostringstream x;
    std::ostringstream y;
    x << position[0];
    y << position[1];
    GameActorView *view = new GameActorView("qrc:/qml/actor");
    std::ostringstream identifiy;
    identifiy << identifier;
    view->setProperty("identifier", identifiy.str());
    view->setProperty("x", x.str());
    view->setProperty("y", y.str());
    if (killed) {
        view->setProperty("color", "red");
    } else {
        view->setProperty("color", "yellow");
    }
    std::ostringstream rot;
    rot << calculateRotation();
    view->setProperty("angle", rot.str());
    return view;
}

/**
 * Returns the GameField of this GameActor.
 * @return the field
 */
GameField* GameActor::getField() const
{
    return field;
}

/**
 * Creates and returns a string representation of this GameActor. 
 * @return string representation of this GameActor
 */
std::string GameActor::toString() const
{
    std::ostringstream os;
    os << "pos:(" << (double) position[0] << ", " << (double) position[1] << 
        ", " << (double) position[2] << ")";
    os << std::endl;
    os << "vel:(" << (double) velocity[0] << ", " << (double) velocity[1] << 
        ", " << (double) velocity[2] << ")";
    os << std::endl;
    os << "speed: " << velocity.magnitude();
    return os.str();
}

/**
 * Returns the GameActor list of this GameActor.
 * @return the GameActor list of this GameActor
 */
vector<GameActor*> *GameActor::getActors() const
{
    return actors;
}

/**
 * Replaces the GameActor list of this instance with a given list.
 * @param actors a list (vector) with GameActors which will interact 
 * with this instance of GameActor
 */
void GameActor::setActors(vector<GameActor*> *actors)
{
    this->actors = actors;
}

/**
 * Determines what will happen if this GameActor collides with another
 * instance of GameActor. 
 * @param other the GameActor colliding with this one
 */
void GameActor::handleCollision(GameActor &other)
{}

/**
 * Determines what will happen if this GameActor is killed.
 */
void GameActor::handleKill()
{}

/**
 * Calculates the rotation of this game actor and returns the rotation
 * angle in degrees in mathematical positive direction, ranging from 0 to 360. 
 * @return the rotation in degrees
 */
float GameActor::calculateRotation() const
{
    float res = 0;
    if (abs(velocity[0]) < 0.0001)
    {
        if (velocity[1] < 0)
            res = 90;
        else
            res = 270;
    }
    else if (abs(velocity[1]) < 0.0001)
    {
        if (velocity[0] > 0)
            res = 180;
        else
            res = 0;
    }
    else
    {
        res = atan(velocity[1] / velocity[0]);
        res = radToDeg(res);
        if (velocity[0] > 0)
            res += 180;
    }
    return res;
}

/**
 * Converts a given value in radians to degrees.
 * @param  radians the radians value to convert
 * @return         the converted vlue
 */
float GameActor::radToDeg(float radians) const
{
    return radians * 180 / M_PI;
}

/**
 * Determines the distance between this instance of GameActor and
 * a given one. 
 * @param  to the other GameActor
 * @return    the distance to the given GameActor
 */
float GameActor::getDistance(GameActor &to) const
{
    return Physics::distance(position, to.getPosition());
}
