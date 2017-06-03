#include "Bird.h"
#include "SpriteRenderer.h"

Bird::Bird(Vector2 &at) : GameEntity("Bird")
{
	transform.position = at;
}

void Bird::SetUp()
{
	SpriteRenderer* sr = (SpriteRenderer*)AddComponent<SpriteRenderer>();
	sr->LoadSprite("Resources/Flappy_Bird.png");

	bm = (BirdMovement*)AddComponent<BirdMovement>();
	GameEntity::SetUp();
}