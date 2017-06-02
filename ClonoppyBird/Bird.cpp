#include "Bird.h"

Bird::Bird(Vector2 &at) : GameEntity("Bird")
{
	transform.position = at;
	
	SpriteRenderer* sr = (SpriteRenderer*)AddComponent<SpriteRenderer>();
	sr->LoadSprite("Flappy_Bird.png");

	bm = (BirdMovement*)AddComponent<BirdMovement>();
}