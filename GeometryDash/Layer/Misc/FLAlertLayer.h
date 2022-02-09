#ifndef __FLALERTLAYER_H__
#define __FLALERTLAYER_H__

#include "cocos2d.h"

class FLAlertLayer;

class CC_DLL FLAlertLayerProtocol
{
public:
	virtual void FLAlert_Clicked(FLAlertLayer *layer, bool accept);
};

/* Floating alert layer. By default it's a message box that returns user's choice to the delegate, but you can extend it to create any kind of floating layers */
class CC_DLL FLAlertLayer
	: public cocos2d::CCLayerColor
{
public:
	static FLAlertLayer *create(FLAlertLayerProtocol *delegate, const char *title, const char *text, const char *btn1Text, const char *btn2Text);
	static FLAlertLayer *create(FLAlertLayerProtocol *delegate, const char *title, const char *text, const char *btn1Text, const char *btn2Text, float layerHeight);
	bool init(FLAlertLayerProtocol *delegate, const char *title, const char *text, const char *btn1Text, const char *btn2Text, float layerHeight);
	
	void registerWithTouchDispatcher();
	
	void onBtn1();
	void onBtn2();
	
	virtual void show();
	virtual void keyBackClicked();
	
	CC_SYNTHESIZE(FLAlertLayerProtocol*, pParent_, PParent);
	CC_SYNTHESIZE(CCNode*, targetScene_, TargetScene);
	CC_SYNTHESIZE(bool, reverseKeyBack_, ReverseKeyBack);
	CC_SYNTHESIZE(CCLayer*, internalLayer_, InternalLayer);
};

#endif //__FLALERTLAYER_H__
