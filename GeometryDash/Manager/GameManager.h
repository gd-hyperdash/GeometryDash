#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include "../Layer/Game/PlayLayer.h"
#include "../Layer/Menu/GJGarageLayer.h"
#include "../Layer/Menu/LevelSelectLayer.h"
#include "../Object/GJGameLevel.h"
#include "GManager.h"

#define GM GameManager::sharedState()

enum LastGameScene
{
	kDefaultScene,
	kCreatorScene,
	kMyLevelsScene,
	kLevelInfoScene,
	kSavedLevelsScene,
	kSearchScene,
	kMenuScene,
	kLevelSelectScene
};

class PremiumPopup;

class CC_DLL GameManager
	: public GManager
{
public:
	~GameManager();
	
	static GameManager *sharedState();
	bool init();
	
	void dataLoaded(DS_Dictionary *dict);
	void encodeDataTo(DS_Dictionary *dict);
	void firstLoad();
	void setup();
	
	void applicationDidEnterBackground();
	void applicationWillEnterForeground();
	
	/* Get color for index, example use: player color */
	cocos2d::ccColor3B colorForIdx(int idx);
	
#define SYM_claimItemsResponse "_ZN11GameManager18claimItemsResponseESs"

	/* Called in GameStoreManager */
	[[deprecated("unimplemented"), link_name(SYM_claimItemsResponse)]]
	void claimItemsResponse(gdstd::string response);

#undef SYM_claimItemsResponse

	/* Called on item purchase, GD has no purchases so this is unused */
	[[deprecated("unused")]] [[deprecated("unimplemented")]] void itemPurchased(const char *item);
	/* Called in GameStoreManager::unlockFeature, features are basically in-app purchases */
	void eventUnlockFeature(const char *feature);
	[[deprecated("unused")]] [[deprecated("unimplemented")]] void unlockedPremium();
	[[deprecated("unused")]] bool levelIsPremium(int level, int type);
	/* Unused boolean, probably has something to do with purchases */
	[[deprecated("unused")]] bool unused1_;
	
	/* The results system isn't used in the game */
	[[deprecated("unused")]] int getResultForLevel(int level, int type);
	/* The results system isn't used in the game */
	[[deprecated("unused")]] int getNextLevel(int level, int type);
	/* The results system isn't used in the game */
	[[deprecated("unused")]] int highestLevelForType(int type);
	/* The results system isn't used in the game */
	[[deprecated("unused")]] void updateHighest(int level, int type);
	/* The results system isn't used in the game */
	[[deprecated("unused")]] const char *getLevelKey(int level, int type);
	/* The results system isn't used in the game */
	[[deprecated("unused")]] void registerLevelResult(int level, int result, int type);
	cocos2d::CCDictionary *scoreKeeper_;
	
	const char *colorKey(int colorIdx, bool mainColor);
	bool isColorUnlocked(int colorIdx, bool mainColor);
	void unlockColor(int colorIdx, bool mainColor);
	const char *iconKey(int iconIdx);
	bool isIconUnlocked(int iconIdx);
	void unlockIcon(int iconIdx);
	cocos2d::CCDictionary *valueKeeper_;
	
	void reportPercentageForLevel(int level, int percentage, bool practiceMode);
	void reportAchievementWithID(const char *achievementID, int percentage);
	void completedAchievement(const char *achievementID);
	
	[[deprecated("unused")]] [[deprecated("unimplemented")]] void showInterstitial();
	[[deprecated("unused")]] [[deprecated("unimplemented")]] void showMainMenuAd();
	[[deprecated("unused")]] int unused2_;
	
	/* Shows TutorialPopup */
	[[deprecated("unused")]] void showTutorial();
	[[deprecated("unused")]] bool shouldShowTutorial();
	void reactivateTutorial();
	int tutorialPage_;
	
	void fadeInMusic(const char *music);
	void resetMusic();
	void toggleMusic();
	void toggleFX();
	void updateMusicVolume();
	/* Stores the playing music filename */
	gdstd::string playingMusic_;
	float musicVolume_;
	float musicVolumeEnd_;
	
	/* Sync Game Center achievements */
	void syncGCAchievements();
	bool syncedAchievements_;
	
	/* Called to return one scene back based on lastScene_ */
	void returnToLastScene(GJGameLevel *level);
	
	void openEditorGuide();
	void rateGame();
	
	CC_SYNTHESIZE(PlayLayer*, playLayer_, PlayLayer);
	CC_SYNTHESIZE(LevelSelectLayer*, levelSelectLayer_, LevelSelectLayer);
	CC_SYNTHESIZE(bool, mainMenuActive_, MainMenuActive);
	[[deprecated("unused")]] CC_SYNTHESIZE(PremiumPopup*, premiumPopup_, PremiumPopup);
	CC_SYNTHESIZE(bool, gameCenterEnabled_, GameCenterEnabled);
	CC_SYNTHESIZE(bool, firstSetup_, FirstSetup);
	CC_SYNTHESIZE(bool, showedFirstTutorial_, ShowedFirstTutorial);

protected:
	gdstd::string playerUDID_;

public:

#define SYM_getPlayerUDID "_ZNK11GameManager13getPlayerUDIDEv"

	[[link_name(SYM_getPlayerUDID)]]
	virtual gdstd::string getPlayerUDID() const;

#undef SYM_getPlayerUDID

#define SYM_setPlayerUDID "_ZN11GameManager13setPlayerUDIDESs"

	[[link_name(SYM_setPlayerUDID)]]
	virtual void setPlayerUDID(gdstd::string udid);

#undef SYM_setPlayerUDID

protected:
	gdstd::string playerName_;

public:

#define SYM_getPlayerName "_ZNK11GameManager13getPlayerNameEv"

	[[link_name(SYM_getPlayerName)]]
	virtual gdstd::string getPlayerName() const;

#undef SYM_setPlayerName

#define SYM_setPlayerName "_ZN11GameManager13setPlayerNameESs"

	[[link_name(SYM_setPlayerName)]]
	virtual void setPlayerName(gdstd::string name);

#undef SYM_setPlayerName

	CC_SYNTHESIZE_READONLY(bool, musicEnabled_, MusicEnabled);
	CC_SYNTHESIZE_READONLY(bool, fxEnabled_, FxEnabled);
	CC_SYNTHESIZE(bool, didRateGame_, DidRateGame);
	[[deprecated("unused")]] CC_SYNTHESIZE(bool, wasHigh_, WasHigh);
	CC_SYNTHESIZE(bool, editMode_, EditMode);
	CC_SYNTHESIZE(LastGameScene, lastScene_, LastScene);
	CC_SYNTHESIZE(bool, returnToSearch_, ReturnToSearch);
	CC_SYNTHESIZE(int, playerFrame_, PlayerFrame);
	CC_SYNTHESIZE(int, playerColor_, PlayerColor);
	CC_SYNTHESIZE(int, playerColor2_, PlayerColor2);
	CC_SYNTHESIZE(bool, autoCheckpoints_, AutoCheckpoints);
	CC_SYNTHESIZE(bool, showSongMarkers_, ShowSongMarkers);
	CC_SYNTHESIZE(bool, showBPMMarkers_, ShowBPMMarkers);
	CC_SYNTHESIZE(bool, clickedGarage_, ClickedGarage);
	CC_SYNTHESIZE(bool, clickedEditor_, ClickedEditor);
	CC_SYNTHESIZE(bool, clickedName_, ClickedName);
	CC_SYNTHESIZE(bool, showedEditorGuide_, ShowedEditorGuide);
	CC_SYNTHESIZE(GameRateDelegate*, rateDelegate_, RateDelegate);
};

#endif //__GAMEMANAGER_H__
