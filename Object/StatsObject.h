#ifndef __STATSOBJECT_H__
#define __STATSOBJECT_H__

#include "cocos2d.h"

class CC_DLL StatsObject
	: public cocos2d::CCObject
{
public:
	static StatsObject *create(const char *key, int value);
	bool init(const char *key, int value);
	
	CC_SYNTHESIZE_READONLY(const char*, key_, Key);
	CC_SYNTHESIZE_READONLY(int, value_, Value);
};

#endif //__STATSOBJECT_H__
