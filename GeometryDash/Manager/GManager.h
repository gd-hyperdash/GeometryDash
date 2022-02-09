#ifndef __GMANAGER_H__
#define __GMANAGER_H__

#include "cocos2d.h"

/* Base class for all managers with save data */
class CC_DLL GManager
	: public cocos2d::CCNode
{
public:
	void load();
	void loadDataFromFile(const char *filename);
	
	void save();
	void saveGMTo(const char *filename);
	void saveData(DS_Dictionary *dict, const char *filename);
	
	virtual void setup();
	virtual void encodeDataTo(DS_Dictionary *dict);
	virtual void dataLoaded(DS_Dictionary *dict);
	virtual void firstLoad();
	
	const char *filename_;
	bool setUp_;
	bool saving_;
};

#endif //__GMANAGER_H__
