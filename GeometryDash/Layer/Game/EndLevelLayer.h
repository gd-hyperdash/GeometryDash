#ifndef __ENDLEVELLAYER_H__
#define __ENDLEVELLAYER_H__

#include "../Misc/GJDropDownLayer.h"

class CC_DLL EndLevelLayer
	: public GJDropDownLayer
{
public:
	~EndLevelLayer();
	
	static EndLevelLayer *create();
	bool init();
	
	void customSetup();
	void exitLayer();
	
	const char *getEndText();
	
	void onMenu();
	void onReplay();
	
	void showLayer(bool dontAnimate);
	
	cocos2d::CCMenu *menu_;
};

#endif //__ENDLEVELLAYER_H__
