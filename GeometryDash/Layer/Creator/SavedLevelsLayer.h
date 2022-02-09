#ifndef __SAVEDLEVELSLAYER_H__
#define __SAVEDLEVELSLAYER_H__

#include "cocos2d.h"

class CC_DLL SavedLevelsLayer
	: public cocos2d::CCLayer
{
public:
	~SavedLevelsLayer();
	
	static cocos2d::CCScene *scene();
	static SavedLevelsLayer *create();
	bool init();
	
	void onBack();
	
	void setupLevelBrowser();
	
	virtual void keyBackClicked();
};

#endif //__SAVEDLEVELSLAYER_H__
