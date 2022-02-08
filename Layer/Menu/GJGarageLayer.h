#ifndef __GJGARAGELAYER_H__
#define __GJGARAGELAYER_H__

#include "GeometryDash/Layer/Misc/FLAlertLayer.h"
#include "GeometryDash/Object/PlayerObject.h"

enum UnlockType
{
	kUnlockNone,
	kUnlockIcon,
	kUnlockColor,
	kUnlockColor2
};

class CC_DLL GameRateDelegate
{
public:
	virtual void updateRate();
};

/* A layer for viewing and changing player looks */
class CC_DLL GJGarageLayer
	: public cocos2d::CCLayer,
	public TextInputDelegate,
	public FLAlertLayerProtocol,
	public GameRateDelegate
{
public:
	~GJGarageLayer();
	
	static cocos2d::CCScene *scene();
	static GJGarageLayer *node();
	bool init();
	
	/* Check if the color is unlocked */
	bool checkColor(int color, bool mainColor);
	/* Check if the icon is unlocked */
	bool checkIcon(int icon);
	
	/* Show the popup with unlock requirement */
	void showUnlockPopup(int idx, UnlockType type);

#define SYM_descriptionForUnlock "_ZN13GJGarageLayer20descriptionForUnlockEi10UnlockType"

	[[link_name(SYM_descriptionForUnlock)]]
	gdstd::string descriptionForUnlock(
		int idx,
		UnlockType type);

#undef SYM_descriptionForUnlock
	
	void onBack();
	void onPlayerColor1(CCNode *button);
	void onPlayerColor2(CCNode *button);
	void onPlayerIcon(CCNode *button);
	
	void setupColorSelect();
	void setupPlayerSelect();
	
	void updatePlayerColors();
	void updatePlayerName(const char *name);
	
	virtual void textInputOpened(CCTextInputNode *textInput);
	virtual void textInputClosed(CCTextInputNode *textInput);
	virtual void textChanged(CCTextInputNode *textInput);
	
	virtual void updateRate();
	
	virtual void FLAlert_Clicked(FLAlertLayer *layer);
	
	virtual void keyBackClicked();
	
	PlayerObject *player_;
	cocos2d::CCSprite *playerSelect_;
	cocos2d::CCSprite *color1Select_;
	cocos2d::CCSprite *color2Select_;
	/* The icon awarded for rating game */
	cocos2d::CCSprite *rateIcon_;
	float barHeight_;
	float barPosition_;
};

#endif //__GJGARAGELAYER_H__
