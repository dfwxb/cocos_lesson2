#pragma once

#include "BaseLayer.h"

USING_NS_CC;

class AnimationPreLoad : public BaseLayer
{
public:
	AnimationPreLoad();
	~AnimationPreLoad();
	CREATE_FUNC(AnimationPreLoad);
	static CCScene* scene();
	virtual bool init();

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
};

