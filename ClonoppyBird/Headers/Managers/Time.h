#pragma once
#include <SDL.h>

class Time
{
public:
	static void Init();
	static float GetElapsed();
	static float GetDelta();
	static void Tick();

private:
	static Uint32 time;
	static float deltaTime;

	Time() {}
};
