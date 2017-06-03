#pragma once
#include <list>
#include "Vector2.h"
#include "Vector3.h"

using namespace std;

class GameEntity;

class Transform
{
public:
	Vector2 position;
	Vector2 scale;
	Vector3 rotation;
	GameEntity *gameObject;
	Transform *parent;
	list<Transform*> children;
	
	Transform();

	void SetParent(Transform* parent);

};