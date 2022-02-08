#ifndef __ACHIEVEMENTSLAYER_H__
#define __ACHIEVEMENTSLAYER_H__

#include "GeometryDash/Layer/Misc/GJDropDownLayer.h"

class CC_DLL AchievementsLayer
	: public GJDropDownLayer
{
public:
	~AchievementsLayer();
	
	static AchievementsLayer *create();
	void customSetup();
};

#endif //__ACHIEVEMENTSLAYER_H__
