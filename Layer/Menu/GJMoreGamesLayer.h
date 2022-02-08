#ifndef __GJMOREGAMESLAYER_H__
#define __GJMOREGAMESLAYER_H__

#include "GeometryDash/Layer/Misc/GJDropDownLayer.h"

class CC_DLL GJMoreGamesLayer
	: public GJDropDownLayer
{
public:
	~GJMoreGamesLayer();
	
	static GJMoreGamesLayer *create();
	
	void customSetup();
};

#endif //__GJMOREGAMESLAYER_H__
