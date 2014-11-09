#pragma once

#include "cocos2d.h"
#include "BaseLayer.h"

class T03Cood : public BaseLayer {
public:
	T03Cood();
	~T03Cood();
	CREATE_FUNC(T03Cood);
	static cocos2d::CCScene* scene();
	virtual bool init();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

private:
	cocos2d::CCSprite* m_pSprite;
};

