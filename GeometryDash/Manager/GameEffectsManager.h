#ifndef __GAMEEFFECTSMANAGER_H__
#define __GAMEEFFECTSMANAGER_H__

#include "cocos2d.h"

//this too /cos
class PlayLayer;

class CC_DLL GameEffectsManager
	: public cocos2d::CCNode
{
public:
	~GameEffectsManager();
	
	static GameEffectsManager *create(PlayLayer *playLayer);
	bool init(PlayLayer *playLayer);
	
	[[deprecated("unimplemented")]] void addParticle(cocos2d::CCParticleSystemQuad *particleSystem, int);
	[[deprecated("unused")]] void scaleParticle(cocos2d::CCParticleSystemQuad *particleSystem, float scale);
};

#endif //__GAMEEFFECTSMANAGER_H__
