#pragma once

#include "cocos2d.h"
#include "BaseLayer.h"

class T12MenuItems : BaseLayer
{
public:
	T12MenuItems();
	~T12MenuItems();

	CREATE_FUNC(T12MenuItems);
	static cocos2d::CCScene* scene();
	virtual bool init();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	void menuHandle(cocos2d::CCObject* pSender);
};

