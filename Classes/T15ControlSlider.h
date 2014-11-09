#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
#include "BaseLayer.h"

USING_NS_CC_EXT;
USING_NS_CC;

class T15ControlSlider : public BaseLayer {
public:
	T15ControlSlider();
	~T15ControlSlider();
	CREATE_FUNC(T15ControlSlider);
	static cocos2d::CCScene* scene();
	virtual bool init();
	void valueChange(CCObject* pSender, CCControlEvent event);
};

