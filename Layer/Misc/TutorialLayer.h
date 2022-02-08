#ifndef __TUTORIALLAYER_H__
#define __TUTORIALLAYER_H__

#include "GeometryDash/Layer/Misc/FLAlertLayer.h"

/* The usual tutorial layer */
class CC_DLL TutorialLayer
	: public FLAlertLayer
{
public:
	static TutorialLayer *create();
	bool init();
	
	void keyBackClicked();
	
	CCLayer *internalLayer_;
	void loadPage(int page);
	int page_;
	void onNext();
	CCMenuItemSpriteExtra *nextPageBtn_;
	void onClose();
	CCMenuItemSpriteExtra *closeBtn_;
};

#endif //__TUTORIALLAYER_H__
