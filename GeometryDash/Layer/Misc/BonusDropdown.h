#ifndef __BONUSDROPDOWN_H__
#define __BONUSDROPDOWN_H__

#include "cocos2d.h"

[[deprecated("unused")]] class CC_DLL PriceLabel
	: public cocos2d::CCNode
{
public:
	static PriceLabel *create(int price);
	bool init(int price);
	
	void setPrice(int price);
	
	void setColor(cocos2d::ccColor3B color);
	void setOpacity(float value);
	
	cocos2d::CCLabelBMFont *label_;
	cocos2d::CCSprite *coinSprite_;
};

/* Unused class used to notify player about new bonuses */
[[deprecated("unused")]] class CC_DLL BonusDropdown
	: public cocos2d::CCNode
{
public:

#define SYM_create "_ZN13BonusDropdown6createESsi"

	[[link_name(SYM_create)]]
	static BonusDropdown *create(
		gdstd::string title,
		int amount);

#undef SYM_create
	
#define SYM_init "_ZN13BonusDropdown4initESsi"

	[[link_name(SYM_init)]]
	bool init(
		gdstd::string title,
		int amount);

#undef SYM_init
	
	cocos2d::CCLayerColor *internalLayer_;
	/* Position after the end of dropdown animation. */
	float yPos_;
	
	void show();
	
	CC_SYNTHESIZE(CCNode*, targetScene_, TargetScene);
};

#endif //__BONUSDROPDOWN_H__
