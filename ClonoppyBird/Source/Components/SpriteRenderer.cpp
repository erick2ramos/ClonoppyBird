#include "Game.h"
#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer() : GameComponent()
{
	origRect = NULL;
	flip = SDL_FLIP_NONE;
}

SpriteRenderer::~SpriteRenderer()
{
	SDL_DestroyTexture(sprite);
	sprite = nullptr;
}

void SpriteRenderer::LoadSprite(const char* path)
{
	SDL_Surface* surface = IMG_Load(path);
	if (surface == NULL)
	{
		printf("IMG_Load: %s", IMG_GetError());
	}
	sprite = SDL_CreateTextureFromSurface(Game::mRenderer, surface );

	SDL_QueryTexture(sprite, NULL, NULL, &w, &h);
	
	SDL_FreeSurface(surface);
}

void SpriteRenderer::LoadSprite(const char* path, SDL_Rect* origin)
{
	SDL_Surface* surface = IMG_Load(path);
	if (surface == NULL)
	{
		printf("IMG_Load: %s", IMG_GetError());
	}
	sprite = SDL_CreateTextureFromSurface(Game::mRenderer, surface);

	origRect = origin;
	w = origin->w;
	h = origin->h;

	SDL_FreeSurface(surface);
}

void SpriteRenderer::Start()
{

}

void SpriteRenderer::Update()
{
	if (sprite != nullptr)
	{
		int rScaleX = w * transform->scale.x,
			rScaleY = h * transform->scale.y;
		
		dstRect = {
			(int)(transform->position.x),
			(int)(Game::mScreenHeight) - rScaleY - (int)(transform->position.y),
			rScaleX,
			rScaleY
		};

		SDL_SetRenderDrawColor(Game::mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderCopyEx(Game::mRenderer, sprite, origRect, &dstRect,
			-transform->rotation.z, NULL, flip);
	}
}