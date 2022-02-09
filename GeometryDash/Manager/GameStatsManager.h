#ifndef __GAMESTATSMANAGER_H__
#define __GAMESTATSMANAGER_H__

#include "GManager.h"

class CC_DLL GameStatsManager
	: public GManager
{
public:
	~GameStatsManager();
	
	static GameStatsManager *sharedState();
	bool init();
	
	void dataLoaded(DS_Dictionary *dict);
	void encodeDataTo(DS_Dictionary *dict);
	void firstSetup();
	
	bool checkAchievement(const char *statKey);
	int getStat(const char *statKey);
	void incrementStat(const char *statKey);
	cocos2d::CCDictionary *value_;
	
	const char *getLevelKey(int levelID, bool customLevel);
	void completedLevel(int levelID, bool customLevel);
	bool hasCompletedLevel(int levelID, bool customLevel);
	cocos2d::CCDictionary *completed_;
};

#endif //__GAMESTATSMANAGER_H__
