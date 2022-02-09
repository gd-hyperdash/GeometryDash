#ifndef __CHECKPOINTOBJECT_H__
#define __CHECKPOINTOBJECT_H__

#include "GameObject.h"

enum EnterEffect
{
	kEnterEffectDefault,
	kEnterEffectNone,
	kEnterEffectScaleUp,
	kEnterEffectScaleDown,
	kEnterEffectFinishTop,
	kEnterEffectFinishBottom,
	kEnterEffectFinishLeft,
	kEnterEffectFinishRight
};

/* Used for saving game state */
class CC_DLL CheckpointObject
	: public cocos2d::CCNode
{
public:
	~CheckpointObject();
	
	static CheckpointObject *create();
	bool init();
	
	CC_SYNTHESIZE(cocos2d::CCPoint, playerPos_, PlayerPos);
	CC_SYNTHESIZE(float, playerYVel_, PlayerYVel);
	CC_SYNTHESIZE(bool, flipGravity_, FlipGravity);
	CC_SYNTHESIZE(bool, flyMode_, FlyMode);
	CC_SYNTHESIZE(bool, canJump_, CanJump);
	CC_SYNTHESIZE(int, ghostType_, GhostType);
	CC_SYNTHESIZE(cocos2d::CCPoint, cameraPos_, CameraPos);
	CC_SYNTHESIZE(cocos2d::ccColor3B, bgColor_, BGColor);
	CC_SYNTHESIZE(cocos2d::ccColor3B, groundColor_, GroundColor);
	CC_SYNTHESIZE(EnterEffect, activeEnterEffect_, ActiveEnterEffect);
	CC_SYNTHESIZE(GameObject*, portalObject, PortalObject);
};

#endif //__CHECKPOINTOBJECT_H__
