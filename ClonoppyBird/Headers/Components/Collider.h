#pragma once
#include <list>
#include "GameComponent.h"
#include "GameEntity.h"

using namespace std;

class Collider : public GameComponent
{
public:
	Collider();
	~Collider();

	static list<Collider*> colliders;
	static bool CheckCollisions(Collider* col);

	virtual bool CollideWith(Collider* other);

protected:
	virtual void Update() {};
};