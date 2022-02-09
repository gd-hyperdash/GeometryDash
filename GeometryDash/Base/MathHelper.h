#ifndef __MATHHELPER_H__
#define __MATHHELPER_H__

#include "cocos2d.h"

/* Random integer from min to max */
int randInt(int min, int max);
/* Random number from min to max */
float randRange(float min, float max);
/* Weighted random number from min to max */
int randRangeWeighted(float min, float max);
/* Normalize a vector given as a point */
cocos2d::CCPoint normalize(cocos2d::CCPoint point);
/* Get squared distance between a and b */
float getDistanceSquared(cocos2d::CCPoint a, cocos2d::CCPoint b);

/* Use cocos2d::ccpDistance instead, it's much faster */
float getDistance(cocos2d::CCPoint a, cocos2d::CCPoint b);

/* http://www.paradeofrain.com/2009/07/26/interpolating-2d-rotations/ */
struct Spinor
{
public:
	static Spinor slerp(const Spinor &from, const Spinor &dest, float t);
	float real;
	float complex;
};
/* http://www.paradeofrain.com/2009/07/26/interpolating-2d-rotations/ */
float Slerp2D(float fromAngle, float toAngle, float t);

#endif //__MATHHELPER_H__