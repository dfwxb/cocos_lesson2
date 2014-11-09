#ifndef __T01SPRITECREATE_H__
#define __T01SPRITECREATE_H__

#include "cocos2d.h"
#include "BaseLayer.h"

class T01SpriteCreate : public BaseLayer
{
public:
	T01SpriteCreate();
	~T01SpriteCreate();
	CREATE_FUNC(T01SpriteCreate);
	static cocos2d::CCScene* scene();
	virtual bool init();
};

#endif // __T01SPRITECREATE_H__


