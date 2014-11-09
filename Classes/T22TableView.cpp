#include "T22TableView.h"


T22TableView::T22TableView()
{
	m_pCells = CCArray::create();
	m_pCells->retain();
}
T22TableView::~T22TableView()
{
		CC_SAFE_RELEASE(m_pCells);
}

CCScene* T22TableView::scene()
{
	CCScene* pRet = CCScene::create();

	T22TableView* pLayer = T22TableView::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T22TableView::init()
{
	if (!BaseLayer::init()) return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint ptCenter = ccp(winSize.width / 2, winSize.height / 2);

	// 创建CCTableViewCell
	for (int i = 0; i < 5; i++) {
		CCTableViewCell *pCell = new CCTableViewCell();
		if (pCell) {
			pCell->autorelease();
			m_pCells->addObject(pCell);
			CCSprite* pSprite = CCSprite::create("HelloWorld.png");
			pCell->addChild(pSprite);
			pSprite->setPosition(ptCenter);
		}
		else {
			CC_SAFE_DELETE(pCell);
		}
	}
	// 创建CCTableView
	CCTableView* pTableView = CCTableView::create(this, winSize);
	addChild(pTableView);
	// 设置方向为水平
	pTableView->setDirection(kCCScrollViewDirectionHorizontal); 
	// 改变方向之后重新加载
	pTableView->reloadData();
	// 设置代理类
	pTableView->setDelegate(this);
	
	//setTouchEnabled(true);
	//setTouchMode(kCCTouchesOneByOne);

	return true;
}
