#pragma once

#include "cocos2d.h"
#include "BaseLayer.h"

class T02Layer : public BaseLayer
{
public:
	T02Layer();
	~T02Layer();
	CREATE_FUNC(T02Layer);
	static cocos2d::CCScene* scene();
	virtual bool init();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

private:
	cocos2d::CCLayerMultiplex* m_pLayers;
};

