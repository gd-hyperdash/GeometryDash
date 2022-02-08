#ifndef __PLATFORMTOOLBOX_H__
#define __PLATFORMTOOLBOX_H__

#include "cocos2d.h"

class CC_DLL PlatformToolbox
{
public:
	static void activateGameCenter();

#define SYM_doesFileExist "_ZN15PlatformToolbox13doesFileExistESs"

	[[link_name(SYM_doesFileExist)]]
	static bool doesFileExist(gdstd::string filename);

#undef SYM_doesFileExist

#define SYM_downloadAndSavePromoImage "_ZN15PlatformToolbox25downloadAndSavePromoImageESsSs"

	[[link_name(SYM_downloadAndSavePromoImage)]]
	static void downloadAndSavePromoImage(
		gdstd::string game,
		gdstd::string file);

#undef SYM_downloadAndSavePromoImage
	
#define SYM_getUniqueUserID "_ZN15PlatformToolbox15getUniqueUserIDEv"

	[[link_name(SYM_getUniqueUserID)]]
	static gdstd::string getUniqueUserID();

#undef SYM_getUniqueUserID

#define SYM_getUserID "_ZN15PlatformToolbox9getUserIDEv"

	[[link_name(SYM_getUserID)]]
	static gdstd::string getUserID();

#undef SYM_getUserID
	
	static bool isHD();
	static bool isLocalPlayerAuthenticated();
	static bool isNetworkAvailable();

#define SYM_loadAndDecryptFileToString "_ZN15PlatformToolbox26loadAndDecryptFileToStringEPKcS1_"

	[[link_name(SYM_loadAndDecryptFileToString)]]
	static gdstd::string loadAndDecryptFileToString(
		const char *filename,
		const char *path);

#undef SYM_loadAndDecryptFileToString

	static void logEvent(const char *event);
	static void onGameLaunch();
	static void onNativeResume();
	static void onNativePause();
	static void onToggleKeyboard();
	static void openAppPage();
	static void reportAchievementWithID(const char *achievementID, int percentage);
	static void reportLoadingFinished();

#define SYM_saveAndEncryptStringToFile "_ZN15PlatformToolbox26saveAndEncryptStringToFileESsPKcS1_"

	[[link_name(SYM_saveAndEncryptStringToFile)]]
	static void saveAndEncryptStringToFile(
		gdstd::string str,
		const char *filename,
		const char *path);

#undef SYM_saveAndEncryptStringToFile

	static void sendMail(const char *subject, const char *text, const char *email);
	static void setBlockBackButton(bool value);
	static void setKeyboardState(bool enabled);
	static bool shouldResumeSound();
	static void showAchievements();

#define SYM_spriteFromSavedFile "_ZN15PlatformToolbox19spriteFromSavedFileESs"

	[[link_name(SYM_spriteFromSavedFile)]]
	static cocos2d::CCSprite *spriteFromSavedFile(gdstd::string file);

#undef SYM_spriteFromSavedFile

	static void startFlurry(const char *id);

#define SYM_tryShowRateDialog "_ZN15PlatformToolbox17tryShowRateDialogESs"

	[[link_name(SYM_tryShowRateDialog)]]
	static void tryShowRateDialog(gdstd::string text);

#undef SYM_tryShowRateDialog
};

#endif //__PLATFORMTOOLBOX_H__
