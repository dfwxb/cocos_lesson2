#pragma once

#include "BaseLayer.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class T14SwitchControl : public BaseLayer
{
public:
	T14SwitchControl();
	~T14SwitchControl();
	CREATE_FUNC(T14SwitchControl);
	static cocos2d::CCScene* scene();
	virtual bool init();
	void switchValueChange(CCObject* pSender, CCControlEvent event);
};

