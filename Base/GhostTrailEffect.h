#ifndef __GHOSTTRAILEFFECT_H__
#define __GHOSTTRAILEFFECT_H__

#include "cocos2d.h"

enum GhostType
{
	kGhostDisable,
	kGhostEnable
};

class GhostTrailEffect;

class GhostTrailDelegate
{
public:
	virtual void ghostTrailWillExit(GhostTrailEffect *effect);
};

class CC_DLL GhostTrailEffect
	: public cocos2d::CCNode
{
public:
	~GhostTrailEffect();
	
	static GhostTrailEffect *create();
	
	void draw();
	
	void runWithTarget(
		cocos2d::CCSprite *target,
		float snapshotInterval,
		float fadeDuration,
		float duration,
		float scale,
		bool fadeAlpha);

	void stopTrail();
	void trailSnapshot();
	float snapshotInterval_;
	float fadeDuration_;
	float scale_;
	bool fadeAlpha_;
	
	void doBlendAdditive();
	CC_SYNTHESIZE(cocos2d::ccBlendFunc, blendFunc_, BlendFunc);
	CC_SYNTHESIZE(cocos2d::CCSprite*, target_, Target);
	CC_SYNTHESIZE(cocos2d::CCSprite*, posTarget_, PosTarget);
	CC_SYNTHESIZE(cocos2d::CCSprite*, pTarget, PTarget);
	CC_SYNTHESIZE(float, startAlpha_, StartAlpha);
	CC_SYNTHESIZE(GhostTrailDelegate*, delegate_, Delegate);
	CC_SYNTHESIZE(cocos2d::ccColor3B, ghostColor_, GhostColor);
};

#endif //__GHOSTTRAILEFFECT_H__
