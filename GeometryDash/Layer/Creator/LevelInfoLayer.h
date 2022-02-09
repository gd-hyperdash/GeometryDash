#ifndef __LEVELINFOLAYER_H__
#define __LEVELINFOLAYER_H__

#include "../../Base/LoadingCircle.h"
#include "../../Object/GJGameLevel.h"
#include "RateLevelLayer.h"

class CC_DLL InfoLayer
	: public FLAlertLayer
{
public:
	~InfoLayer();
	
	static InfoLayer *create(GJGameLevel *level);
	bool init(GJGameLevel *level);
	
	void keyBackClicked();
	
	void onClose();
	void onMore();
	
	void setupLevelInfo();
};

class CC_DLL LevelInfoLayer
	: public cocos2d::CCLayer,
	public LevelDownloadDelegate,
	public LevelUpdateDelegate,
	public RateLevelDelegate,
	public FLAlertLayerProtocol
{
public:
	~LevelInfoLayer();
	
	static cocos2d::CCScene *scene(GJGameLevel *level);
	static LevelInfoLayer *create(GJGameLevel *level);
	bool init(GJGameLevel *level);
	
	void incrementLikes();
	
	cocos2d::CCMenu *menu_;
	void onBack();
	void onClone();
	void onDelete();
	void onInfo();
	void onLike();
	void onPlay();
	void onRate();
	void onUpdate();
	
	void setupLevelInfo();
	void setupProgressBars();
	GJGameLevel *level_;
	
	virtual void levelDownloadFinished(GJGameLevel *level);
	virtual void levelDownloadFailed(int errorCode);
	
	virtual void levelUpdateFinished(GJGameLevel *level, UpdateResponse response);
	virtual void levelUpdateFailed(int errorCode);
	void showUpdateAlert(UpdateResponse response);
	
	virtual void rateLevelClosed();
	
	void updateSideButtons();
	CCMenuItemSpriteExtra *rateDiffBtn_;
	CCMenuItemSpriteExtra *likeBtn_;
	
	void updateLabelValues();
	cocos2d::CCLabelBMFont *levelLengthLabel_;
	cocos2d::CCLabelBMFont *downloadsLabel_;
	cocos2d::CCLabelBMFont *likesLabel_;
	
	GJLevelType levelType_;
	
	virtual void FLAlert_Clicked(FLAlertLayer *layer, bool accept);
	virtual void keyBackClicked();
	void confirmDelete();
	
	LoadingCircle *loadingCircle_;
};

#endif //__LEVELINFOLAYER_H__
