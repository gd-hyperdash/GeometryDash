#ifndef __GAMESTOREMANAGER_H__
#define __GAMESTOREMANAGER_H__

#include "GManager.h"

class CC_DLL GameStoreManager
	: public GManager
{
public:
	~GameStoreManager();
	
	static GameStoreManager *sharedState();
	bool init();
	
	void dataLoaded(DS_Dictionary *dict);
	void encodeDataTo(DS_Dictionary *dict);
	void firstLoad();
	void setup();
	
	[[deprecated("unused")]] void claimItems(const char *url);
	[[deprecated("unused")]] void onClaimItemsComplete(CCNode *sender, void *data);
	[[deprecated("unused")]] void displayGoldError();
	[[deprecated("unused")]] int boughtGold(int purchaseType);
	
	[[deprecated("unused")]] cocos2d::CCArray *getAllItemsForCategory(const char *category);
	[[deprecated("unused")]] cocos2d::CCArray *getCategory(const char *category);
	[[deprecated("unused")]] cocos2d::CCArray *getShopCategories();
	[[deprecated("unused")]] void sortCategories();
	cocos2d::CCDictionary *categories_;
	
	[[deprecated("unimplemented")]] void playBuySound();
	[[deprecated("unused")]] bool isBillingSupported();
	[[deprecated("unimplemented")]] void purchaseConsumable(const char *item, int count, int price);
	[[deprecated("unused")]] void purchaseItem(const char *item);
	[[deprecated("unused")]] void itemPurchaseFailed(const char *item);
	[[deprecated("unused")]] void itemPurchased(const char *item);
	[[deprecated("unused")]] void itemRefunded(const char *item);
	[[deprecated("unused")]] void addCount(int count, const char *item);
	[[deprecated("unused")]] void consumeItem(const char *item);
	[[deprecated("unused")]] int countForItem(const char *item);
	[[deprecated("unused")]] void setCount(int count, const char *item);
	cocos2d::CCDictionary *storeData_;
	
	int unused_;
	
	[[deprecated("unused")]] void restorePurchases();
	[[deprecated("unused")]] void displayItemRestore(bool premium, bool mysteryMachine);
	[[deprecated("unused")]] void purchaseFeature(const char *featureID);
	[[deprecated("unused")]] void unlockFeature(const char *featureID);
	[[deprecated("unused")]] void eventUnlockFeature(const char *featureID);
	[[deprecated("unused")]] bool isFeatureUnlocked(const char *featureID);
	[[deprecated("unused")]] cocos2d::CCDictionary *dictForFeatureID(const char *featureID);
	CC_SYNTHESIZE_READONLY(cocos2d::CCDictionary*, shopItems_, ShopItems);
};

#endif //__GAMESTOREMANAGER_H__
