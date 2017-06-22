#pragma once
#include "GameObject.h"
#include "StarInfo.h"
enum class UISTATE
{
	NONE,
	CLICK,
	ROLLOVER,
	DRAG,
};

class UIDelegate 
{
public:
	virtual void Callback_UISTATE(size_t,UISTATE)=0;
};

class UIGameObject :public GameObject
{
public:
	UIGameObject() {};
	~UIGameObject() {};
	void setPosition(Vec2& pos) override;
	void setSpeed(Vec2& vel) override;
	void setDestination(Vec2& dst) override;
	void setTextureID(TEXTURE_ID texID) override;
	void setIndex(size_t idx) override;
	void setScale(Vec2) override;
	void setScalePower(Vec2) override;
	void setDstScale(Vec2) override;
	void setAngle(double) override;
	void setDstAngle(double) override;

	Vec2 getPosition() override;
	Vec2 getSpeed()  override;
	Vec2 getDestination() override;
	TEXTURE_ID getTextureID() override;
	Vec2 getScale() override;
	Vec2 getDstScale() override;
	Vec2 getScalePower() override;
	double getAngle() override;
	double getDstAngle() override;
	size_t getIndex() override;
	size_t getDstIndex()override;


	UIGameObject(TEXTURE_ID tex_id, Vec2 position,size_t index, UIDelegate*);
//	void checkState(std::weak_ptr<King::Engine> _engine);

private:
	UIDelegate* mDelegate;
	UISTATE mUIState;
	bool bMousePressed;
};
