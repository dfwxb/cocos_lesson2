#include "T24Memory.h"


T24Memory::T24Memory()
{
}
T24Memory::~T24Memory()
{
}


CCScene* T24Memory::scene()
{
	CCScene* pRet = CCScene::create();

	T24Memory* pLayer = T24Memory::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T24Memory::init()
{
	if (!BaseLayer::init()) return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint ptCenter = ccp(winSize.width / 2, winSize.height / 2);

	CCSprite* pSprite = CCSprite::create();

	//setTouchEnabled(true);
	//setTouchMode(kCCTouchesOneByOne);

	return true;
}