#pragma once
#include "GameComponent.h"
#include <SDL_ttf.h>

class Text :
	public GameComponent
{
public:
	char* text;
	int fontSize, w, h;
	SDL_Rect dstRect;

	Text();
	~Text();

	void LoadFont(int, char*, const char*);
	void ChangeText(char*);

	void Start();

protected:
	void Update();

	TTF_Font* textFont;
	SDL_Texture* sprite;
};

