#include "T23TableViewSmall.h"


T23TableViewSmall::T23TableViewSmall()
{
	m_pCells = CCArray::create();
	m_pCells->retain();
}
T23TableViewSmall::~T23TableViewSmall()
{
	CC_SAFE_RELEASE(m_pCells);
}

CCScene* T23TableViewSmall::scene()
{
	CCScene* pRet = CCScene::create();

	T23TableViewSmall* pLayer = T23TableViewSmall::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T23TableViewSmall
::init()
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
			CCSprite* pSprite = CCSprite::create("CloseNormal.png");
			pCell->addChild(pSprite);
			pSprite->setPosition(ccp(20, 20));
		}
		else {
			CC_SAFE_DELETE(pCell);
		}
	}
	// 创建CCTableView
	CCTableView* pTableView = CCTableView::create(this, CCSizeMake(40*3, 40));
	addChild(pTableView);
	pTableView->setPosition(ptCenter);
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
