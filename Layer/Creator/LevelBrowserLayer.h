#ifndef __LEVELBROWSERLAYER_H__
#define __LEVELBROWSERLAYER_H__

#include "GeometryDash/Base/LoadingCircle.h"
#include "GeometryDash/Manager/GameLevelManager.h"
#include "GeometryDash/Layer/Misc/GJListLayer.h"

class CC_DLL LevelBrowserLayer
	: public cocos2d::CCLayer,
	public LevelManagerDelegate
{
public:
	~LevelBrowserLayer();
	
	static cocos2d::CCScene *scene(GJSearchObject *searchObject);
	static LevelBrowserLayer *create(GJSearchObject *searchObject);
	bool init(GJSearchObject *searchObject);
	
	bool isCorrect(const char *key);
	
	void setupLevelBrowser(cocos2d::CCArray *levels);
	GJListLayer *listLayer_;
	
	CCMenuItemSpriteExtra *nextPageBtn_;
	void onNextPage();
	CCMenuItemSpriteExtra *prevPageBtn_;
	void onPrevPage();
	
	cocos2d::CCArray *levels_;
	virtual void loadLevelsFinished(cocos2d::CCArray *levels, const char *key);
	virtual void loadLevelsFailed(const char *key);
	
	void loadPage(GJSearchObject *searchObject);
	GJSearchObject *searchObject_;
	
	void updateLevelsLabel();
	cocos2d::CCLabelBMFont *levelsLabel_;
	
#define SYM_setupPageInfo "_ZN17LevelBrowserLayer13setupPageInfoESsPKc"

	[[link_name(SYM_setupPageInfo)]]
	virtual void setupPageInfo(
		gdstd::string pageInfo,
		const char *key);

#undef SYM_setupPageInfo

	int totalItems_;
	int currentItem_;
	int itemsPerPage_;
	
	virtual void keyBackClicked();
	void onBack();
	
	LoadingCircle *loadingCircle_;
};

#endif //__LEVELBROWSERLAYER_H__
