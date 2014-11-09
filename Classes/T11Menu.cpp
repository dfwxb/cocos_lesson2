#include "T11Menu.h"

USING_NS_CC;

T11Menu::T11Menu()
{
}
T11Menu::~T11Menu()
{
}

CCScene* T11Menu::scene()
{
	CCScene* pRet = CCScene::create();

	T11Menu* pLayer = T11Menu::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T11Menu::init()
{
	if (!BaseLayer::init())
		return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint ptCenter = ccp(winSize.width / 2, winSize.height / 2);

	CCMenu* pMenu = CCMenu::create();
	addChild(pMenu);
	pMenu->setPosition(ccp(0, 0));

	// 默认坐标在中心
	CCMenuItemFont* pItemFont = CCMenuItemFont::create("This is item");
	CCMenuItemFont* pItemFont2 = CCMenuItemFont::create("This is item2");
	pMenu->addChild(pItemFont);
	pMenu->addChild(pItemFont2);

	pItemFont->setPosition(ccp(winSize.width / 2, winSize.height / 2 - 50));
	pItemFont2->setPosition(ccp(winSize.width / 2, winSize.height / 2 + 50));

	// 设置响应函数
	pItemFont->setTarget(this, menu_selector(T11Menu::menuHandle));
	pItemFont2->setTarget(this, menu_selector(T11Menu::menuHandle));

	pItemFont->setTag(1);
	pItemFont2->setTag(2);

	setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);

	return true;
}


bool T11Menu::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void T11Menu::menuHandle(CCObject* pSender)
{
	CCMenuItemFont* pItem = dynamic_cast<CCMenuItemFont*>(pSender);

	if (pItem->getTag() == 1) {
		CCLog("----Clicked1-----");
	}
	else if (pItem->getTag() == 2) {
		CCLog("----Clicked2-----");
	}
}
