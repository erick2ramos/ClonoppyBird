#include "InputManager.h"
#include "Game.h"

Vector2 InputManager::pointerPosition = Vector2();
bool InputManager::isTouchUp = false;
bool InputManager::isEscPressed = false;

bool InputManager::GetTouchUp()
{
	return isTouchUp;
}

bool InputManager::GetEscPressed()
{
	return isEscPressed;
}

void InputManager::InputPolling()
{
	SDL_Event mEvent;
	while (SDL_PollEvent(&mEvent))
	{
		switch (mEvent.type)
		{
			case SDL_KEYDOWN:
			{
				if (mEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					isEscPressed = true;
				break;
			}
			case SDL_FINGERUP:
			{
				isTouchUp = true;
				pointerPosition.x = mEvent.tfinger.x * Game::mScreenWidth;
				pointerPosition.y = mEvent.tfinger.y * Game::mScreenHeight;
				printf("x = %d, y = %d", pointerPosition.x, pointerPosition.y);
				break;
			}
			case SDL_MOUSEBUTTONUP:
			{
				isTouchUp = true;
				pointerPosition.x = mEvent.button.x;//mEvent.tfinger.x;
				pointerPosition.y = mEvent.button.y;//mEvent.tfinger.y;
				break;
			}
		}
	}
}

void InputManager::Init()
{
	isTouchUp = false;
	isEscPressed = false;
	pointerPosition.x = 0.0f;
	pointerPosition.y = 0.0f;
}