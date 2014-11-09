#include "T26ActionShow.h"
#include "HelloWorldScene.h"

static const char* _actionName[] =
{
	"CCMoveBy",
	"CCMoveTo",
	"CCRotateBy",
	"CCRotateTo",
	"CCScaleBy",
	"CCScaleTo",
	"CCSkewBy",
	"CCSkewTo",
	"CCJumpBy",
	"CCJumpTo",
	"CCBezierBy",
	"CCBezierTo",
	"CCFadeIn",
	"CCFadeOut",
	"CCTintTo",
	"CCTintBy",
	"CCBlink",
	"CCDelayTime",
	"CCOrbitCamera",
	"CCCardinalSplineTo",
	"CCCardinalSplineBy",
	"CCCatmullRomTo",
	"CCCatmullRomBy",
	"CCFollow",
	"CCCallFunc",
	"CCCallFuncN",
	"CCCallFuncND",
};

CCScene* T26ActionShow::scene()
{
	CCScene* s = CCScene::create();
	T26ActionShow* layer = T26ActionShow::create();
	s->addChild(layer);
	return s;
}

bool T26ActionShow::init()
{
	BaseLayer::init();
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	
	CCNode* c = CCNode::create();
	_c = c;
	int actionCount = sizeof(_actionName) / sizeof(*_actionName);
	
	for (int i = 0; i < actionCount; i++)
	{
		/*
		CCSprite* bg = CCSprite::create("HelloWorld.png");
		c->addChild(bg);
		bg->setPosition(ccp(winSize.width / 2 + i*winSize.width, winSize.height / 2));
		*/
		CCLayerColor* layer;
		if (i % 2 == 0)
		{
			layer = CCLayerColor::create(ccc4(192, 192, 192, 255), winSize.width, winSize.height);
		}
		else
		{
			layer = CCLayerColor::create(ccc4(128, 128, 128, 255), winSize.width, winSize.height);
		}
		c->addChild(layer);
		layer->setPosition(ccp(i*winSize.width, 0));

		/* 设置Title */
		const char* title = _actionName[i];
		CCLabelTTF* label = CCLabelTTF::create(title, "Arial", 36);
		layer->addChild(label);
		label->setPosition(ccp(winSize.width / 2, winSize.height - 80));
	}

	CCScrollView* view = CCScrollView::create(winSize, c);
	view->setDirection(kCCScrollViewDirectionHorizontal);
	view->setContentSize(CCSize(winSize.width*actionCount, winSize.height));
	addChild(view);

	c->setPositionX((1 - actionCount)*winSize.width);

	// 能触摸
	setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);

	return true;
}

bool T26ActionShow::ccTouchBegan(CCTouch*, CCEvent*)
{
	return true;
}

