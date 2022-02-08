#ifndef __UNDOOBJECT_H__
#define __UNDOOBJECT_H__

#include "GeometryDash/Object/GameObject.h"

enum UndoCommand
{
	kUndoNone,
	kUndoRemoveObject,
	kUndoCreateobject
};

class CC_DLL UndoObject
	: public cocos2d::CCNode
{
public:
	~UndoObject();

	static UndoObject* create(GameObject* object, UndoCommand command);
	bool init(GameObject* object, UndoCommand command);

	CC_SYNTHESIZE_READONLY(GameObject*, object_, Object);
	CC_SYNTHESIZE_READONLY(UndoCommand, command_, Command);
};

#endif