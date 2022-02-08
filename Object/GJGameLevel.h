#ifndef __GJGAMELEVEL_H__
#define __GJGAMELEVEL_H__

#include "cocos2d.h"

enum UpdateResponse
{
	kUpdateResponseNone,
	kUpdateResponseUpToDate,
	kUpdateResponseOldAppVersion,
	kUpdateResponseSuccess
};

enum GJLevelType
{
	kGJLevelDefault,
	kGJMainLevel,
	kGJOnlineLevel,
	kGJLocalLevel
};

class GJGameLevel;

class CC_DLL LevelDownloadDelegate
{
public:
	virtual void levelDownloadFinished(GJGameLevel* level);
	virtual void levelDownloadFailed(int errorCode);
};

class CC_DLL LevelUploadDelegate
{
public:
	virtual void levelUploadFinished(GJGameLevel* level);
	virtual void levelUploadFailed(int errorCode);
};

class CC_DLL LevelUpdateDelegate
{
public:
	virtual void levelUpdateFinished(GJGameLevel* level, UpdateResponse response);
	virtual void levelUpdateFailed(int errorCode);
};

class CC_DLL GJGameLevel
	: public cocos2d::CCNode
{
public:
	~GJGameLevel();
	
	static GJGameLevel *create();
	static GJGameLevel *createWithCoder(DS_Dictionary *dict);
	bool init();
	
	static int getLengthKey(int levelDistance);

#define SYM_lengthKeyToString "_ZN11GJGameLevel17lengthKeyToStringEi"

	[[link_name(SYM_lengthKeyToString)]]
	static gdstd::string lengthKeyToString(int lengthKey);

#undef SYM_lengthKeyToString
	
	void encodeWithCoder(DS_Dictionary *dict);
	bool canEncode();
	
	void levelWasAltered();
	void levelWasSubmitted();
	void savePercentage(int percentage, bool practiceMode);
	
	CC_SYNTHESIZE(int, levelID_, LevelID);

protected:
	gdstd::string levelName_;

public:

#define SYM_getLevelName "_ZNK11GJGameLevel12getLevelNameEv"

	[[link_name(SYM_getLevelName)]]
	virtual gdstd::string getLeveName() const;

#undef SYM_getLevelName

#define SYM_setLevelName "_ZN11GJGameLevel12setLevelNameESs"

	[[link_name(SYM_setLevelName)]]
	virtual void setLevelName(gdstd::string levelName);

#undef SYM_setLevelName

protected:
	gdstd::string levelDesc_;

public:

#define SYM_getLevelDesc "_ZNK11GJGameLevel12getLevelDescEv"

	[[link_name(SYM_getLevelDesc)]]
	virtual gdstd::string getLevelDesc() const;

#undef SYM_getLevelDesc

#define SYM_setLevelDesc "_ZN11GJGameLevel12setLevelDescESs"

	[[link_name(SYM_setLevelDesc)]]
	virtual void setLevelDesc(gdstd::string levelDesc);

#undef SYM_setLevelDesc

protected:
	gdstd::string levelString_;

public:

#define SYM_getLevelString "_ZNK11GJGameLevel14getLevelStringEv"

	[[link_name(SYM_getLevelString)]]
	virtual gdstd::string getLevelString() const;

#undef SYM_getLevelString

#define SYM_setLevelString "_ZN11GJGameLevel14setLevelStringESs"

	[[link_name(SYM_setLevelString)]]
	virtual void setLevelString(gdstd::string levelString);

#undef SYM_setLevelString

protected:
	gdstd::string userName_;

public:

#define SYM_getUserName "_ZNK11GJGameLevel11getUserNameEv "

	[[link_name(SYM_getUserName)]]
	virtual gdstd::string getUserName() const;

#undef SYM_getUserName

#define SYM_setUserName "_ZN11GJGameLevel11setUserNameESs"

	[[link_name(SYM_setUserName)]]
	virtual void setUserName(gdstd::string userName);

#undef SYM_setUserName

	CC_SYNTHESIZE(int, userID_, UserID);
	CC_SYNTHESIZE(int, difficulty_, Difficulty);
	CC_SYNTHESIZE(int, audioTrack_, AudioTrack);
	CC_SYNTHESIZE(int, ratings_, Ratings);
	CC_SYNTHESIZE(int, ratingsSum_, RatingsSum);
	CC_SYNTHESIZE(int, downloads_, Downloads);
	CC_SYNTHESIZE(int, completes_, Completes);
	CC_SYNTHESIZE(bool, isEditable_, IsEditable);
	CC_SYNTHESIZE(bool, isVerified_, IsVerified);
	CC_SYNTHESIZE(bool, isUploaded_, IsUploaded);
	CC_SYNTHESIZE(int, levelVersion_, LevelVersion);
	CC_SYNTHESIZE(int, gameVersion_, GameVersion);
	CC_SYNTHESIZE(int, attempts_, Attempts);
	CC_SYNTHESIZE(int, normalPercent_, NormalPercent);
	CC_SYNTHESIZE(int, practicePercent_, PracticePercent);
	CC_SYNTHESIZE(int, likes_, Likes);
	CC_SYNTHESIZE(int, levelLength_, LevelLength);
	CC_SYNTHESIZE(cocos2d::CCPoint, lastCameraPos_, LastCameraPos);
	CC_SYNTHESIZE(float, lastEditorZoom_, LastEditorZoom);
	CC_SYNTHESIZE(GJLevelType, levelType_, LevelType);
	CC_SYNTHESIZE_READONLY(int, m_id_, M_ID);
};

#endif //__GJGAMELEVEL_H__
