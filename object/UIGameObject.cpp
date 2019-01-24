#include "UIGameObject.h"
//#include "GameGrid.h"

UIGameObject::UIGameObject(TEXTURE_ID tex_id, Vec2 pos, size_t idx, UIDelegate* delegate) :mDelegate(delegate)
{
	mTextureID = tex_id;
	mObjectPosition = pos;
	mObjectDestination = pos;
	mObjectVelocity.zero();
	mScale = Vec2(1.0f, 1.0f);
	mDstScale = Vec2(1.0f, 1.0f);
	mScalePower = Vec2(1.0f, 1.0f);
	mAngle = 0.0f;
	mDstAngle = 0.0f;
	mIndex = idx;
}

/*
* SETTERS
*/
void UIGameObject::setPosition(Vec2& pos)
{
	mObjectPosition = pos;
}

void UIGameObject::setSpeed(Vec2& vel)
{
	mObjectVelocity = vel;
}

void UIGameObject::setDestination(Vec2& dst)
{
	mObjectDestination = dst;
}

void UIGameObject::setTextureID(TEXTURE_ID texID)
{
	mTextureID = texID;
}

void UIGameObject::setIndex(size_t idx)
{
	mIndex = idx;
}

void UIGameObject::setScale(Vec2 scale)
{
	mScale = scale;
}
void UIGameObject::setScalePower(Vec2 pow)
{
	mScalePower = pow;
}
void UIGameObject::setAngle(double angle)
{
	mAngle = angle;
}
void UIGameObject::setDstScale(Vec2 scale)
{
	mDstScale = scale;
}
void UIGameObject::setDstAngle(double angle)
{
	mDstAngle = angle;
}

/*
* GETTERS
*/
Vec2 UIGameObject::getPosition()
{
	return mObjectPosition;
}

Vec2 UIGameObject::getSpeed()
{
	return mObjectVelocity;
}

Vec2 UIGameObject::getDestination()
{
	return mObjectDestination;
}

TEXTURE_ID UIGameObject::getTextureID()
{
	return mTextureID;
}

Vec2 UIGameObject::getScale()
{
	return mScale;
}

Vec2 UIGameObject::getScalePower()
{
	return mScalePower;
}

Vec2 UIGameObject::getDstScale()
{
	return mDstScale;
}

double UIGameObject::getAngle()
{
	return mAngle;
}

double UIGameObject::getDstAngle()
{
	return mDstAngle;
}

size_t UIGameObject::getIndex()
{
	return mIndex;
}
size_t UIGameObject::getDstIndex()
{
	return mIndex;
}

//void UIGameObject::checkState(std::weak_ptr<King::Engine> _engine)
//{
//	auto engine = _engine.lock();
//	Vec2 halfsize = Vec2(engine->GetTextureWidth(mTextureID), engine->GetTextureHeight(mTextureID))*0.5;
//	Vec2 distance = ((mObjectPosition)-Vec2(engine->GetMouseX(), engine->GetMouseY()));
//	distance = Vec2(abs(distance.x), abs(distance.y));
//
//	if (distance.x < halfsize.x && (distance.y < halfsize.y))
//	{
//		if (engine->GetMouseButtonDown())
//		{
//			if (bMousePressed)
//			{
//				mUIState = UISTATE::DRAG;
//				mDelegate->Callback_UISTATE(mIndex, mUIState);
//				return;
//			}
//			else
//			{
//				mUIState = UISTATE::CLICK;
//				mDelegate->Callback_UISTATE(mIndex, mUIState);
//				bMousePressed = true;
//				return;
//			}
//		}
//		else
//		{
//			mUIState = UISTATE::ROLLOVER;
//			this->mTextureID = TEXTURE_ID::TEXTURE_BUTTONOVER;
//			bMousePressed = false;
//			return;
//		}
//	}
//
//	if (!engine->GetMouseButtonDown())
//	{
//		mUIState = UISTATE::NONE;
//		this->mTextureID = TEXTURE_ID::TEXTURE_BUTTON;
//		bMousePressed = false;
//		return;
//	}
//
//}
