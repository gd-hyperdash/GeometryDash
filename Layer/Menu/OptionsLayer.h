#ifndef __OPTIONSLAYER_H__
#define __OPTIONSLAYER_H__

#include "GeometryDash/Layer/Misc/FLAlertLayer.h"
#include "GeometryDash/Layer/Misc/GJDropDownLayer.h"

class CC_DLL OptionsLayer
	: public GJDropDownLayer,
	public FLAlertLayerProtocol
{
public:
	~OptionsLayer();
	
	static OptionsLayer *create();
	void customSetup();
	
	cocos2d::CCMenu *menu_;
	void onSupport();
	void onRate();
	void onSoundtracks();
	void onHelp();
	void onMusic();
	void onFX();
	void onGC();
	
	bool goToSupport_;
	bool goToSongs_;
	void exitLayer();
	void layerHidden();
	void FLAlert_Clicked(FLAlertLayer *layer, bool accept);
};

#endif //__OPTIONSLAYER_H__
