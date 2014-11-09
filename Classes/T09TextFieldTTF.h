#pragma once

#include "cocos2d.h"
#include "BaseLayer.h"

class T09TextFieldTTF : public BaseLayer {
public:
	T09TextFieldTTF();
	~T09TextFieldTTF();
	
	CREATE_FUNC(T09TextFieldTTF);
	static cocos2d::CCScene* scene();
	virtual bool init();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

