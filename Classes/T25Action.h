#pragma once

#include "BaseLayer.h"

USING_NS_CC;

class T25Action : public BaseLayer
{
public:
	T25Action();
	~T25Action();
	CREATE_FUNC(T25Action);
	static CCScene* scene();
	virtual bool init();
};

