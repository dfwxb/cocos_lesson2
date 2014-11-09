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
		GL������ϵ�����½�Ϊԭ��
		UI������ϵ�����Ͻ�Ϊԭ��
		����������ϵ���Ǵ��ڵ�������ϵ����GL������ϵ��ԭ���Ǵ��ڵ����½�
		�ڵ�������ϵ��ԭ���ǽڵ�����½�

		��һ���ڵ����setPositionsʱ��ʹ�õĲ��������ĸ��ڵ��������ϵ
		CCLayer��CCSceneĬ�ϴ�С�ʹ���һ������������������ϵ������������ϵ�غ�
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

	// ��ê����Ϊԭ����ת���Ľ��
	CCPoint ptSpriteInWorldByAnchor = pLayerColor->convertToWorldSpaceAR(m_pSprite->getPosition());

	// ����������ʾUI��GL�����ת��
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

	// �ж��Ƿ���о���
	// ��ȡ����ľ��Σ� ��ȡ�����㣬 �жϴ������Ƿ��ھ�����
	CCRect rc = m_pSprite->boundingBox();
	CCPoint ptTouch = pTouch->getLocation();

	//if (rc.containsPoint(m_pSprite->getParent()->convertToNodeSpace(ptTouch))) {
	if (rc.containsPoint(m_pSprite->getParent()->convertTouchToNodeSpace(pTouch))) {
		CCLog("touch sprite");
	}

	return true;
}