#pragma once
#include <list>
#include <SDL.h>
#include "Vector2.h"
#include "GameEntity.h"
#include "Bird.h"

using namespace std;

class PipeHandler : public GameEntity
{
public:
	PipeHandler(int mP);
	~PipeHandler();

	void SetUp();
	void UpdateComponents();

private:
	int maxPipes;
	bool start;
	float spawnCooldown;
	float timer;

	list<GameEntity*> pipes;
	Bird* player;

	GameEntity* CreatePipe();
};