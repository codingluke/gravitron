#ifndef VEC3F_HEADER
#define VEC3F_HEADER

#include <iostream>
#include <cmath>
/**
*   part source: programmng-techniques.com
*/

using std::ostream;
using std::cout;
using std::cin;
using std::endl; 
class Vec3f {
    public:
        float v[3];
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
