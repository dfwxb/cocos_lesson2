#pragma once
#include "BaseLayer.h"

USING_NS_CC;

class T19Update : public BaseLayer
{
public:
	T19Update();
	~T19Update();
	CREATE_FUNC(T19Update);
	static CCScene* scene();
	virtual bool init();
	virtual void update(float dt);

public:
	void scheduleFunc(float dt);
};

