#ifndef __BOOMLISTVIEW_H__
#define __BOOMLISTVIEW_H__

#include "cocos2d.h"

enum BoomListType
{
	kBoomNormalList,
	kBoomScoreList,
	kBoomFriendsList,
	kBoomStatsList,
	kBoomAchList,
	kBoomLevelList,
	kBoomGamesList = 7,
	kBoomSongList
};

class CC_DLL ListCell
	: public CCTableViewCell
{
public:
	ListCell(
		char const* mCellIdentifier,
		float mCellWidth,
		float mCellHeight);

	bool init();
	
	void draw();

	void loadFromObject(
		CCObject *object,
		int displayNumber,
		int cellData,
		int cellNumber);
	
	void onTouch();
	void updateBGColor(int cellNumber);
	
	cocos2d::ccColor4B lineColor_;
};

class CC_DLL GameCell
	: public CCTableViewCell
{
public:
	GameCell(const char * mCellIdentifier, float mCellWidth, float mCellHeight);
	bool init();
	
	void draw();

#define SYM_loadFromString "_ZN8GameCell14loadFromStringESs "

	[[link_name(SYM_loadFromString)]]
	void loadFromString(gdstd::string game);

#undef SYM_loadFromString
	
	void onTouch();
	void updateBGColor(int cellNumber);
	
	int unused_;
	gdstd::string downloadUrl_;
};

class CC_DLL BoomListView
	: public cocos2d::CCLayer,
	public CCTableViewDelegate,
	public CCTableViewDataSource
{
public:
	~BoomListView();
	
	static BoomListView *create(cocos2d::CCArray *rows, float layerHeight, float layerWidth, int cellData, BoomListType listType);

	bool init(cocos2d::CCArray *rows, float layerHeight, float layerWidth, int cellData, BoomListType listType);
	void draw();
	
	/* Does the initial list setup */
    virtual void setupList();
	
    virtual void ccTableViewWillDisplayCellForRowAtIndexPath(CCIndexPath &mIndexPath,CCTableViewCell * mTableViewCell,CCTableView * mTableView);
    virtual float cellHeightForRowAtIndexPath(CCIndexPath & mIndexPath,CCTableView * mTableView);
    virtual void didSelectRowAtIndexPath(CCIndexPath & mIndexPath,CCTableView * mTableView);
    virtual unsigned int numberOfRowsInSection(unsigned int mSection,CCTableView * mTableView);
    virtual unsigned int numberOfSectionsInCCTableView(CCTableView * mTableView);
	virtual CCTableViewCell * cellForRowAtIndexPath(CCIndexPath &mIndexPath,CCTableView * mTableView);
	virtual void ccTableViewCommitCellEditingStyleForRowAtIndexPath(CCTableView * mTableView,CCTableViewCellEditingStyle mCellEditStyle,CCIndexPath &mIndexPath);
    virtual void ccTableViewWillReloadCellForRowAtIndexPath(CCIndexPath &mIndexPath,CCTableViewCell * mTableViewCell,CCTableView * mTableView);
	
	virtual CCTableViewCell *getListCell(const char *title);
	virtual void loadCell(CCTableViewCell *cell);
	
	CCTableView *tableView_;
	cocos2d::CCArray *rows_;
	BoomListType listType_;
	float layerHeight_;
	float layerWidth_;
	float cellHeight_;
	int cellData_;
};

/* A container for BoomListView */
class CC_DLL BoomListLayer
	: public cocos2d::CCLayerColor
{
public:
	~BoomListLayer();
	
	static BoomListLayer *create(BoomListView *listView, const char *title);
	bool init(BoomListView *listView, const char *title);
};

#endif //__BOOMLISTVIEW_H__
