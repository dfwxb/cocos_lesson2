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

	// ��֡ѭ��ÿ�ε���this->update()����
	scheduleUpdate();

	// ÿ��1/60�����
	schedule(schedule_selector(T19Update::scheduleFunc));

	// ÿ���������
	schedule(schedule_selector(T19Update::scheduleFunc), 2.0f);

	// ���޴����Ķ�ʱ���� �������ܴ�ʱ�ͳ�Ϊ���ޣ�����ʱ����,ʵ�ʴ���Ϊָ������+1
	schedule(schedule_selector(T19Update::scheduleFunc), 2.0f, 8, 3.0f);

	// ֻ����һ�Σ�����Ϊ��ʱ
	scheduleOnce(schedule_selector(T19Update::scheduleFunc), 2.0f);

	// ȡ����ʱ��, ֹͣ�Բ���Ϊ�ص������Ķ�ʱ��
	unschedule(schedule_selector(T19Update::scheduleFunc));

	// ֹͣupdate()����
	unscheduleUpdate();

	// ֹͣ���еĵ���
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