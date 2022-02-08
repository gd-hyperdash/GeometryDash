#ifndef __ACHIEVEMENTMANAGER_H__
#define __ACHIEVEMENTMANAGER_H__

#include "cocos2d.h"

class CC_DLL AchievementManager
	: public cocos2d::CCNode
{
public:
	~AchievementManager();
	
	static AchievementManager *sharedState();
	
	bool init();
	
	/* Unused function */
	[[deprecated("unimplemented")]] void setup();
	
	/** \brief Unused function. 
	  * Geometry Dash is originally meant to be a f2p game, and this function is meant to give you appropriate achievements based on purchased items. As of now, it does nothing and isn't used anywhere.
	  */
	[[deprecated("unimplemented")]] void checkAchievementFromUnlock(const char *unlock);
	
	/* Contains achievement description. Each item is a dictionary with following CCString fields: identifier, (optional) icon, title, achievedDescription, unachievedDescription, order */
	cocos2d::CCDictionary *achievementsDesc_;
	[[deprecated("unimplemented")]] int unused_;
	/* Get achievement description by its id. */
	cocos2d::CCDictionary *getAchievementsWithID(const char *id);
	/** Get achievement list.
	  * \return Ordered achievement list.
	  */
	cocos2d::CCArray *getAllAchievements();
	
	bool isAchievementEarned(const char *id);
	/** Checks if the achievemnts in the array are earned.
	  * \param achievements CCString array with achievement IDs.
	  * \return The check result
	  */
	bool areAchievementsEarned(cocos2d::CCArray *achievements);
	
	/* Show achievement complete notification to player */
	void notifyAchievementWithID(const char *id);
	
	/* Get achievement progress percentage */
	int percentForAchievement(const char *id);
	[[deprecated("unused")]] int percentageForCount(int count, int totalCount);
	
	void reportAchievementWithID(const char *id, int percentage);
	
	void resetAchievements();
	
	CC_SYNTHESIZE(cocos2d::CCDictionary*, reportedAchievements_, ReportedAchievements);
};

#endif //__ACHIEVEMENTMANAGER_H__
