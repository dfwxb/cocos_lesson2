#include "T12MenuItems.h"

USING_NS_CC;

T12MenuItems::T12MenuItems()
{
}
T12MenuItems::~T12MenuItems()
{
}

CCScene* T12MenuItems::scene()
{
	CCScene* pRet = CCScene::create();

	T12MenuItems* pLayer = T12MenuItems::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T12MenuItems::init()
{
	if (!BaseLayer::init())
		return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint ptCenter = ccp(winSize.width / 2, winSize.height / 2);

	CCMenu* pMenu = CCMenu::create();
	addChild(pMenu);
	//pMenu->setPosition(ccp(0, 0));

	CCMenuItemFont* pItemFont = CCMenuItemFont::create("This is item");
	CCMenuItemAtlasFont* pItemAtlasFont = CCMenuItemAtlasFont::create("123456", "labelatlasimg.png", 24, 32, '0');
	CCMenuItemImage *pItemImg = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png");

	CCMenuItemLabel* pItemLabelTTF = CCMenuItemLabel::create(CCLabelTTF::create("This is ttf item", "Arial", 20));
	CCMenuItemLabel* pItemLabelAtlas = CCMenuItemLabel::create(CCLabelAtlas::create("1456", "labelatlasimg.png", 24, 32, '0'));
	CCMenuItemLabel* pItemLabelBMFont = CCMenuItemLabel::create(CCLabelBMFont::create("ABC", "bitmapFontTest.fnt"));

	CCMenuItemSprite* pItemSprite = CCMenuItemSprite::create(CCSprite::create("CloseNormal.png"),
		CCSprite::create("CloseSelected.png"));

	CCMenuItem* pSubItem1 = CCMenuItemFont::create("On");
	CCMenuItem* pSubItem2 = CCMenuItemFont::create("Off");
	CCMenuItemToggle* PItemToggle = CCMenuItemToggle::create(pSubItem1);
	PItemToggle->addSubItem(pSubItem2);

	pMenu->addChild(pItemFont);
	pMenu->addChild(pItemAtlasFont);
	pMenu->addChild(pItemImg);
	pMenu->addChild(pItemLabelTTF);
	pMenu->addChild(pItemLabelAtlas);
	pMenu->addChild(pItemLabelBMFont);
	pMenu->addChild(pItemSprite);
	pMenu->addChild(PItemToggle);

	pMenu->alignItemsVertically();

	CCArray* pItems = pMenu->getChildren();

	int nIndex = 0;
	float dt = 2.0f;
	CCObject* pObj = NULL;
	CCARRAY_FOREACH(pItems, pObj) {
		CCMenuItem* pItem = dynamic_cast<CCMenuItem*>(pObj);

		CCDelayTime* pDelay = CCDelayTime::create(dt * nIndex);

		if (nIndex % 2 == 0) {
			pItem->setPositionX(pItem->getPositionX() - winSize.width);
			pItem->runAction(CCSequence::create(
				pDelay,
				CCEaseElasticOut::create(
				CCMoveBy::create(dt, ccp(winSize.width, 0))), 
				NULL));
		}
		else {
			pItem->setPositionX(pItem->getPositionX() + winSize.width);
			pItem->runAction(CCSequence::create(
				pDelay,
				CCEaseElasticOut::create(
				CCMoveBy::create(dt, ccp(-winSize.width, 0))),
				NULL));
		}
		
		nIndex++;
	}

	setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);

	return true;
}


bool T12MenuItems::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void T12MenuItems::menuHandle(CCObject* pSender)
{
	
}

