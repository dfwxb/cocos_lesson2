#pragma once
#include "cocos2d.h"
class BaseLayer : public cocos2d::CCLayer
{
public:
	BaseLayer();
	~BaseLayer();
	//CREATE_FUNC(BaseLayer);
	virtual bool init();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	void doBack(cocos2d::CCObject* pSender);
};

