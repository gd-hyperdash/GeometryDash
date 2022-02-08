#ifndef __GAMETOOLBOX_H__
#define __GAMETOOLBOX_H__

#include "cocos2d.h"

class CC_DLL GameToolbox
{
public:
	/* Reposition the nodes in array so they will be aligned horisontally */
	static void alignItemsHorisontally(cocos2d::CCArray *items, float distance, cocos2d::CCPoint position);
	/* Reposition the nodes in array so they will be aligned vertically */
	[[deprecated("unused")]] static void alignItemsVertically(cocos2d::CCArray *items, float distance, cocos2d::CCPoint position);
	static bool doWeHaveInternet();
	[[deprecated("unused")]] static cocos2d::CCSequence *getDropActionWDelay(float delay, float fadeDuration, float scale, cocos2d::CCNode *target, cocos2d::SEL_CallFunc handler);
	[[deprecated("unused")]] static cocos2d::CCSequence *getDropActionWEnd(float delay, float fadeDuration, float scale, cocos2d::CCAction *end, float endDelay);

#define SYM_getResponse "_ZN11GameToolbox11getResponseEPN7cocos2d9extension14CCHttpResponseE"

	/* Get response string from CCHttpResponse */
	[[link_name(SYM_getResponse)]]
	static gdstd::string getResponse(cocos2d::extension::CCHttpResponse *response);

#undef SYM_getResponse

	static bool isIOS();

#define SYM_openRateURL "_ZN11GameToolbox11openRateURLESsSs"

	[[deprecated("unused"), link_name(SYM_openRateURL)]]
	static void openRateURL(
		gdstd::string unused1,
		gdstd::string unused2);

#undef SYM_openRateURL

	/* Define a scissor box.
	 * \param target the node to visit
	 * \param rect the scissor box
	 * \param spaceNode the node used for convertToWorldSpace, if it's nullptr target's parent is used instead
	 */
	[[deprecated("unused")]] static void preVisitWithClippingRect(cocos2d::CCNode *target, cocos2d::CCRect rect, cocos2d::CCNode *spaceNode);
	static void postClipVisit();
};

#endif //__GAMETOOLBOX_H__
