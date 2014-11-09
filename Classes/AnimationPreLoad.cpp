#include "AnimationPreLoad.h"


AnimationPreLoad::AnimationPreLoad()
{
}
AnimationPreLoad::~AnimationPreLoad()
{
}

CCScene* AnimationPreLoad::scene()
{
	CCScene* pRet = CCScene::create();

	AnimationPreLoad* pLayer = AnimationPreLoad::create();

	if (pRet && pLayer) {
		pRet->addChild(pLayer);
	}
	else {
		CC_SAFE_DELETE(pLayer);
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool AnimationPreLoad::init()
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
	
	// 加入到缓存
	CCAnimationCache::sharedAnimationCache()->addAnimation(animation, "mario_walk");

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
	CCAnimationCache::sharedAnimationCache()->addAnimation(animation, "plane_boom");

	CCSprite* sp = CCSprite::create();
	sp->setPosition(ptCenter);
	addChild(sp);
	sp->setTag(100);

	setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);

	return true;
}

bool AnimationPreLoad::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCSprite* sp = dynamic_cast<CCSprite*>(getChildByTag(100));
	if (!sp) return true;
	
	sp->stopAllActions();

	static int i = 1;
	if (i == 1) {
		sp->runAction(CCAnimate::create(
			CCAnimationCache::sharedAnimationCache()->animationByName("mario_walk")));
	}
	else {
		sp->runAction(CCAnimate::create(
			CCAnimationCache::sharedAnimationCache()->animationByName("plane_boom")));
	}

	i = 1 - i;

	return true;
}
