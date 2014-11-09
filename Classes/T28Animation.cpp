#include "T28Animation.h"


T28Animation::T28Animation()
{
}
T28Animation::~T28Animation()
{
}

CCScene* T28Animation::scene()
{
	CCScene* pRet = CCScene::create();

	T28Animation* pLayer = T28Animation::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool T28Animation::init()
{
	if (!BaseLayer::init()) return false;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint ptCenter = ccp(winSize.width / 2, winSize.height / 2);

	// 创建纹理
	CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("walkLeft.png");

	// 从纹理中扣出帧,保存到数组中
	CCArray* arr = CCArray::create();
	for (int i = 9; i >= 0; i--) {
		CCSpriteFrame* frame = CCSpriteFrame::createWithTexture(texture, CCRectMake(i * 18, 0, 18, 32));
		arr->addObject(frame);
	} 

	// 通过数组创建动画
	CCAnimation* animation = CCAnimation::createWithSpriteFrames(arr, 0.1f);
	CCAnimate* animate = CCAnimate::create(animation);

	CCSprite* pSprite = CCSprite::create();
	addChild(pSprite);
	pSprite->setPosition(ptCenter);
	pSprite->setScale(2.0f);
	//pSprite->runAction(CCRepeatForever::create(animate));

	//////////////////////////////////////////////////////////////////////////
	// 有plist文件的动画
	CCSpriteFrameCache* frameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	frameCache->addSpriteFramesWithFile("PFBoom.plist");
	arr = CCArray::create();
	for (int i = 1; i <= 18; i++) {
		char key[128] = { 0 };
		sprintf(key, "Boom_%d.png", i);
		CCSpriteFrame* frame = frameCache->spriteFrameByName(key);
		arr->addObject(frame);
	}
	animation = CCAnimation::createWithSpriteFrames(arr, 0.05f);
	animate = CCAnimate::create(animation);
	
	CCCallFunc* callFunc = CCCallFunc::create(pSprite, callfunc_selector(CCSprite::removeFromParent));

	pSprite->runAction(CCSequence::create(animate, callFunc, NULL));

	//setTouchEnabled(true);
	//setTouchMode(kCCTouchesOneByOne);

	return true;
}
