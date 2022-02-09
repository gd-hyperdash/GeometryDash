#ifndef __RINGOBJECT_H__
#define __RINGOBJECT_H__

#include "../Object/GameObject.h"

class CC_DLL RingObject
	: public GameObject
{
public:
	static RingObject *create(const char *frame);
	bool init(const char *frame);
	
	void setPosition(const cocos2d::CCPoint &position);
	void setVisible(bool value);
	void setScale(float value);
	
	void resetObject();
	
	void triggerActivated();
	void powerOnObject();
	void powerOffObject();
	
	void spawnCircle();
	
	[[deprecated("unused")]] void updateColors(cocos2d::ccColor3B color);
	
};

#endif //__RINGOBJECT_H__
