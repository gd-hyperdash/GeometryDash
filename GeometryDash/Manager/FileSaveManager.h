#ifndef __FILESAVEMANAGER_H__
#define __FILESAVEMANAGER_H__

#include "GManager.h"

class CC_DLL FileOperation
{
public:
	static void saveFile();

#define SYM_getFilePath "_ZN13FileOperation11getFilePathEv"

	[[link_name(SYM_getFilePath)]]
	static gdstd::string getFilePath();

#undef SYM_getFilePath
};

class CC_DLL FileSaveManager
	: public GManager
{
public:
	~FileSaveManager();
	
	static FileSaveManager *sharedState();
	bool init();
	
	void firstLoad();
	
	void loadDataFromFile(const char *filename);
	cocos2d::CCDictionary *getStoreData();
	
	CC_SYNTHESIZE_READONLY(cocos2d::CCDictionary*, shopItems_, ShopItems);
};

#endif //__FILESAVEMANAGER_H__
