#include "BaseLayer.h"

USING_NS_CC;

BaseLayer::BaseLayer()
{
}
BaseLayer::~BaseLayer()
{
}

bool BaseLayer::init()
{
	if (!CCLayer::init())
		return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	CCMenu *pMenu = CCMenu::create();
	addChild(pMenu);
	pMenu->setZOrder(100);

	CCMenuItem* pBackItem = CCMenuItemImage::create("CloseNormal.png",
		"CloseSelected.png", this, menu_selector(BaseLayer::doBack));
	pMenu->addChild(pBackItem);
	pBackItem->setPosition(winSize.width / 2 - pBackItem->getContentSize().width / 2,
		pBackItem->getContentSize().height / 2 - winSize.height / 2);

//	setTouchEnabled(true);
//	setTouchMode(kCCTouchesOneByOne);

	return true;
}


bool BaseLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}


void BaseLayer::doBack(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
}