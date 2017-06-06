#include "Background.h"
#include <SDL.h>
#include "Vector2.h"
#include "SpriteRenderer.h"
#include "Parallax.h"
#include "Game.h"

Background::Background() : GameEntity("Background")
{
	
}

Background::~Background()
{

}

void Background::SetUp()
{
	SpriteRenderer* sr = (SpriteRenderer*)AddComponent<SpriteRenderer>();
	sr->LoadSprite("Resources/FB_Atlas.png", new SDL_Rect({
		0, 0,
		287, 512
	}));
	sr->w = Game::mScreenWidth;
	sr->h = Game::mScreenHeight;
	
	AddComponent<Parallax>();
	transform.scale = Vector2(1, 1);
}