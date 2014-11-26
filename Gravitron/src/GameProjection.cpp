#include "./headers/GameProjection.h"


/**
 * Returns the spherical coordinates for a given GameActor
 * @param  actor the GameActor
 * @return       spherical coordinates [theta, phi]
 */
Vec2f GameProjection::getInclinationAndAzimuth(GameActor &actor) 
{
	double radius = actor.getPosition().magnitude();
	double theta = asin(actor.getPosition().v[2] / radius);
	double phi = atan2(actor.getPosition().v[1], actor.getPosition().v[0]);
	return Vec2f(theta, phi);
}

/**
 * Returns the 2-dimensional coordinates of a GameActor in relation to 
 * another GameActor (most likely the player). Notice that what actually
 * happens is a determination of the spherical coordinates of the two
 * GameActors followed by a subtraction of the anchors coordinates from
 * the other GameActor. This can be seen as a resetting of all GameActors
 * to new positions and especially the anchor (player) to [0,0,1]. By
 * doing this, we can strike the z-coordinate (or use it for scaling later
 * on) and project all GameActors onto a plane which is orthotogonal to 
 * the z-axis ([0,0,1]). The returned Vec2f simply contains the x and y-
 * coordinates of the relocated GameActor. 	
 * @param  anchor the centric GameActor aka the player or view point	
 * @param  other  the other GameActor
 * @return        a 2-dimensional vector storing the x and y coordinates 
 *                  of the other GameActor projected on to a plane 
 *                  perpendicular to the z-axis.
 */
Vec2f GameProjection::get2DCoords(GameActor &anchor, GameActor &other) 
{
	Vec2f anchorVals = getInclinationAndAzimuth(anchor);
	Vec2f otherVals = getInclinationAndAzimuth(other);
	otherVals -= anchorVals;
	float radius = anchor.getPosition().magnitude();
	float x = radius * cos(otherVals.v[0]) * cos(otherVals.v[1]);
	float y = radius * cos(otherVals.v[0]) * sin(otherVals.v[1]);
	return Vec2f(x, y);
}
