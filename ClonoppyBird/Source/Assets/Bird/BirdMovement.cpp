#include "BirdMovement.h"
#include "Bird.h"
#include "Collider.h"

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
		if (!Collider::CheckCollisions(((Bird*)gameObject)->collider))
		{
			velocity = (velocity + gravity * 50.0f * Time::GetDelta());
			direction = direction + velocity;
			transform->rotation.z = atan2(direction.y, direction.x) * 180 / M_PI;
			transform->position = transform->position + (velocity * Time::GetDelta());
		}
		else
		{
			started = false;
		}
	}
}