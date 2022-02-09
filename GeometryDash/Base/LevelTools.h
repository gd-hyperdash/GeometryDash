#ifndef __LEVELTOOLS_H__
#define __LEVELTOOLS_H__

#include "cocos2d.h"

class GJGameLevel;

class CC_DLL LevelTools
{
public:
	static const char *nameForArtist(int artist);
	
	static const char *fbURLForArtist(int artist);
	static const char *ngURLForArtist(int artist);
	static const char *ytURLForArtist(int artist);
	
	static int artistForAudio(int audioTrack);
	
	static const char *getAudioFileName(int audioTrack);
	static const char *getAudioTitle(int audioTrack);
	static const char *urlForAudio(int audioTrack);
	static int getAudioBPM(int audioTrack);

#define SYM_getAudioString "_ZN10LevelTools14getAudioStringEi"

	[[link_name(SYM_getAudioString)]]
	static gdstd::string getAudioString(int audioTrack);

#undef SYM_getAudioString
	
	static GJGameLevel *getLevel(int levelID);
};

#endif //__LEVELTOOLS_H__
