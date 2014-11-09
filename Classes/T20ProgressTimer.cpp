#include "T20ProgressTimer.h"


T20ProgressTimer::T20ProgressTimer()
{
}
T20ProgressTimer::~T20ProgressTimer()
{
}


CCScene* T20ProgressTimer::scene()
{
	CCScene* pRet = CCScene::create();

	T20ProgressTimer* pLayer = T20ProgressTimer::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T20ProgressTimer::init()
{
	if (!BaseLayer::init()) return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint ptCenter = ccp(winSize.width / 2, winSize.height / 2);

	CCSprite* pSprite = CCSprite::create("CloseNormal.png");

	CCProgressTimer* pProgress = CCProgressTimer::create(pSprite);
	addChild(pProgress);
	pProgress->setPosition(ptCenter);

	// 设置类型和变化率
	//pProgress->setType(kCCProgressTimerTypeBar);
	//pProgress->setBarChangeRate(ccp(1, 0));
	//pProgress->setMidpoint(ccp(0, 0));

	// 设置显示百分比
	pProgress->setPercentage(0.0f);

	pProgress->setTag(100);

	// 用于动画显示CCProgressTimer的进度
	CCProgressTo* pProgressTo = CCProgressTo::create(2.0f, 100.0f);
	pProgress->runAction(pProgressTo);

//	schedule(schedule_selector(T20ProgressTimer::scheduleFunc), 0.5f);

	return true;
}

void T20ProgressTimer::scheduleFunc(float dt)
{
	CCProgressTimer* pProgress = dynamic_cast<CCProgressTimer*>(getChildByTag(100));
	
	if (pProgress->getPercentage() <= 100.0f)
		pProgress->setPercentage(pProgress->getPercentage() + 1.0f);
}