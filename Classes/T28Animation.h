#pragma once

#include "BaseLayer.h"

USING_NS_CC;

class T28Animation : public BaseLayer
{
public:
	T28Animation();
	~T28Animation();
	CREATE_FUNC(T28Animation);
	static CCScene* scene();
	virtual bool init();
};

