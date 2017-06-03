#include "Bird.h"
#include "SpriteRenderer.h"
#include "BoxCollider.h"

Bird::Bird(Vector2 &at) : GameEntity("Bird")
{
	transform.position = at;
}

void Bird::SetUp()
{
	transform.scale = transform.scale * 1.5f;
	SpriteRenderer* sr = (SpriteRenderer*)AddComponent<SpriteRenderer>();
	sr->LoadSprite("Resources/FB_Atlas.png");
	sr->origRect = new SDL_Rect({
		6, 981,
		35, 24
	});

	bm = (BirdMovement*)AddComponent<BirdMovement>();
	collider = (BoxCollider*)AddComponent<BoxCollider>();
	collider->w = 34 * transform.scale.x;
	collider->h = 24 * transform.scale.y;

	GameEntity::SetUp();
}