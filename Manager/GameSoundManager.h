#ifndef __GAMESOUNDMANAGER_H__
#define __GAMESOUNDMANAGER_H__

#include "cocos2d.h"

enum SoundManagerState
{
	kSoundManagerStopped,
	kSoundManagerReady = 4
};

class CC_DLL GameSoundManager
	: public cocos2d::CCNode
{
public:
	static GameSoundManager *sharedManager();
	bool init();
	
	void asynchronousSetup();
	void setup();
	
	void setBGMusicVolume(float value);
	
	[[deprecated("unused")]] void resumeSound();
	
	[[deprecated("unused")]] void fadeInMusic(bool unused = false);
	[[deprecated("unused")]] void fadeOutMusic(bool unused = false);
	
	[[deprecated("unused")]] bool isLoopedSoundPlaying(const char *filename);
	[[deprecated("unused")]] void playLoopedSound(const char *key, const char *filename, float unused, float gain, bool unused2, bool unused3, bool applyBGVolume);
	[[deprecated("unused")]] void pauseLoopedSound(const char *filename);
	[[deprecated("unused")]] void removeLoopedSound(const char *filename);
	[[deprecated("unused")]] void stopLoopedSound(const char *filename, bool unused = false);
	[[deprecated("unused")]] void resumeAllLoopedSounds();
	[[deprecated("unused")]] void pauseAllLoopedSounds();
	[[deprecated("unused")]] void stopAllLoopedSounds();
	[[deprecated("unimplemented")]] void updateLoopedVolume(const char *filename, float value);
	cocos2d::CCDictionary *loopedSounds_;
	
	[[deprecated("unused")]] void playEffect(const char *filename);
	void playEffect(const char *filename, float pitch, float pan, float gain);
	
	[[deprecated("unused")]] void playUniqueEffect(const char *filename);
	[[deprecated("unused")]] void playUniqueEffect(const char *filename, float pitch, float pan, float gain);
	[[deprecated("unused")]] void resetUniqueEffects();
	cocos2d::CCDictionary *uniqueEffects_;
	float uniqueEffectsTime_;
	
	void preload();
	
	CC_SYNTHESIZE_READONLY(SoundManagerState, state_, State);
	CC_SYNTHESIZE(float, bgVol_, BGVol);
};

#endif //__GAMESOUNDMANAGER_H__
