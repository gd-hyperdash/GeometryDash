#ifndef __AUDIOEFFECTSLAYER_H__
#define __AUDIOEFFECTSLAYER_H__

#include "cocos2d.h"

/* The layer responsible for playing audio scaling effects */
class CC_DLL AudioEffectsLayer
	: public cocos2d::CCLayerColor
{
public:
	~AudioEffectsLayer();
	
#define SYM_create "_ZN17AudioEffectsLayer6createESs"

	[[link_name(SYM_create)]]
	static AudioEffectsLayer *create(gdstd::string audioString);

#undef SYM_create

#define SYM_init "_ZN17AudioEffectsLayer4initESs"

	[[link_name(SYM_init)]]
	bool init(gdstd::string audioString);

#undef SYM_init
	
	void draw();
	void updateTweenAction(float value, const char *key);
	
	/* Called when the effect started going down */
	void goingDown();
	/* Resets the effects to be played */
	void resetAudioVars();
	void triggerEffect(float scale);
	
	[[deprecated("unused")]] cocos2d::CCSprite *getBGSquare();
protected:
	cocos2d::CCSpriteBatchNode *batchNode_;
	cocos2d::CCArray *audioVars_;
	cocos2d::CCArray *queuedEffects_;
	float time_;
	float scalingTo_;
	bool goingDown_;
	CC_SYNTHESIZE_READONLY(float, audioScale_, AudioScale);
	CC_SYNTHESIZE(bool, rainActive_, RainActive);
};

#endif //__AUDIOEFFECTSLAYER_H__
