#ifndef __UILAYER_H__
#define __UILAYER_H__

#include "cocos2d.h"

class CC_DLL UILayer
	: public cocos2d::CCLayerColor
{
public:
	~UILayer();
	
	static UILayer *create();
	bool init();
	
	void draw();
	
	void pCommand(cocos2d::CCNode *button);
	
	void enableMenu();
	void disableMenu();
	
	cocos2d::CCMenu *checkpointsMenu_;
	void toggleCheckpointsMenu();
	void onCheck();
	void onDeleteCheck();
	
	int unused1_;
	
	CCMenuItemSpriteExtra *pauseBtn_;
	void onPause();
	
	int unused2_;
	
	virtual void keyBackClicked();
	
	void registerWithTouchDispatcher();
	bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchCancelled(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	
	CC_SYNTHESIZE_READONLY(float, clkTimer_, ClkTimer);
};

#endif //__UILAYER_H__
