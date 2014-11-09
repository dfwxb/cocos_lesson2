#include "T25Action.h"


T25Action::T25Action()
{
}
T25Action::~T25Action()
{
}

CCScene* T25Action::scene()
{
	CCScene* pRet = CCScene::create();

	T25Action* pLayer = T25Action::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T25Action::init()
{
	if (!BaseLayer::init()) return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint ptCenter = ccp(winSize.width / 2, winSize.height / 2);

	CCSprite* pSprite = CCSprite::create("CloseNormal.png");
	addChild(pSprite);
	pSprite->setPosition(ccp(200, 200));

	// ����һ��ʱ��
	CCMoveTo* moveTo = CCMoveTo::create(2.0f, ccp(100, 100));
	//pSprite->runAction(moveTo);

	// ��������
	CCPlace *place = CCPlace::create(ccp(400, 300));
	//pSprite->runAction(place);

	// ˳��ִ��
	CCSequence* seq = CCSequence::create(moveTo, place, NULL);
	//pSprite->runAction(seq);

	// ����ִ��
	CCSpawn *spawn = CCSpawn::create(moveTo, place, NULL);
	//pSprite->runAction(spawn);

	// ������ת
	CCMoveBy *moveBy = CCMoveBy::create(2.0f, ccp(100, 100));
	CCAction *moveBack = moveBy->reverse();
	CCSequence* seq1 = CCSequence::create(moveBy, moveBack, NULL);
	pSprite->runAction(seq1);

	// repeat�ظ�
	pSprite->runAction(CCRepeatForever::create(seq1));

	//setTouchEnabled(true);
	//setTouchMode(kCCTouchesOneByOne);

	return true;
}
