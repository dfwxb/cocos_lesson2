#pragma once
#include "cocos2d.h"
#include "BaseLayer.h"

class T06CCLabelAtlas : public BaseLayer {
public:
	T06CCLabelAtlas();
	~T06CCLabelAtlas();
	CREATE_FUNC(T06CCLabelAtlas);
	static cocos2d::CCScene* scene();
	virtual bool init();

	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

