#ifndef VEC2F_HEADER
#define VEC2F_HEADER

#include <iostream>
#include <cmath>
/**
*   part source: programmng-techniques.com
*/

using std::ostream;
using std::cout;
using std::cin;
using std::endl; 
class Vec2f {
    public:
        float v[2];
    public:
        Vec2f();
        Vec2f(float x, float y); 
        float &operator[](int index);
        float operator[](int index) const; 
        Vec2f operator*(float scale) const;
        Vec2f operator/(float scale) const;
        Vec2f operator+(const Vec2f &other) const;
        Vec2f operator-(const Vec2f &other) const;
        Vec2f operator-() const; 
        const Vec2f &operator*=(float scale);
        const Vec2f &operator/=(float scale);
        const Vec2f &operator+=(const Vec2f &other);
        const Vec2f &operator-=(const Vec2f &other); 
        float magnitude() const;
        float magnitudeSquared() const;
        Vec2f normalize() const;
        float dot(const Vec2f &other) const;
        Vec2f cross(const Vec2f &other) const;
        Vec2f &operator=(const Vec2f &original);
        bool operator==(const Vec2f &other) const;
        bool operator!=(const Vec2f &other) const;
};

#endif
