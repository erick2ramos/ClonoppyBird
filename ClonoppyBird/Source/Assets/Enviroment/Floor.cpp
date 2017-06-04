#include "Floor.h"
#include <SDL.h>
#include "Vector2.h"
#include "SpriteRenderer.h"
#include "Parallax.h"

Floor::Floor() : GameEntity("Floor")
{
	
}

Floor::~Floor()
{

}

void Floor::SetUp()
{
	SpriteRenderer* sr = (SpriteRenderer*)AddComponent<SpriteRenderer>();
	sr->LoadSprite("Resources/FB_Atlas.png");
	sr->origRect = new SDL_Rect({
		584, 0,
		336, 112
	});
	AddComponent<Parallax>();
	transform.scale = Vector2(1.79, 1);
	collider = (BoxCollider*)AddComponent<BoxCollider>();
	collider->w = 336 * transform.scale.x;
	collider->h = 112 * transform.scale.y;
}