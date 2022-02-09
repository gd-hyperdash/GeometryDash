#ifndef __CREATORLAYER_H__
#define __CREATORLAYER_H__

#include "cocos2d.h"

/* Main menu for user-created levels */
class CC_DLL CreatorLayer
	: public cocos2d::CCLayer
{
public:
	~CreatorLayer();
	
	static cocos2d::CCScene *scene();
	static CreatorLayer *create();
	bool init();
	
	virtual void keyBackClicked();
	
	void onBack();
	
	void onMyLevels();
	void onSavedLevels();
	void onFeaturedLevels();
	void onOnlineLevels();
};

#endif //__CREATORLAYER_H__
