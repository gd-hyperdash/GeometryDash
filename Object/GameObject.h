#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "cocos2d.h"

enum GameObjectType
{
	kGameObjectInvalid,
	kGameObjectDefault,
	kGameObjectSpike,
	kGameObjectGravityFlipPortal,
	kGameObjectGravityNormalPortal,
	kGameObjectFlyPortal,
	kGameObjectCubePortal,
	kGameObjectMisc,
	kGameObjectBallRod,
	kGameObjectJumpPad,
	kGameObjectJumpRing
};

class CC_DLL GameObject
	: public cocos2d::CCSprite
{
public:
	~GameObject();
	
#define SYM_objectFromString "_ZN10GameObject16objectFromStringESs"

	[[link_name(SYM_objectFromString)]]
	static GameObject *objectFromString(gdstd::string stringSetup);

#undef SYM_objectFromString

	/* Create appropriate object (GameObject or RingObject) based on frame name */
	static GameObject *createObject(const char *frame);
	static GameObject *create(const char *frame);
	bool init(const char *frame);
	
	static const char *frameToKey(const char *frame);
	static const char *keyToFrame(const char *key);
	static const char *getBallFrame(int idx);
	/* Used to convert object string to CCDictionary */

#define SYM_stringSetupToDict "_ZN10GameObject17stringSetupToDictESs"

	[[link_name(SYM_stringSetupToDict)]]
	static cocos2d::CCDictionary *stringSetupToDict(gdstd::string stringSetup);

#undef SYM_stringSetupToDict
	
	void update(float dt);
	void setRotation(float value);
	void setScaleX(float value);
	void setScaleY(float value);
	void setScale(float value);
	void setPosition(const cocos2d::CCPoint &value);
	void setVisible(bool value);
	void setOpacity(GLubyte value);
	
	/* Setup the properties based on object key */
	void customSetup();
	void setupTypeFromFrame(const char *frame);
	
	void addGlow();
	void removeGlow();
	CCSprite *glow_;
	
	virtual void resetObject();
	virtual void triggerObject();
	virtual void activateObject();
	virtual void deactivateObject();
	virtual cocos2d::CCRect getObjectRect();
	virtual cocos2d::CCRect getObjectRect(float scaleModX, float scaleModY);
	virtual cocos2d::CCPoint getRealPosition();
	virtual void setStartPos(cocos2d::CCPoint startPos);

#define SYM_getSaveString "_ZN10GameObject13getSaveStringEv"

	[[link_name(SYM_getSaveString)]]
	virtual gdstd::string getSaveString();

#undef SYM_getSaveString

	virtual void setFlipX(bool value);
	virtual void setFlipY(bool value);
	virtual void calculateSpawnXPos();
	virtual void triggerActivated();
	bool isActiveObject_;
	
	bool isStateObject_;
	
	virtual void powerOnObject();
	virtual void powerOffObject();
	bool poweredOn_;
	
	float realWidth_;
	float realHeight_;
	bool activated_;
	bool hasGlow_;
	
	cocos2d::CCParticleSystemQuad *createAndAddParticle(const char *filename, int zOrder);
	cocos2d::CCParticleSystemQuad *particle_;
	cocos2d::CCPoint particleOffset_;
	
	void updateState();
	
	void customScaleMod(const char *frame);
	CC_SYNTHESIZE(float, scaleModX_, ScaleModX);
	CC_SYNTHESIZE(float, scaleModY_, ScaleModY);
	CC_SYNTHESIZE(int, m_id_, M_ID);
	CC_SYNTHESIZE_READONLY(GameObjectType, type_, Type);
	CC_SYNTHESIZE(int, sectionIdx_, SectionIdx);
	CC_SYNTHESIZE_READONLY(bool, shouldSpawn_, ShouldSpawn);
	CC_SYNTHESIZE_READONLY(cocos2d::CCPoint, startPos_, StartPos);

protected:
	gdstd::string frame_;

public:

#define SYM_getFrame "_ZNK10GameObject8getFrameEv"

	[[link_name(SYM_getFrame)]]
	gdstd::string getFrame() const;

#undef SYM_getFrame

	CC_SYNTHESIZE_READONLY(bool, blendAdditive_, BlendAdditive);
	CC_SYNTHESIZE_READONLY(bool, usePlayerColor_, UsePlayerColor);
	CC_SYNTHESIZE_READONLY(bool, isDisabled_, IsDisabled);
	CC_SYNTHESIZE(float, startRotation_, StartRotation);
	CC_SYNTHESIZE(float, startScaleX_, StartScaleX);
	CC_SYNTHESIZE(float, startScaleY_, StartScaleY);
	CC_SYNTHESIZE(bool, shouldHide_, ShouldHide);
	CC_SYNTHESIZE_READONLY(cocos2d::CCPoint, spawnXPos_, spawnXPos_);
	CC_SYNTHESIZE_READONLY(bool, isInvisible_, IsInvisible);
	CC_SYNTHESIZE(int, enterEffect_, EnterEffect);
	CC_SYNTHESIZE(cocos2d::ccColor3B, tintColor_, TintColor);
	CC_SYNTHESIZE(float, tintDuration_, TintDuration);
	CC_SYNTHESIZE(int, objectKey_, ObjectKey);
	CC_SYNTHESIZE(bool, dontTransform_, DontTransform);
	CC_SYNTHESIZE(bool, hasBeenActivated_, HasBeenActivated);
	CC_SYNTHESIZE(bool, stateVar_, StateVar);
	CC_SYNTHESIZE(int, objectZ_, ObjectZ);
	CC_SYNTHESIZE(CCNode*, objectParent_, ObjectParent);
};

#endif //__GAMEOBJECT_H__
