#pragma once
#include <SDL.h>
#include "Vector2.h"

class InputManager
{
public:
	static Vector2 pointerPosition;

	static bool GetTouchUp();
	static bool GetEscPressed();
	static void InputPolling();
	static void Init();

private:
	static bool isTouchUp;
	static bool isEscPressed;

	InputManager(){}
};