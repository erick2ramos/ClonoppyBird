#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <list>
#include "Typedefs.h"
#include "Time.h"
#include "Bird.h"
#include "InputManager.h"
#include "Scene.h"

class Game 
{
public:
	bool mRunnning;
	static SDL_Renderer* mRenderer;
	static SDL_Window* mWindow;
	static ui32 mScreenWidth;
	static ui32 mScreenHeight;
	static SDL_Surface* mScreenSurface;
	Scene* currentScene;

	SDL_Event mEvent;

	std::list<GameEntity*> gameObjects;

	Game(const int width, const int height);
	~Game();

	bool Init();
	bool LoadMedia();
	void Run();
	void Close();

protected:
	float lag;
};
