#include "Text.h"
#include "Game.h"

Text::Text()
	: GameComponent()
{

}

Text::~Text()
{
	SDL_DestroyTexture(sprite);
	sprite = nullptr;

	TTF_CloseFont(textFont);
	textFont = NULL;
}

void Text::LoadFont(int size, char* text, const char* path)
{
	this->text = text;
	this->fontSize = size;
	textFont = TTF_OpenFont(path, fontSize);
	if (textFont == NULL) 
	{
		printf("Not a valid font %s", TTF_GetError());
		return;
	}
	TTF_SetFontOutline(textFont, 0);
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Surface* textSurface = TTF_RenderText_Blended(textFont, text, color);
	if (textSurface == NULL)
	{
		printf("Error with rendering text to surface %s", TTF_GetError());
	} 
	else 
	{
		sprite = SDL_CreateTextureFromSurface(Game::mRenderer, textSurface);
		if (sprite == NULL) 
		{
			printf("Couldn't generate texture %s", SDL_GetError());
		}
		else
		{
			w = textSurface->w;
			h = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}
}

void Text::ChangeText(char* newText)
{
	text = newText;
	TTF_SetFontOutline(textFont, 0);
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Surface* textSurface = TTF_RenderText_Blended(textFont, text, color);
	if (textSurface == NULL)
	{
		printf("Error with rendering text to surface %s", TTF_GetError());
	}
	else
	{
		sprite = SDL_CreateTextureFromSurface(Game::mRenderer, textSurface);
		if (sprite == NULL)
		{
			printf("Couldn't generate texture %s", SDL_GetError());
		}
		else
		{
			w = textSurface->w;
			h = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}
}

void Text::Start()
{

}

void Text::Update()
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
		SDL_RenderCopy(Game::mRenderer, sprite, NULL, &dstRect);
	}
}