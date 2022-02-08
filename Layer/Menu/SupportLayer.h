#ifndef __SUPPORTLAYER_H__
#define __SUPPORTLAYER_H__

#include "GeometryDash/Layer/Misc/GJDropDownLayer.h"

class CC_DLL SupportLayer
	: public GJDropDownLayer
{
public:
	~SupportLayer();
	
	static SupportLayer *create();
	void customSetup();
	
	void exitLayer();
	
	void onCocos2d();
	void onEmail();
	void onRobTop();
};

#endif //__SUPPORTLAYER_H__
