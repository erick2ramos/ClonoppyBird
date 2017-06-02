#include "Time.h"
float Time::deltaTime = 0.0f;
Uint32 Time::time = 0;

void Time::Init()
{
	time = SDL_GetTicks();
	deltaTime = 0.0f;
}
float Time::GetElapsed()
{
	return time;
}
float Time::GetDelta()
{
	return deltaTime;
}
void Time::Tick()
{
	Uint32 current = SDL_GetTicks();
	deltaTime = (current - time) / 1000.0;
	time = current;
}