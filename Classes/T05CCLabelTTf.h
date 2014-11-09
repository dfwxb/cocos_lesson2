#pragma once
#include "cocos2d.h"
#include "BaseLayer.h"
class T05CCLabelTTf : public BaseLayer
{
public:
	T05CCLabelTTf();
	~T05CCLabelTTf();
	CREATE_FUNC(T05CCLabelTTf);
	static cocos2d::CCScene* scene();
	virtual bool init();

	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

