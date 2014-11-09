#ifndef __T26ActionShow_H__
#define __T26ActionShow_H__

#include "cocos-ext.h"
#include "BaseLayer.h"
USING_NS_CC;
USING_NS_CC_EXT;

class T26ActionShow : public BaseLayer
{
public:
	static CCScene* scene();

	CREATE_FUNC(T26ActionShow);
	bool init();

	bool ccTouchBegan(CCTouch*, CCEvent*);
	void ccTouchEnded(CCTouch*, CCEvent*);

	CCNode* _c;
	void testAction(int idx, CCLayerColor*);
	void func();
	void funcN(CCNode*);
	void funcND(CCNode*, void*);
};

#endif

