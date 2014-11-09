#include "T27ActionMore.h"
#include "HelloWorldScene.h"

static const char* _actionName[] =
{
	"CCEaseBounceIn",
	"CCEaseBounceOut",
	"CCEaseBounceInOut",
	"CCEaseBackIn",
	"CCEaseBackOut",
	"CCEaseBackInOut",
	"CCEaseElasticIn",
	"CCEaseElasticOut",
	"CCEaseElasticInOut",
	"CCEaseExponentialIn",
	"CCEaseExponentialOut",
	"CCEaseExponentialInOut",
	"CCEaseIn",
	"CCEaseOut",
	"CCEaseInOut",
	"CCEaseSineIn",
	"CCEaseSineOut",
	"CCEaseSineInOut",
	"CCSpeed",
	"CCSpawn",
	"CCSequence",
	"CCRepeat",
	"CCRepeatForever",
};

CCScene* T27ActionMore::scene()
{
	CCScene* s = CCScene::create();
	T27ActionMore* layer = T27ActionMore::create();
	s->addChild(layer);
	return s;
}

bool T27ActionMore::init()
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

bool T27ActionMore::ccTouchBegan(CCTouch*, CCEvent*)
{
	return true;
}

void T27ActionMore::testAction(int idx, CCLayerColor* layer)
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
	CCAction* action = NULL;
	sprite->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	CCMoveBy* moveBy = CCMoveBy::create(4, ccp(0, sprite->getContentSize().height / 2 - winSize.height / 2));

	if (an == "CCEaseBounceIn")
	{
		action = CCEaseBounceIn::create(moveBy);
	}
	if (an == "CCEaseBounceOut")
	{
		action = CCEaseBounceOut::create(moveBy);
	}
	if (an == "CCEaseBounceInOut")
	{
	}
	if (an == "CCEaseBackIn")
	{
		action = CCEaseBackIn::create(moveBy);
	}
	if (an == "CCEaseBackOut")
	{
		action = CCEaseBackOut::create(moveBy);
	}
	if (an == "CCEaseBackInOut")
	{
	}
	if (an == "CCEaseElasticIn")
	{
		action = CCEaseElasticIn::create(moveBy);
	}
	if (an == "CCEaseElasticOut")
	{
		action = CCEaseElasticOut::create(moveBy);
	}
	if (an == "CCEaseElasticInOut")
	{
		action = CCEaseElasticInOut::create(moveBy);
	}
	if (an == "CCEaseExponentialIn")
	{
		action = CCEaseExponentialIn::create(moveBy);
	}
	if (an == "CCEaseExponentialOut")
	{
		action = CCEaseExponentialOut::create(moveBy);
	}
	if (an == "CCEaseExponentialInOut")
	{
		action = CCEaseExponentialInOut::create(moveBy);
	}
	if (an == "CCEaseIn")
	{
		action = CCEaseIn::create(moveBy, 10.0f);
	}
	if (an == "CCEaseOut")
	{
		action = CCEaseOut::create(moveBy, 10.f);
	}
	if (an == "CCEaseInOut")
	{
		action = CCEaseInOut::create(moveBy, 10.f);
	}
	if (an == "CCEaseSineIn")
	{
		action = CCEaseSineIn::create(moveBy);
	}
	if (an == "CCEaseSineOut")
	{
		action = CCEaseSineOut::create(moveBy);
	}
	if (an == "CCEaseSineInOut")
	{
		action = CCEaseSineInOut::create(moveBy);
	}
	if (an == "CCSpeed")
	{
		action = CCSpeed::create(moveBy, 10);
	}
	if (an == "CCSpawn")
	{
	}
	if (an == "CCSequence")
	{
	}
	if (an == "CCRepeat")
	{
	}
	if (an == "CCRepeatForever")
	{
	}

	if (action)
		sprite->runAction(action);

}

void T27ActionMore::ccTouchEnded(CCTouch* t, CCEvent*)
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
