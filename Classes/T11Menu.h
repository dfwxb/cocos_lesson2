#pragma once

#include "cocos2d.h"
#include "BaseLayer.h"

class T11Menu : public BaseLayer
{
public:
	T11Menu();
	~T11Menu();
	CREATE_FUNC(T11Menu);
	static cocos2d::CCScene* scene();
	virtual bool init();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	void menuHandle(cocos2d::CCObject* pSender);

};

