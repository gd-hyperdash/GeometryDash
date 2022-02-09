#ifndef __GJDROPDOWNLAYER_H__
#define __GJDROPDOWNLAYER_H__

#include "GJListLayer.h"

class CC_DLL GJDropDownLayer
	: public cocos2d::CCLayerColor
{
public:
	~GJDropDownLayer();
	
	static GJDropDownLayer *create(const char *title);
	static GJDropDownLayer *create(const char *title, float height);
	bool init(const char *title);
	bool init(const char *title, float height);
	
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
	
	cocos2d::CCPoint endPosition_;
	cocos2d::CCPoint startPosition_;
	
	cocos2d::CCMenu *menu_;
	GJListLayer *listLayer_;
	
	CC_SYNTHESIZE_READONLY(CCLayer*, internalLayer_, InternalLayer);
	CC_SYNTHESIZE(bool, removeOnExit_, RemoveOnExit);
};

#endif //__GJDROPDOWNLAYER_H__
