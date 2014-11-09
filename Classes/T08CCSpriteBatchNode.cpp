#include "T08CCSpriteBatchNode.h"

USING_NS_CC;

T08CCSpriteBatchNode::T08CCSpriteBatchNode()
{
}
T08CCSpriteBatchNode::~T08CCSpriteBatchNode()
{
}

CCScene* T08CCSpriteBatchNode::scene()
{
	CCScene* pRet = CCScene::create();

	T08CCSpriteBatchNode* pLayer = T08CCSpriteBatchNode::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T08CCSpriteBatchNode::init()
{
	if (!BaseLayer::init())
		return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint ptCenter = ccp(winSize.width / 2, winSize.height / 2);

	/*
		CCSpriteBatchNode是一个容器，只能包容CCSprite对象，要求这些精灵来自同一个纹理
	*/

	CCSpriteBatchNode* pBatch = CCSpriteBatchNode::create("CloseNormal.png");
	addChild(pBatch);
	pBatch->setTag(10);

	CCSprite *pSprite = CCSprite::createWithTexture(pBatch->getTexture());
	pBatch->addChild(pSprite);
	pSprite->setPosition(ptCenter);

	setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);

	return true;
}


bool T08CCSpriteBatchNode::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	CCSpriteBatchNode* pBatch = (CCSpriteBatchNode*)getChildByTag(10);

	for (int i = 0; i < 1000; i++) {
		CCSprite* pSprite = CCSprite::create("CloseNormal.png");
		pBatch->addChild(pSprite);
		pSprite->setPosition(ccp(CCRANDOM_0_1()*winSize.width, CCRANDOM_0_1()*winSize.height));
	}

	return true;
}
