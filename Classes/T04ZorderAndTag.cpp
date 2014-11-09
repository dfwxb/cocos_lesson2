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
		ZOrder: ��������Ⱦ˳���ֵ,ÿ��CCNode����ZOrder
			1. Ĭ��0
			2. Խ��Խ�����
			3. ���Ϊzorder��ͬ����arrival˳���ȼ���Ľڵ��Ȼ���
			4. ֻ������ͬ�ĸ��ڵ�Ľڵ�֮��Ƚ�
	
		Tag: ��һ���ڵ�����֤������ͨ��getChildByTag()�õ��ڵ�
			1. �������ڼ��ٳ�Ա����
			2. ֻ������ͬ�ĸ��ڵ�Ľڵ�֮��Ƚ�
			3. Tag����ͬ���ڵ�Ľڵ㲻����ͬ����ͬ����£� getChildByTag()���ܵò�������Ľڵ�
			4. һ����ö�ٱ�ʾTag�Է�ֹ�ظ�
			5. Tag��ʱ����Ե���IDʹ��,���䵱����˵���ʹ��ͬһ����Ӧ����ʱ
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


