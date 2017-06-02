#pragma once
#include "GameComponent.h"

class PipeBehavior : public GameComponent
{
public:
	float speed;

	PipeBehavior();
	~PipeBehavior();

	void Start();

protected:
	void Update();
};