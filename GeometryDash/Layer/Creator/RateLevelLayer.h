#ifndef __RATELEVELLAYER_H__
#define __RATELEVELLAYER_H__

#include "../Misc/FLAlertLayer.h"

class CC_DLL RateLevelDelegate
{
public:
	virtual void rateLevelClosed();
};

class CC_DLL RateLevelLayer
	: public FLAlertLayer
{
public:
	~RateLevelLayer();
	
	static RateLevelLayer *create(int levelID);
	bool init(int levelID);
	
	void keyBackClicked();
	
	void onClose();
	void onRate();
	
	void selectRating(CCNode *button);
	
	CCMenuItemSpriteExtra *rateBtn_;
	cocos2d::CCArray *difficultyButtons_;
	int levelID_;
	int difficulty_;
	CC_SYNTHESIZE(RateLevelDelegate*, delegate_, Delegate);
};

#endif //__RATELEVELLAYER_H__
