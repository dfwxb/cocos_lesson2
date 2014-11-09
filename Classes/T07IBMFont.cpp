#include "T07IBMFont.h"

USING_NS_CC;

T07IBMFont::T07IBMFont()
{
}
T07IBMFont::~T07IBMFont()
{
}

CCScene* T07IBMFont::scene()
{
	CCScene* pRet = CCScene::create();

	T07IBMFont* pLayer = T07IBMFont::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T07IBMFont::init()
{
	if (!BaseLayer::init())
		return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint ptCenter = ccp(winSize.width / 2, winSize.height / 2);

	CCLabelBMFont* pLabel = CCLabelBMFont::create("ABC", "bitmapFontTest.fnt");
	addChild(pLabel);
	pLabel->setPosition(ptCenter);

	CCArray* parrSprite = pLabel->getChildren();
	CCSprite* pSprite = (CCSprite*)parrSprite->objectAtIndex(1);
	pSprite->setScale(1.5f);
	return true;
}
