#pragma once
#include "cocos2d.h"
#include "BaseLayer.h"

class T08CCSpriteBatchNode : public BaseLayer
{
public:
	T08CCSpriteBatchNode();
	~T08CCSpriteBatchNode();
	CREATE_FUNC(T08CCSpriteBatchNode);
	static cocos2d::CCScene* scene();
	virtual bool init();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

