#ifndef __SONGSLAYER_H__
#define __SONGSLAYER_H__

#include "GeometryDash/Layer/Misc/GJDropDownLayer.h"

class CC_DLL SongsLayer
	: public GJDropDownLayer
{
public:
	~SongsLayer();
	
	static SongsLayer *create();
	void customSetup();
};

#endif //__SONGSLAYER_H__
