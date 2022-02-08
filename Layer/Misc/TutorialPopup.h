#ifndef __TUTORIALPOPUP_H__
#define __TUTORIALPOPUP_H__

#include "cocos2d.h"

/* Called in GameManager::showTutorial, but GameManager::showTutorial itself never gets called */
[[deprecated("unused")]] class CC_DLL TutorialPopup
{
	~TutorialPopup();
	
	static TutorialPopup *create(const char *frame);
	bool init(const char *frame);
	
	void keyBackClicked();
	
	void registerForCallback(cocos2d::SEL_CallFuncO callback);
	void show();
	
	const char *frame_;
	bool registeredCallback_;
	cocos2d::SEL_MenuHandler callback_;
	CCMenuItemSpriteExtra *nextBtn_;
};

#endif //__TUTORIALPOPUP_H__
