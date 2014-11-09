#include "T03Cood.h"

USING_NS_CC;

T03Cood::T03Cood()
{
}
T03Cood::~T03Cood()
{
}

CCScene* T03Cood::scene()
{
	CCScene* pRet = CCScene::create();

	T03Cood* pLayer = T03Cood::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T03Cood::init()
{
	if (!BaseLayer::init())
		return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	/*
		GL坐标体系：左下角为原点
		UI坐标体系：左上角为原点
		世界坐标体系：是窗口的坐标体系，是GL坐标体系，原点是窗口的左下角
		节点坐标体系：原点是节点的左下角

		当一个节点调用setPositions时，使用的参数是它的父节点的坐标体系
		CCLayer和CCScene默认大小和窗口一样，所以它的坐标体系和世界坐标体系重合
	*/

	CCLayerColor* pLayerColor = CCLayerColor::create(ccc4(255, 0, 0, 255),
		winSize.width / 2, winSize.height / 2);
	addChild(pLayerColor);

	m_pSprite = CCSprite::create("CloseNormal.png");
	pLayerColor->addChild(m_pSprite);
	m_pSprite->setPosition(ccp(100, 100));

	pLayerColor->setPosition(ccp(100, 100));

	CCPoint ptSpriteInWorld = pLayerColor->convertToWorldSpace(m_pSprite->getPosition());

	CCLog("pt:x=%f, y=%f", ptSpriteInWorld.x, ptSpriteInWorld.y);

	// 以锚点作为原点来转换的结果
	CCPoint ptSpriteInWorldByAnchor = pLayerColor->convertToWorldSpaceAR(m_pSprite->getPosition());

	// 触摸处理，演示UI和GL坐标的转换
	setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);

	return true;
}

bool T03Cood::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint ptInUI = pTouch->getLocationInView();
	CCPoint ptInGL = pTouch->getLocation();

	CCPoint ptUIConvent = CCDirector::sharedDirector()->convertToGL(ptInUI);

	CCLog("%f, %f", ptInUI.x, ptInUI.y);
	CCLog("%f, %f, %f, %f", ptUIConvent.x, ptUIConvent.y, ptInGL.x, ptInGL.y);

	// 判断是否点中精灵
	// 获取精灵的矩形， 获取触摸点， 判断触摸点是否在矩形内
	CCRect rc = m_pSprite->boundingBox();
	CCPoint ptTouch = pTouch->getLocation();

	//if (rc.containsPoint(m_pSprite->getParent()->convertToNodeSpace(ptTouch))) {
	if (rc.containsPoint(m_pSprite->getParent()->convertTouchToNodeSpace(pTouch))) {
		CCLog("touch sprite");
	}

	return true;
}