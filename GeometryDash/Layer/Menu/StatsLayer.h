#ifndef __STATSLAYER_H__
#define __STATSLAYER_H__

#include "../Misc/GJDropDownLayer.h"

class CC_DLL StatsLayer
	: public GJDropDownLayer
{
public:
	~StatsLayer();
	
	static StatsLayer *create();
	void customSetup();
};

#endif //__STATSLAYER_H__
