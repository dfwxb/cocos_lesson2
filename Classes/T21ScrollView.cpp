#include "T21ScrollView.h"

T21ScrollView::T21ScrollView()
{
}
T21ScrollView::~T21ScrollView()
{
}

CCScene* T21ScrollView::scene()
{
	CCScene* pRet = CCScene::create();

	T21ScrollView* pLayer = T21ScrollView::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T21ScrollView::init()
{
	if (!BaseLayer::init()) return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint ptCenter = ccp(winSize.width / 2, winSize.height / 2);

	CCNode* pNode = CCNode::create();
	m_pContainer = pNode;

	for (int i = 0; i < 5; i++) {
		CCSprite *pSprite = CCSprite::create("HelloWorld.png");
		pNode->addChild(pSprite);
		pSprite->setPosition(ptCenter + ccp(winSize.width * i, 0));
	}
	
	CCScrollView* pScrollView = CCScrollView::create(winSize, pNode);
	addChild(pScrollView);
	// 设置方向为垂直
	pScrollView->setDirection(kCCScrollViewDirectionHorizontal);
	// 让scrollview知道内容的总大小
	pScrollView->setContentSize(CCSize(winSize.width * 5, winSize.height));
	// 设置代理
	pScrollView->setDelegate(this);
	// 去掉弹性
	//pScrollView->setBounceable(false);

	setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);

	return true;
}

bool T21ScrollView::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void T21ScrollView::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint ptClickDown = pTouch->getStartLocation();
	CCPoint ptUp = pTouch->getLocation();

	CCNode* pContaner = m_pContainer;
	if (!pContaner) return;

	if (ptUp.getDistanceSq(ptClickDown) <= 25) {
		// 检查点击的是哪一个图片
		CCPoint ptInContainer = pContaner->convertToNodeSpace(ptUp);
		CCArray* arr = pContaner->getChildren();

		for (int i = 0; i < arr->count(); i++) {
			CCSprite* pSprite = (CCSprite*)arr->objectAtIndex(i);
			if (pSprite->boundingBox().containsPoint(ptInContainer)) {
				CCLog("------click i=%d-----", i);
				break;
			}
		}
	} 
	else {
		int x = m_pContainer->getPositionX();
		if (x >= -1920 && x <= 0) {
			// 调整(0, -480, -1440, -1920)
			int idx = (-x + 240) / 480;
			x = -idx * 480;
			this->m_pContainer->runAction(CCMoveTo::create(0.5f, ccp(x, m_pContainer->getPositionY())));
		}
	}
}

void T21ScrollView::scrollViewDidScroll(CCScrollView* view)
{
	CCPoint pt = m_pContainer->getPosition();
	CCLOG("pt.x=%f,pt.y=%f", pt.x, pt.y);
}

void T21ScrollView::scrollViewDidZoom(CCScrollView* view)
{

}
