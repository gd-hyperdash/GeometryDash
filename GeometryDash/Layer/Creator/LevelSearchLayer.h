#ifndef __LEVELSEARCHLAYER_H__
#define __LEVELSEARCHLAYER_H__

#include "cocos2d.h"

class CC_DLL SearchButton
	: public cocos2d::CCSprite
{
public:
	static SearchButton *create(const char *backgroundFrame, const char *text, float labelScale, const char *spriteFrame);
	
	CC_SYNTHESIZE_READONLY(cocos2d::CCLabelBMFont*, label_, Label);
	CC_SYNTHESIZE_READONLY(CCSprite*, sprite_, Sprite);
};

class CC_DLL LevelSearchLayer
	: public cocos2d::CCLayer,
	public TextInputDelegate
{
public:
	~LevelSearchLayer();
	
	static cocos2d::CCScene *scene();
	static LevelSearchLayer *create();
	bool init();
	
	void updateSearchLabel(const char *text);
	void textInputOpened(CCTextInputNode *textInput);
	void textInputClosed(CCTextInputNode* textInput);
	void textChanged(CCTextInputNode *textInput);
	CCTextInputNode *searchInput_;
	
	virtual void keyBackClicked();
	
	void onBack();
	void onClose();
	void onMostDownloaded();
	void onMostLikes();
	void onTrending();
	void onMostRecent();
	void onSearch();
	
	const char *getDiffKey();
	bool checkDiff(int diff);
	void toggleDifficulty(CCNode *button);
	void toggleDifficultyNum(int difficulty, bool value);
	cocos2d::CCArray *difficultyButtons_;
	
	const char *getTimeKey();
	bool checkTime(int time);
	void toggleTime(CCNode *button);
	void toggleTimeNum(int time, bool value);
	cocos2d::CCArray *timeButtons_;
	
	const char *getSearchDiffKey();
	const char *getLevelLenKey();
	cocos2d::CCDictionary values_;
};

#endif //__LEVELSEARCHLAYER_H__
