#include "T15ControlSlider.h"

T15ControlSlider::T15ControlSlider()
{
}
T15ControlSlider::~T15ControlSlider()
{
}

CCScene* T15ControlSlider::scene()
{
	CCScene* pRet = CCScene::create();

	T15ControlSlider* pLayer = T15ControlSlider::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T15ControlSlider::init()
{
	if (!BaseLayer::init()) return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	CCControlSlider* pSlider = CCControlSlider::create(
		"sliderTrack.png",
		"sliderProgress.png",
		"sliderThumb.png");
	addChild(pSlider);
	pSlider->setPosition(ccp(winSize.width / 2, winSize.height / 2));

	pSlider->setMinimumValue(0);
	pSlider->setMaximumValue(100);

	pSlider->setMinimumAllowedValue(10);
	pSlider->setMaximumAllowedValue(90);

	pSlider->addTargetWithActionForControlEvents(
		this,
		cccontrol_selector(T15ControlSlider::valueChange),
		CCControlEventValueChanged);

	return true;
}

void  T15ControlSlider::valueChange(
	CCObject* pSender, CCControlEvent event)
{
	if (event == CCControlEventValueChanged) {
		
		CCControlSlider* pSlider = dynamic_cast<CCControlSlider*>(pSender);
		CCLog("-----Value:%f-------", pSlider->getValue());
	}
	else {
		CCLog("-----Other-------");
	}
}
