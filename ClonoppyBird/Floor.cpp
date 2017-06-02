#include "Floor.h"
#include <SDL.h>
#include "Vector2.h"
#include "SpriteRenderer.h"
#include "Parallax.h"

Floor::Floor()
{
	SpriteRenderer* sr = (SpriteRenderer*)AddComponent<SpriteRenderer>();
	sr->LoadSprite("FB_Atlas.png");
	sr->origRect = new SDL_Rect({
		584, 0,
		336, 112
	});
	AddComponent<Parallax>();
	transform.scale = Vector2(1.79, 1);
}

Floor::~Floor()
{

}