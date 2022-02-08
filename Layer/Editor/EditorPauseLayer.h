#ifndef __EDITORPAUSELAYER_H__
#define __EDITORPAUSELAYER_H__

#include "GeometryDash/Layer/Editor/LevelEditorLayer.h"
#include "GeometryDash/Layer/Misc/FLAlertLayer.h"

class CC_DLL EditorPauseLayer
	: public CCBlockLayer,
	public FLAlertLayerProtocol
{
public:
	~EditorPauseLayer();
	
	static EditorPauseLayer *create(LevelEditorLayer *editorLayer);
	bool init(LevelEditorLayer *editorLayer);
	
	void customSetup();
	
	void FLAlert_Clicked(FLAlertLayer *layer, bool accept);
	void keyBackClicked();
	
	void onBPM();
	void onExitEditor();
	void onExitNoSave();
	void onHelp();
	void onResume();
	void onSaveAndExit();
	void onSaveAndPlay();
	void onSaveAndTest();
	void onSong();
	void saveLevel();
	void updateBPMButton();
	void updateSongButton();
	
	CCMenuItemSpriteExtra *songBtnOn_;
	CCMenuItemSpriteExtra *songBtnOff_;
	CCMenuItemSpriteExtra *bpmBtnOn_;
	CCMenuItemSpriteExtra *bpmBtnOff_;
	LevelEditorLayer *editorLayer_;
};

#endif //__EDITORPAUSELAYER_H__
