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
		CCLayerColor:	 可以改变Layer的背景，可以设置大小
		CCLayerGradient: 有渐变效果(颜色和透明度都可以渐变, 渐变的方向可以改变)
		CCLayerMultiplex:可以包含好几个层，但是只显示一个
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

	// 用鼠标来切换多层
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
