#pragma once

#include "cocos2d.h"
#include "BaseLayer.h"

class ZorderAndTag : public BaseLayer
{
public:
	ZorderAndTag();
	~ZorderAndTag();
	CREATE_FUNC(ZorderAndTag);
	static cocos2d::CCScene* scene();
	virtual bool init();
//	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

