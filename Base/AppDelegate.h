#ifndef __APPDELEGATE_H__
#define __APPDELEGATE_H__

#include "cocos2d.h"

class CC_DLL AppDelegate
	: public cocos2d::CCApplication,
	public cocos2d::CCSceneDelegate
{
public:
	AppDelegate();
	~AppDelegate();
	
	static AppDelegate *get();

	virtual void applicationDidEnterBackground();
	virtual bool applicationDidFinishLaunching();
	virtual void applicationWillEnterForeground();
	virtual void applicationWillResignActive();
	
	/* Called on loading end */
	void loadingIsFinished();
	
	void pauseGame();
	void resumeSound();
	/* Don't use this function */
	[[deprecated("unused")]] void checkSound();
	
	/* It was used in boomlings, extended in GD beta, but it became empty before release */
	[[deprecated("unimplemented")]] void showLoadingCircle(bool isOnlineLoading, bool blockInput, bool unknown);
	[[deprecated("unimplemented")]] void hideLoadingCircle();
	/* Saves the managers if loading is finished */
	void trySaveGame();
	
	virtual void willSwitchToScene(cocos2d::CCScene *pScene);
	
protected:
	[[deprecated("unimplemented")]] int unused_;
public:
	CC_SYNTHESIZE(bool, paused_, Paused);
	CC_SYNTHESIZE(cocos2d::CCNode*, scenePointer_, ScenePointer);
	CC_SYNTHESIZE_READONLY(bool, loadingFinished_, LoadingFinished);
	CC_SYNTHESIZE(bool, managersLoaded_, ManagersLoaded);
	CC_SYNTHESIZE_READONLY(bool, isIOS_, IsIOS);
};

#endif //__APPDELEGATE_H__
