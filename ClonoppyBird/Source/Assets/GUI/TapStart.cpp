#include "TapStart.h"
#include "SpriteRenderer.h"
#include "Game.h"
#include "OverlayBehavior.h"

TapStart::TapStart()
	: GameEntity("TapStartScreen")
{
}

TapStart::~TapStart()
{

}

void TapStart::SetUp()
{
	SpriteRenderer* sr = (SpriteRenderer*)AddComponent<SpriteRenderer>();
	sr->LoadSprite("Resources/FB_Atlas.png");
	sr->origRect = new SDL_Rect({
		586, 176,
		112, 105
	});

	AddComponent<OverlayBehavior>();

	transform.position = Vector2(Game::mScreenWidth / 2 - (112/2), Game::mScreenHeight / 2);
}
