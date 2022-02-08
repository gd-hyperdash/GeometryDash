#ifndef __MOREGAMESMANAGER_H__
#define __MOREGAMESMANAGER_H__

#include "cocos2d.h"

class CC_DLL MoreGamesManager
	: public cocos2d::CCNode
{
public:
	~MoreGamesManager();
	
	static MoreGamesManager *sharedState();
	bool init();
	
	void dataLoaded(DS_Dictionary *dict);
	void encodeDataTo(DS_Dictionary *dict);
	void firstLoad();
	
	void promoImageDownloaded();
	
	cocos2d::CCArray *getMoreGamesList();
	
	void checkMoreGames();
	void onCheckMoreGamesCompleted(CCNode *sender, void *data);

#define SYM_handleMoreGamesResponse "_ZN16MoreGamesManager23handleMoreGamesResponseESs"

	[[link_name(SYM_handleMoreGamesResponse)]]
	void handleMoreGamesResponse(gdstd::string response);

#undef SYM_handleMoreGamesResponse

	bool shouldCheckMoreGames();
	int lastCheckMonth_;
	int lastCheckDay_;

protected:
	gdstd::string moreGamesString_;

public:

#define SYM_getMoreGamesString "_ZNK16MoreGamesManager18getMoreGamesStringEv"

	[[link_name(SYM_getMoreGamesString)]]
	virtual gdstd::string getMoreGamesString() const;

#undef SYM_getMoreGamesString

#define SYM_setMoreGamesString "_ZN16MoreGamesManager18setMoreGamesStringESs"

	[[link_name(SYM_setMoreGamesString)]]
	virtual void setMoreGamesString(gdstd::string moreGamesString);

#undef SYM_setMoreGamesString

	CC_SYNTHESIZE(bool, hasNewGames_, HasNewGames);
};

#endif //__MOREGAMESMANAGER_H__
