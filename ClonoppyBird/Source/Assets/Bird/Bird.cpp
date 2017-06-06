#include "Bird.h"
#include "SpriteRenderer.h"
#include "BoxCollider.h"

Bird::Bird(Vector2 &at) : GameEntity("Bird")
{
	transform.position = at;
}

Bird::~Bird()
{

}

void Bird::SetUp()
{
	SpriteRenderer* sr = (SpriteRenderer*)AddComponent<SpriteRenderer>();
	sr->LoadSprite("Resources/FB_Atlas.png", new SDL_Rect({
		6, 981,
		35, 24
	}));
	transform.scale = transform.scale * 2.5;

	bm = (BirdMovement*)AddComponent<BirdMovement>();
	collider = (BoxCollider*)AddComponent<BoxCollider>();
	collider->w = sr->w * transform.scale.x -10.f;
	collider->h = sr->h * transform.scale.y -10.f;

	GameEntity::SetUp();
}