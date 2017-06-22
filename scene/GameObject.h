#pragma once

#include "StarMain.h"
#include "StarDefine.h"
class GameObject
{

public:
	GameObject() {};
	~GameObject() {};
	virtual void setPosition(Vec2& pos) = 0;
	virtual void setSpeed(Vec2& vel) = 0;
	virtual void setDestination(Vec2& dst) = 0;
	virtual void setTextureID(TEXTURE_ID texID) = 0;
	virtual void setIndex(size_t idx) = 0;
	virtual void setScale(Vec2 scale) = 0;
	virtual void setScalePower(Vec2 scale) = 0;
	virtual void setDstScale(Vec2 scale) = 0;
	virtual void setAngle(double angle) = 0;
	virtual void setDstAngle(double angle) = 0;

	virtual Vec2 getPosition() = 0;
	virtual Vec2 getSpeed() = 0;
	virtual Vec2 getDestination() = 0;
	virtual TEXTURE_ID getTextureID() = 0;
	virtual size_t getIndex() = 0;
	virtual double getDstAngle() = 0;
	virtual double getAngle() = 0;
	virtual Vec2 getDstScale() = 0;
	virtual Vec2 getScale() = 0;
	virtual Vec2 getScalePower() = 0;
	virtual size_t getDstIndex() = 0;


protected:
	TEXTURE_ID mTextureID;
	Vec2 mObjectPosition;
	Vec2 mObjectDestination;
	Vec2 mObjectVelocity;
	size_t mIndex;

	Vec2 mScale;
	Vec2 mScalePower;
	Vec2 mDstScale;
	double mDstAngle;
	double mAngle;
};
