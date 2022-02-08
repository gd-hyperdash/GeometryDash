#ifndef __ENDPORTALOBJECT_H__
#define __ENDPORTALOBJECT_H__

#include "GeometryDash/Object/GameObject.h"

class CC_DLL EndPortalObject
	: public GameObject
{
public:
	static EndPortalObject *create();
	bool init();
	
	void setPosition(const cocos2d::CCPoint &position);
	void setVisible(bool value);
	
	void calculateSpawnXPos();
	void triggerObject();
	
	void updateColors(cocos2d::ccColor3B value);
	
	CCSprite *portalBar_;
};

#endif //__ENDPORTALOBJECT_H__
