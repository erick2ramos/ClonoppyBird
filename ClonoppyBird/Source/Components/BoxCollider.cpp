#include "BoxCollider.h"
#include "Game.h"

BoxCollider::BoxCollider()
{
}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::Update()
{
	x = transform->position.x;
	y = Game::mScreenHeight - h - transform->position.y;

	SDL_Rect rectToDraw = { x, y, w, h };
	SDL_RenderDrawRect(Game::mRenderer, &rectToDraw);
}

bool BoxCollider::CollideWith(Collider* other)
{
	float RightF, TopF;
	float LeftS, RightS, BottomS, topS;

	RightF = x + w;
	TopF = y + h;
	LeftS = ((BoxCollider*)other)->x;
	BottomS = ((BoxCollider*)other)->y;
	RightS = LeftS + ((BoxCollider*)other)->w;
	topS = BottomS + ((BoxCollider*)other)->h;

	if (y >= topS)
		return false;
	if (TopF <= BottomS)
		return false;
	if (RightF <= LeftS)
		return false;
	if (x >= RightS)
		return false;

	return true;
}