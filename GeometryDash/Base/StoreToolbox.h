#ifndef __STORETOOLBOX_H__
#define __STORETOOLBOX_H__

#include "cocos2d.h"

class CC_DLL StoreToolbox
{
public:
	static void doICheck();
	static bool isBillingSupported();
	static void purchaseItem(const char *item);
	static void restorePurchase();
	static void setupStore();
};

#endif //__STORETOOLBOX_H__
