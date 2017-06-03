#pragma once
#include "GameEntity.h"
#include "BirdMovement.h"

class Bird : public GameEntity
{
public:
	BirdMovement* bm;

	Bird(Vector2 &at);

	void SetUp();
};