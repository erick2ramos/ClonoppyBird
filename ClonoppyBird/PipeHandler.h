#pragma once
#include <list>
#include <SDL.h>
#include "Vector2.h"
#include "GameEntity.h"

using namespace std;

class PipeHandler : public GameEntity
{
public:
	PipeHandler(int mP);
	~PipeHandler();

	void UpdateComponents();

private:
	int maxPipes;
	bool start;
	float spawnCooldown;
	float timer;

	list<GameEntity*> pipes;

	GameEntity* CreatePipe();
};