#ifndef __LEVELSELECTLAYER_H__
#define __LEVELSELECTLAYER_H__

#include "GeometryDash/Layer/Misc/BoomScrollLayer.h"
#include "GeometryDash/Object/GJGameLevel.h"

class CC_DLL LevelPage
	: public cocos2d::CCLayer
{
public:
	~LevelPage();
	
	static LevelPage *create(GJGameLevel *level);
	bool init(GJGameLevel *level);
	
	void onPlay();
	
	bool exiting_;
	GJGameLevel *level_;
	cocos2d::CCMenu *menu_;
};

class CC_DLL LevelSelectLayer
	: public cocos2d::CCLayer,
	public BoomScrollLayerDelegate
{
public:
	~LevelSelectLayer();
	
	static cocos2d::CCScene *scene(int page);
	static LevelSelectLayer *create(int page);
	bool init(int page);
	
	cocos2d::ccColor3B colorForPage(int page);
	cocos2d::ccColor3B getColorValue(int pageFrom, int pageTo, float scrollLength);
	
	virtual void scrollLayerMovec(cocos2d::CCPoint position);
	virtual void keyBackClicked();
	
	void onBack();
	void onDownload();
	void onPrev();
	void onNext();
	
	float windowWidth_;
	cocos2d::CCSprite *background_;
	cocos2d::CCSprite *groundSquare_;
	BoomScrollLayer *scrollLayer_;
	int unused_;
};

#endif //__LEVELSELECTLAYER_H__
