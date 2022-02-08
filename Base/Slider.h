#ifndef __SLIDER_H__
#define __SLIDER_H__

#include "cocos2d.h"

class CC_DLL SliderThumb
	: public cocos2d::CCMenuItemImage
{
public:
	static SliderThumb *create(cocos2d::CCNode *target, cocos2d::SEL_MenuHandler selector, const char *normalImage, const char *selectedImage);
	bool init(cocos2d::CCNode *target, cocos2d::SEL_MenuHandler selector, const char *normalImage, const char *selectedImage);
	
	float getValue();
	void setValue(float value);
};

class Slider;

class CC_DLL SliderTouchLogic
	: public cocos2d::CCMenu
{
public:
	static SliderTouchLogic *create(cocos2d::CCNode *target, cocos2d::SEL_MenuHandler selector, const char *normalThumbImage, const char *selectedThumbImage);
	bool init(cocos2d::CCNode *target, cocos2d::SEL_MenuHandler selector, const char *normalThumbImage, const char *selectedThumbImage);
	
	CC_SYNTHESIZE_READONLY(SliderThumb*, thumb_, Thumb);
	CC_SYNTHESIZE(Slider*, sliderDelegate_, Slider);
	CC_SYNTHESIZE(bool, liveDragging_, LiveDragging);
};

class CC_DLL Slider
	: public cocos2d::CCLayer
{
public:
	static Slider *create(cocos2d::CCNode *target, cocos2d::SEL_MenuHandler selector);
	static Slider *create(cocos2d::CCNode *target, cocos2d::SEL_MenuHandler selector, const char *sliderBarFrame, const char *sliderGrooveFrame, const char *sliderThumbFrame, const char *sliderThumbSelFrame);
	
	[[deprecated("unused")]] bool getLiveDragging();
	SliderThumb *getThumb();
	float getValue();
	
	void setBarVisibility(bool value);
	void setLiveDragging(bool value);
	void setValue(float value);
	
	void updateBar();
	
	bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchCancelled(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	
	SliderTouchLogic *touchLogic_;
	cocos2d::CCSprite *sliderBar_;
	float sliderScale_;
	float sliderWidth_;
};

#endif //__SLIDER_H__
