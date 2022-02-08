#ifndef __SLIDEINLAYER_H__
#define __SLIDEINLAYER_H__

#include "cocos2d.h"

class SlideInLayer;

class CC_DLL SlideInLayerDelegate
{
public:
	virtual void slideInLayerWillExit(SlideInLayer *layer);
};

class CC_DLL SlideInLayer
	: public cocos2d::CCLayerColor
{
public:
	static SlideInLayer *create();
	bool init();
	
	void draw();
	void registerWithTouchDispatcher();
	
	bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchCancelled(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	
	virtual void customSetup();
	virtual void enterLayer();
	virtual void exitLayer();
	virtual void showLayer(bool dontAnimate);
	virtual void hideLayer(bool dontAnimate);
	virtual void layerVisible();
	virtual void layerHidden();
	virtual void enterAnimFinished();
	virtual void disableUI();
	virtual void enableUI();
	virtual void keyBackClicked();
	
	CCLayer *internalLayer_;
	
	cocos2d::CCMenu *menu_;
	
	cocos2d::CCSprite *startBtnSprite_;
	CCMenuItemSpriteExtra *startBtn_;
	
	cocos2d::CCPoint showPosition_;
	cocos2d::CCPoint hidePosition_;
	
	CC_SYNTHESIZE(SlideInLayerDelegate*, delegate_, Delegate);
	CC_SYNTHESIZE(bool, removeOnExit_, RemoveOnExit);
};

#endif //__SLIDEINLAYER_H__
