#include "Floor.h"
#include <SDL.h>
#include "Vector2.h"
#include "SpriteRenderer.h"
#include "Parallax.h"
#include "Game.h"

Floor::Floor() : GameEntity("Floor")
{
	
}

Floor::~Floor()
{

}

void Floor::SetUp()
{
	SpriteRenderer* sr = (SpriteRenderer*)AddComponent<SpriteRenderer>();
	sr->LoadSprite("Resources/FB_Atlas.png", new SDL_Rect({
		584, 0,
		336, 112
	}));
	sr->w = Game::mScreenWidth;
	transform.scale = Vector2(1, 1);
	AddComponent<Parallax>();
	collider = AddComponent<BoxCollider>();
	collider->w = sr->w * transform.scale.x;
	collider->h = sr->h * transform.scale.y;
}