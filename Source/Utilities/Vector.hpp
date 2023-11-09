#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector2
{
public:
    float x;
    float y;

    Vector2(float x, float y) : x(x), y(y) {};
    Vector2() : x(0), y(0) {};
    ~Vector2() {};

    Vector2 operator+(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(const Vector2& other) const
    {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 operator*(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator/(const Vector2& other) const
    {
        return Vector2(x / other.x, y / other.y);
    }

    Vector2 New(Vector2 data)
    {
        return Vector2(data.x, data.y);
    }
};

#endif