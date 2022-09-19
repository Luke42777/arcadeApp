#pragma once
#include "Vec2D.h"
class Line2D
{
	Vec2D mP0;
	Vec2D mP1;

public:
	Line2D();
	Line2D(const Vec2D& p0,const Vec2D& p1);
	Line2D(float x0, float y0, float x1, float y1);

	inline  const Vec2D& GetP0()const { return mP0; }
	inline  const Vec2D& GetP1()const { return mP1; }
	inline void SetP0(const Vec2D& p0) { mP0 = p0; }
	inline void SetP1(const Vec2D& p1) {mP1 = p1; }

	bool operator==(const Line2D& other)const; 
	float MinDistanceFrom(const Vec2D& point, bool limitToSegment = false)const;
	Vec2D ClosestPoint(const Vec2D& point, bool limitToSegment = false)const;

	Vec2D MidPoint()const;
	float Slope()const;
	float Length()const;


};

