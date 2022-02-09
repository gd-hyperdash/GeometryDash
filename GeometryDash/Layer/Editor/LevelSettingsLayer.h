#ifndef __LEVELSETTINGSLAYER_H__
#define __LEVELSETTINGSLAYER_H__

#include "Layer/Editor/ColorPickerPopup.h"
#include "Object/LevelSettingsObject.h"

class CC_DLL LevelSettingsDelegate
{
public:
	virtual void levelSettingsUpdated();
};

class CC_DLL LevelSettingsLayer
	: public FLAlertLayer,
	public ColorPickerDelegate
{
public:
	~LevelSettingsLayer();
	
	static LevelSettingsLayer *create(LevelSettingsObject *levelSettings);
	bool init(LevelSettingsObject *levelSettings);
	
	void audioPrevious();
	void audioNext();
	void selectSong(int song);
	int audioTrack_;
	
	void keyBackClicked();
	void onClose();
	
	void colorPickerClosed(ColorPickerPopup *colorPicker);
	void onBG();
	cocos2d::CCSprite *startBGColorSprite_;
	void onG();
	cocos2d::CCSprite *startGColorSprite_;
	LevelSettingsObject *levelSettings_;
	
	void updateAudioLabel();
	cocos2d::CCLabelBMFont *audioLabel_;
	
	CC_SYNTHESIZE(LevelSettingsDelegate*, delegate_, Delegate);
};

#endif //__LEVELSETTINGSLAYER_H__
