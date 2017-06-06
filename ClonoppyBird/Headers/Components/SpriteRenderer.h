#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameComponent.h"

class SpriteRenderer : public GameComponent
{
public:
	SDL_Texture* sprite;
	int w, h;
	SDL_RendererFlip flip;
	SDL_Point center;
	SDL_Rect* origRect;
	SDL_Rect dstRect;

	SpriteRenderer();
	~SpriteRenderer();
	void LoadSprite(const char*);

	void Start();
protected:
	void Update();
};