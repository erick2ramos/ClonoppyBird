#pragma once
#include "Transform.h"
#include "Typedefs.h"

class Game;
class GameEntity;

class GameComponent
{
public:
	bool enabled;

	Transform* transform;
	GameEntity* gameObject;

	GameComponent();
	virtual ~GameComponent();

	virtual void Start() {};
	void Run();

protected:
	virtual void Update() {};
};
