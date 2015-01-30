#ifndef ACTORSADJUSTMENTS_H
#define ACTORSADJUSTMENTS_H
/**
 * Class that holds a bunch of adjustment variables for each gameactor type.
 * It is designed so that each GameActor property can be in a range between
 * the maxiaml and minimal value.
 *
 * The static members of the class are self explaining and do not need further
 * documentation.
 */
class ActConf {

public:
	static constexpr float SUN_MAX_MASS = 6;
	static constexpr float SUN_MIN_MASS = 6;
	static constexpr float SUN_MAX_G = 10;
	static constexpr float SUN_MIN_G = 10;
	static constexpr float SUN_MAX_GRAVITATION_RANGE = 1500;
	static constexpr float SUN_MIN_GRAVITATION_RANGE = 1500;
	static constexpr float SUN_MAX_MAXSPEED = 0;
	static constexpr float SUN_MIN_MAXSPEED = 0;
	static constexpr float SUN_MAX_RADIUS = 100;
	static constexpr float SUN_MIN_RADIUS = 100;
	static constexpr float SUN_DAMAGE = 10;
	static constexpr float SUN_MAX_HEALTH = -1;
	static constexpr float SUN_MIN_HEALTH = -1;

	static constexpr float PLANET_MAX_MASS = 3;
	static constexpr float PLANET_MIN_MASS = 3;
	static constexpr float PLANET_MAX_G = 3;
	static constexpr float PLANET_MIN_G = 3;
	static constexpr float PLANET_MAX_GRAVITATION_RANGE = 500;
	static constexpr float PLANET_MIN_GRAVITATION_RANGE = 500;
	static constexpr float PLANET_MAX_MAXSPEED = 0;
	static constexpr float PLANET_MIN_MAXSPEED = 0;
	static constexpr float PLANET_MAX_RADIUS = 50;
	static constexpr float PLANET_MIN_RADIUS = 50;
	static constexpr float PLANET_DAMAGE = 5;
	static constexpr float PLANET_MAX_HEALTH = 3000;
	static constexpr float PLANET_MIN_HEALTH = 2000;


	static constexpr float ASTEROID_MAX_MASS = 2;
	static constexpr float ASTEROID_MIN_MASS = 0.5;
	static constexpr float ASTEROID_MAX_G = 0.7;
	static constexpr float ASTEROID_MIN_G = 0.7;
	static constexpr float ASTEROID_MAX_GRAVITATION_RANGE = 0.5;
	static constexpr float ASTEROID_MIN_GRAVITATION_RANGE = 0.5;
	static constexpr float ASTEROID_MAX_MAXSPEED = 10;
	static constexpr float ASTEROID_MIN_MAXSPEED = 10;
	static constexpr float ASTEROID_MAX_RADIUS = 25;
	static constexpr float ASTEROID_MIN_RADIUS = 40;
	static constexpr float ASTEROID_DAMAGE = 2;
	static constexpr float ASTEROID_MAX_HEALTH = 150;
	static constexpr float ASTEROID_MIN_HEALTH = 20;


	static constexpr float SPACECRAFT_MAX_MASS = 0.5;
	static constexpr float SPACECRAFT_MIN_MASS = 0.5;
	static constexpr float SPACECRAFT_MAX_G = 0;
	static constexpr float SPACECRAFT_MIN_G = 0;
	static constexpr float SPACECRAFT_MAX_GRAVITATION_RANGE = 0;
	static constexpr float SPACECRAFT_MIN_GRAVITATION_RANGE = 0;
	static constexpr float SPACECRAFT_MAX_MAXSPEED = 12;
	static constexpr float SPACECRAFT_MIN_MAXSPEED = 12;
	static constexpr float SPACECRAFT_MAX_RADIUS = 25;
	static constexpr float SPACECRAFT_MIN_RADIUS = 25;
	static constexpr float SPACECRAFT_MAX_HEALTH = 300;
	static constexpr float SPACECRAFT_MIN_HEALTH = 300;
	static constexpr float SPACECRAFT_COLLISION_DAMAGE = 10;

