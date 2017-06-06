#include "Scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{
}

void Scene::Reset()
{
	reset = true;
}

void Scene::Load()
{
	for (list<GameEntity*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		(*it)->SetUp();
	}
	reset = false;
}

void Scene::Unload()
{

}

void Scene::Run()
{
	for (std::list<GameEntity*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		if ((*it)->active)
		{
			(*it)->UpdateComponents();
		}
	}
}