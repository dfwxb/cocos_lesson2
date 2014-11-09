#include "T04ZorderAndTag.h"

USING_NS_CC;

ZorderAndTag::ZorderAndTag()
{
}

ZorderAndTag::~ZorderAndTag()
{
}

CCScene* ZorderAndTag::scene()
{
	CCScene* pRet = CCScene::create();

	ZorderAndTag* pLayer = ZorderAndTag::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool ZorderAndTag::init()
{
	if (!BaseLayer::init())
		return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	/*
		ZOrder: 是描述渲染顺序的值,每个CCNode都有ZOrder
			1. 默认0
			2. 越大越后绘制
			3. 如果为zorder相同，则看arrival顺序，先加入的节点先绘制
			4. 只在有相同的父节点的节点之间比较
	
		Tag: 是一个节点的身份证，可以通过getChildByTag()得到节点
			1. 意义在于减少成员变量
			2. 只在有相同的父节点的节点之间比较
			3. Tag在相同父节点的节点不能相同，相同情况下， getChildByTag()可能得不到理想的节点
			4. 一般用枚举表示Tag以防止重复
			5. Tag有时候可以当做ID使用,尤其当多个菜单项使用同一个响应函数时
	*/

	CCSprite* pSprite1 = CCSprite::create("CloseNormal.png");
	addChild(pSprite1, 1);
	pSprite1->setPosition(ccp(winSize.width / 2, winSize.height / 2));
//	pSprite1->setTag(100000);

	CCSprite* pSprite2 = CCSprite::create("HelloWorld.png");
	addChild(pSprite2);
	pSprite2->setPosition(ccp(winSize.width / 2, winSize.height / 2));

	pSprite1->setZOrder(2);

//	setTouchEnabled(true);
//	setTouchMode(kCCTouchesOneByOne);

	return true;
}

#if 0

bool ZorderAndTag::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	/*CCSprite* pSprite = dynamic_cast<CCSprite*>(getChildByTag(100000));

	if (pSprite->boundingBox().containsPoint(pTouch->getLocation())) {
	CCLog("---------Touch---------");
	pSprite->setZOrder(0);
	}*/

	return true;
}

#endif


