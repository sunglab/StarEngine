#pragma once

#include "GameObject.h"

#include "StarMain.h"
#include <vector>
#include <list>

enum class GAMESCENES
{
	SCENE_INTRO,
	SCENE_PLAY,
	SCENE_END,
};

class GameScene
{

public:

	virtual void init(const std::weak_ptr<King::Engine> engine) = 0;
	virtual void reset() = 0; 
	virtual void update(std::weak_ptr<StateManager>) = 0;
	virtual void render() = 0; 
	virtual std::unique_ptr<GameScene> Make_Scene(std::weak_ptr<King::Engine>) = 0;

	virtual size_t addGameObject(GameObject* obj) 
	{
		mGameObject.push_back(obj);
		return mGameObject.size();
	}

	virtual size_t addUIObject(UIGameObject* obj) 
	{
		mUIObject.push_back(obj);
		return mUIObject.size();
	}

protected:
	std::vector<GameObject*> mGameObject;
	std::list<UIGameObject*> mUIObject;
	std::shared_ptr<StateManager> stateManager;
	Vec2 mMousePosition;
	Vec2 mMousePositionPrev;
	bool mMousePressed;

	double mTick;
	double mTimer;
	double mTimerCount;
	bool bTimeOver;

	std::shared_ptr<King::Engine> mEngine;
};

