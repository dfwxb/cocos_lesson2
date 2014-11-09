#ifndef __T27ActionMore_H__
#define __T27ActionMore_H__

#include "cocos-ext.h"
#include "BaseLayer.h"
USING_NS_CC;
USING_NS_CC_EXT;

class T27ActionMore : public BaseLayer
{
public:
	static CCScene* scene();

	CREATE_FUNC(T27ActionMore);
	bool init();

	bool ccTouchBegan(CCTouch*, CCEvent*);
	void ccTouchEnded(CCTouch*, CCEvent*);

	CCNode* _c;
	void testAction(int idx, CCLayerColor*);
};

#endif

