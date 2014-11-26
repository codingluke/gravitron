#include "headers/Vec2f.h"

Vec2f::Vec2f()
{
    v[0] = 0;
    v[1] = 0;
}

Vec2f::Vec2f(float x, float y) {
    v[0] = x;
    v[1] = y;
}

float &Vec2f::operator[](int index)
{
    return v[index];
}

float Vec2f::operator[](int index) const
{
    return v[index];
}

Vec2f Vec2f::operator*(float scale) const
{
    return Vec2f(v[0] * scale, v[1] * scale);
}

Vec2f Vec2f::operator/(float scale) const
{
    return Vec2f(v[0] / scale, v[1] / scale);
}

Vec2f Vec2f::operator+(const Vec2f &other)  const{
    return Vec2f(v[0] + other.v[0], v[1] + other.v[1]);
}

Vec2f Vec2f::operator-(const Vec2f &other) const
{
    return Vec2f(v[0] - other.v[0], v[1] - other.v[1]);
}

Vec2f Vec2f::operator-() const
{
    return Vec2f(-v[0], -v[1]);
}

const Vec2f &Vec2f::operator*=(float scale)
{
    v[0] *= scale;
    v[1] *= scale;
    return *this;
}

const Vec2f &Vec2f::operator/=(float scale)
{
    v[0] /= scale;
    v[1] /= scale;
    return *this;
}

const Vec2f &Vec2f::operator+=(const Vec2f &other)
{
    v[0] += other.v[0];
    v[1] += other.v[1];
    return *this;
}

const Vec2f &Vec2f::operator-=(const Vec2f &other)
{
    v[0] -= other.v[0];
    v[1] -= other.v[1];
    return *this;
}

float Vec2f::magnitude() const
{
    return sqrt(v[0] * v[0] + v[1] * v[1]);
}

float Vec2f::magnitudeSquared() const
{
    return v[0] * v[0] + v[1] * v[1];
}

Vec2f Vec2f::normalize() const
{
    float m = sqrt(v[0] * v[0] + v[1] * v[1]);
    return Vec2f(v[0] / m, v[1] / m);
}

float Vec2f::dot(const Vec2f &other) const
{
    return v[0] * other.v[0] + v[1] * other.v[1];
}

Vec2f Vec2f::cross(const Vec2f &other) const
{
    return Vec2f(v[1] * other.v[0] - v[0] * other.v[1],
                 v[0] * other.v[1] - v[1] * other.v[0]);
}

ostream &operator<<(ostream &output, const Vec2f &v)
{
    cout << '(' << v[0] << ", " << v[1] <<  ')';
    return output;
}

Vec2f &Vec2f::operator=(const Vec2f &original)
{
    v[0] = original[0];
    v[1] = original[1];
    return *this;
}

bool Vec2f::operator==(const Vec2f &other) const
{
    bool equal = true;
    for (int i = 0; i < 2; i++)
    {
        if (v[i] != other[i])
            equal = false;
    }
    return equal;
}

bool Vec2f::operator!=(const Vec2f &other) const
{
    return !(*this == other);
}
