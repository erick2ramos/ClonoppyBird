#include "Pipe.h"
#include "SpriteRenderer.h"
#include "Vector2.h"
#include "Game.h"
#include "PipeBehavior.h"

Pipe::Pipe() :
	GameEntity()
{
	transform.position = Vector2(Game::mScreenWidth - 200, 0);
	PipeBehavior* pb = (PipeBehavior*)AddComponent<PipeBehavior>();

	for (int i = 0; i < 2; i++)
	{
		pipeHolder[i] = *(new GameEntity());
		SpriteRenderer* sr = (SpriteRenderer*)pipeHolder[i].AddComponent<SpriteRenderer>();
		sr->LoadSprite("FB_Atlas.png");
		sr->origRect = new SDL_Rect({
			168, 646,
			53, 320
		});
		pipeHolder[i].transform.scale = Vector2(2, 1.6f);
		if (i == 1) {
			(*sr).flip = SDL_FLIP_VERTICAL;
		}
	}
}

Pipe::~Pipe()
{

}

void Pipe::RandomHeight()
{
	float r = (std::rand() % 300) - 150;
	transform.position.y = r;
}

void Pipe::UpdateComponents()
{
	GameEntity::UpdateComponents();
	
	pipeHolder[0].transform.position = transform.position + (Vector2(0, -175));
	pipeHolder[1].transform.position = transform.position + (Vector2(0, 525));
	pipeHolder[0].UpdateComponents();
	pipeHolder[1].UpdateComponents();
}