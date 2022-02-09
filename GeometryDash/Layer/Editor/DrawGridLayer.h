#ifndef __DRAWGRIDLAYER_H__
#define __DRAWGRIDLAYER_H__

#include "../../Object/GameObject.h"

/* The editor grid */
class CC_DLL DrawGridLayer
	: public cocos2d::CCLayer
{
public:
	~DrawGridLayer();
	
	static DrawGridLayer *create(CCNode *parent);
	bool init(CCNode *parent);
	
	void draw();
	
	void loadBPM(float bpm);

#define SYM_loadMarkers "_ZN13DrawGridLayer11loadMarkersESs"

	[[link_name(SYM_loadMarkers)]]
	void loadMarkers(gdstd::string markers);

#undef SYM_loadMarkers

#define SYM_loadTimeMarkers "_ZN13DrawGridLayer15loadTimeMarkersESs"

	[[link_name(SYM_loadTimeMarkers)]]
	void loadTimeMarkers(gdstd::string timeMarkers);

#undef SYM_loadTimeMarkers
	
	void removeFromEffects(GameObject *effectObject);
	
	CCNode *parent_;
	cocos2d::CCArray *timeMarkers_;
	cocos2d::CCArray *effects_;
	double bpmMarkerDistance_;
	float timeMod_;
};

#endif //__DRAWGRIDLAYER_H__
