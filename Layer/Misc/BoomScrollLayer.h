#ifndef __BOOMSCROLLLAYER_H__
#define __BOOMSCROLLLAYER_H__

#include "cocos2d.h"

class BoomScrollLayer;

class CC_DLL BoomScrollLayerDelegate
{
public:
	/** Called when scroll layer begins scrolling.
	 * Usefull to cancel CCTouchDispatcher standardDelegates.
	 */
	virtual void scrollLayerScrollingStarted(BoomScrollLayer* sender) {}
	
	/** Called in moveToPageEnded:
	 */
	virtual void scrollLayerScrolledToPage(BoomScrollLayer* sender, unsigned int page) {}
	
	/** Called in setPosition
	 */
	virtual void scrollLayerMoved(cocos2d::CCPoint position);
};

/* A class to overload setPosition for BoomScrollLayer */
class CC_DLL ExtendedLayer
{
public:
	static ExtendedLayer *create();
	bool init();
	
	void setPosition(const cocos2d::CCPoint &position);
	
	CC_SYNTHESIZE(BoomScrollLayerDelegate*, delegate_, Delegate);
};

class CC_DLL BoomScrollLayer
	: public cocos2d::CCLayer
{
public:
	~BoomScrollLayer();

	static BoomScrollLayer* create(cocos2d::CCArray* layers, int widthOffset, bool pagesLooped);
	bool init(cocos2d::CCArray* layers, int widthOffset, bool pagesLooped);

	cocos2d::CCArray *pageIndicators_;
	
	int previousScreen_;
	
	// The initial point the user starts their swipe
	float startSwipe_;
	
	// Current touch speed
	float touchSpeed_;
	
	bool pagesLooped_;
	
	cocos2d::CCArray *pageSetup_;
	
	void setPageSetup(cocos2d::CCArray *setup);
	
	bool dynamicScrolling_;
	
	// Internal state of scrollLayer (scrolling or idle).
	int state_;
	bool stealingTouchInProgress_;
	// Holds the touch that started the scroll
	cocos2d::CCTouch* scrollTouch_;
	
	// A count of the total screens available
	cocos2d::CCArray *layers_;

	float touchStartTime_;
	
	cocos2d::CCPoint pagePosition_;
	
	CC_SYNTHESIZE_READONLY(CCLayer*, internalLayer_, InternalLayer);
	
	// Holds the current height and width of the screen
	CC_SYNTHESIZE(cocos2d::CCRect, scrollArea_, ScrollArea);
	
	CC_SYNTHESIZE(float, minTouchSpeed_, MinTouchSpeed);
	
	CC_SYNTHESIZE(float, touchSpeedFast_, TouchSpeedFast);
	
	CC_SYNTHESIZE(float, touchSpeedMid_, TouchSpeedMid);

	CC_SYNTHESIZE(BoomScrollLayerDelegate*, delegate_, Delegate);
	
	CC_SYNTHESIZE_READONLY(bool, movingToPage_, MovingToPage);
	
	/** Calibration property. Minimum moving touch length that is enough
	 * to cancel menu items and start scrolling a layer. 
	 */
	CC_SYNTHESIZE(float, minimumTouchLengthToSlide_, MinimumTouchLengthToSlide);

	/** Calibration property. Minimum moving touch length that is enough to change
	 * the page, without snapping back to the previous selected page.
	 */
	CC_SYNTHESIZE(float, minimumTouchLengthToChangePage_, MinimumTouchLengthToChangePage);
	
	/** Offset that can be used to let user see empty space over first or last page. */
	CC_SYNTHESIZE(float, marginOffset_, MarginOffset);

	/** If YES - when starting scrolling CCScrollLayer will claim touches, that are 
	 * already claimed by others targetedTouchDelegates by calling CCTouchDispatcher#touchesCancelled
	 * Usefull to have ability to scroll with touch above menus in pages.
	 * If NO - scrolling will start, but no touches will be cancelled.
	 * Default is YES.
	 */
	CC_SYNTHESIZE(bool, stealTouches_, StealTouches);

	/** Whenever show or not white/grey dots under the scroll layer.
	 * If yes - dots will be rendered in parents transform (rendered after scroller visit).
	 */
	CC_SYNTHESIZE(bool, showPagesIndicator_, ShowPagesIndicator);

	/** Position of dots center in parent coordinates. 
	 * (Default value is screenWidth/2, screenHeight/4)
	 */
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::CCPoint, pagesIndicatorPosition_, PagesIndicatorPosition);
	
	CC_SYNTHESIZE(cocos2d::ccColor4B, pagesIndicatorSelectedColor_, PagesIndicatorSelectedColor);
	CC_SYNTHESIZE(cocos2d::ccColor4B, pagesIndicatorNormalColor_, PagesIndicatorNormalColor);
	/** Total pages available in scrollLayer. */
	unsigned int getTotalPages();

	/** Current page number, that is shown. Belongs to the [0, totalScreen] interval. */
	CC_SYNTHESIZE_READONLY(unsigned int, currentScreen_, CurrentScreen);
	
	/** Offset, that can be used to let user see next/previous page. */
	CC_SYNTHESIZE(float, pagesWidthOffset_, PagesWidthOffset);

	/** Array of pages CCLayer's  */
	CC_SYNTHESIZE_READONLY(cocos2d::CCArray*, pages_, pages);

	/** Adds new page and reorders pages trying to set given number for newly added page.
	 * If number > pages count - adds new page to the right end of the scroll layer.
	 * If number <= 0 - adds new page to the left end of the scroll layer. 
	 * @attention Designated addPage method. 
	 */
	void addPage(CCLayer* aPage, unsigned int pageNumber);

	/** Adds new page to the right end of the scroll layer. */
	void addPage(CCLayer* aPage);
	
	void quickUpdate();

	int pageNumberForPosition(cocos2d::CCPoint pos);
	int positionForPageWithNumber(int pageNumber);

	void selectPage(int pageNumber);
	void instantMoveToPage(int pageNumber);
	void moveToPage(int pageNumber);
	void moveToPageEnded();
	
	void removePage(CCLayer *page);
	void removePageWithNumber(int pageNumber);
	
	void repositionPageLooped();
	
	CCLayer *getPage(int pageNumer);
	CCLayer *getRelativePageForNum(int pageNumer);
	cocos2d::CCPoint getRelativePosForPage(int pageNumber);
	
	/* Update page indicators */
	void updateDots();
	/* Update pages positions after removing/adding pages */
	void updatePages();
	
	virtual void visit();
	
    void claimTouch(cocos2d::CCTouch* pTouch);
    void cancelAndStoleTouch(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	virtual void registerWithTouchDispatcher();
	
	virtual bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	virtual void ccTouchCancelled(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
};

#endif //__BOOMSCROLLLAYER_H__
