#include "T14SwitchControl.h"

T14SwitchControl::T14SwitchControl()
{
}
T14SwitchControl::~T14SwitchControl()
{
}

CCScene* T14SwitchControl::scene()
{
	CCScene* pRet = CCScene::create();

	T14SwitchControl* pLayer = T14SwitchControl::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T14SwitchControl::init()
{
	if (!BaseLayer::init()) return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	CCControlSwitch * pSwitchControl = CCControlSwitch::create(
		CCSprite::create("switch-mask.png"),
		CCSprite::create("switch-on.png"),
		CCSprite::create("switch-off.png"),
		CCSprite::create("switch-thumb.png"),
		CCLabelTTF::create("ON", "Arial", 16),
		CCLabelTTF::create("OFF", "Arial", 16));
	addChild(pSwitchControl);
	pSwitchControl->setPosition(winSize.width/2, winSize.height/2);

	// +事件处理函数
	pSwitchControl->addTargetWithActionForControlEvents(
		this, 
		cccontrol_selector(T14SwitchControl::switchValueChange), 
		CCControlEventValueChanged);

	pSwitchControl->addTargetWithActionForControlEvents(
		this,
		cccontrol_selector(T14SwitchControl::switchValueChange),
		CCControlEventTouchDown);
	return true;
}


void  T14SwitchControl::switchValueChange(
	CCObject* pSender, CCControlEvent event)
{
	if (event == CCControlEventValueChanged) {
		CCControlSwitch* pSwitch = dynamic_cast<CCControlSwitch*>(pSender);
		if (pSwitch->isOn()) {
			CCLog("-----On-------");
		}
		else {
			CCLog("-----Off-------");
		}
	}
}