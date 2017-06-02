#include "PipeBehavior.h"
#include "Time.h"
#include "GameEntity.h";

PipeBehavior::PipeBehavior() :
	GameComponent()
{

}

PipeBehavior::~PipeBehavior()
{

}

void PipeBehavior::Start()
{
	speed = 150.0f;
}

void PipeBehavior::Update()
{
	transform->position = transform->position + (Vector2(-1, 0) * speed * Time::GetDelta());

	if (transform->position.x + 150 < 0)
	{
		gameObject->active = false;
	}
}