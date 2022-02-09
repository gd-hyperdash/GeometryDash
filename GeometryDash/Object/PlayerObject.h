#ifndef __PLAYEROBJECT_H__
#define __PLAYEROBJECT_H__

#include "../Base/GhostTrailEffect.h"
#include "CheckpointObject.h"

enum PlayerButton
{
	kPlayerButtonNone,
	kPlayerButtonJump
};

class CC_DLL PlayerObject
	: public GameObject
{
public:
	static PlayerObject *create(int playerFrame, cocos2d::CCLayer *gameLayer);
	bool init(int playerFrame, cocos2d::CCLayer *gameLayer);
	
	void update(float dt);
	void updateJump(float dt);
	void updateShipRotation();
	void collidedWithObject(float dt, GameObject *object);
	[[deprecated("unimplemented")]] void touchedObject(GameObject *object);
	void hitGround(bool isCeiling);
	
	void setColor(const cocos2d::ccColor3B &color);
	void setSecondColor(const cocos2d::ccColor3B &color);
	void setOpacity(GLubyte value);
	
	void resetObject();
	void spawnCircle();
	void spawnPortalCircle(cocos2d::ccColor3B color, float radius);
	
	void toggleFlyMode(bool value);
	void toggleGhostEffect(GhostType GhostType);
	void updatePlayerFrame(int frame);
	
	void runRotateAction();
	void stopRotation();
	
	int unused1_;
	GhostType ghostType_;
	GhostTrailEffect *ghostEffect_;
	CCSprite *mainSprite_;
	CCSprite *secondarySprite_;
	CCSprite *shipSprite_;
	
	void activateStreak();
	void deactivateStreak();
	void resetStreak();
	cocos2d::CCMotionStreak *streak_;
	
	int unused2_; /* padding? */
	
	void logValues();
	void speedUp();
	void speedDown();
	double xVel_;
	void yStartUp();
	void yStartDown();
	double jump_;
	void gravityUp();
	void gravityDown();
	double gravity_;
	bool disableEffects_;
	
	void propellPlayer();
	bool propellingPlayer_;
	
	void pushButton(PlayerButton button);
	void releaseButton(PlayerButton button);
	bool canJump_;
	bool buttonPressed_;
	bool propellingDown_;
	
	void tryPlaceCheckpoint();
	bool placeCheckpoints_;
	
	bool playMode_;
	
	void ringJump();
	bool shouldRingJump_;
	bool unused3_;
	
	bool particleEnabled_;
	bool shipTouchEffectEnabled_;
	
	void saveToCheckpoint(CheckpointObject *checkpoint);
	void loadFromCheckpoint(CheckpointObject *checkpoint);
	float recentlyPlacedCheckpoint_;
	float checkpointPlaceTime_;
	
	int unused4_; /* padding? */
	double yVel_;
	int unused5_; /* unused5+unused6 = double? */
	int unused6_;
	
	double snapPosition_;
	float jumpTime_;
	
	void checkSnapJumpToObject(GameObject *object);
	GameObject *snapObject_;
	
	void removePendingCheckpoint();
	CheckpointObject *pendingCheckpoint_;
	int checkpointUpdateTicks_;
	
	cocos2d::CCPoint getRealPosition();
	cocos2d::CCPoint realPosition_;
	
	void deactivateParticle();
	cocos2d::CCParticleSystemQuad *particle_;
	
	cocos2d::CCParticleSystemQuad *dragEffect_;
	cocos2d::CCParticleSystemQuad *shipTouchEffect_;
	cocos2d::CCParticleSystemQuad *shipDragEffect_;
	bool nextLandEffect_;
	cocos2d::CCParticleSystemQuad *gravityLandEffect_;
	cocos2d::CCParticleSystemQuad *angleLandEffect_;
	
	int flipMod();
	bool playerIsFalling();
	
	void flipGravity(bool gravityFlipped);
	
	void lockPlayer();
	
	void playerDestroyed();
	
	CC_SYNTHESIZE_READONLY(bool, flyMode_, FlyMode);
	CC_SYNTHESIZE_READONLY(bool, gravityFlipped_, GravityFlipped);
	CC_SYNTHESIZE_READONLY(bool, isDead_, IsDead);
	CC_SYNTHESIZE(cocos2d::CCPoint, lastP_, LastP);
	CC_SYNTHESIZE(cocos2d::CCPoint, portalP, PortalP);
	CC_SYNTHESIZE(cocos2d::CCLayer*, gameLayer_, GameLayer);
	CC_SYNTHESIZE(bool, onGround_, OnGround);
	CC_SYNTHESIZE_READONLY(bool, isLocked_, IsLocked);
	CC_SYNTHESIZE_READONLY(cocos2d::CCPoint, lastGroundPos_, LastGroundPos);
	CC_SYNTHESIZE(GameObject*, touchedRing_, TouchedRing);
	CC_SYNTHESIZE(GameObject*, portalObject_, PortalObject);
	CC_SYNTHESIZE_READONLY(bool, hasJumped_, HasJumped);
	CC_SYNTHESIZE_READONLY(bool, hasRingJumped_, HasRingJumped);
};

#endif //__PLAYEROBJECT_H__
