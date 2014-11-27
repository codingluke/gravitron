#ifndef PLANE_H
#define	PLANE_H

#include "Vec3f.h"

class Plane {
private:
	/**
	 * Plane equation: a*x + b*y + c*z + d = 0.
	*/
	float a, b, c, d;
public:
	Plane();
	Plane(const Plane &plane);
	Plane(float a, float b, float c, float d);
	Plane(const Vec3f &normalizedNormal, float d);

	static Plane fromPointAndNormal(const Vec3f &point, const Vec3f normal);
	static Plane fromPointAndVectors(const Vec3f &point, const Vec3f &vec1, const Vec3f &vec2);
	static Plane fromPoints(const Vec3f &point1, const Vec3f &point2, const Vec3f &point3);

	float getUnsignedDistance(const Vec3f &point) const;
	float getSignedDistance(const Vec3f &point) const;
    
    Vec3f getClosestPoint(const Vec3f &Point);

    Vec3f getIntersectingLine(const Vec3f &vec1, const Vec3f &vec2) const;

    Vec3f getNormal() const;

    Plane normalize();
};
#endif
