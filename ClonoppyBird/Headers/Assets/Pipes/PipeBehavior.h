#pragma once
#include "GameComponent.h"
#include "BirdMovement.h"
#include "Bird.h"

class PipeBehavior : public GameComponent
{
public:
	float speed;

	PipeBehavior();
	~PipeBehavior();

	void Start();

protected:
	void Update();

private:
	Bird* player;
};