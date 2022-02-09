#ifndef __SONGINFOLAYER_H__
#define __SONGINFOLAYER_H__

#include "../../Object/SongObject.h"
#include "FLAlertLayer.h"

class CC_DLL SongInfoLayer
	: public FLAlertLayer
{
public:
	~SongInfoLayer();
	
	static SongInfoLayer *create(SongObject *songObject);
	bool init(SongObject *songObject);
	
	void keyBackClicked();
	
	void onClose();
	void onDownload();
	void onFB();
	void onNG();
	void onYT();
	
	SongObject *songObject_;
};

#endif //__SONGINFOLAYER_H__
