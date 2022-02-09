#ifndef __ACHIEVEMENTNOTIFIER_H__
#define __ACHIEVEMENTNOTIFIER_H__

#include "cocos2d.h"

/* Dropdown bar for displaying unlocked achievements */
class CC_DLL AchievementBar
	: public cocos2d::CCNode
{
public:
	static AchievementBar *create(const char *title, const char *description, const char *icon);
	
	bool init(const char *title, const char *description, const char *icon);
	
	cocos2d::CCLayerColor *internalLayer_;
	/* Position after the end of dropdown animation. */
	float yPos_;
	
	void show();
	
	CC_SYNTHESIZE(CCNode*, targetScene_, TargetScene);
};

class CC_DLL AchievementNotifier
	: public cocos2d::CCNode
{
public:
	~AchievementNotifier();
	
	static AchievementNotifier *sharedState();
	
	bool init();
	void notifyAchievement(const char *title, const char *description, const char *icon);
	
	cocos2d::CCArray *notificationQueue_;
	AchievementBar *showingNotification_;
	
	void showNextAchievement();
	
	/* Automatically called by AppDelegate */
	void willSwitchToScene(cocos2d::CCScene *scene);
};

#endif //__ACHIEVEMENTNOTIFIER_H__
