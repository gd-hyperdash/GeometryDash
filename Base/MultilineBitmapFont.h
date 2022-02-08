#ifndef __MULTILINEBITMAPFONT_H__
#define __MULTILINEBITMAPFONT_H__

#include "cocos2d.h"

class CC_DLL FontObject
{
public:
	static FontObject *createWithConfigFile(const char *filename, float scale);
	bool initWithConfigFile(const char *filename, float scale);
	
	void parseConfigFile(const char *filename, float scale);
	
	float getFontWidth(int character);
	
	int fontWidths_[300];
};

/* Stores the FontObjects */
class CC_DLL BitmapFontCache
	: public cocos2d::CCNode
{
public:
	~BitmapFontCache();
	
	static BitmapFontCache *sharedFontCache();
	[[deprecated("unused")]] static void purgeSharedFontCache();
		
	FontObject *fontWithConfigFile(const char *filename, float scale);
	
	cocos2d::CCDictionary *fonts_;
};

/* Stores information about a colored text section */
class CC_DLL ColoredSection
	: public cocos2d::CCObject
{
public:
	static ColoredSection *create(cocos2d::ccColor3B col, int startPos, int endPos);
	
	bool init(cocos2d::ccColor3B col, int startPos, int endPos);
	
	CC_SYNTHESIZE(cocos2d::ccColor3B, col_, Col);
	CC_SYNTHESIZE(int, startPos_, StartPos);
	CC_SYNTHESIZE(int, endPos_, endPos);
};

class CC_DLL MultilineBitmapFont
	: public cocos2d::CCSprite
{
public:
	~MultilineBitmapFont();
	
#define SYM_createWithFont "_ZN19MultilineBitmapFont14createWithFontEPKcSsffN7cocos2d7CCPointEi"

	[[link_name(SYM_createWithFont)]]
	static MultilineBitmapFont *createWithFont(
		const char *font,
		gdstd::string text,
		float scale,
		float maxWidth,
		cocos2d::CCPoint anchorPoint,
		int lineHeight);

#undef SYM_createWithFont

#define SYM_initWithFont "_ZN19MultilineBitmapFont12initWithFontEPKcSsffN7cocos2d7CCPointEi"

	[[link_name(SYM_initWithFont)]]
	bool initWithFont(
		const char *font,
		gdstd::string text,
		float scale,
		float maxWidth,
		cocos2d::CCPoint anchorPoint,
		int lineHeight);

#undef SYM_initWithFont
	
	void setOpacity(GLubyte value);
	
#define SYM_stringWithMaxWidth "_ZN19MultilineBitmapFont18stringWithMaxWidthESsff"

	[[link_name(SYM_stringWithMaxWidth)]]
	gdstd::string stringWithMaxWidth(
		gdstd::string text,
		float maxWidth,
		float scale);

#undef SYM_stringWithMaxWidth
	
	int fontWidths[300];

#define SYM_readColorInfo "_ZN19MultilineBitmapFont13readColorInfoESs"

	[[link_name(SYM_readColorInfo)]]
	gdstd::string readColorInfo(gdstd::string text);

#undef SYM_readColorInfo

	cocos2d::CCArray *colorInfo_;
	cocos2d::CCArray *unused_;
	cocos2d::CCArray *characters_;
	int maxLineWidth_;
	bool stringLoaded_;
	int unused2_;
	CC_SYNTHESIZE_READONLY(float, textHeight_, TextHeight);
	CC_SYNTHESIZE_READONLY(float, textWidth_, TextWidth);
	CC_SYNTHESIZE_READONLY(cocos2d::CCPoint, textPos_, TextPos);
	CC_SYNTHESIZE_READONLY(float, sizeWidth_, SizeWidth);
};

#endif //__MULTILINEBITMAPFONT_H__
