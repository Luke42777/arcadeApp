
#include "Star2D.h"

 const Line2D* Star2D::GetLines()const {
	return mLines;
}

 void Star2D::SetLine(const Vec2D& midPoint, const Vec2D& p1,size_t index){
	 mLines[index] = Line2D(midPoint, p1);
 }

Star2D::Star2D(const Vec2D& midPoint, float branchLength){
	mMidPoint = midPoint;
	mBranchLength = branchLength;

	Vec2D p1 = Vec2D(mMidPoint.GetX() ,mMidPoint.GetY() + mBranchLength);

	
	for (size_t i = 0; i < 9; i++) {
		p1.Rotate(30.0f, mMidPoint);
		mLines[i] = Line2D(mMidPoint, p1);
	}
	
}

Star2D::Star2D(const Star2D& other){
	mBranchLength = other.mBranchLength;
	mMidPoint = other.mMidPoint;
}

Star2D& Star2D::operator=(const Star2D& other){
	mBranchLength = other.mBranchLength;
	mMidPoint = other.mMidPoint;
	return *this;
}

