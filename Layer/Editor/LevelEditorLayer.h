#ifndef __LEVELEDITORLAYER_H__
#define __LEVELEDITORLAYER_H__

#include "GeometryDash/Layer/Editor/DrawGridLayer.h"
#include "GeometryDash/Layer/Editor/LevelSettingsLayer.h"
#include "GeometryDash/Object/GJGameLevel.h"
#include "GeometryDash/Object/UndoObject.h"

class CC_DLL LevelEditorLayer
	: public cocos2d::CCLayer,
	public LevelSettingsDelegate
{
public:
	~LevelEditorLayer();
	
	static cocos2d::CCScene *scene(GJGameLevel *level);
	static LevelEditorLayer *create(GJGameLevel *level);
	bool init(GJGameLevel *level);
	
	cocos2d::CCSpriteBatchNode *batchNode_;
	
#define SYM_getLevelString ""

	[[link_name(SYM_getLevelString)]]
	gdstd::string getLevelString();

#undef SYM_getLevelString
	
	GameObject *objectAtPosition(cocos2d::CCPoint position);
	cocos2d::CCArray *objectsInRect(cocos2d::CCRect rect);
	
#define SYM_createObjectsFromSetup "_ZN9PlayLayer22createObjectsFromSetupESs"

	[[link_name(SYM_createObjectsFromSetup)]]
	void createObjectsFromSetup(gdstd::string setup);

#undef SYM_createObjectsFromSetup

	void removeAllObjects();

#define SYM_typeExistsAtPosition "_ZN16LevelEditorLayer20typeExistsAtPositionESsN7cocos2d7CCPointEbbf"

	[[link_name(SYM_typeExistsAtPosition)]]
	bool typeExistsAtPosition(
		gdstd::string type,
		cocos2d::CCPoint position,
		bool flipX,
		bool flipY,
		float rotation);

#undef SYM_typeExistsAtPosition

	GameObject *createObject(const char *frame, cocos2d::CCPoint position);
	void removeObject(GameObject *object);
	void removeObjectFromSection(GameObject *object);
	void reorderObjectSection(GameObject *object);
	int sectionForPos(cocos2d::CCPoint pos);
	int getSectionCount();
	cocos2d::CCArray *sections_;
	
	void addToUndoList(UndoObject *object);
	void undoLastAction();
	cocos2d::CCArray *undoActions_;
	void addToRedoList(UndoObject *object);
	void redoLastAction();
	cocos2d::CCArray *redoActions_;
	DrawGridLayer *gridLayer_;
	
	void levelSettingsUpdated();
	
	CC_SYNTHESIZE(int, objectCount_, ObjectCount);
	CC_SYNTHESIZE_READONLY(CCLayer*, gameLayer_, GameLayer);
	CC_SYNTHESIZE_READONLY(GJGameLevel*, level_, Level);
	CC_SYNTHESIZE_READONLY(LevelSettingsObject*, levelSettings_, LevelSettings);
	CC_SYNTHESIZE_READONLY(int, levelDistance_, LevelDistance);
};

#endif //__LEVELEDITORLAYER_H__