	static constexpr float MISSILE_MASS = 1;
	static constexpr float MISSILE_G = 0;
	static constexpr float MISSILE_GRAVITATION_RANGE = 0;
	static constexpr float MISSILE_MAXSPEED = 15;
	static constexpr float MISSILE_RADIUS = 10;
	static constexpr float MISSILE_HEALTH = 5;
	static constexpr float MISSILE_DAMAGE = 20;
	static constexpr float MISSILE_TIME_TO_LIVE = 300;

	static constexpr float AIM_MISSILE_MAX_MASS = 0.5;
	static constexpr float AIM_MISSILE_MIN_MASS = 0.5;
	static constexpr float AIM_MISSILE_MAX_G = 0;
	static constexpr float AIM_MISSILE_MIN_G = 0;
	static constexpr float AIM_MISSILE_MAX_GRAVITATION_RANGE = 0;
	static constexpr float AIM_MISSILE_MIN_GRAVITATION_RANGE = 0;
	static constexpr float AIM_MISSILE_MAX_MAXSPEED = 13;
	static constexpr float AIM_MISSILE_MIN_MAXSPEED = 13;
	static constexpr float AIM_MISSILE_MAX_RADIUS = 10;
	static constexpr float AIM_MISSILE_MIN_RADIUS = 10;
	static constexpr float AIM_MISSILE_MAX_HEALTH = 40;
	static constexpr float AIM_MISSILE_MIN_HEALTH = 40;
	static constexpr float AIM_MISSILE_MAX_POWER = 50;
	static constexpr float AIM_MISSILE_MIN_POWER = 50;
	static constexpr float AIM_MISSILE_DAMAGE = 40;


	static constexpr float SCRAP_MAX_MASS = 0.2;
	static constexpr float SCRAP_MIN_MASS = 0.05;
	static constexpr float SCRAP_MAX_G = 0;
	static constexpr float SCRAP_MIN_G = 0;
	static constexpr float SCRAP_MAX_GRAVITATION_RANGE = 0;
	static constexpr float SCRAP_MIN_GRAVITATION_RANGE = 0;
	static constexpr float SCRAP_MAX_MAXSPEED = 0;
	static constexpr float SCRAP_MIN_MAXSPEED = 2;
	static constexpr float SCRAP_MAX_RADIUS = 2;
	static constexpr float SCRAP_MIN_RADIUS = 2;
	static constexpr float SCRAP_DAMAGE = 0.5;
	static constexpr float SCRAP_MAX_HEALTH = 5;
	static constexpr float SCRAP_MIN_HEALTH = 1;


	static constexpr float LASER_MAX_MASS = 0;
	static constexpr float LASER_MIN_MASS = 0;
	static constexpr float LASER_MAX_G = 0;
	static constexpr float LASER_MIN_G = 0;
	static constexpr float LASER_MAX_GRAVITATION_RANGE = 0;
	static constexpr float LASER_MIN_GRAVITATION_RANGE = 0;
	static constexpr float LASER_MAX_MAXSPEED = 25;
	static constexpr float LASER_MIN_MAXSPEED = 25;
	static constexpr float LASER_MAX_RADIUS = 10;
	static constexpr float LASER_MIN_RADIUS = 10;
	static constexpr float LASER_MAX_HEALTH = 80; 
	static constexpr float LASER_MIN_HEALTH = 80; 
	static constexpr float LASER_DAMAGE = 20;


	static constexpr float POWERUP_MAX_MASS = 0;
	static constexpr float POWERUP_MIN_MASS = 0;
	static constexpr float POWERUP_MAX_G = 0;
	static constexpr float POWERUP_MIN_G = 0;
	static constexpr float POWERUP_MAX_GRAVITATION_RANGE = 0;
	static constexpr float POWERUP_MIN_GRAVITATION_RANGE = 0;
	static constexpr float POWERUP_MAX_MAXSPEED = 0;
	static constexpr float POWERUP_MIN_MAXSPEED = 0;
	static constexpr float POWERUP_MAX_RADIUS = 10;
	static constexpr float POWERUP_MIN_RADIUS = 10;
	static constexpr float POWERUP_MAX_HEALTH = -1;
	static constexpr float POWERUP_MIN_HEALTH = -1;
};

#endif // ACTORSADJUSTMENTS_H
