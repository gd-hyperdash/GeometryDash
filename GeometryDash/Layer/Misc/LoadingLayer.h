#ifndef __LOADINGLAYER_H__
#define __LOADINGLAYER_H__

#include "../../Base/TextArea.h"

class CC_DLL LoadingLayer
	: public cocos2d::CCLayer
{
public:
	~LoadingLayer();
	
	static cocos2d::CCScene *scene();
	static LoadingLayer *node();
	bool init();
	
	const char *getLoadingString();
	
	bool unused_;
	bool loadingStarted_;
	
	void loadingFinished();
	
	void loadAssets();
	void updateProgress(int percentage);
	
	int loadProgress_;
	cocos2d::CCLabelBMFont *loadingLabel_;
	TextArea *loadingTextArea_;
	cocos2d::CCSprite *sliderBar_;
	float sliderLength_;
	float sliderHeight_;
};

#endif //__LOADINGLAYER_H__
