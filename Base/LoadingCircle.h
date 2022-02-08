#ifndef __LOADINGCIRCLE_H__
#define __LOADINGCIRCLE_H__

#include "cocos2d.h"

class CC_DLL LoadingCircle
	: public cocos2d::CCLayerColor
{
public:
	static LoadingCircle *create();
	bool init();
	
	void draw();
	
	void show();
	void fadeAndRemove();
	
	CC_SYNTHESIZE_READONLY(cocos2d::CCSprite*, circle_, Circle);
	CC_SYNTHESIZE(cocos2d::CCNode*, targetScene_, TargetScene);
	CC_SYNTHESIZE(bool, darkOverlay_, DarkOverlay);
	
	void registerWithTouchDispatcher();
	bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

#endif //__LOADINGCIRCLE_H__
