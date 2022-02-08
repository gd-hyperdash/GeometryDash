#ifndef __GJSEARCHOBJECT_H__
#define __GJSEARCHOBJECT_H__

#include "cocos2d.h"

enum SearchType
{
	kSearchDefault,
	kSearchMostDownloaded,
	kSearchMostLikes,
	kSearchTrendingLevels,
	kSearchMostRecent,
	kSearchLevelsByUser,
	kSearchFeaturedLevels
};

class CC_DLL GJSearchObject
	: public cocos2d::CCNode
{
public:
	~GJSearchObject();

#define SYM_create "_ZN14GJSearchObject6createE10SearchTypeSsSsSsi"

	[[link_name(SYM_create)]]
	static GJSearchObject *create(
		SearchType type,
		gdstd::string str,
		gdstd::string difficultyStr,
		gdstd::string lengthStr, int page);

#undef SYM_create

	static GJSearchObject *createFromKey(const char *key);
	
#define SYM_init "_ZN14GJSearchObject4initE10SearchTypeSsSsSsi"

	[[link_name(SYM_init)]]
	bool init(
		SearchType type,
		gdstd::string str,
		gdstd::string difficultyStr,
		gdstd::string lengthStr, int page);

#undef SYM_init
	
#define SYM_getSearchKey "_ZN14GJSearchObject12getSearchKeyE10SearchTypeSsSsSsi"

	[[link_name(SYM_getSearchKey)]]
	static const char *getSearchKey(
		SearchType type,
		gdstd::string str,
		gdstd::string difficultyStr
		gdstd::string lengthStr, int page);

#undef SYM_getSearchKey
	
	const char *getKey();
	const char *getNextPageKey();
	
	GJSearchObject *getPrevPageObject();
	GJSearchObject *getNextPageObject();
	
	CC_SYNTHESIZE(SearchType, type_, Type);

protected:
	gdstd::string string_;

public:

#define SYM_getString "_ZNK14GJSearchObject9getStringEv"

	[[link_name(SYM_getString)]]
	virtual gdstd::string getString() const;

#undef SYM_getString

#define SYM_setString "_ZN14GJSearchObject9setStringESs"

	[[link_name(SYM_setString)]]
	virtual void setString(gdstd::string string);

#undef SYM_setString

protected:
	gdstd::string difficultyStr_;

public:

#define SYM_getDifficultyStr "_ZNK14GJSearchObject16getDifficultyStrEv"

	[[link_name(SYM_getDifficultyStr)]]
	virtual gdstd::string getDifficultyStr() const;

#undef SYM_getDifficultyStr

#define SYM_setDifficultyStr "_ZN14GJSearchObject16setDifficultyStrESs"

	[[link_name(SYM_setDifficultyStr)]]
	virtual void setDifficultyStr(gdstd::string difficultyStr);

#undef SYM_setDifficultyStr

protected:
	gdstd::string lengthStr_;

public:

#define SYM_getLengthStr "_ZNK14GJSearchObject12getLengthStrEv"

	[[link_name(SYM_getLengthStr)]]
	virtual gdstd::string getLengthStr() const;

#undef SYM_getLengthStr

#define SYM_setLengthStr "_ZN14GJSearchObject12setLengthStrESs"

	[[link_name(SYM_setLengthStr)]]
	virtual void setLengthStr(gdstd::string lengthStr);

#undef SYM_setLengthStr

	CC_SYNTHESIZE(int, page_, Page);
};

#endif //__GJSEARCHOBJECT_H__
