#pragma once
#include "GameComponent.h"
#include "BoxCollider.h"

class PlayButtonBehavior : public GameComponent
{
public:
	BoxCollider* collider;

	PlayButtonBehavior();
	~PlayButtonBehavior();

	void Start();

protected:
	void Update();
};