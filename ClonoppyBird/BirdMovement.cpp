#include "BirdMovement.h"

BirdMovement::BirdMovement() : GameComponent()
{
	gravity = Vector2(0, 1.8f * -9.8f);
	speed = 500.0f;
}

BirdMovement::~BirdMovement()
{

}

void BirdMovement::Start()
{
	transform->scale = transform->scale * 0.5f;
}

void BirdMovement::Update()
{
	direction = Vector2(1, 0) * speed;
	if (InputManager::GetTouchUp())
	{
		started = true;
		velocity.y = speed;
	}
	ProcessMovement();
}

void BirdMovement::ProcessMovement()
{
	if(started)
	{
		velocity = (velocity + gravity * 50.0f * Time::GetDelta());
		direction = direction + velocity;
		transform->rotation.z = atan2(direction.y, direction.x) * 180 / M_PI;
		transform->position = transform->position + (velocity * Time::GetDelta());
	}
}