void T26ActionShow::testAction(int idx, CCLayerColor* layer)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCSprite* sprite = (CCSprite*)layer->getUserObject();

	if (sprite == NULL)
	{
		sprite = CCSprite::create("CloseNormal.png");
		layer->setUserObject(sprite);
		layer->addChild(sprite);
	}
	const char* an = _actionName[idx];
	CCAction* action;
	sprite->setPosition(ccp(winSize.width / 2, winSize.height / 2));

	if (an == "CCMoveTo")
	{
		action = CCMoveTo::create(2, ccp(100, 100));
	}
	if (an == "CCMoveBy")
	{
		//
	}
	if (an == "CCRotateBy")
	{
		action = CCRotateBy::create(2, 250);
	}
	if (an == "CCRotateTo")
	{
		action = CCRotateTo::create(2, 250);
	}
	if (an == "CCScaleBy")
	{
		action = CCScaleBy::create(2, 2);
	}
	if (an == "CCScaleTo")
	{
		action = CCScaleTo::create(2, 2);
	}
	if (an == "CCSkewBy")
	{
		action = CCSkewBy::create(2, 35, 87);
	}
	if (an == "CCSkewTo")
	{
		action = CCSkewTo::create(2, 35, 87);
	}
	if (an == "CCJumpBy")
	{
		action = CCJumpBy::create(3, ccp(100, 100), 50, 6);
	}
	if (an == "CCJumpTo")
	{
		action = CCJumpTo::create(3, ccp(100, 100), 50, 6);
	}
	if (an == "CCBezierBy")
	{
		ccBezierConfig c;
		c.controlPoint_1 = ccp(400, 400);
		c.controlPoint_2 = ccp(250, 360);
		c.endPosition = ccp(100, 100);
		action = CCBezierBy::create(3, c);
	}
	if (an == "CCBezierTo")
	{
		ccBezierConfig c;
		c.controlPoint_1 = ccp(400, 400);
		c.controlPoint_2 = ccp(250, 360);
		c.endPosition = ccp(100, 100);
		action = CCBezierTo::create(3, c);
	}
	if (an == "CCFadeIn")
	{
		action = CCFadeIn::create(3);
	}
	if (an == "CCFadeOut")
	{
		action = CCFadeOut::create(3);
	}
	if (an == "CCTintTo")
	{
		action = CCTintTo::create(3, 255, 0, 0);
	}
	if (an == "CCTintBy")
	{
		action = CCTintBy::create(3, 23, 47, 37);
	}
	if (an == "CCBlink")
	{
		action = CCBlink::create(3, 10);
	}
	if (an == "CCDelayTime")
	{
		CCMoveBy* move = CCMoveBy::create(2, ccp(100, 100));
		CCDelayTime* delay = CCDelayTime::create(1);
		CCFiniteTimeAction* back = move->reverse();
		action = CCSequence::create(move, delay, back, NULL);
	}
	if (an == "CCOrbitCamera")
	{
		// static CCOrbitCamera* create(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX);
		 action = CCOrbitCamera::create(5, 80, 13, 55, 13, 80, 24);
	}
	if (an == "CCCardinalSplineTo")
	{
		CCPointArray* arr = CCPointArray::create(20);
		arr->addControlPoint(ccp(200, 200));
		arr->addControlPoint(ccp(200, 100));
		arr->addControlPoint(ccp(100, 100));
		arr->addControlPoint(ccp(100, 200));
		action = CCCardinalSplineTo::create(5, arr, 5.0f);
	}
	
	if (an == "CCCardinalSplineBy")
	{
		CCPointArray* arr = CCPointArray::create(20);
		arr->addControlPoint(ccp(200-50, 200-50));
		arr->addControlPoint(ccp(200-50, 100-50));
		arr->addControlPoint(ccp(100-50, 100-50));
		arr->addControlPoint(ccp(100-50, 200-50));
		action = CCCardinalSplineBy::create(5, arr, 5.0f);
	}
	if (an == "CCCatmullRomTo")
	{
		CCPointArray* arr = CCPointArray::create(20);
		arr->addControlPoint(ccp(200, 200));
		arr->addControlPoint(ccp(200, 100));
		arr->addControlPoint(ccp(100, 100));
		arr->addControlPoint(ccp(100, 200));
		action = CCCatmullRomTo::create(5, arr);
	}
	if (an == "CCCatmullRomBy")
	{
		CCPointArray* arr = CCPointArray::create(20);
		arr->addControlPoint(ccp(200, 200));
		arr->addControlPoint(ccp(200, 100));
		arr->addControlPoint(ccp(100, 100));
		arr->addControlPoint(ccp(100, 200));
		action = CCCatmullRomBy::create(5, arr);
	}
	if (an == "CCFollow") // 明天说
	{
		CCSprite* sprite2 = CCSprite::create("green_edit.png");
		layer->addChild(sprite2);
		sprite2->setPosition(ccp(winSize.width / 2, winSize.height / 2));
		sprite2->runAction(CCJumpBy::create(100, ccp(800, 800), 800, 60));
		action = CCFollow::create(sprite2);
	}

	if (an == "CCCallFunc")
	{
		action = CCCallFunc::create(this, callfunc_selector(T26ActionShow::func));
	}
	if (an == "CCCallFuncN")
	{
		action = CCCallFuncN::create(this, callfuncN_selector(T26ActionShow::funcN));
	}
	if (an == "CCCallFuncND")
	{
		void* p = NULL;
		action = CCCallFuncND::create(this, callfuncND_selector(T26ActionShow::funcND), p);
	}
	sprite->runAction(action);

}

void T26ActionShow::funcN(CCNode* node)
{
	
}

void T26ActionShow::func()
{
	// ....
}

void T26ActionShow::funcND(CCNode*, void*)
{
	
}

void T26ActionShow::ccTouchEnded(CCTouch* t, CCEvent*)
{
	CCPoint ptStart = t->getStartLocation();
	CCPoint ptEnd = t->getLocation();
	if (ptStart.getDistanceSq(ptEnd) <= 25)
	{
		// click
		// 点中了哪个子窗口
		
		// 转换ptStart为ScrollView中的Container的坐标
		// 再判断被点击的LayerColor
		CCPoint ptInContainer = _c->convertToNodeSpace(ptStart);
		CCArray* arr = _c->getChildren(); // 所有的layercolor
		for (int i = 0; i < sizeof(_actionName) / sizeof(*_actionName); i++)
		{
			CCLayerColor* layer = (CCLayerColor*)arr->objectAtIndex(i);
			if (layer->boundingBox().containsPoint(ptInContainer))
			{
				testAction(i, layer);
				break;
			}
		}
	}

}
