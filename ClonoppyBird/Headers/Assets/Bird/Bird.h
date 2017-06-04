#pragma once
#include "GameEntity.h"
#include "BirdMovement.h"
#include "BoxCollider.h"

class Bird : public GameEntity
{
public:
	BirdMovement* bm;
	BoxCollider* collider;

	Bird(Vector2 &at);
	~Bird();
	void SetUp();
};