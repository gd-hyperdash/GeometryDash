#ifndef __GJLISTLAYER_H__
#define __GJLISTLAYER_H__

#include "GeometryDash/Base/BoomListView.h"

class CC_DLL GJListLayer
	: public cocos2d::CCLayerColor
{
public:
	~GJListLayer();
	
	static GJListLayer *create(BoomListView *listView, const char *title, cocos2d::ccColor4B color, float width, float height);
	bool init(BoomListView *listView, const char *title, cocos2d::ccColor4B color, float width, float height);
};

#endif //__GJLISTLAYER_H__
