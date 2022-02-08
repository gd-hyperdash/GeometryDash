#ifndef __OBJECTMANAGER_H__
#define __OBJECTMANAGER_H__

#include "cocos2d.h"

class CC_DLL ObjectDecoder
{
public:
	static cocos2d::CCObject* getDecodedObject(const char* key);
};

class CC_DLL ObjectManager
	: public cocos2d::CCNode
{
public:
	~ObjectManager();
	
	static ObjectManager *instance();
	bool init();
	
	void setup();
	
	static cocos2d::CCDictionary *replaceAllOccurencesOfString(
		cocos2d::CCString *what,
		cocos2d::CCString *withWhat,
		cocos2d::CCDictionary *inWhat);
	
	cocos2d::CCDictionary *getDefinition(const char *animKey);
	cocos2d::CCDictionary *getGlobalAnimCopy(const char *animKey);
	
	bool animLoaded(const char *animKey);
	void setLoaded(const char *animKey);
	
	void loadCopiedAnimations();
	void loadCopiedSets();
	
	cocos2d::CCDictionary *objectDefinitions_;
	cocos2d::CCDictionary *loadedObjects_;
};

#endif //__OBJECTMANAGER_H__
