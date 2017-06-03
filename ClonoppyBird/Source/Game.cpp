#include <stdio.h>
#include "Game.h"
#include "MainScene.h"

SDL_Renderer* Game::mRenderer = NULL;
SDL_Window* Game::mWindow = NULL;
ui32 Game::mScreenWidth = 0;
ui32 Game::mScreenHeight = 0;
SDL_Surface* Game::mScreenSurface = NULL;


Game::Game(const int width, const int height)
{
	mScreenWidth = width;
	mScreenHeight = height;
}

Game::~Game() 
{
	Close();
}

bool Game::Init() {
	//Initialization flag
	bool success = true;

	Time::Init();

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		mWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN);
		if (mWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
			if (mRenderer == NULL)
			{
				printf("Renderer not created!");
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				//Get window surface
				mScreenSurface = SDL_GetWindowSurface(mWindow);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image couldn't initialize: %s", IMG_GetError());
					success = false;
				} 
				else
				{
					currentScene = new MainScene();
					currentScene->Load();
					mRunnning = true;
				}
			}
		}
	}

	return success;
}

bool Game::LoadMedia() 
{
	//Loading success flag
	bool success = true;
	return success;
}

void Game::Run()
{
	InputManager::Init();
	InputManager::InputPolling();
	
	if (InputManager::GetEscPressed())
	{
		mRunnning = false;
	}

	SDL_RenderClear(mRenderer);
	currentScene->Run();

	Time::Tick();
	lag += Time::GetDelta();

	SDL_RenderPresent(mRenderer);
	/*while (lag >= 1000)
	{
		lag -= 1000;
	}*/
	//SDL_UpdateWindowSurface(mWindow);

}

void Game::Close()
{
	mRunnning = false;

	SDL_DestroyRenderer(mRenderer);

	//Destroy window
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}