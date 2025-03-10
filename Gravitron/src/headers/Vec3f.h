#ifndef VEC3F_H
#define VEC3F_H

#include <iostream>
#include <cmath>

using std::ostream;
using std::cout;
using std::cin;
using std::endl; 

/**
 * This class represents 3-dimensional vectors in euclidian vector space. It implements
 * all common operations, such as determining the magnitudes of vetors, normalizing them,
 * determining the cross of any two vectors or the dot product. Also vectors may be
 * compared, but this comparison is only reliable to a certain degree, determined by
 * the public precision constant. 
 */
class Vec3f {
    public:
        float v[3];
        const float precision = 0.0000001;
    public:
        Vec3f();
        Vec3f(float x, float y, float z); 
        float &operator[](int index);
        float operator[](int index) const; 
        Vec3f operator*(float scale) const;
        Vec3f operator/(float scale) const;
        Vec3f operator+(const Vec3f &other) const;
        Vec3f operator-(const Vec3f &other) const;
        Vec3f operator-() const; 
        const Vec3f &operator*=(float scale);
        const Vec3f &operator/=(float scale);
        const Vec3f &operator+=(const Vec3f &other);
        const Vec3f &operator-=(const Vec3f &other); 
        float magnitude() const;
        float magnitudeSquared() const;
        Vec3f normalize() const;
        float dot(const Vec3f &other) const;
        Vec3f cross(const Vec3f &other) const;
        Vec3f &operator=(const Vec3f &original);
        bool operator==(const Vec3f &other) const;
        bool operator!=(const Vec3f &other) const;
};

#endif
