#pragma once

#include <iostream>
using namespace std;

class Vec2D {
public:
    static const Vec2D sZero;

    Vec2D() :Vec2D(0, 0) {}
    Vec2D(float x, float y) : mX(x), mY(y) {}

    inline float GetX()const { return mX; };
    inline float GetY()const { return mY; };
    void  SetX(float x) { mX = x; }
    void  SetY(float y) { mY = y; }

    friend ostream& operator<<(ostream& consoleOut, const Vec2D& vec);
    bool operator==(const Vec2D& other)const;
    bool operator!=(const Vec2D& other)const;

    //operations on vectors
    Vec2D operator-()const;//negating vector
    Vec2D operator*(float scale)const;//multiplication by scale(NO changing vector)
    Vec2D operator/(float scale)const;//dividing by scale(NO changing vector)
    Vec2D& operator*=(float scale);//multiplication by scale(changing vector)
    Vec2D& operator/=(float scale);//dividing by scale(changing vector)
    friend Vec2D operator*(float scale, const Vec2D& vec);//to be able to multiply scale * vec2D
    Vec2D operator+(const Vec2D& other)const;//adding two vectors(No changing)
    Vec2D operator-(const Vec2D& other)const;
    Vec2D& operator+=(const Vec2D& other);
    Vec2D& operator-=(const Vec2D& other);
    float Mag2()const;
    float Mag()const;//length of the vector
    Vec2D GetUnitVec()const;// to get unit vector(length = 1) based on our vector
    Vec2D& Normalize();
    float Distance(const Vec2D& other)const;
    float Dot(const Vec2D& other)const;
    Vec2D ProjectOnto(const Vec2D& other)const;
    float AngleBetween(const Vec2D& other)const;
    Vec2D Reflect(const Vec2D& normal)const;
    void Rotate(float angle, const Vec2D& aroundPoint);
    Vec2D RotationResult(float angle, const Vec2D& aroundPoint)const;
private:
    float mX;
    float mY;

};
