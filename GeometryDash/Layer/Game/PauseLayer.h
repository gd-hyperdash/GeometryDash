#ifndef __PAUSELAYER_H__
#define __PAUSELAYER_H__

#include "cocos2d.h"

class CC_DLL PauseLayer
	: public CCBlockLayer
{
public:
	~PauseLayer();
	
	static PauseLayer *create();
	void customSetup();
	
	void keyBackClicked();
	
	void onEdit();
	void onNormalMode();
	void onPracticeMode();
	void onResume();
	void onQuit();
	void onRestart();
	void onMusic();
	void onFX();
	void onAutoCheck();
	void onHelp();
	
	void setupProgressBars();
};

#endif //__PAUSELAYER_H__
