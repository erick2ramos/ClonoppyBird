#include "Background.h"
#include <SDL.h>
#include "Vector2.h"
#include "SpriteRenderer.h"
#include "Parallax.h"

Background::Background() : GameEntity("Background")
{
	
}

Background::~Background()
{

}

void Background::SetUp()
{
	SpriteRenderer* sr = (SpriteRenderer*)AddComponent<SpriteRenderer>();
	sr->LoadSprite("Resources/FB_Atlas.png");
	sr->origRect = new SDL_Rect({
		0, 0,
		287, 512
	});
	AddComponent<Parallax>();
	transform.scale = Vector2(2.091, 2);
}