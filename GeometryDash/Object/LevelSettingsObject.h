#ifndef __LEVELSETTINGSOBJECT_H__
#define __LEVELSETTINGSOBJECT_H__

#include "cocos2d.h"

class CC_DLL LevelSettingsObject
	: public cocos2d::CCNode
{
public:
	static LevelSettingsObject* create();

#define SYM_objectFromString "_ZN19LevelSettingsObject16objectFromStringESs"

	[[link_name(SYM_objectFromString)]]
	static LevelSettingsObject* objectFromString(gdstd::string object);

#undef SYM_objectFromString

	bool init();

	CC_SYNTHESIZE(cocos2d::ccColor3B, startBGColor_, StartBGColor);
	CC_SYNTHESIZE(cocos2d::ccColor3B, startGColor_, StartGColor);
	CC_SYNTHESIZE(int, audioTrack_, AudioTrack);
};

#endif