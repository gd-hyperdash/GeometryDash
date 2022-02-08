#ifndef __CUSTOMLISTVIEW_H__
#define __CUSTOMLISTVIEW_H__

#include "GeometryDash/Base/BoomListView.h"

class GJGameLevel;
class SongObject;
class StatsObject;

class CC_DLL AchievementCell
	: public CCTableViewCell
{
public:
	AchievementCell(const char* mCellIdentifier, float mCellWidth, float mCellHeight);
	
	bool init();
	void draw();
	
	/* Dictionary is taken from AchievementManager, the dictionary fields can also be found there */
	void loadFromDict(cocos2d::CCDictionary *dict);
	void updateBGColor(int cellNumber);
};

class CC_DLL LevelCell
	: public CCTableViewCell
{
public:
	LevelCell(const char* mCellIdentifier, float mCellWidth, float mCellHeight);
	~LevelCell();
	
	bool init();
	void draw();
	
	void loadFromLevel(GJGameLevel *level);
	void loadCustomLevelCell();
	void loadLocalLevelCell();
	
	void onClick();
	
	void updateBGColor(int cellNumber);
};

class CC_DLL SongCell : public CCTableViewCell {
public:
	SongCell(const char* mCellIdentifier, float mCellWidth, float mCellHeight);
	~SongCell();
	
	bool init();
	void draw();
	
	void loadFromObject(SongObject *object);
	
	void onClick();
	
	void updateBGColor(int cellNumber);
	
	SongObject *songObject_;
};

class CC_DLL StatsCell : public CCTableViewCell {
public:
	StatsCell(const char* mCellIdentifier, float mCellWidth, float mCellHeight);
	
	bool init();
	void draw();
	
	const char *getTitleForKey(const char *key);
	
	void loadFromObject(StatsObject *object);
	
	void onClick();
	
	void updateBGColor(int cellNumber);
};

class CC_DLL CustomListView
	: public BoomListView
{
public:
	~CustomListView();
	
	static CustomListView *create(cocos2d::CCArray *rows, float layerHeight, float layerWidth, int cellData, BoomListType listType);
	bool init(cocos2d::CCArray *rows, float layerHeight, float layerWidth, int cellData, BoomListType listType);
	
	CCTableViewCell *getListCell(const char *title);
	void loadCell(CCTableViewCell *cell);
	
	void setupList();
};

#endif //__CUSTOMLISTVIEW_H__
