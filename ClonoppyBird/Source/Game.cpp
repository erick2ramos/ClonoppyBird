#include <stdio.h>
#include "Game.h"
#include "MainScene.h"
#include "MainMenuScene.h"
#include <SDL_ttf.h>
#include <algorithm>

SDL_Renderer* Game::mRenderer = nullptr;
SDL_Window* Game::mWindow = nullptr;
ui32 Game::mScreenWidth = 0;
ui32 Game::mScreenHeight = 0;
SDL_Surface* Game::mScreenSurface = nullptr;
Scene* Game::currentScene = nullptr;
Scene* Game::nextScene = nullptr;
Scene* Game::scenes[2] = {
	new MainMenuScene(),
	new MainScene()
};

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
#ifdef __ANDROID__
		//Uncomment to change screen size of android
		SDL_DisplayMode DM;
		SDL_GetCurrentDisplayMode(0, &DM);
		mScreenWidth = std::max(DM.w, (int) mScreenWidth);
		mScreenHeight = std::max(DM.h, (int)mScreenHeight);
#endif
		mWindow = SDL_CreateWindow("Clonoppy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN);
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

				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
				else
				{
					currentScene = scenes[0];
					mRunnning = true;
				}
			}
		}
	}

	return success;
}

void Game::ResetScene()
{
	currentScene->Reset();
}

void Game::ChangeScene(int sceneIndex)
{		
	nextScene = scenes[sceneIndex];
}

bool Game::LoadMedia() 
{
	//Loading success flag
	bool success = true;
	currentScene->Load();
	return success;
}

void Game::Run()
{
	Time::Tick();

	InputManager::Init();
	InputManager::InputPolling();
	
	if (InputManager::GetEscPressed())
	{
		mRunnning = false;
	}

	SDL_RenderClear(mRenderer);
	currentScene->Run();

	lag += Time::GetDelta();

	SDL_RenderPresent(mRenderer);

	if (nextScene != nullptr && nextScene != currentScene)
	{
		currentScene->Unload();
		currentScene = nextScene;
		currentScene->Load();
	}
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
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}