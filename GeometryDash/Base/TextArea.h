#ifndef __TEXTAREA_H__
#define __TEXTAREA_H__

#include "MultilineBitmapFont.h"

class CC_DLL TextArea
	: public cocos2d::CCSprite
{
public:
	static TextArea *create(const char *str, float areaWidth, int order, cocos2d::CCPoint align, const char *font);
	static TextArea *create(const char *str, float areaWidth, int order, cocos2d::CCPoint align, const char *font, float lineSpace);
	bool init(const char *str, float areaWidth, int order, cocos2d::CCPoint align, const char *font, float lineSpace);
	
	void draw();
	[[deprecated("unused")]] void fadeIn(float duration, bool unused);
	[[deprecated("unused")]] void fadeOut(float duration);
	[[deprecated("unused")]] void fadeOutAndRemove(float duration);
	[[deprecated("unused")]] void showAll();
	void hideAll();
	void stopAllCharacterActions();
	
	void finishFade();
	
	void setString(const char *str);
	
	MultilineBitmapFont *bitmapFont_;
	float areaWidth_;
	int unused_;
	const char *font_;
	CC_SYNTHESIZE(int, order_, Order);
	CC_SYNTHESIZE(float, lineSpace_, LineSpace);
	CC_SYNTHESIZE(bool, onTimer_, OnTimer);
	CC_SYNTHESIZE(cocos2d::CCPoint, align_, Align);
	CC_SYNTHESIZE(bool, fadeInFinished_, FadeInFinished);
	CC_SYNTHESIZE_READONLY(float, textHeight_, TextHeight);
	CC_SYNTHESIZE_READONLY(float, textWidth_, TextWidth);
	CC_SYNTHESIZE_READONLY(float, sizeWidth_, SizeWidth);
	CC_SYNTHESIZE_READONLY(cocos2d::CCPoint, textPosition_, TextPosition);
};

#endif //__TEXTAREA_H__
