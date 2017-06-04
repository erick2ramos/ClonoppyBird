#include "GameEntity.h"

GameEntity::GameEntity()
{
	name = "GameEntity";
	active = true;
	transform = Transform();
	transform.gameObject = this;
	gameEntities.push_back(this);
}

GameEntity::GameEntity(char* name)
{
	this->name = name;
	active = true;
	transform = Transform();
	transform.gameObject = this;
	gameEntities.push_back(this);
}

GameEntity::~GameEntity()
{
	while (components.size() > 0)
	{
		GameComponent* gc = components.back();
		delete gc;
		components.pop_back();
	}
}

vector<GameEntity*> GameEntity::gameEntities;

GameEntity* GameEntity::Find(const char* name)
{
	for(vector<GameEntity*>::iterator it = gameEntities.begin(); it != gameEntities.end(); ++it)
	{
		if (strcmp((*it)->name, name) == 0)
		{
			return (*it);
		}
	}
	return NULL;
}

void GameEntity::SetUp()
{

}

void GameEntity::UpdateComponents()
{
	for (std::list<GameComponent*>::iterator it = components.begin(); it != components.end(); ++it)
	{
		if((*it)->enabled)
		{
			(*it)->Run();
		}
	}
}