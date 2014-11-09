#pragma once

#include "cocos2d.h"
#include "BaseLayer.h"

class T10EditBox : public BaseLayer
{
public:
	T10EditBox();
	~T10EditBox();
	CREATE_FUNC(T10EditBox);
	static cocos2d::CCScene* scene();
	virtual bool init();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

