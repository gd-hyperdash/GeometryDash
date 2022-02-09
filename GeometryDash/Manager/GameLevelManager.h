#ifndef __GAMELEVELMANAGER_H__
#define __GAMELEVELMANAGER_H__

#include "../Object/GJGameLevel.h"
#include "../Object/GJSearchObject.h"
#include "GManager.h"

class CC_DLL LevelManagerDelegate
{
public:
	virtual void loadLevelsFinished(cocos2d::CCArray *levels, const char *key);
	virtual void loadLevelsFailed(const char *key);

#define SYM_setupPageInfo "_ZN20LevelManagerDelegate13setupPageInfoESsPKc"

	[[link_name(SYM_setupPageInfo)]]
	virtual void setupPageInfo(
		gdstd::string pageInfo,
		const char* key);

#undef SYM_setupPageInfo
};

class CC_DLL GameLevelManager
	: public GManager
{
public:
	~GameLevelManager();
	
	static GameLevelManager *sharedState();
	bool init();
	
	void dataLoaded(DS_Dictionary *dict);
	void encodeDataTo(DS_Dictionary *dict);
	void firstSetup();
	
	void gotolevelPage(GJGameLevel *level);
	
	GJGameLevel *getMainLevel(int m_id);
	cocos2d::CCArray *mainLevels_;
	
	const char *getDiffKey(int diff);
	const char *getLevelKey(int levelID);
	const char *getLenKey(int len);
	const char *getLikeKey(int levelID);
	const char *getRateKey(int levelID);
	cocos2d::CCDictionary *values_;
	
	bool isUpdateValid(int levelID);
	bool isTimeValid(const char *key, float maxDelta);
	void markTimeStamp(const char *key);
	void resetAllTimers();
	cocos2d::CCDictionary *timers_;
	
#define SYM_storeUserNames "_ZN16GameLevelManager14storeUserNamesESs"

	[[link_name(SYM_storeUserNames)]]
	void storeUserNames(gdstd::string response);

#undef SYM_storeUserNames

#define SYM_userNameForID "_ZN16GameLevelManager13userNameForIDEPKc"

	[[link_name(SYM_userNameForID)]]
	gdstd::string userNameForID(const char *userID);

#undef SYM_userNameForID

	cocos2d::CCDictionary *userNames_;
	
	cocos2d::CCArray *getStoredOnlineLevels(const char *searchKey);

#define SYM_storeSearchResult "_ZN16GameLevelManager17storeSearchResultEPN7cocos2d7CCArrayESsPKc"

	[[link_name(SYM_storeSearchResult)]]
	void storeSearchResult(
		cocos2d::CCArray *result,
		gdstd::string pageInfo,
		const char *key);

#undef SYM_storeSearchResult

	cocos2d::CCDictionary *searchResults_;
	
	const char *getPageInfo(const char *key);
	cocos2d::CCDictionary *pagesInfo_;
	
	[[deprecated("unused")]] cocos2d::CCDictionary *unused_;

#define SYM_removeDelimiterChars "_ZN16GameLevelManager20removeDelimiterCharsESs"

	[[deprecated("broken"), link_name(SYM_removeDelimiterChars)]]
	void removeDelimiterChars(gdstd::string str);

#undef SYM_removeDelimiterChars
	
#define SYM_responseToDict "_ZN16GameLevelManager14responseToDictESs"

	[[link_name(SYM_responseToDict)]]
	cocos2d::CCDictionary *responseToDict(gdstd::string response);

#undef SYM_responseToDict

	void onDownloadLevelCompleted(CCNode *sender, void *data);
	void onGetOnlineLevelsCompleted(CCNode *sender, void *data);
	void onLikeLevelCompleted(CCNode *sender, void *data);
	void onRateLevelCompleted(CCNode *sender, void *data);
	void onUpdateLevelCompleted(CCNode *sender, void *data);
	void onUpdateUserNameCompleted(CCNode *sender, void *data);
	void onUploadLevelCompleted(CCNode *sender, void *data);
	
	void downloadLevel(int levelID);
	bool hasDownloadedLevel(int levelID);
	void markLevelAsDownloaded(int levelID);
	void likeLevel(int levelID);
	bool hasLikedLevel(int levelID);
	void markLevelAsLiked(int levelID);
	void rateLevel(int levelID, int difficulty);
	bool hasRatedLevel(int levelID);
	void markLevelAsRated(int levelID);
	
	void uploadLevel(GJGameLevel *level);
	void updateLevel(GJGameLevel *level);
	void updateUserName();
	
#define SYM_createAndGetLevels "_ZN16GameLevelManager18createAndGetLevelsESs"

	[[link_name(SYM_createAndGetLevels)]]
	cocos2d::CCArray *createAndGetLevels(gdstd::string levelsString);

#undef SYM_createAndGetLevels


	void getOnlineLevels(GJSearchObject *searchObject);
	void saveLevel(GJGameLevel *level);
	GJGameLevel *getSavedLevel(int levelID);
	cocos2d::CCArray *getSavedLevels();
	cocos2d::CCDictionary *savedLevels_;
	
	void addDLToActive(const char *key);
	void removeDLFromActive(const char *key);
	bool isDLActive(const char *key);
	cocos2d::CCDictionary *activeDLs_;
	
	cocos2d::CCDictionary *uploadingLevels_;
	
	GJGameLevel *createNewLevel();
	void deleteLevel(GJGameLevel *level);
	GJGameLevel *getLocalLevel(int m_id);
	CC_SYNTHESIZE_READONLY(cocos2d::CCArray*, localLevels_, LocalLevels);
	
	cocos2d::CCScene *getSearchScene(const char *key);
	/* Check if the search diff is selected */
	bool getDiffVal(int diff);
	void setDiffVal(int diff, bool val);

#define SYM_getDifficultyStr "_ZN16GameLevelManager16getDifficultyStrEbbbbbb"

	[[link_name(SYM_getDifficultyStr)]]
	gdstd::string getDifficultyStr(
		bool na,
		bool easy,
		bool normal,
		bool hard,
		bool harder,
		bool insane);

#undef SYM_getDifficultyStr

	/* Check if the search length is selected */
	bool getLenVal(int len);
	void setLenVal(int len, bool val);

#define SYM_getLengthStr "_ZN16GameLevelManager12getLengthStrEbbbb"

	[[link_name(SYM_getLengthStr)]]
	gdstd::string getLengthStr(
		bool tinyLen,
		bool shortLen,
		bool mediumLen,
		bool longLen);

#undef SYM_getLengthStr

protected:
	gdstd::string lastSearchKey_;

public:

#define SYM_getLastSearchKey "_ZNK16GameLevelManager16getLastSearchKeyEv"

	[[link_name(SYM_getLastSearchKey)]]
	virtual gdstd::string getLastSearchKey() const;

#undef SYM_getLastSearchKey

#define SYM_setLastSearchKey "_ZN16GameLevelManager16setLastSearchKeyESs"

	[[link_name(SYM_setLastSearchKey)]]
	virtual void setLastSearchKey(gdstd::string lastSearchKey);

#undef SYM_setLastSearchKey

	CC_SYNTHESIZE(LevelManagerDelegate*, delegate_, Delegate);
	CC_SYNTHESIZE(LevelDownloadDelegate*, dlDelegate_, DlDelegate);
	CC_SYNTHESIZE(LevelUploadDelegate*, upDelegate_, UpDelegate);
	CC_SYNTHESIZE(LevelUpdateDelegate*, updateDelegate, UpdateDelegate);
};

#endif //__GAMELEVELMANAGER_H__
