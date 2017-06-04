#include "PipeHandler.h"
#include "Pipe.h"
#include "Time.h"
#include "Game.h"

PipeHandler::PipeHandler(int maxPipes) :
	GameEntity("PHandler")
{
	spawnCooldown = 2.5f;
	timer = 0.0f;

	(*this).maxPipes = maxPipes;
	for (int i = 0; i < maxPipes; i++)
	{
		pipes.push_back(CreatePipe());
	}
}

PipeHandler::~PipeHandler()
{
	for (int i = 0; i < maxPipes; i++)
	{
		GameEntity* ge = pipes.back();
		delete ge;
		pipes.pop_back();
	}
	pipes.clear();
	player = nullptr;
}

void PipeHandler::UpdateComponents()
{
	GameEntity::UpdateComponents();
	
	for (list<GameEntity*>::iterator it = pipes.begin(); it != pipes.end(); ++it)
	{
		if ((*it)->active)
		{
			(*it)->UpdateComponents();
		}
	}

	if (player->bm == NULL || !player->bm->started)
		return;


	timer += Time::GetDelta();
	if (timer >= spawnCooldown) 
	{
		timer = 0.0f;
		for (list<GameEntity*>::iterator it = pipes.begin(); it != pipes.end(); ++it)
		{
			if (!(*it)->active)
			{
				(*it)->transform.position.x = Game::mScreenWidth;
				((Pipe*)(*it))->RandomHeight();
				(*it)->active = true;
				break;
			}
		}
	}
}

GameEntity* PipeHandler::CreatePipe()
{
	Pipe* newPipe = new Pipe();
	(*newPipe).active = false;
	return newPipe;
}

void PipeHandler::SetUp()
{
	player = (Bird*)GameEntity::Find("Bird");
	for (list<GameEntity*>::iterator it = pipes.begin(); it != pipes.end(); ++it)
	{
		(*it)->SetUp();
	}
	GameEntity::SetUp();
}
