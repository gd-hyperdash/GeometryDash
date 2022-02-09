#ifndef __ADTOOLBOX_H__
#define __ADTOOLBOX_H__

#include "cocos2d.h"

class CC_DLL AdToolbox
{
public:
	static void setupAds();
	
	[[deprecated("unused")]] static void cacheInterstitial();

#define SYM_cacheInterstitial "_ZN9AdToolbox17cacheInterstitialESs"

	[[deprecated("unused"), link_name(SYM_cacheInterstitial)]]
	static void cacheInterstitial(gdstd::string position);

#undef SYM_cacheInterstitial

	[[deprecated("unused")]] static void hasCachedInterstitial();

#define SYM_hasCachedInterstitial "_ZN9AdToolbox21hasCachedInterstitialESs"

	[[deprecated("unused"), link_name(SYM_hasCachedInterstitial)]]
	static void hasCachedInterstitial(gdstd::string position);

#undef SYM_hasCachedInterstitial

	[[deprecated("unused")]] static void showInterstitial();

#define SYM_showInterstitial "_ZN9AdToolbox16showInterstitialESs"
	
	[[deprecated("unused"), link_name(SYM_showInterstitial)]] 
	static void showInterstitial(gdstd::string position);
	
#undef SYM_showInterstitial
	
	[[deprecated("unused")]] static void disableBanner();
	[[deprecated("unused")]] static void enableBanner();
};

#endif //__ADTOOLBOX_H__
