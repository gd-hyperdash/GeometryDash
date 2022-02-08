#ifndef __MYLEVELSLAYER_H__
#define __MYLEVELSLAYER_H__

#include "cocos2d.h"

class CC_DLL MyLevelsLayer
	: public cocos2d::CCLayer
{
public:
	~MyLevelsLayer();
	
	static cocos2d::CCScene *scene();
	static MyLevelsLayer *create();
	bool init();
	
	void onBack();
	void onNew();
	
	void setupLevelBrowser();
	
	virtual void keyBackClicked();
};

#endif //__MYLEVELSLAYER_H__
