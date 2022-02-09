#ifndef __SONGOBJECT_H__
#define __SONGOBJECT_H__

#include "cocos2d.h"

/* Why does this even have a separate header */
class CC_DLL SongObject
	: public cocos2d::CCObject
{
public:
	static SongObject *create(int audioTrack);
	bool init(int audioTrack);
	
	CC_SYNTHESIZE_READONLY(int, audioTrack_, AudioTrack);
};

#endif //__SONGOBJECT_H__
