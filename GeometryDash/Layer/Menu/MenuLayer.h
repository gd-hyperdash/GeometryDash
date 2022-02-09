#ifndef __MENULAYER_H__
#define __MENULAYER_H__

#include "../../Object/PlayerObject.h"
#include "../Misc/FLAlertLayer.h"

/* Layer for displaying players in main menu */
class CC_DLL MenuGameLayer
	: public cocos2d::CCLayer
{
public:
	~MenuGameLayer();
	
	static MenuGameLayer *create();
	bool init();
	
	void update(float dt);
	
	void tryJump();
	
	cocos2d::CCPoint backgroundPos_;
	PlayerObject *player_;
	cocos2d::CCSprite *backgroundLayer_;
	cocos2d::CCSprite *groundSquare_;
	CCLayer *groundLayer_;
	float groundWidth_;
	float backgroundWidth_;
};

class CC_DLL MenuLayer
	: public cocos2d::CCLayer,
	public FLAlertLayerProtocol
{
public:
	~MenuLayer();
	
	static cocos2d::CCScene *scene();
	static MenuLayer *node();
	bool init();
	
	void endGame();
	
	void showGCQuestion();
	
	void onPlay();
	void onGarage();
	void onCreator();
	void onGameCenter();
	void onAchievements();
	void onOptions();
	void onStats();
	void onRobTop();
	void onMoreGames();
	
	virtual void keyBackClicked();
	virtual void FLAlert_Clicked(FLAlertLayer *layer, bool accept);
};

#endif //__MENULAYER_H__
