#pragma once

#include "BaseLayer.h"

USING_NS_CC;

class T24Memory : public BaseLayer
{
public:
	T24Memory();
	~T24Memory();
	CREATE_FUNC(T24Memory);
	static CCScene* scene();
	virtual bool init();
};

