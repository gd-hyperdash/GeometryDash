#ifndef __COLORPICKERPOPUP_H__
#define __COLORPICKERPOPUP_H__

#include "GeometryDash/Layer/Misc/FLAlertLayer.h"
#include "GeometryDash/Object/GameObject.h"

class ColorPickerPopup;

class CC_DLL ColorPickerDelegate
{
public:
	void colorPickerClosed(ColorPickerPopup *colorPicker);
};

class CC_DLL ColorPickerPopup
	: public FLAlertLayer
{
public:
	~ColorPickerPopup();
	
	static ColorPickerPopup *create();
	bool init();
	
	void closeColorSelect();
	
	cocos2d::ccColor3B getColorValue();
	void selectColor(cocos2d::ccColor3B color);
	
	void show();
	
	cocos2d::extension::CCControlColourPicker colorPicker_;
	[[deprecated("unused")]] cocos2d::ccColor3B color_;
	[[deprecated("unused")]] GameObject *object_;
	CC_SYNTHESIZE(ColorPickerDelegate*, delegate_, Delegate);
};

#endif //__COLORPICKERPOPUP_H__
