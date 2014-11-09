#include "T02Layer.h"

USING_NS_CC;

T02Layer::T02Layer()
{
}


T02Layer::~T02Layer()
{
}

CCScene* T02Layer::scene()
{
	CCScene* pRet = CCScene::create();

	T02Layer* pLayer = T02Layer::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T02Layer::init()
{
	if (!BaseLayer::init())
		return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	/*
		CCLayerColor:	 ���Ըı�Layer�ı������������ô�С
		CCLayerGradient: �н���Ч��(��ɫ��͸���ȶ����Խ���, ����ķ�����Ըı�)
		CCLayerMultiplex:���԰����ü����㣬����ֻ��ʾһ��
	*/

	CCLayerColor* layer1 = CCLayerColor::create(ccc4(255, 0, 0, 100), 
	    winSize.width/2, winSize.height/2);
	//addChild(layer1);

	CCLayerGradient* layer2 = CCLayerGradient::create(ccc4(255, 0, 0, 0), 
		ccc4(0, 255, 0, 100), ccp(1, 1));
	layer2->setVector(ccp(0, 1));
	layer2->changeWidthAndHeight(winSize.width / 2, winSize.height / 2);
	//addChild(layer2);

	m_pLayers = CCLayerMultiplex::create(layer1, layer2, NULL);
	//m_pLayers->switchTo(0);
	addChild(m_pLayers);

	// ��������л����
	setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);

	return true;
}

bool T02Layer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	static int s_nIndex;
	m_pLayers->switchTo(s_nIndex = 1 - s_nIndex);

	return true;
}
