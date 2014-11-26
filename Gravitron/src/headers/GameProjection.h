#ifndef GAME_PROJECTION_H
#define GAME_PROJECTION_H

#include "GameActor.h"
#include "Vec2f.h"

class GameProjection
{

	public:
		static Vec2f getInclinationAndAzimuth(GameActor &actor);
		static Vec2f get2DCoords(GameActor &anchor, GameActor &other);
};
#endif