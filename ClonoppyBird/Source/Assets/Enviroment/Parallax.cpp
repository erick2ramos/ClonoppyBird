#include "Parallax.h"
#include "GameEntity.h"
#include "Time.h"
#include "Game.h"

Parallax::Parallax()
{

}

Parallax::~Parallax()
{

}

void Parallax::Start()
{
	sr = gameObject->GetComponent<SpriteRenderer>();
	speed = 170.0f;
	minX = sr->w / 2;
	maxX = sr->w;
	player = (Bird*)GameEntity::Find("Bird");
}

void Parallax::Update()
{
	if (player != NULL && player->bm != NULL && player->bm->started)
	{
		transform->position = transform->position + (Vector2(-1, 0) * speed * Time::GetDelta());
		if (transform->position.x + transform->scale.x * maxX < 0)
		{
			transform->position.x = (float)Game::mScreenWidth;
		}
	}
}