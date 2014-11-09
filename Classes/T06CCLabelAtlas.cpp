#include "T06CCLabelAtlas.h"

USING_NS_CC;

T06CCLabelAtlas::T06CCLabelAtlas()
{
}
T06CCLabelAtlas::~T06CCLabelAtlas()
{
}

CCScene* T06CCLabelAtlas::scene()
{
	CCScene* pRet = CCScene::create();

	T06CCLabelAtlas* pLayer = T06CCLabelAtlas::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T06CCLabelAtlas::init()
{
	if (!BaseLayer::init())
		return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	/*
	提供了三个类来显示文字
	CCLabelTTf,CCLabelAtlas,CCLabelIBMFont
	*/
	

	return true;
}

bool T06CCLabelAtlas::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void T06CCLabelAtlas::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	
}
