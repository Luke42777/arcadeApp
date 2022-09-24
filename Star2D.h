#pragma once
#include "Vec2D.h"
#include "Line2D.h"


class Star2D{
	Vec2D mMidPoint;
	Line2D mLines[9] = {};
	float mBranchLength;

public:
	const Line2D* GetLines()const;
	void SetLine(const Vec2D& midPoint, const Vec2D& p1,size_t index);
	const Vec2D& GetMidPoint()const{return mMidPoint;}
	Star2D(const Vec2D& midPoint, float branchLength);
	Star2D() :Star2D(Vec2D::sZero, 0.0f) {}
	Star2D(const Star2D& other);
	Star2D& operator=(const Star2D& other);


};

