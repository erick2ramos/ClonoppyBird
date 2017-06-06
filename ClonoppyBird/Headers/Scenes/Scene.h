#pragma once
#include <list>
#include "GameEntity.h"

using namespace std;


class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Reset();
	virtual void Load();
	virtual void Unload();
	virtual void Run();

protected:
	list<GameEntity*> gameObjects;
	bool reset;

};
