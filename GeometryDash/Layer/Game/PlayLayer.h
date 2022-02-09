#ifndef __PLAYLAYER_H__
#define __PLAYLAYER_H__

#include "../../Object/EndPortalObject.h"
#include "../../Object/GameObject.h"
#include "../../Object/GJGameLevel.h"
#include "../../Object/PlayerObject.h"
#include "AudioEffectsLayer.h"
#include "UILayer.h"

class GameEffectsManager;

class CC_DLL PlayLayer
	: public cocos2d::CCLayer
{
public:
	~PlayLayer();
	
	static cocos2d::CCScene *scene(GJGameLevel *level);
	static PlayLayer *create(GJGameLevel *level);
	bool init(GJGameLevel *level);
	
	void onEnterTransitionDidFinish();
	
	void update(float dt);
	void checkCollisions(float dt);
	void updateCamera(float dt);
	void updateAttempts();
	void updateVisibility();
	void updateTweenAction(float value, const char *key);
	
	void onExit();
	void onQuit();
	
	void startGame();
	void resume();
	void pauseGame();
	
	void playGravityEffect(bool flipEffect);
	
	float cameraYPos_;
	float bottomGroundY_;
	float topGroundY_;
	LevelSettingsObject *levelSettings_;
	EndPortalObject *endPortal_;
	
	CheckpointObject *createCheckpoint();
	CheckpointObject *getLastCheckpoint();
	void loadLastCheckpoint();
	void removeLastCheckpoint();
	void markCheckpoint();
	void storeCheckpoint(CheckpointObject *checkpoint);
	cocos2d::CCArray *checkpoints_;
	
	float getRelativeMod(cocos2d::CCPoint position, float fadeDistanceScreenRight, float fadeDistanceScreenLeft, float distanceOffset);
	void applyEnterEffect(GameObject *object);
	void setActiveEnterEffect(EnterEffect enterEffect);
	EnterEffect activeEnterEffect_;
	
	cocos2d::CCSprite *background_;
	cocos2d::CCSprite *groundSquare_;
	cocos2d::CCSprite *groundColorSquareBottom_;
	cocos2d::CCSprite *groundColorSquareTop_;
	cocos2d::CCSprite *floorLineBottom_;
	cocos2d::CCSprite *floorLineTop_;
	CCLayer *ground_;
	CCLayer *groundBottom_;
	CCLayer *groundTop_;
	float groundWidth_;
	float backgroundWidth_;
	
	void animateOutGround(bool disableEffects);
	void animateOutGroundFinished();
	void animateInGround(bool disableEffects);
	bool animatingInGround_;
	
	void addToSection(GameObject *object);
	void removeObjectFromSection(GameObject *object);
	void reorderObjectSection(GameObject *object);
	int sectionForPos(cocos2d::CCPoint pos);
	cocos2d::CCArray *sections_;
	
	cocos2d::CCArray *nearDamagingObjects_;
	
	void registerActiveObject(GameObject *object);
	void unregisterActiveObject(GameObject *object);
	cocos2d::CCArray *activeObjects_;
	
	void checkSpawnObjects();
	cocos2d::CCArray *defaultSpawnObjects_;
	cocos2d::CCArray *spawnObjects_;
	
#define SYM_createObjectsFromSetup "_ZN9PlayLayer22createObjectsFromSetupESs"

	[[link_name(SYM_createObjectsFromSetup)]]
	void createObjectsFromSetup(gdstd::string setup);

#undef SYM_createObjectsFromSetup

	cocos2d::CCArray *objects_;
	
	void registerStateObject(GameObject *object);
	void unregisterStateObject(GameObject *object);
	cocos2d::CCArray *stateObjects_;
	
	void toggleGlitter(bool value);
	cocos2d::CCParticleSystemQuad *glitter_;
	
	void toggleAudioRain(bool value);
	AudioEffectsLayer *audioEffectsLayer_;
	
	float groundBottomY_;
	float groundTopY_;
	
	void destroyPlayer();
	bool playerDestroyed_;
	
	void resetLevel();
	void fullReset();
	bool lastResetClean_;
	
	void moveCameraToPos(cocos2d::CCPoint pos);
	void cameraMoveX(float xPos, float moveDuration, float easeRate);
	bool movingCameraX_;
	void cameraMoveY(float yPos, float moveDuration, float easeRate);
	bool movingCameraY_;
	
	int unused_;
	int firstActiveSection_;
	int lastActiveSection_;
	int ballFrame_;
	cocos2d::ccColor3B activeGColor_;
	float levelLength_;
	float maxObjectX_;
	cocos2d::CCLabelBMFont *attemptsLabel_;
	
	void shakeCamera();
	void stopCameraShake();
	bool shakeCamera_;
	float cameraShakeStrength_;
	
	void levelComplete();
	void showCompleteEffect();
	void showCompleteText();
	void showEndLayer();
	void spawnCircle();
	void spawnFirework();
	bool levelCompleted_;
	
	
	void showHint();
	bool showedHint_;
	
	void switchToFlyMode(GameObject *portal, bool disableEffects);
	
	void tintBackground(cocos2d::ccColor3B color, float tintDuration);
	void tintGround(cocos2d::ccColor3B color, float tintDuration);
	
	void togglePracticeMode(bool value);
	
	CC_SYNTHESIZE_READONLY(GameEffectsManager*, gEM_, GEM);
	CC_SYNTHESIZE_READONLY(UILayer*, uiLayer_, UILayer);
	CC_SYNTHESIZE_READONLY(PlayerObject*, playerObject_, PlayerObject);
	CC_SYNTHESIZE_READONLY(GJGameLevel*, level_, Level);
	CC_SYNTHESIZE_READONLY(cocos2d::CCPoint, cameraPos_, CameraPos);
	CC_SYNTHESIZE_READONLY(bool, testMode_, TestMode);
	CC_SYNTHESIZE_READONLY(bool, practiceMode_, PracticeMode);
	CC_SYNTHESIZE_READONLY(cocos2d::CCSpriteBatchNode*, batchNode_, BatchNode);
	CC_SYNTHESIZE_READONLY(cocos2d::CCSpriteBatchNode*, batchNodeAdd_, BatchNodeAdd);
	CC_SYNTHESIZE_READONLY(CCLayer*, gameLayer_, GameLayer);
	CC_SYNTHESIZE_READONLY(cocos2d::ccColor3B, activeBGColor_, ActiveBGColor);
	CC_SYNTHESIZE(bool, cleanReset_, CleanReset);
	CC_SYNTHESIZE(cocos2d::CCPoint, startPos_, StartPos);
	CC_SYNTHESIZE_READONLY(int, attempts_, Attempts);
	CC_SYNTHESIZE(int, jumps_, Jumps);
	CC_SYNTHESIZE_READONLY(float, clkTimer_, ClkTimer);
};

#endif //__PLAYLAYER_H__
