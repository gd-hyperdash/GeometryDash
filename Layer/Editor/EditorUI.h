#ifndef __EDITORUI_H__
#define __EDITORUI_H__

#include "GeometryDash/Layer/Editor/ColorSelectPopup.h"
#include "GeometryDash/Layer/Editor/LevelEditorLayer.h"

enum EditMode
{
	kEditModeNone,
	kEditModeDelete,
	kEditModeBuild,
	kEditModeEdit
};

enum EditCommand
{
	kEditCommandNone,
	kEditCommandMoveUp,
	kEditCommandMoveDown,
	kEditCommandMoveLeft,
	kEditCommandMoveRight,
	kEditCommandMoveUp2,
	kEditCommandMoveDown2,
	kEditCommandMoveLeft2,
	kEditCommandMoveRight2,
	kEditCommandFlipX,
	kEditCommandFlipY,
	kEditCommandRotateClockwise,
	kEditCommandRotateCounterClockwise
};

class CC_DLL ButtonPage
{
public:
	static ButtonPage *create(cocos2d::CCArray *items, cocos2d::CCPoint position);
	bool init(cocos2d::CCArray *items, cocos2d::CCPoint position);
};

class CC_DLL EditButtonBar
{
public:
	~EditButtonBar();
	
	static EditButtonBar *create(cocos2d::CCArray *items, cocos2d::CCPoint position);
	bool init(cocos2d::CCArray *items, cocos2d::CCPoint position);
	
	void onLeft();
	void onRight();
};

class CC_DLL CreateMenuItem
	: public CCMenuItemSpriteExtra
{
public:
	static CreateMenuItem *create(CCNode *normalSprite, CCNode *selectedSprite, CCObject *target, cocos2d::SEL_MenuHandler selector);
	bool init(CCNode *normalSprite, CCNode *selectedSprite, CCObject *target, cocos2d::SEL_MenuHandler selector);

protected:
	gdstd::string objectFrame_;

public:

#define SYM_getObjectFrame "_ZNK14CreateMenuItem14getObjectFrameEv"

	[[link_name(SYM_getObjectFrame)]]
	virtual gdstd::string getObjectFrame() const;

#undef SYM_getObjectFrame

#define SYM_setObjectFrame "_ZN14CreateMenuItem14setObjectFrameESs"

	[[link_name(SYM_setObjectFrame)]]
	virtual void setObjectFrame(gdstd::string objectFrame);

#undef SYM_setObjectFrame

};

class CC_DLL EditorUI
	: public cocos2d::CCLayer,
	public FLAlertLayerProtocol,
	public ColorSelectDelegate
{
public:
	~EditorUI();
	
	static EditorUI *create(LevelEditorLayer *gameLayer);
	bool init(LevelEditorLayer *gameLayer);
	
	void draw();
	
	void FLAlert_Clicked(FLAlertLayer *layer, bool accept);
	
	void colorSelectClosed(cocos2d::ccColor3B color);
	
	cocos2d::CCPoint offsetForFrame(const char *frame);
	cocos2d::CCPoint getRelativeOffset(GameObject *object);
	/* Apply the relative offset to object (Called after object transform) */
	void applyOffset(GameObject *object);
	/* Opposite to applyOffset (Called before object transform */
	void removeOffset(GameObject *object);
	
	void resetUI();
	
	CCMenuItemSpriteExtra *getModeBtn(const char *title, int mode);
	CCMenuItemSpriteExtra *getSpriteButton(const char *backgroundFrame, cocos2d::SEL_MenuHandler handler, cocos2d::CCMenu *menu, float scale);
	
	void onCreateButton(CCNode *button);
	CreateMenuItem *getCreateBtn(const char *objectFrame, int backgroundType);
	void setupCreateMenu();
	void updateCreateMenu();
	EditButtonBar *createMenu_;	
	
	void createMoveMenu();
	void moveObject(GameObject *object, cocos2d::CCPoint distance);
	void moveObjectCall(CCNode *button);
	void transformObject(GameObject *object, EditCommand command);
	void transformObjectCall(CCNode *button);
	void setupEditMenu();
	void updateEditMenu();
	EditButtonBar *editMenu_;
	
	void sliderChanged(SliderThumb *thumb);
	void updateSlider();
	Slider *slider_;
	
	float screenBottom_;
	float editBarPos_;
	float editBarHeight_;
	
	void toggleSwipe();
	bool swipe_;
	bool selectStarted_;
	cocos2d::CCPoint gridSnappeTouchPos_;
	
	void selectObjectsInRect(cocos2d::CCRect rect);
	void deselectAll();
	cocos2d::CCArray *selectedObjects_;
	
	void disableButton(CCMenuItemSpriteExtra *button);
	void enableButton(CCMenuItemSpriteExtra *button);
	CCMenuItemSpriteExtra *getButton(const char *title, int width, cocos2d::SEL_MenuHandler handler, cocos2d::CCMenu *menu);
	void onDeleteAll();
	[[deprecated("unused")]] void showDeleteConfirmation();
	void onPause();
	void onSettings();
	
	void setupDeleteMenu();
	void updateDeleteMenu();
	cocos2d::CCMenu *deleteMenu_;
	
	CCMenuItemSpriteExtra *deleteModeBtn_;
	CCMenuItemSpriteExtra *buildModeBtn_;
	CCMenuItemSpriteExtra *editModeBtn_;
	CCMenuItemSpriteExtra *swipeBtn_;
	CCMenuItemSpriteExtra *deselectBtn_;
	CCMenuItemSpriteExtra *zoomInBtn_;
	CCMenuItemSpriteExtra *zoomOutBtn_;
	
	void zoomGameLayer(bool zoomIn);
	void zoomIn();
	void zoomOut();
	
	void undoLastAction();
	void redoLastAction();
	CCMenuItemSpriteExtra *undoBtn_;
	CCMenuItemSpriteExtra *redoBtn_;
	
	CCMenuItemSpriteExtra *editObjBtn_;
	
	int unused1_;
	int unused2_;
	
	gdstd::string selectedCreateMenuObjectFrame_;
	cocos2d::CCArray *createMenuItems_;
	
	void toggleMode(CCNode *button);
	CC_SYNTHESIZE(EditMode, editMode_, EditMode);
	LevelEditorLayer *editorLayer_;
	
	float valueFromXPos(float xPos);
	float xPosFromValue(float value);
	float getXMin();
	
	void constrainGameLayerPosition();
	
	cocos2d::CCPoint getGridSnappedPos(cocos2d::CCPoint position);
	cocos2d::CCPoint touchStart_;
	cocos2d::CCPoint selectionPos_;
	cocos2d::CCPoint touchPoint_;
	cocos2d::CCPoint clickedObjectPos_;
	
	void selectObject(GameObject *object);
	void deselectObject();
	void editObject();
	GameObject *selectedObject_;
	
	bool movingGameLayer_;
	
	void clickOnPosition(cocos2d::CCPoint position);
	
	void showMaxError();
	
	void onCreate();
	void onCreateObject(const char *objectFrame);
	
	void onDelete();
	
	cocos2d::CCPoint getTouchPoint(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	
	void registerWithTouchDispatcher();
	bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

#endif //__EDITORUI_H__
