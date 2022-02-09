#ifndef __COLORSELECTPOPUP_H__
#define __COLORSELECTPOPUP_H__

#include "../../Base/Slider.h"
#include "ColorPickerPopup.h"

class ColorSelectPopup;

class CC_DLL ColorSelectDelegate
{
public:
	void colorSelectClosed(ColorSelectPopup *colorSelect);
};

class CC_DLL ColorSelectPopup : public FLAlertLayer {
public:
	~ColorSelectPopup();
	
	static ColorSelectPopup *create(GameObject *object);
	bool init();
	
	void closeColorSelect();
	
	cocos2d::ccColor3B getColorValue();
	void selectColor(cocos2d::ccColor3B color);
	
	void show();
	
	cocos2d::extension::CCControlColourPicker colorPicker_;
	[[deprecated("unused")]] cocos2d::ccColor3B color_;
	cocos2d::CCLabelBMFont *durLabel_;
	Slider *slider_;
	GameObject *object_;
	CC_SYNTHESIZE(ColorPickerDelegate*, delegate_, Delegate);
	CC_SYNTHESIZE(float, duration_, Duration);
};

#endif //__COLORSELECTPOPUP_H__
