#include "Line2D.h"

bool Line2D::operator==(const Line2D& other) const
{
	return (*this).mP0 == other.mP0 && this->mP1 == other.mP1;
}

float Line2D::MinDistanceFrom(const Vec2D& point, bool limitToSegment) const
{
	return 0.0f;
}

Vec2D Line2D::ClosestPoint(const Vec2D& point, bool limitToSegment) const
{
	return Vec2D();
}
