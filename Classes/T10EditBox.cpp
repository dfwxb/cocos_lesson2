#include "T10EditBox.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

T10EditBox::T10EditBox()
{
}
T10EditBox::~T10EditBox()
{
}

CCScene* T10EditBox::scene()
{
	CCScene* pRet = CCScene::create();

	T10EditBox* pLayer = T10EditBox::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T10EditBox::init()
{
	if (!BaseLayer::init())
		return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint ptCenter = ccp(winSize.width / 2, winSize.height / 2);

	CCScale9Sprite* pBgSprite = CCScale9Sprite::create("green_edit.png");
	pBgSprite->setContentSize(CCSize(100, 30));
	CCEditBox* pEditBox = CCEditBox::create(CCSize(100, 30), pBgSprite);
	addChild(pEditBox);
	pEditBox->setPosition(ptCenter);
	pEditBox->setPlaceHolder("Input here");
	pEditBox->setFont("Arial", 20);
	pEditBox->setMaxLength(10);

	// 设置回车按钮的样子
	pEditBox->setReturnType(kKeyboardReturnTypeGo);

	pEditBox->setInputFlag(kEditBoxInputFlagInitialCapsAllCharacters);
	pEditBox->setInputMode(kEditBoxInputModeEmailAddr);

//	setTouchEnabled(true);
//	setTouchMode(kCCTouchesOneByOne);

	return true;
}


bool T10EditBox::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}
