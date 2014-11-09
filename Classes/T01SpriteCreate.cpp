#include "T01SpriteCreate.h"

USING_NS_CC;

T01SpriteCreate::T01SpriteCreate()
{
}
T01SpriteCreate::~T01SpriteCreate()
{
}

CCScene* T01SpriteCreate::scene()
{
	CCScene* pRet = CCScene::create();

	T01SpriteCreate* pLayer = T01SpriteCreate::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	} else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T01SpriteCreate::init()
{
	if (!BaseLayer::init())
		return false;

#if 0
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	// 1. ͨ���ļ�ֱ�Ӵ�������
	//CCSprite* pSp = CCSprite::create();
	//CCSprite* pSp = CCSprite::create("HelloWorld.png", CCRect(0, 0, 80, 80));
	//CCSprite* pSp = CCSprite::create("HelloWorld.png");

	// 2. ͨ������������
	CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("HelloWorld.png");
	//CCSprite* pSp1 = CCSprite::createWithTexture(texture);
	//CCSprite* pSp2 = CCSprite::createWithTexture(texture);
	//CCSprite* pSp3 = CCSprite::createWithTexture(texture);
	//CCSprite* pSp4 = CCSprite::createWithTexture(texture, CCRect(0, 0, 80, 80));

	// 3. ͨ��֡��������
	CCSize size = texture->getContentSize();
	CCSpriteFrame* frame = CCSpriteFrame::createWithTexture(texture,
		CCRect(size.width / 4, size.height / 4, size.width / 2, size.height / 2));
	CCSprite* pSp5 = CCSprite::createWithSpriteFrame(frame);

	// 4. ͨ������֡���洴������
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(frame, "MyFrame");
	CCSprite *pSp6 = CCSprite::createWithSpriteFrameName("MyFrame");
	addChild(pSp6);
	pSp6->setPosition(ccp(winSize.width / 2, winSize.height / 2));
#endif

	return true;
}
