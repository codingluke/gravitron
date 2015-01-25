#include "headers/GameActor.h"
#include <sstream>
#include <QDebug>
#include <iostream>
#include "headers/Physics.h"
#include <math.h>

int GameActor::id = 0;

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

GameActor::GameActor()
{
	//Vec3f in = Vec3f();
    //GameField *f = new GameField();
    //initialize(Vec3f(), 1., 1., 1., -1, GameField(), -1);
}

GameActor::GameActor(Vec3f position, double mass, float gravitationRange, float g, int health, GameField &field, vector<GameActor*> *actors)
{
    initialize(position, mass, gravitationRange, g, health, field, -1, actors);
}

GameActor::GameActor(Vec3f position, double mass, float gravitationRange, float g, int health, GameField &field, float maxSpeed, vector<GameActor*> *actors)
{
    initialize(position, mass, gravitationRange, g, health, field, maxSpeed, actors);
}

GameActor::GameActor(const GameActor &actor)
{
	initialize(actor);
}

GameActor::~GameActor()
{
}

/**
 * This method will be used, to apply any kind of force to the GameActor.
 * Such would be gravitation, the trajectory analog to the user input, etc.
 * After appliyng all forces for the current frame, update(radius) should
 * be called.
 * @param force the force to apply to this GameActor
 */
void GameActor::applyForce(Vec3f force)
{
	acceleration += force;
}

void GameActor::update()
{
	velocity += acceleration;
    //add velocity limitation
	position += velocity;
    if (position.v[0] > field->getWidth())
        position.v[0] = position.v[0] - field->getWidth();
    if (position.v[0] < 0)
        position.v[0] = field->getWidth() - position.v[0];
    if (position.v[1] > field->getHeight())
        position.v[1] = position.v[1] - field->getHeight();
    if (position.v[1] < 0)
        position.v[1] = field->getHeight() - position.v[1];
    if (maxSpeed != -1) {
        if (velocity.magnitude() > maxSpeed)
            velocity = velocity.normalize() * maxSpeed;
    }
}

void GameActor::updateAll()
{
    GameActor *other;
    for (unsigned int i = 0; i < actors->size(); i++) {
    	other = actors->at(i);
    	if (other != this)
    	{
    	    // Collision Detection
    	    bool collision = Physics::collisionDetection(position, 20.0f,
		          other->getPosition(), 20.0f);
    	    if (collision)
            {
    		        handleCollision(*other);
                other->handleCollision(*this);
            }
    	    // Update Gravitation
    	    Vec3f f = Physics::calculateGravitationForce(this, actors->at(i));
    	    actors->at(i)->applyForce(f);
        }
    }
    update();
}

void GameActor::update(vector<GameActor*> actors)
{
    GameActor *other;
    for (unsigned int i = 0; i < actors.size(); i++) {
            other = actors.at(i);
            if (other != this)
            {
                // Collision Detection
                bool collision = Physics::collisionDetection(position, 20.0f,
                                          other->getPosition(), 20.0f);
                if (collision)
            {
                        handleCollision(*other);
                other->handleCollision(*this);
            }
                // Update Gravitation
                Vec3f f = Physics::calculateGravitationForce(this, actors.at(i));
                actors.at(i)->applyForce(f);
        }
    }
    update();
}

void GameActor::kill()
{
    handleKill();
    killed = true;
}

bool GameActor::isKilled()
{
    return killed;
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

bool GameActor::operator== (GameActor& right) {
    int equals = 1;
    if(position != right.getPosition()) {
        equals = 0;
    } else if (velocity != right.getVelocity()) {
        equals = 0;
    } else if (acceleration != right.getAcceleration()) {
        equals = 0;
    } else if (mass != right.getMass()) {
        equals = 0;
    }
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

float GameActor::getMass() const
{
	return mass;
}

float GameActor::getGravitationRange() const
{
    return gravitationRange;
}

float GameActor::getG() const
{
    return g;
}

void GameActor::setG(float g)
{
    this->g = g;
}

float GameActor::getMaxSpeed() const
{
    return maxSpeed;
}

void GameActor::setMaxSpeed(float maxSpeed)
{
    this->maxSpeed = maxSpeed;
}

int GameActor::getHealth() const
{
    return health;
}

void GameActor::setHealth(int health)
{
    this->health = health;
}

void GameActor::addHealth(int health)
{
    this->health += health;
}

void GameActor::dealDamage(int damage)
{
    if (health != -1)
    {
        if (health <= damage)
        {
            health = 0;
            kill();
        }
        else
            health -= damage;
    }
    // cout << "Dealing damage: " << damage << ".\n";
}

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

GameField* GameActor::getField() const
{
    return field;
}

std::string GameActor::toString() const
{
    std::ostringstream os;
    os << "pos:(" << (double) position[0] << ", " << (double) position[1] << ", " << (double) position[2] << ")";
    os << std::endl;
    os << "vel:(" << (double) velocity[0] << ", " << (double) velocity[1] << ", " << (double) velocity[2] << ")";
    os << std::endl;
    os << "speed: " << velocity.magnitude();
    return os.str();
}

vector<GameActor*> *GameActor::getActors() const
{
    return actors;
}

void GameActor::setActors(vector<GameActor*> *actors)
{
    this->actors = actors;
}

void GameActor::handleCollision(GameActor &other)
{}

void GameActor::handleKill()
{}

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

float GameActor::radToDeg(float radians) const
{
    return radians * 180 / M_PI;
}
