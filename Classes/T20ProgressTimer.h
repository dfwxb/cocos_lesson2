#pragma once

#include "BaseLayer.h"

USING_NS_CC;

class T20ProgressTimer : public BaseLayer
{
public:
	T20ProgressTimer();
	~T20ProgressTimer();
	CREATE_FUNC(T20ProgressTimer);
	static CCScene* scene();
	virtual bool init();
	//virtual void update(float dt);
	void scheduleFunc(float dt);

	
};

