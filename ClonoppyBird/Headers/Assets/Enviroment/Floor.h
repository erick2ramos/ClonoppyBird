#pragma once
#include "GameEntity.h"
#include "BoxCollider.h"

class Floor : public GameEntity
{
public:
	Floor();
	~Floor();

	BoxCollider* collider;

	void SetUp();
};