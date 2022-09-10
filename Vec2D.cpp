
#include "Vec2D.h"
#include "Utils.h"
#include <cassert>
#include <cmath>
using namespace std;

const Vec2D Vec2D::sZero;

ostream& operator<<(ostream& consoleOut, const Vec2D& vec) {
	consoleOut << "X: " << vec.mX << ",Y: " << vec.mY << endl;
	return consoleOut;
}

bool Vec2D::operator==(const Vec2D& other)const {
	return IsEqual(this->mX, other.mX) && IsEqual(this->mY, other.mY);
}
bool Vec2D::operator!=(const Vec2D& other)const {
	return !(*this == other);
}
//operations on vector
Vec2D Vec2D::operator-()const {
	return Vec2D(-mX, -mY);
}
Vec2D Vec2D::operator*(float scale)const {
	return Vec2D(scale * mX, scale * mY);
}
Vec2D Vec2D::operator/(float scale)const {
	assert(scale > EPSILON);
	return Vec2D(mX / scale, mY / scale);
}
Vec2D& Vec2D::operator*=(float scale) {
	*this = (*this) * scale;
	return *this;
}
Vec2D& Vec2D::operator/=(float scale) {
	*this = *this / scale;
	return *this;
}
Vec2D operator*(float scale, const Vec2D& vec) {
	return vec * scale;
}
Vec2D Vec2D::operator+(const Vec2D& other)const {
	return Vec2D(mX + other.mX, mY + other.mY);
}
Vec2D Vec2D::operator-(const Vec2D& other)const {
	return Vec2D(mX - other.mX, mY - other.mY);
}
Vec2D& Vec2D::operator+=(const Vec2D& other) {
	*this = *this + other;
	return *this;
}
Vec2D& Vec2D::operator-=(const Vec2D& other) {
	*this = *this - other;
	return *this;
}
float Vec2D::Mag2()const {
	return Dot(*this);
}
float Vec2D::Mag()const {
	return sqrt(Mag2());
}
Vec2D Vec2D::GetUnitVec()const {
	float mag = Mag();

	if (mag > EPSILON) {
		return *this / mag;
	}
	return sZero;
}
Vec2D& Vec2D::Normalize() {
	float mag = Mag();

	if (mag > EPSILON) {
		return *this /= mag;
	}
	return *this;
}
float Vec2D::Distance(const Vec2D& other)const {
	return (other - *this).Mag();
}
float Vec2D::Dot(const Vec2D& other)const {
	return mX * other.mX + mY * other.mY;
}
Vec2D Vec2D::ProjectOnto(const Vec2D& other)const {
	Vec2D unitOther = other.GetUnitVec();
	float dot = this->Dot(other);
	return unitOther * dot;
}
float Vec2D::AngleBetween(const Vec2D& other)const {
	return acosf(GetUnitVec().Dot(other.GetUnitVec()));
}
Vec2D Vec2D::Reflect(const Vec2D& normal)const {
	// v - 2(v dot n)n
	//(v dot n)n = v.ProjectOnto(n)
	return *this - 2 * ProjectOnto(normal);
}

void Vec2D::Rotate(float angle, const Vec2D& aroundPoint) {
	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vec2D thisVec(mX, mY);

	thisVec -= aroundPoint;

	float xRot = thisVec.mX * cosine - thisVec.mY * sine;
	float yRot = thisVec.mX * sine + thisVec.mY * cosine;

	Vec2D rot = Vec2D(xRot, yRot);

	*this = rot + aroundPoint;
}
Vec2D Vec2D::RotationResult(float angle, const Vec2D& aroundPoint)const {
	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vec2D thisVec(mX, mY);

	thisVec -= aroundPoint;

	float xRot = thisVec.mX * cosine - thisVec.mY * sine;
	float yRot = thisVec.mX * sine + thisVec.mY * cosine;

	Vec2D rot = Vec2D(xRot, yRot);

	return  rot + aroundPoint;
}





