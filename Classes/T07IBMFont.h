#pragma once
#include "cocos2d.h"
#include "BaseLayer.h"

class T07IBMFont : public BaseLayer
{
public:
	T07IBMFont();
	~T07IBMFont();
	CREATE_FUNC(T07IBMFont);
	static cocos2d::CCScene* scene();
	virtual bool init();
};

