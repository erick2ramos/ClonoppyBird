#include <stdio.h>
#include <SDL.h>
#include "Game.h"

//Screen dimension constants
int SCREEN_WIDTH = 600;
int SCREEN_HEIGHT = 800;

int main( int argc, char* args[] )
{
	Game mainGame(SCREEN_WIDTH, SCREEN_HEIGHT);

	if(!mainGame.Init())
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		if (!mainGame.LoadMedia())
		{
			printf("No media!\n");
		}
		else
		{
			while (mainGame.mRunnning) 
			{
				mainGame.Run();
			}
		}
	}
	
	mainGame.Close();

	return 0;
}