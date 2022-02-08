#ifndef __BUTTONSPRITE_H__
#define __BUTTONSPRITE_H__

#include "cocos2d.h"

enum ButtonSpriteType
{
	kButtonSpriteImage,
	kButtonSpriteText
};

/* Used for creating button sprites */
class CC_DLL ButtonSprite
	: public cocos2d::CCSprite
{
public:
	static ButtonSprite *create(const char *text);
	static ButtonSprite *create(const char *text, float scale);
	static ButtonSprite *create(const char *text, int buttonWidth, int widthLimit, float scale, bool limitWidth);
	static ButtonSprite *create(const char *text, int buttonWidth, int widthLimit, float scale, bool limitWidth, const char *font, const char *backgroundFrame);
	static ButtonSprite *create(const char *text, int buttonWidth, int widthLimit, float scale, bool limitWidth, const char *font, const char *backgroundFrame, float labelHeight);
	bool init(const char *text, int buttonWidth, int widthLimit, float scale, bool limitWidth, const char *font, const char *backgroundFrame, float labelHeight);
	
	static ButtonSprite *create(CCSprite *sprite);
	static ButtonSprite *create(CCSprite *sprite, int buttonWidth, int widthLimit, float spriteHeight, float scale, bool limitWidth);
	static ButtonSprite *create(CCSprite *sprite, int buttonWidth, int widthLimit, float spriteHeight, float scale, bool limitWidth, const char *backgroundFrame);
	bool init(CCSprite *sprite, int buttonWidth, int widthLimit, float spriteHeight, float scale, bool limitWidth, const char *backgroundFrame);
	
	void setColor(cocos2d::ccColor3B color);
	void updateBGImage(const char *backgroundFrame);
	void updateSpriteBGSize();
protected:
	ButtonSpriteType buttonType_;
	float buttonWidth_;
	float widthLimit_;
	float maxLabelScale_;
	float spriteHeight_;
	bool dontLimitWidth_;
	cocos2d::CCLabelBMFont *label;
	CCSprite *sprite;
	cocos2d::extension::CCScale9Sprite *background;
	cocos2d::CCPoint labelOffset;
	gdstd::string text;
};

#endif //__BUTTONSPRITE_H__
