#include "T09TextFieldTTF.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

T09TextFieldTTF::T09TextFieldTTF()
{
}
T09TextFieldTTF::~T09TextFieldTTF()
{
}

CCScene* T09TextFieldTTF::scene()
{
	CCScene* pRet = CCScene::create();

	T09TextFieldTTF* pLayer = T09TextFieldTTF::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T09TextFieldTTF::init()
{
	if (!BaseLayer::init())
		return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint ptCenter = ccp(winSize.width / 2, winSize.height / 2);

	CCTextFieldTTF* pTextEdit = CCTextFieldTTF::textFieldWithPlaceHolder("please input your name", "Arial", 36);
	pTextEdit->setPosition(ptCenter);
	addChild(pTextEdit);
	pTextEdit->setTag(10);

	// ÃÜÂëÊäÈë
	pTextEdit->setSecureTextEntry(true);

	// ¸ø¿Ø¼şÔö¼Ó±³¾°
	CCScale9Sprite* pBackGround = CCScale9Sprite::create("green_edit.png");
	pTextEdit->addChild(pBackGround);
	pBackGround->setAnchorPoint(ccp(0, 0));
	pBackGround->setPosition(ccp(0, 0));
	pBackGround->setContentSize(pTextEdit->boundingBox().size);
	pBackGround->setZOrder(-1);

	setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);

	return true;
}


bool T09TextFieldTTF::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCTextFieldTTF* pTextEdit = (CCTextFieldTTF*)getChildByTag(10);

	if (pTextEdit->boundingBox().containsPoint(pTouch->getLocation())) {
		// µ¯³öÈí¼üÅÌ
		pTextEdit->attachWithIME();
		CCLog("-----Touch--------");
	}
	else {
		CCLog("-----%s-----", pTextEdit->getString());
	}

	return true;
}

