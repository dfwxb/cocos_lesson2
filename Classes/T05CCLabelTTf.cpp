#include "T05CCLabelTTf.h"

USING_NS_CC;

T05CCLabelTTf::T05CCLabelTTf()
{
}
T05CCLabelTTf::~T05CCLabelTTf()
{
}


CCScene* T05CCLabelTTf::scene()
{
	CCScene* pRet = CCScene::create();

	T05CCLabelTTf* pLayer = T05CCLabelTTf::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T05CCLabelTTf::init()
{
	if (!BaseLayer::init())
		return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	/*
		�ṩ������������ʾ����
		CCLabelTTf,CCLabelAtlas,CCLabelIBMFont
	*/
	CCLabelTTF* pLabelTTf = CCLabelTTF::create("Hello,World", "Arial", 30);
	addChild(pLabelTTf);
	pLabelTTf->setPosition(ccp(winSize.width / 2, winSize.height / 2));

	setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);

	return true;
}

bool T05CCLabelTTf::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void T05CCLabelTTf::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	// ��ô����ƶ��ľ���
#if 0
	CCPoint ptDelta = pTouch->getDelta();
	CCPoint ptLayer = getPosition();
	ptLayer = ccpAdd(ptLayer, ptDelta);
	setPosition(ptLayer);
#endif

	// ֻ���»���
	CCPoint ptDelta = pTouch->getDelta();
	setPositionY(getPositionY() + ptDelta.y);
}