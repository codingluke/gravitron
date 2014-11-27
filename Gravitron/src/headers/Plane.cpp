#include "headers/Plane.h"

Plane::Plane() 
{

}

Plane::Plane(const Plane &plane)
{
	a = plane.a;
	b = plane.b;
	c = plane.c;
	d = plane.d;
}

Plane::Plane(float a, float b, float c, float d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

Plane::Plane(const Vec3f &normalizedNormal, float d)
{
	a = normalizedNormal.a;
	b = normalizedNormal.b;
	c = normalizedNormal.c;
	this->d = d;
}

Plane Plane::fromPointAndNormal(const Vec3f &point, const Vec3f normal)
{
	Plane plane;
	Vec3f normalizedNormal = normal.normalize();
	plane.a = normalizedNormal.v[0];
	plane.b = normalizedNormal.v[1];
	plane.c = normalizedNormal.v[2];
	plane.d = -normalizedNormal.dot(point);
	return plane;
}

Plane Plane::fromPointAndVectors(const Vec3f &point, const Vec3f &vec1, const Vec3f &vec2)
{
	Vec3f normal = vec1.cross(vec2);
	return fromPointAndNormal(point, normal);
}

Plane Plane::fromPoints(const Vec3f &point1, const Vec3f &point2, const Vec3f &point3)
{
	Vec3f normal = ((point2 - point1).cross(point3 - point1)).normalize();
    return fromPointAndNormal(point1, Normal);
}

float Plane::getUnsignedDistance(const Vec3f &point) const
{
	return Math::Abs(getSignedDistance(point));
}

float Plane::getSignedDistance(const Vec3f &point) const
{
	return (a * point.v[0] + b * point.v[1] + c * point.v[2] + d);
}
    
Vec3f Plane::getClosestPoint(const Vec3f &Point)
{
	return (Point - getNormal() * SignedDistance(Point));
}

Vec3f Plane::getIntersectingLine(const Vec3f &vec1, const Vec3f &vec2) const
{
	Vec3f difference = vec1 - vec2;
    float denominator = a * difference.x + b * difference.y + c * difference.z;
    if(denominator == 0.0f)
    {
        return (vec1 + vec2) * 0.5f;
    }
    float u = (a * vec1.x + b * vec1.y + c * vec1.z + d) / denominator;

    return (vec1 + u * (vec2 - vec1));
}

Vec3f Plane::getNormal() const
    {
        return Vec3f(a, b, c);
    }

Plane Plane::normalize()
{
	Plane plane;
	float dist = sqrt(a * a + b * b + c * c);
	plane.a = a / dist;
	plane.b = b / dist;
	plane.c = c / dist;
	plane.d = d / dist;
	return plane;
}