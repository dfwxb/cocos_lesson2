#pragma once

#include "cocos-ext.h"
#include "BaseLayer.h"

USING_NS_CC_EXT;
USING_NS_CC;

class T21ScrollView : public BaseLayer, CCScrollViewDelegate {
public:
	T21ScrollView();
	~T21ScrollView();
	CREATE_FUNC(T21ScrollView);
	static CCScene* scene();
	virtual bool init();

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	// ScrollViewµÄ´úÀí
	virtual void scrollViewDidScroll(CCScrollView* view);
	virtual void scrollViewDidZoom(CCScrollView* view);

private:
	CCNode* m_pContainer;
};

