#include "T19Update.h"


T19Update::T19Update()
{
}
T19Update::~T19Update()
{
}

CCScene* T19Update::scene()
{
	CCScene* pRet = CCScene::create();

	T19Update* pLayer = T19Update::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T19Update::init()
{
	if (!BaseLayer::init()) return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	// 让帧循环每次调用this->update()函数
	scheduleUpdate();

	// 每隔1/60秒调用
	schedule(schedule_selector(T19Update::scheduleFunc));

	// 每隔两秒调用
	schedule(schedule_selector(T19Update::scheduleFunc), 2.0f);

	// 有限次数的定时器， 当次数很大时就成为无限，可延时触发,实际次数为指定参数+1
	schedule(schedule_selector(T19Update::scheduleFunc), 2.0f, 8, 3.0f);

	// 只调用一次，参数为延时
	scheduleOnce(schedule_selector(T19Update::scheduleFunc), 2.0f);

	// 取消定时器, 停止以参数为回调函数的定时器
	unschedule(schedule_selector(T19Update::scheduleFunc));

	// 停止update()函数
	unscheduleUpdate();

	// 停止所有的调度
	unscheduleAllSelectors();

	return true;
}

void T19Update::scheduleFunc(float dt)
{
	CCLOG("------scheduleFunc-------");
}

void T19Update::update(float dt)
{
	CCLOG("------update-------");
}