#ifndef __EDITLEVELLAYER_H__
#define __EDITLEVELLAYER_H__

#include "../../Base/TextArea.h"
#include "../../Object/GJGameLevel.h"
#include "../Misc/FLAlertLayer.h"

class CC_DLL UploadPopup
	: public FLAlertLayer,
	public LevelUploadDelegate
{
public:
	~UploadPopup();
	
	static UploadPopup *create(GJGameLevel *level);
	bool init(GJGameLevel *level);
	
	void keyBackClicked();
	
	void show();
	
	void levelUploadFinished(GJGameLevel *level);
	void levelUploadFailed(GJGameLevel *level);
	
	void onBack();
	void onClose();
	void onReturnToLevel();
};

class CC_DLL ShareLevelLayer : public FLAlertLayer {
public:
	~ShareLevelLayer();
	
	static ShareLevelLayer *create(GJGameLevel *level);
	bool init(GJGameLevel *level);
	
	void keyBackClicked();
	void onClose();
	void onShare();
	
	GJGameLevel *level_;
};

/* The layer used for displaying a created level */
class CC_DLL EditLevelLayer
	: public cocos2d::CCLayer,
	public TextInputDelegate,
	public FLAlertLayerProtocol
{
public:
	~EditLevelLayer();
	
	static cocos2d::CCScene *scene();
	static EditLevelLayer *create(GJGameLevel *level);
	bool init(GJGameLevel *level);
	
	void setupLevelInfo();
	void updateDescText(const char *text);
	
	void closeTextInputs();
	/* Show a delete confirmation dialog */
	void confirmDelete();
	
	void onBack();
	void onDelete();
	void onEdit();
	void onHelp();
	void onPlay();
	void onShare();
	void onTest();
	
	virtual void FLAlertLayer_Clicked(FLAlertLayer *layer, bool accept);
	
	virtual void textInputOpened(CCTextInputNode *textInput);
	virtual void textInputClosed(CCTextInputNode *textInput);
	virtual void textChanged(CCTextInputNode *textInput);
	
	virtual void keyBackClicked();

	cocos2d::CCMenu *menu_;
	GJGameLevel *level_;
	TextArea *desc_;
	cocos2d::CCArray *textInputs_;
	GJLevelType levelType_;
};

#endif //__EDITLEVELLAYER_H__
