#ifndef __MOREGAMESLAYER_H__
#define __MOREGAMESLAYER_H__

#include "SlideInLayer.h"

[[deprecated("unused")]] class CC_DLL MoreGamesLayer
	: public SlideInLayer
{
public:
	~MoreGamesLayer();
	
	static MoreGamesLayer *create();
	bool init();
	
	void updateListBGColor(cocos2d::ccColor3B color);
};

#endif //__MOREGAMESLAYER_H__
